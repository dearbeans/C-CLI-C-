using Irisking;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;
using System.Windows;
using System.Windows.Forms;
using Size = System.Drawing.Size;

namespace WindowsFormsApp
{
    public partial class MainForm : Form
    {
        Dictionary<IK_Iris_Mode, String> comBoxEnrollModeDataSource = new Dictionary<IK_Iris_Mode, string>();
        IK_SDK_E30 e30 = new IK_SDK_E30();
        private bool _openState = false;
        private static int PIX_SCALE = 0;
        public readonly string APP_Enr_Image_Path_Left = ".\\ResultSave\\Enroll_Image\\Left_Eye";
        public readonly string APP_Enr_Image_Path_Right = ".\\ResultSave\\Enroll_Image\\Right_Eye";

        public readonly string APP_Enr_Code_Path_Left = ".\\ResultSave\\Enroll_Template\\Left_Eye";
        public readonly string APP_Enr_Code_Path_Right = ".\\ResultSave\\Enroll_Template\\Right_Eye";
        Byte[] leftIrisCode = new Byte[0];
        Byte[] rightIrisCode = new Byte[0];
        int leftIrisCount = 0;
        int rightIrisCount = 0;
        byte[] imgHearder;
        public MainForm()
        {
            InitializeComponent();
            comBoxScale.SelectedIndex = 0;
            comBoxScale.DropDownStyle = ComboBoxStyle.DropDownList;
            FileStream fileStream = new FileStream("temp.bmp", FileMode.Open, FileAccess.Read); //将图片以文件流的形式进行保存
            BinaryReader binaryReader = new BinaryReader(fileStream);
            imgHearder = binaryReader.ReadBytes((int)fileStream.Length).Take(1078).ToArray();
            fileStream.Dispose();
            binaryReader.Dispose();

            #region comBoxEnrollModeDataSource
            comBoxEnrollModeDataSource = new Dictionary<IK_Iris_Mode, string> {
                { IK_Iris_Mode.IKIrisModeUndef, "任意眼" },
                { IK_Iris_Mode.IKIrisModeLeft, "左眼" },
                { IK_Iris_Mode.IKIrisModeRight, "右眼" },
                { IK_Iris_Mode.IKIrisModeBoth, "双眼" }
            };
            comBoxEnrollMode.DisplayMember = "Value";
            comBoxEnrollMode.ValueMember = "Key";

            comBoxEnrollMode.DropDownStyle = ComboBoxStyle.DropDownList;
            comBoxEnrollMode.DataSource = new BindingSource(comBoxEnrollModeDataSource, null);
            comBoxEnrollMode.SelectedIndex = 3;
            #endregion

            Init();
            lb_IrisDist.Parent = picBoxMedium;
            lb_IrisDist.BackColor = Color.Transparent;
        }

        /// <summary>
        /// 初始化文件夹创建
        /// </summary>
        private void Init()
        {

            if (!Directory.Exists(APP_Enr_Image_Path_Left))
            {
                Directory.CreateDirectory(APP_Enr_Image_Path_Left);
            }
            if (!Directory.Exists(APP_Enr_Image_Path_Right))
            {
                Directory.CreateDirectory(APP_Enr_Image_Path_Right);
            }
            if (!Directory.Exists(APP_Enr_Code_Path_Left))
            {
                Directory.CreateDirectory(APP_Enr_Code_Path_Left);
            }
            if (!Directory.Exists(APP_Enr_Code_Path_Right))
            {
                Directory.CreateDirectory(APP_Enr_Code_Path_Right);
            }

            ReadLeftCode();
            ReadRightCode();
        }

        private void ReadLeftCode()
        {
            string[] files = Directory.GetFiles(APP_Enr_Code_Path_Left);
            foreach (var item in files)
            {
                var featureCode = File.ReadAllBytes(item);
                leftIrisCode= leftIrisCode.Concat(featureCode).ToArray();
                leftIrisCount += 1;
            }
        }
        private void ReadRightCode()
        {
            string[] files = Directory.GetFiles(APP_Enr_Code_Path_Right);
            foreach (var item in files)
            {
                var featureCode = File.ReadAllBytes(item);
                rightIrisCode = rightIrisCode.Concat(featureCode).ToArray();
                rightIrisCount += 1;
            }
        }

        private void CameraUpdated(IK_Camera_Updated res)
        {
            if (res.frame.frame_type == IK_Frame_Type.IK_Frame_IRIS || res.frame.frame_type == IK_Frame_Type.IK_Frame_IRIS_VGA_L ||
             res.frame.frame_type == IK_Frame_Type.IK_Frame_IRIS_VGA_R || res.frame.frame_type == IK_Frame_Type.IK_Frame_IRIS_VGA_LR)
            {
                ByteToImage(res.frame);
            }
        }

        /// <summary>
        /// 转成bmp图像信息
        /// </summary>
        /// <param name="frame"></param>
        public void ByteToImage(IK_Frame frame)
        {
            //biSize
            byte[] bytes = BitConverter.GetBytes(frame.data_len + 1078);
            imgHearder[2] = bytes[0];
            imgHearder[3] = bytes[1];
            imgHearder[4] = bytes[2];
            imgHearder[5] = bytes[3];


            //biSizeImage
            bytes = BitConverter.GetBytes(frame.data_len);
            imgHearder[34] = bytes[0];
            imgHearder[35] = bytes[1];
            imgHearder[36] = bytes[2];
            imgHearder[37] = bytes[3];

            //biWidth

            bytes = BitConverter.GetBytes(frame.width);
            imgHearder[18] = bytes[0];
            imgHearder[19] = bytes[1];

            //biHeight
            bytes = BitConverter.GetBytes(frame.height);
            imgHearder[22] = bytes[0];
            imgHearder[23] = bytes[1];


            byte[] imgArr = new byte[frame.data_len + 1078];
            
            imgHearder.CopyTo(imgArr, 0);
            frame.data.CopyTo(imgArr, imgHearder.Length);
            MemoryStream stream = new MemoryStream(imgArr);

            System.Drawing.Image image = System.Drawing.Image.FromStream(stream);
            //旋转180度
            image.RotateFlip(RotateFlipType.Rotate180FlipX);
            if (PIX_SCALE != 0)
            {
                Size imgSize = new Size();
                imgSize = GetImageSize(imgSize);
                image = resizeImage(image, imgSize);
            }

            stream.Dispose();
            SetImage(image);
        }

        /// <summary>
        /// 保存虹膜图片
        /// </summary>
        /// <param name="fileName"></param>
        /// <param name="iK_Iris_Info"></param>
        public void SaveToBmpImage(string fileName, IK_Iris_Info iK_Iris_Info)
        {
            //biSize
            byte[] bytes = BitConverter.GetBytes(iK_Iris_Info.imgDataLen + 1078);
            imgHearder[2] = bytes[0];
            imgHearder[3] = bytes[1];
            imgHearder[4] = bytes[2];
            imgHearder[5] = bytes[3];


            //biSizeImage
            bytes = BitConverter.GetBytes(iK_Iris_Info.imgDataLen);
            imgHearder[34] = bytes[0];
            imgHearder[35] = bytes[1];
            imgHearder[36] = bytes[2];
            imgHearder[37] = bytes[3];

            //biWidth

            bytes = BitConverter.GetBytes(iK_Iris_Info.ImgWidth);
            imgHearder[18] = bytes[0];
            imgHearder[19] = bytes[1];

            //biHeight
            bytes = BitConverter.GetBytes(iK_Iris_Info.ImgHeight);
            imgHearder[22] = bytes[0];
            imgHearder[23] = bytes[1];


            byte[] imgArr = new byte[iK_Iris_Info.imgDataLen + 1078];
            imgHearder.CopyTo(imgArr, 0);
            iK_Iris_Info.imgData.CopyTo(imgArr, imgHearder.Length);
            MemoryStream stream = new MemoryStream(imgArr);

            System.Drawing.Image image = System.Drawing.Image.FromStream(stream);
            image.Save(fileName);
            stream.Dispose();
        }
        private Size GetImageSize(Size imgSize)
        {
            if (PIX_SCALE == 1)
            {
                imgSize = new Size(960, 540);
            }
            else if (PIX_SCALE == 2)
            {
                imgSize = new Size(680, 480);
            }
            else if (PIX_SCALE == 3)
            {
                imgSize = new Size(480, 360);
            }

            return imgSize;
        }

        /// <summary>
        /// 设置图像大小
        /// </summary>
        /// <param name="imgToResize"></param>
        /// <param name="size"></param>
        /// <returns></returns>
        private static System.Drawing.Image resizeImage(System.Drawing.Image imgToResize, Size size)
        {
            //获取图片宽度
            int srcWidth = imgToResize.Width;
            //获取图片高度
            int srcHeight = imgToResize.Height;

            float nPercent = 0;
            float nPercentW = 0;
            float nPercentH = 0;
            //计算宽度的缩放比例
            nPercentW = ((float)size.Width / (float)srcWidth);
            //计算高度的缩放比例
            nPercentH = ((float)size.Height / (float)srcHeight);

            if (nPercentH < nPercentW)
                nPercent = nPercentH;
            else
                nPercent = nPercentW;
            //期望的宽度
            int destWidth = (int)(srcWidth * nPercent);
            //期望的高度
            int destHeight = (int)(srcHeight * nPercent);

            Bitmap bitmap = new Bitmap(destWidth, destHeight);
            Graphics graphics = Graphics.FromImage((System.Drawing.Image)bitmap);
            graphics.InterpolationMode = InterpolationMode.HighQualityBicubic;
            //绘制图像
            graphics.DrawImage(imgToResize, 0, 0, destWidth, destHeight);
            graphics.Dispose();
            return (System.Drawing.Image)bitmap;
        }

        private delegate void SetImageCallBack(System.Drawing.Image img);
        private delegate void SetLbIrisDistCallBack(String txt);
        private void SetImage(System.Drawing.Image img)
        {
            if (this.picBoxMedium.InvokeRequired)
            {
                SetImageCallBack setImg = new SetImageCallBack(SetImage);
                try
                {
                    this.Invoke(setImg, new object[] { img });
                }
                catch (Exception ex)
                {

                }

            }
            else
            {
                this.picBoxMedium.Image = img;
            }
        }
        private void SetLbIrisDist(String txt)
        {
            if (this.lb_IrisDist.InvokeRequired)
            {
                SetLbIrisDistCallBack setLb = new SetLbIrisDistCallBack(SetLbIrisDist);
                try
                {
                    this.Invoke(setLb, new object[] { txt });
                }
                catch (Exception ex)
                {

                }

            }
            else
            {
                this.lb_IrisDist.Text = txt;
            }
        }
        private void MainForm_Load(object sender, EventArgs e)
        {
            var _sdk = e30.CreateSDKObject();
        }

        private void Btn_Start_Click(object sender, EventArgs e)
        {
            int res = 0;

            #region 测试函数

            #region OpenSDKObject
            //var _sdk = e30.CreateSDKObject();
            #endregion
            #region GetVersion
            //string version = string.Empty;
            //e30.GetVersion(ref version); 
            #endregion

            #region InitDevice
            res = e30.InitDevice(IK_Init_Mode.IKInitModeIris);
            #endregion
            #region Config
            //IK_Config_Info_Struct _ik_config_info_struct = new IK_Config_Info_Struct();
            //_ik_config_info_struct.mode = IK_Enroll_Ident_Mode.IKModeIris;
            //_ik_config_info_struct.irisMode = IK_Iris_Mode.IKIrisModeBoth;
            //_ik_config_info_struct.irisCount = 2;
            //_ik_config_info_struct.overTime = 30;
            //res = e30.Config(_ik_config_info_struct);
            #endregion
            #region StartEnroll
            //res = e30.StartEnroll();
            #endregion
            #region StartIdent
            //e30.StartIdent("我是码农", 2, "", 2, "", 2); 
            #endregion
            #region MatchFeature
            //IK_Match_Output_Struct pMatchOutput=new IK_Match_Output_Struct();
            //e30.MatchFeature("我是码农", "我是码农", 3, pMatchOutput, IK_Match_Mode.IKMatchModeIris);
            #endregion

            #region DestroySDKObject
            //e30.DestroySDKObject();
            #endregion
            #region Release
            //e30.Release();
            #endregion
            #endregion

            #region picBoxMedium

            #endregion

            #region Handler
            IK_SDK_E30.HandleCameraUpdated += CameraUpdated;
            IK_SDK_E30.HandleProcessCompleted += ProcessCompleted;
            IK_SDK_E30.HandleIdentProcessCompleted += IdentProcessCompleted;
            IK_SDK_E30.HandleStateUpdated += StateUpdated;

            #endregion

            _openState = true;
        }

        private void StateUpdated(IK_Processor_State state)
        {
            //lb_IrisDist.Text = $"L:{state.pIrisState.leftIrisProgress}% R:{state.pIrisState.rightIrisProgress}% Dist:{state.pIrisState.irisPos.dist}% IFRate:0.0";
            SetLbIrisDist($"L:{state.pIrisState.leftIrisProgress}% R:{state.pIrisState.rightIrisProgress}% Dist:{state.pIrisState.irisPos.dist}% IFRate:0.0");
        }

        private void IdentProcessCompleted(IK_Ident_Processed_Result_Struct result)
        {
          if(result._enrollIdentResFlag > IK_Enroll_Ident_Result_Flag.IKEnrRecUnknown)
            {
                MessageBox.Show($"识别成功!");
            }
        }

        private void ProcessCompleted(IK_Base_Enroll_Processed_Result result)
        {
            if (result.getEnrollIdentResFlag() > 0)
            {
                int g_left_save_num = 0;
                int g_right_save_num = 0;

                for (int num = 0; num < result.getIrisFrameNum(); num++)
                {
                    IK_Iris_Processed_Result s_irisResultData = new IK_Iris_Processed_Result();
                    result.getIrisResultData(num, ref s_irisResultData);

                    if (s_irisResultData.irisInfo.ImgType == 1)
                    {
                        string leftImgName = $"{APP_Enr_Image_Path_Left}\\{tb_Id.Text}_Left_{g_left_save_num}.bmp";
                        SaveToBmpImage(leftImgName, s_irisResultData.irisInfo);
                        string leftCodeName = $"{APP_Enr_Code_Path_Left}\\{tb_Id.Text}_Left_{g_left_save_num}.enr";
                        SaveToCodeTemp(leftCodeName, s_irisResultData.irisInfo);
                        g_left_save_num += 1;

                        leftIrisCode = leftIrisCode.Concat(s_irisResultData.irisInfo.irisEnrTemplate).ToArray();
                        leftIrisCount += 1;
                    }
                    else if (s_irisResultData.irisInfo.ImgType == 2)
                    {
                        string rightImgName = $"{APP_Enr_Image_Path_Right}\\{tb_Id.Text}_Right_{g_right_save_num}.bmp";
                        SaveToBmpImage(rightImgName, s_irisResultData.irisInfo);
                        string rightCodeName = $"{APP_Enr_Code_Path_Right}\\{tb_Id.Text}_Right_{g_right_save_num}.enr";
                        SaveToCodeTemp(rightCodeName, s_irisResultData.irisInfo);
                        g_right_save_num += 1;

                        rightIrisCode = rightIrisCode.Concat(s_irisResultData.irisInfo.irisEnrTemplate).ToArray();
                        rightIrisCount += 1;
                    }
                }
            }
        }

        /// <summary>
        /// 保存虹膜特征码
        /// </summary>
        /// <param name="fileName"></param>
        /// <param name="irisInfo"></param>
        private void SaveToCodeTemp(string fileName, IK_Iris_Info irisInfo)
        {
            FileStream fileStream = new FileStream(fileName, FileMode.Create);
            fileStream.Write(irisInfo.irisEnrTemplate, 0, irisInfo.irisEnrTemplateLen);
            fileStream.Close();
        }

        private void Btn_Close_Click(object sender, EventArgs e)
        {
            IK_SDK_E30.HandleCameraUpdated -= CameraUpdated;
            IK_SDK_E30.HandleProcessCompleted -= ProcessCompleted;
            var stop_res = e30.StopEnroll();
            var rel_res = e30.Release();
            _openState = false;
        }

        private void Btn_Version_Click(object sender, EventArgs e)
        {
            string version = string.Empty;
            e30.GetVersion(ref version);
            MessageBox.Show(version);
        }

        private void Btn_StartEnroll_Click(object sender, EventArgs e)
        {
            Config(IK_Work_Mode.IK_WorkMode_Enroll);
            int ret = e30.StartEnroll();
        }

        private void Config(IK_Work_Mode workMode)
        {
            if (workMode == IK_Work_Mode.IK_WorkMode_Enroll)
            {
                var selectedMode = ((KeyValuePair<IK_Iris_Mode, String>)comBoxEnrollMode.SelectedItem);
                IK_Config_Info_Struct _ik_config_info_struct = new IK_Config_Info_Struct();
                _ik_config_info_struct.mode = IK_Enroll_Ident_Mode.IKModeIris;
                _ik_config_info_struct.irisMode = (IK_Iris_Mode)selectedMode.Key;
                _ik_config_info_struct.irisCount = int.Parse(tb_Num.Text);
                _ik_config_info_struct.overTime = 30;
                var res = e30.Config(_ik_config_info_struct);
            }
            else if (workMode == IK_Work_Mode.IK_WorkMode_Iden)
            {
                var selectedMode = ((KeyValuePair<IK_Iris_Mode, String>)comBoxEnrollMode.SelectedItem);
                IK_Config_Info_Struct _ik_config_info_struct = new IK_Config_Info_Struct();
                _ik_config_info_struct.mode = IK_Enroll_Ident_Mode.IKModeIris;
                _ik_config_info_struct.irisMode = (IK_Iris_Mode)selectedMode.Key;
                _ik_config_info_struct.overTime = 30;
                var res = e30.Config(_ik_config_info_struct);
            }
        }

        private void Btn_Reset_Click(object sender, EventArgs e)
        {
            var res = e30.Reset();
        }

        private void Btn_StartIdent_Click(object sender, EventArgs e)
        {
            Config(IK_Work_Mode.IK_WorkMode_Iden);
            int ret = e30.StartIdent(leftIrisCode, leftIrisCount, rightIrisCode, rightIrisCount, null, 0);
            if (ret < 0)
            {
                MessageBox.Show($"失败:{ret}");
            }
        }

        private void comBoxScale_SelectedIndexChanged(object sender, EventArgs e)
        {
            PIX_SCALE = comBoxScale.SelectedIndex;
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = false;
            this.Btn_Close_Click(sender, e);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //e30._processed_Result.setEnrollIdentMode;
        }

        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {

        }

        private void lb_IrisDist_Paint(object sender, PaintEventArgs e)
        {
            //e.Graphics.FillRectangle(new SolidBrush(this.BackColor), e.ClipRectangle);
        }
    }
}
