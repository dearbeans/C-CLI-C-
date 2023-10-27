namespace WindowsFormsApp
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_start = new System.Windows.Forms.Button();
            this.btn_close = new System.Windows.Forms.Button();
            this.btn_version = new System.Windows.Forms.Button();
            this.btn_startEnroll = new System.Windows.Forms.Button();
            this.btn_reset = new System.Windows.Forms.Button();
            this.btn_startIdent = new System.Windows.Forms.Button();
            this.comBoxEnrollMode = new System.Windows.Forms.ComboBox();
            this.picBoxMedium = new System.Windows.Forms.PictureBox();
            this.comBoxScale = new System.Windows.Forms.ComboBox();
            this.tb_Id = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tb_Num = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.lb_IrisDist = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxMedium)).BeginInit();
            this.SuspendLayout();
            // 
            // btn_start
            // 
            this.btn_start.Location = new System.Drawing.Point(12, 342);
            this.btn_start.Name = "btn_start";
            this.btn_start.Size = new System.Drawing.Size(75, 23);
            this.btn_start.TabIndex = 0;
            this.btn_start.Text = "开始";
            this.btn_start.UseVisualStyleBackColor = true;
            this.btn_start.Click += new System.EventHandler(this.Btn_Start_Click);
            // 
            // btn_close
            // 
            this.btn_close.Location = new System.Drawing.Point(12, 371);
            this.btn_close.Name = "btn_close";
            this.btn_close.Size = new System.Drawing.Size(75, 23);
            this.btn_close.TabIndex = 1;
            this.btn_close.Text = "关闭";
            this.btn_close.UseVisualStyleBackColor = true;
            this.btn_close.Click += new System.EventHandler(this.Btn_Close_Click);
            // 
            // btn_version
            // 
            this.btn_version.Location = new System.Drawing.Point(112, 342);
            this.btn_version.Name = "btn_version";
            this.btn_version.Size = new System.Drawing.Size(75, 23);
            this.btn_version.TabIndex = 2;
            this.btn_version.Text = "版本";
            this.btn_version.UseVisualStyleBackColor = true;
            this.btn_version.Click += new System.EventHandler(this.Btn_Version_Click);
            // 
            // btn_startEnroll
            // 
            this.btn_startEnroll.Location = new System.Drawing.Point(329, 371);
            this.btn_startEnroll.Name = "btn_startEnroll";
            this.btn_startEnroll.Size = new System.Drawing.Size(75, 23);
            this.btn_startEnroll.TabIndex = 3;
            this.btn_startEnroll.Text = "开始注册";
            this.btn_startEnroll.UseVisualStyleBackColor = true;
            this.btn_startEnroll.Click += new System.EventHandler(this.Btn_StartEnroll_Click);
            // 
            // btn_reset
            // 
            this.btn_reset.Location = new System.Drawing.Point(329, 342);
            this.btn_reset.Name = "btn_reset";
            this.btn_reset.Size = new System.Drawing.Size(75, 23);
            this.btn_reset.TabIndex = 4;
            this.btn_reset.Text = "重置";
            this.btn_reset.UseVisualStyleBackColor = true;
            this.btn_reset.Click += new System.EventHandler(this.Btn_Reset_Click);
            // 
            // btn_startIdent
            // 
            this.btn_startIdent.Location = new System.Drawing.Point(329, 399);
            this.btn_startIdent.Name = "btn_startIdent";
            this.btn_startIdent.Size = new System.Drawing.Size(75, 23);
            this.btn_startIdent.TabIndex = 5;
            this.btn_startIdent.Text = "开始识别";
            this.btn_startIdent.UseVisualStyleBackColor = true;
            this.btn_startIdent.Click += new System.EventHandler(this.Btn_StartIdent_Click);
            // 
            // comBoxEnrollMode
            // 
            this.comBoxEnrollMode.FormattingEnabled = true;
            this.comBoxEnrollMode.Location = new System.Drawing.Point(423, 344);
            this.comBoxEnrollMode.Name = "comBoxEnrollMode";
            this.comBoxEnrollMode.Size = new System.Drawing.Size(121, 20);
            this.comBoxEnrollMode.TabIndex = 6;
            // 
            // picBoxMedium
            // 
            this.picBoxMedium.Location = new System.Drawing.Point(3, 2);
            this.picBoxMedium.Name = "picBoxMedium";
            this.picBoxMedium.Size = new System.Drawing.Size(377, 188);
            this.picBoxMedium.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.picBoxMedium.TabIndex = 7;
            this.picBoxMedium.TabStop = false;
            // 
            // comBoxScale
            // 
            this.comBoxScale.FormattingEnabled = true;
            this.comBoxScale.Items.AddRange(new object[] {
            "默认",
            "960",
            "640",
            "480"});
            this.comBoxScale.Location = new System.Drawing.Point(202, 345);
            this.comBoxScale.Name = "comBoxScale";
            this.comBoxScale.Size = new System.Drawing.Size(121, 20);
            this.comBoxScale.TabIndex = 6;
            this.comBoxScale.SelectedIndexChanged += new System.EventHandler(this.comBoxScale_SelectedIndexChanged);
            // 
            // tb_Id
            // 
            this.tb_Id.Location = new System.Drawing.Point(619, 343);
            this.tb_Id.Name = "tb_Id";
            this.tb_Id.Size = new System.Drawing.Size(100, 21);
            this.tb_Id.TabIndex = 9;
            this.tb_Id.Text = "123";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(579, 347);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 12);
            this.label1.TabIndex = 10;
            this.label1.Text = "编号:";
            // 
            // tb_Num
            // 
            this.tb_Num.Location = new System.Drawing.Point(619, 380);
            this.tb_Num.Name = "tb_Num";
            this.tb_Num.Size = new System.Drawing.Size(100, 21);
            this.tb_Num.TabIndex = 9;
            this.tb_Num.Text = "2";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(560, 383);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 12);
            this.label2.TabIndex = 10;
            this.label2.Text = "注册数量:";
            // 
            // lb_IrisDist
            // 
            this.lb_IrisDist.AutoSize = true;
            this.lb_IrisDist.BackColor = System.Drawing.Color.Transparent;
            this.lb_IrisDist.Font = new System.Drawing.Font("宋体", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lb_IrisDist.ForeColor = System.Drawing.Color.Lime;
            this.lb_IrisDist.Location = new System.Drawing.Point(44, 13);
            this.lb_IrisDist.Name = "lb_IrisDist";
            this.lb_IrisDist.Size = new System.Drawing.Size(0, 19);
            this.lb_IrisDist.TabIndex = 11;
            this.lb_IrisDist.Paint += new System.Windows.Forms.PaintEventHandler(this.lb_IrisDist_Paint);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lb_IrisDist);
            this.Controls.Add(this.picBoxMedium);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tb_Num);
            this.Controls.Add(this.tb_Id);
            this.Controls.Add(this.comBoxScale);
            this.Controls.Add(this.comBoxEnrollMode);
            this.Controls.Add(this.btn_startIdent);
            this.Controls.Add(this.btn_reset);
            this.Controls.Add(this.btn_startEnroll);
            this.Controls.Add(this.btn_version);
            this.Controls.Add(this.btn_close);
            this.Controls.Add(this.btn_start);
            this.Name = "MainForm";
            this.Text = "北京中科虹霸多模态演示程序 version1.0";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MainForm_FormClosed);
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picBoxMedium)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_start;
        private System.Windows.Forms.Button btn_close;
        private System.Windows.Forms.Button btn_version;
        private System.Windows.Forms.Button btn_startEnroll;
        private System.Windows.Forms.Button btn_reset;
        private System.Windows.Forms.Button btn_startIdent;
        private System.Windows.Forms.ComboBox comBoxEnrollMode;
        private System.Windows.Forms.PictureBox picBoxMedium;
        private System.Windows.Forms.ComboBox comBoxScale;
        private System.Windows.Forms.TextBox tb_Id;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tb_Num;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lb_IrisDist;
    }
}

