#pragma once
#include <array>

#include "IKBaseProcessor.h"
namespace Irisking {
	/// <summary>
	/// 初始化打开设备的模式
	/// </summary>
	public enum class IK_Init_Mode
	{
		IKInitModeNone = -1,	/*!< 无效*/
		IKInitModeIris = 0,	/*!< 仅虹膜*/
		IKInitModeFace = 1,	/*!< 仅人脸*/
		IKInitModeDef = 2,	/*!< 打开SDK默认的camera，即支持哪些设备就初始化哪些*/
		IKInitModeBoth = 3		/*!< 虹膜+人脸*/
	};

	/// <summary>
	/// 多模态注册识别模式
	/// </summary>
	public enum class IK_Enroll_Ident_Mode
	{
		IKModeNone = -1,	/*!< 无效*/
		IKModeIris = 0,	/*!< 仅虹膜*/
		IKModeFace = 1,	/*!< 仅人脸*/
		IKModeUndef = 2,	/*!< 虹膜或人脸*/
		IKModeBoth = 3		/*!< 虹膜+人脸*/
	};

	/// <summary>
	/// iris模式,表示虹膜注册/识别时需要哪只眼睛进行注册/识别,或表示眼图类型
	/// </summary>
	public enum class IK_Iris_Mode
	{
		IKIrisModeNone = -1,/*!< 无效*/
		IKIrisModeUndef = 0,/*!< 任意眼*/
		IKIrisModeLeft = 1,/*!< 左眼*/
		IKIrisModeRight = 2,/*!< 右眼*/
		IKIrisModeBoth = 3,/*!< 双眼*/
	};



	//工作模式，表示空闲/注册/识别
	public enum class IK_Iris_Work_Mode
	{
		IKIrisWorkModeIdle = -1,		/*!< 空闲模式*/
		IKIrisWorkModeEnroll = 0,		/*!< 注册模式*/
		IKIrisWorkModeIdent = 1,		/*!< 识别模式*/
		IKIrisWorkModeCapture = 2, /*!< 快速采集模式*/
	};
	public value struct IK_Config_Info_Struct
	{
	public:
		//IK_Config_Info_Struct();
		IK_Enroll_Ident_Mode mode; /*!< 多模态注册识别模式*/
		IK_Iris_Mode irisMode; /*!< 虹膜注册识别模式*/
		bool irisEnrollIsEnforce;/*!< 虹膜注册是否强采,虹霸未明确说明需要强采则均设置为false*/
		IK_Iris_Work_Mode irisWorkMode; /*!< 虹膜,传递给算法的工作模式，用户使用一般情况下不需要设置，需要设置的虹霸会特别提醒*/
		int irisCount;/*!<虹膜注册数量*/
		int faceCount;/*!<人脸注册数量*/
		int overTime;/*!<超时时间，单位:秒*/

	};


	/// <summary>
	/// 比对输出信息
	/// </summary>
	public value struct IK_Match_Output_Struct
	{
	public:
		int matchScore;/*!< 分数*/
		int matchIndex;/*!< 比对成功的特征在输入特征列表中的index*/

	};


	/// <summary>
	/// 比对模式
	/// </summary>
	public enum class  IK_Match_Mode
	{
		IKMatchModeIris = 0,	/*!< 虹膜*/
		IKMatchModeFace = 1,	/*!< 人脸*/
	};



	/// <summary>
	///  Camera部件
	/// </summary>
	public enum class IK_COMPONENT_TYPE
	{
		IKCOMPONENT_InfraredLamp = 0,/*!< 红外灯*/
		IKCOMPONENT_FillLight = 1,/*!< 补光灯*/
		IKCOMPONENT_OUTPUTRGB = 2,/*!< 针对以mjpeg输出的rgb相机*/
		IKCOMPONENT_IRISDIVECE_SN = 3,
		IKCOMPONENT_FACEDIVECE_SN = 4,
		IKCOMPONENT_PTZ_CALIBRATION = 5, /*!< 舵机Y方向校准*/
		IKCOMPONENT_PTZ_HOMING = 6, /*!< 舵机Y方向复位*/
		IKCOMPONENT_PTZ_TEST = 7, /*!< 舵机Y方向测试用*/
	};


	/// <summary>
	/// Camera部件状态值
	/// </summary>
	public enum class IK_COMPONENT_STATUS
	{
		IKCOMPONENTUNKNOWN = -1,
		IKCOMPONENTOFF = 0,/*!< */
		IKCOMPONENTON = 1,/*!< */
	};


	/// <summary>
	/// 图像格式
	/// 目前irisAPI只接收IK_Frame_Format_Gray_8类型图像数据;faceAPI只接收IK_Frame_Format_RGB类型图像数据
	/// </summary>
	public enum class IK_Frame_Format
	{
		IK_Frame_Format_YUV = 0,
		IK_Frame_Format_YUYV = 1,
		IK_Frame_Format_YUV20SP = 2,
		IK_Frame_Format_BGRA = 3,
		IK_Frame_Format_BGR = 4,
		IK_Frame_Format_RGBA = 5,
		IK_Frame_Format_RGB = 6,
		IK_Frame_Format_RGB565 = 7,
		IK_Frame_Format_RAW = 8,
		IK_Frame_Format_NV21 = 9,
		IK_Frame_Format_MJPEG = 10,
		IK_Frame_Format_Gray_8 = 11,
		IK_Frame_Format_Gray_16 = 12,
		IK_Frame_Format_DEPTH = 1024,
		IK_Frame_Formate_Unknown = 9999,
	};


	/// <summary>
	/// 图像类型
	/// </summary>
	public enum class IK_Frame_Type
	{
		IK_Frame_Light = 0,/*!< 人脸图像*/
		IK_Frame_Dark, /*!< */
		IK_Frame_Depth,/*!< 深度图像*/
		IK_Frame_IR,/*!< 红外图像*/
		IK_Frame_IRIS,/*!< 虹膜大图*/
		IK_Frame_IRIS_VGA_L,/*!< 虹膜VGA图左眼*/
		IK_Frame_IRIS_VGA_R,/*!< 虹膜VGA图右眼*/
		IK_Frame_IRIS_VGA_LR,/*!< 虹膜VGA图双眼，默认放置顺序左眼在前右眼在后*/
		IK_Frame_Unknown = 9999,/*!< 未知*/
	};


	/// <summary>
	/// Camera灯的亮度模式
	/// </summary>
	public enum class  IK_LIGHT_MODE
	{
		MODE_DEGUALT = 0,/*!<默认*/
		MODE_ASYNFREQUENT = 1,/*!<异步频闪*/
		MODE_SYNFREQUENT = 2,/*!<同步频闪*/
		MODE_LOWCONTINUOUS = 3,/*!<弱常亮*/
		MODE_HIGHCONTINUOUS = 4,/*!<强常亮*/
	};



	/// <summary>
	/// camera热插拔回调事件枚举类型
	/// </summary>
	public enum class IK_Camera_Event {
		IKUSB_HOTPLUG_EVENT_DEVICE_ARRIVED = (1 << 0),/*!< 设备已插入并可以使用*/
		IKUSB_HOTPLUG_EVENT_DEVICE_LEFT = (1 << 1),/*!< 设备已离开，不再可用*/
		IKUSB_EVENT_DEVICE_UPSIDE = (1 << 2),/*!< 设备倒置*/
		IKUSB_MIRRORFLAG_CHECK_ERROR = (1 << 3),/*!< camera回调的图像方向和SDK设置的不一致，请检查*/
	};

	public value struct IK_Frame
	{
		cli::array<unsigned char, 1>^ data;/*!< 图像数据*/
		long data_len;/*!< 图像数据长度*/
		int width;/*!< 图像的宽*/
		int height;/*!< 图像的高*/
		int rotation;/*!< 旋转角度，暂时未使用*/
		IK_Frame_Format format;/*!< 图像格式*/
		IK_Frame_Type frame_type;/*!< 图像类型*/
	};


	public value struct IK_Camera_Updated {
		IK_Frame frame; /*!< 图像帧指针*/
		bool mirrorFlag; /*!< 图像帧是否为镜像图*/
		IK_Camera_Event event; /*!< Camera事件回调*/
		int deviceType; /*!< Camera设备类型*/
		IK_LIGHT_MODE lightMode; /*!< 红外灯的亮灯模式*/
		System::String^ deviceSN;
		int deviceSNLen;
		System::String^ deviceTypeString;
		int deviceTypeStringLen;
	};




	/// <summary>
	///  注册、识别时的成功,失败提示(描述多模态注册识别成功或失败的模态情况)
	/// </summary>
	public enum class IK_Enroll_Ident_Result_Flag
	{
		IKEnrRecIrisFaceFailed = -3,    /*!< 虹膜人脸注册or识别均失败,所以结果失败*/
		IKEnrRecFaceFailed = -2,		/*!< 人脸注册or识别失败,所以结果失败*/
		IKEnrRecIrisFailed = -1,		/*!< 虹膜注册or识别失败,所以结果失败*/
		IKEnrRecUnknown = 0,			/*!< 未知*/
		IKEnrRecIrisSuccess = 1,		/*!< 虹膜注册or识别成功,所以结果成功*/
		IKEnrRecFaceSuccess = 2,     /*!< 人脸注册or识别成功,所以结果成功*/
		IKEnrRecIrisFaceSuccess = 3,  /*!< 虹膜人脸注册or识别均成功,所以结果成功*/
	};



	/// <summary>
	/// 注册、识别、获取特征时的成功, 失败提示
	/// </summary>
	public enum class IK_Iris_Result_Flag
	{
		IKIrisEnrRecBothFailed = -3,/*!< 注册、识别、获取特征时左右眼均注册或识别失败*/
		IKIrisEnrRecRightFailed = -2,/*!< 右眼注册、识别、获取特征失败导致注册、识别、获取特征失败,左眼情况未知*/
		IKIrisEnrRecLeftFailed = -1,/*!< 左眼注册、识别、获取特征失败导致注册、识别、获取特征失败,右眼情况未知*/

		IKIrisEnrRecUnknown = 0,	/*!< 注册、识别、获取特征结果未知*/

		IKIrisEnrRecLeftSuccess = 1,/*!< 注册、识别、获取特征时仅左眼注册、识别、获取特征成功*/
		IKIrisEnrRecRightSuccess = 2,/*!< 注册、识别、获取特征时仅右眼注册、识别、获取特征成功*/
		IKIrisEnrRecBothSuccess = 3, /*!< 注册、识别、获取特征时左右眼均注册、识别、获取特征成功*/
	};


	/// <summary>
	/// 比对结果信息
	/// </summary>
	public value struct IK_Iris_Match_Output
	{
		int matchScore;/*!< 分数*/
		int matchIndex;/*!< 在输入特征列表中的index值*/
	};


	/*!
	* @brief 虹膜图像结构信息
	*/
	public value struct IK_Iris_Info
	{
		int ImgHeight;/*!< 虹膜图像的高度,当前必须固定为480*/
		int ImgWidth;/*!< 虹膜图像的宽度,当前必须固定为640*/
		int ImgType;/*!< 虹膜图像类型，左眼、右眼OR未知*/
		int IrisRow;/*!< 虹膜图像中虹膜中心的行索引，范围从1到IK_IRIS_IMG_HEIGHT*/
		int IrisCol;/*!< 虹膜图像中虹膜中心的列索引，范围从1到IK_IRIS_IMG_WIDTH*/
		int IrisRadius;/*!< 虹膜图像中的虹膜半径*/
		int FocusScore;/*!< 虹膜图像聚焦级别的指示器，范围从0到100*/
		int PercentVisible;/*!< 虹膜可见部分的百分比，范围从0到100*/
		int Brightness;/*!< 亮度*/
		int MotionBlur;/*!< 运动模糊*/
		int QualityScore;
		cli::array<unsigned char>^ imgData;/*!< 原始虹膜图像的像素强度值的一维数组*/
		int imgDataLen; /*!< IK_IRIS_IMG_SIZE*/
		cli::array<unsigned char>^ imgDataMat;/*!< 虹膜图像算法信息*/
		int imgDataMatLen; /*!< IK_CompleteInfoByte_IrisImFE*/
		cli::array<unsigned char>^ irisEnrTemplate;/*!< 虹膜图像特征模板已注册到数据库中，固定长度为512字节*/
		int irisEnrTemplateLen; /*!< IK_IRIS_ENROLL_FEATURE_SIZE*/
		cli::array<unsigned char>^ irisRecTemplate;/*!< 识别图像的虹膜图像特征模板，固定长度1024字节*/
		int irisRecTemplateLen; /*!< IK_IRIS_IDEN_FEATURE_SIZE*/
		cli::array<int>^ irisInfoUnkonwn;/*!< 预留信息: [10]标记是否进行IDQT处理，"1000"标识进行IDQT处理，其他均未处理*/
		int irisInfoUnkonwnLen; /*!< IK_UnknownInfoLen*/
	};


	/*!
	* @brief 虹膜识别结果数据
	*/
	public value struct IK_Iris_Ident_Processed_Result_Struct
	{

		int _nFunResult;/*!< 识别结果返回值,成功返回IKIris_Fun_Success,失败返回错误码*/
		IK_Iris_Mode _irisMode;/*!< 识别模式*/
		IK_Iris_Result_Flag _flag;/*!< 虹膜识别结果标志，解释虹膜识别成功或失败的具体原因*/
		IK_Iris_Match_Output _matchOutputL, _matchOutputR;/*!< 识别结果左右眼具体信息*/
		IK_Iris_Info _irisInfoL, _irisInfoR;
	};

	/// <summary>
	/// 比对结果结构体
	/// </summary>
	public value struct IK_Face_Match_Output
	{
		int matchScore;/*!< 比对成功的特征分数*/
		int matchIndex;/*!< 比对成功的特征在特征列表中的index*/
	};

	/// <summary>
	///  通用矩形坐标结构
	/// </summary>
	public value struct  SELF_RECT
	{
		long    left;/*!< 左边界坐标*/
		long    top;/*!< 上边界坐标*/
		long    right;/*!< 右边界坐标*/
		long    bottom;/*!< 下边界坐标*/
	};


	/// <summary>
	/// 人脸各角度
	/// </summary>
	public value struct IK_Face_Qulity_Info
	{
		float   yaw;/*!< 人脸左右摇头姿态, 范围为(-50,50)*/
		float   pitch;/*!< 人脸上下抬低头姿态, 范围为(-50,50)*/
		float   roll;/*!< 人脸左右歪头姿态，范围为(-90, 90)*/
		float confidence;/*!< 人脸得分，范围为(0,1)*/
	};

	/// <summary>
	/// 生物模态信息结构体，包含有图像、特征、分数等必要信息
	/// </summary>
	public value struct IK_Face_Processed_Result
	{
		SELF_RECT		m_rcFace;/*!< 可检测区域脸部坐标*/
		IK_Face_Qulity_Info	 m_faceQuality;/*!< 人脸各角度*/
		cli::array<unsigned char>^ m_detectImageData; /*!< 人脸的可检测区域图像数据*/
		int m_detectImageSize;/*!< 人脸可检测区域图像大小*/
		int m_detectImageH;/*!< 人脸可检测区域图像高*/
		int m_detectImageW;/*!< 人脸可检测区域图像宽*/

		cli::array<unsigned char>^ m_imageData; /*!< 人脸的原始图像数据*/
		int m_imageSize;/*!< 人脸原始图像大小*/
		int m_imageH;/*!< 人脸原始图像高*/
		int m_imageW;/*!< 人脸原始图像宽*/

		cli::array<unsigned char>^ m_enrTemplate;/*!< 人脸的注册特征*/
		int m_enrTemplateSize;	/*!< 人脸的注册特征长度*/
		cli::array<unsigned char>^ m_recTemplate; /*!< 人脸的识别特征*/
		int m_recTemplateSize;/*!< 人脸的识别特征长度*/
	};

	/// <summary>
	/// 识别结果结构体
	/// </summary>
	public value struct IK_Face_Ident_Output_Struct
	{
		int identResult;/*!< 识别结果返回值，成功返回IKFace_Fun_Success,失败返回错误码*/
		IK_Face_Match_Output matchResult;/*!< 识别结果特征信息*/
		IK_Face_Processed_Result resultInfo;
	};

	/// <summary>
	/// 多模态识别结果信息结构体
	/// </summary>
	public value struct IK_Ident_Processed_Result_Struct
	{
		IK_Enroll_Ident_Result_Flag _enrollIdentResFlag;/*!< 描述多模态识别结果*/
		IK_Enroll_Ident_Mode _enrollIdentMode;/*!< 识别模式*/
		IK_Iris_Ident_Processed_Result_Struct _irisIdentResult;/*!< 虹膜识别结果*/
		IK_Face_Ident_Output_Struct _faceIdentResult;/*!< 人脸识别结果*/

	};


	/// <summary>
	/// log类型枚举
	/// </summary>
	public enum class IK_Log {
		IK_Log_STATUS = 1,/*!< 只输出帧处理情况的状态回调信息,即丢图过程及原因*/
		IK_Log_VERBOSE = 2,/*!< 在注册识别结束时会将整个注册过程中每一帧输入的图像处理结果综合输出*/
		IK_Log_DEBUG = 3, /*!< 注册识别的过程信息*/
		IK_Log_INFO = 4, /*!< 暂时只输出帧率*/
		IK_Log_WARN = 5, /*!< 暂未使用*/
		IK_Log_ERROR = 6, /*!< 检测到错误*/
		IK_Log_Performance = 7,/*!< 性能测试相关log输出，例如time*/
	};





	/// <summary>
	///  回调信息中人脸虹膜信息有效枚举类型(每帧只有一种类型有效)
	/// </summary>
	public enum class IK_Iris_And_Face_Data_Valid_Flag
	{
		DataNone = 0, /*!< 均无效*/
		IrisDataValid = 1,/*!< 虹膜状态信息有效*/
		FaceDataValid = 2,/*!< 人脸状态信息有效*/
	};


	/// <summary>
	///  虹膜位置信息
	/// </summary>
	public value  struct  IK_Iris_Pos
	{
		value  struct Iris_Pos {
			int xPixel;/*!< x坐标*/
			int yPixel;/*!< y坐标*/
			int radius;/*!< 半径*/
		}leftIrisPos, rightIrisPos; /*!< 左右眼虹膜中心坐标信息*/
		int dist; /*!< 虹膜与摄像头之间的估算距离*/
	};


	/// <summary>
	/// 虹膜算法提示的状态信息
	/// </summary>
	public value  struct IK_Iris_Processor_State {
		IK_Iris_Work_Mode workMode;/*!< 工作模式,空闲还是注册or识别*/
		int detectType;/*!< 眼睛检测函数检测到的眼睛类型*/
		IK_Iris_Mode irisMode;		/*!< 虹膜的图像类型*/
		float leftIrisProgress;	/*!< 左眼进度百分比*/
		float rightIrisProgress;		/*!< 右眼进度百分比*/
		int imageW; /*!< 虹膜位置信息对应的图像的宽*/
		int imageH;  /*!< 虹膜位置信息对应的图像的高*/
		IK_Iris_Pos irisPos;	/*!< 虹膜位置信息*/
		int throwAwayFrameStatus; /*!< 每帧处理失败的原因 <=0的数是有效数据*/
		int irisID;/*!< irisID*/
		int faceID;/*!< faceID*/
		int traceID;/*!< traceID*/
		int irisLeftMargin; /*!< 虹膜注册识别区域限制,图像上下左右预留宽度*/
		int irisRightMargin;
		int irisTopMargin;
		int irisBottomMargin;
		//int reservedInfo[IKIris_RESERVEDINFO_LEN]; /*!< 预留信息*/
	};


	/// <summary>
	/// 人脸工作模式枚举
	/// </summary>
	public enum class IK_Face_Work_Mode
	{
		IKFace_WorkMode_Enroll = 0,/*!< 注册模式*/
		IKFace_WorkMode_Iden = 1,/*!< 识别模式*/
		IKFace_WorkMode_Idle = -1,/*!< 空闲模式*/
	};


	/// <summary>
	/// 通用点坐标结构
	/// </summary>
	public value  struct SELF_POINT
	{
		long  x;/*!< x坐标*/
		long  y;/*!< y坐标*/
	};

	/// <summary>
	/// 人脸ROI区域信息
	/// </summary>
	public value  struct IK_Face_ROI_Info
	{
		bool		        ifValid;/*!< 标记以下数据是否有效*/
		SELF_RECT		rcFace;/*!< 脸部坐标*/
		SELF_POINT		ptLeftEye;/*!< 左眼坐标*/
		SELF_POINT		ptRightEye;/*!< 右眼坐标*/
		SELF_POINT		ptMouthLeft;/*!< 嘴巴坐标*/
		SELF_POINT		ptMouthRight;/*!< 嘴巴坐标*/
		SELF_POINT		ptNose;/*!< 鼻子坐标*/
		IK_Face_Qulity_Info	fAngle;/*!< 脸部角度*/
	};

	/// <summary>
	/// 人脸状态回调信息结构体
	/// </summary>
	public value  struct IK_Face_Processor_State
	{

		IK_Face_Work_Mode workMode;/*!< 工作模式*/
		IK_Face_ROI_Info faceROIInfo; /*!< 检测的人脸ROI区域信息*/
		int dist; /*!< 人脸与摄像头之间的估算距离*/
		float lightScore; /*!< 图像亮度*/
		int imageW; /*!< 原始图像宽*/
		int imageH; /*!< 原始图像高*/
		int detectBeginX; /*!< 检测起始x坐标*/
		int detectBeginY; /*!< 检测起始y坐标*/
		int detectW; /*!< 检测图像宽*/
		int detectH; /*!< 检测图像高*/
		float faceProgress; /*!< 注册识别进度百分比*/
		int throwAwayFrameStatus;/*!< 每帧处理失败的原因 <=0的数是有效数据*/
		int imageIndex;/*!< */
	};

	/// <summary>
	/// 多模态状态回调信息结构体
	/// </summary>
	public value struct IK_Processor_State
	{
		IK_Enroll_Ident_Mode mode;/*!< 注册识别模式*/
		IK_Iris_And_Face_Data_Valid_Flag dataValidFlag;/*!< 人脸虹膜信息有效标志*/
		IK_Iris_Processor_State pIrisState;/*!< 虹膜状态信息*/
		IK_Face_Processor_State pFaceState;/*!< 人脸状态信息*/
	};



	/// <summary>
	///  虹膜注册结果帧数据
	/// </summary>
	public value struct IK_Iris_Processed_Result
	{
		IK_Iris_Mode irisMode;/*!< 注册模式*/
		IK_Iris_Result_Flag flag;/*!< 虹膜注册结果标志，解释虹膜注册成功或失败的具体原因*/
		IK_Iris_Info irisInfo;/*!< 虹膜图像对应的具体信息*/
	};


	///
	///brief 多模态注册结果信息类
	/// 
	public ref  class IK_Base_Enroll_Processed_Result {
	private:
		IKBaseEnrollProcessedResult* _ikBaseEnrollProcessedResult;
	public:

		IK_Base_Enroll_Processed_Result(IKBaseEnrollProcessedResult& _ikBaseEnrollProcessedResult);
		/*!
			@brief 设置注册识别模式
			@param[in] mode 注册识别模式
			@return 无
			*/
		void setEnrollIdentMode(IK_Enroll_Ident_Mode mode);

		/*!
			@brief 获取注册识别模式
			@param 无
			@return 注册识别模式
		   */
		IK_Enroll_Ident_Mode getEnrollIdentMode();

		/*!
			@brief 设置注册识别结果标志
			@note 描述多模态注册识别成功或失败的模态情况
			@param[in] flag 标志
			@return 无
		   */
		void setEnrollIdentResFlag(IK_Enroll_Ident_Result_Flag flag);

		/*!
		  @brief 获取注册识别结果标志
		  @param 无
		  @return  结果标志
		  */
		IK_Enroll_Ident_Result_Flag getEnrollIdentResFlag();

		/*!
			@brief 添加虹膜算法处理结果
			@param algResultData 虹膜算法数据
			@return 无
			*/
		void addIrisData(IK_Iris_Processed_Result% algResultData);


		/*!
			 @brief 添加人脸算法处理结果
			 @param[in] algResultData 虹膜算法数据
			 @return 无
			 */
		void addFaceData(IK_Face_Processed_Result% algResultData);

		/*!
			 @brief 获取虹膜算法结果数据(index对应帧)
			 @param[in] index 数据索引
			 @param[in] data 算法结果数据
			 @return 成功取到算法数据返回true，否则为false
			 */
		bool getIrisResultData(int index, IK_Iris_Processed_Result% data);

		/*!
			 @brief 获取人脸算法结果数据(index对应帧)
			 @param[in] index 数据索引
			 @param[in] data 算法结果数据
			 @return 成功取到算法数据返回true，否则为false
			 */
		bool getFaceResultData(int index, IK_Face_Processed_Result% data);

		/*!
			 @brief 获取虹膜注册结果数据的数量
			 @param 无
			 @return 注册结果数据的数量
			 */
		int getIrisFrameNum();

		/*!
			 @brief 获取人脸注册结果数据的数量
			 @param 无
			 @return 注册结果数据的数量
			 */
		int getFaceFrameNum();

		/*!
			 @brief 设置虹膜注册结果
			 @param[in] 虹膜注册结果
			 @return 无
			 */
		void setIrisRes(int res);
		/*!
			 @brief 设置人脸注册结果
			 @param[in] 人脸注册结果
			 @return 无
			 */
		void setFaceRes(int res);
		/*!
			 @brief 获取虹膜注册结果
			 @param 无
			 @return 注册结果,注册成功返回值为IKIris_Fun_Success,失败返回对应错误码
			 */
		int getIrisRes();
		/*!
			 @brief 获取人脸注册结果
			 @param 无
			 @return 注册结果,注册成功返回值为IKFace_Fun_Success,失败返回对应错误码
			 */
		int getFaceRes();

	};

}