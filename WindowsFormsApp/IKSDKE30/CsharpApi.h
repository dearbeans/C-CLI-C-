#pragma once
#include <array>

#include "IKBaseProcessor.h"
namespace Irisking {
	/// <summary>
	/// ��ʼ�����豸��ģʽ
	/// </summary>
	public enum class IK_Init_Mode
	{
		IKInitModeNone = -1,	/*!< ��Ч*/
		IKInitModeIris = 0,	/*!< ����Ĥ*/
		IKInitModeFace = 1,	/*!< ������*/
		IKInitModeDef = 2,	/*!< ��SDKĬ�ϵ�camera����֧����Щ�豸�ͳ�ʼ����Щ*/
		IKInitModeBoth = 3		/*!< ��Ĥ+����*/
	};

	/// <summary>
	/// ��ģ̬ע��ʶ��ģʽ
	/// </summary>
	public enum class IK_Enroll_Ident_Mode
	{
		IKModeNone = -1,	/*!< ��Ч*/
		IKModeIris = 0,	/*!< ����Ĥ*/
		IKModeFace = 1,	/*!< ������*/
		IKModeUndef = 2,	/*!< ��Ĥ������*/
		IKModeBoth = 3		/*!< ��Ĥ+����*/
	};

	/// <summary>
	/// irisģʽ,��ʾ��Ĥע��/ʶ��ʱ��Ҫ��ֻ�۾�����ע��/ʶ��,���ʾ��ͼ����
	/// </summary>
	public enum class IK_Iris_Mode
	{
		IKIrisModeNone = -1,/*!< ��Ч*/
		IKIrisModeUndef = 0,/*!< ������*/
		IKIrisModeLeft = 1,/*!< ����*/
		IKIrisModeRight = 2,/*!< ����*/
		IKIrisModeBoth = 3,/*!< ˫��*/
	};



	//����ģʽ����ʾ����/ע��/ʶ��
	public enum class IK_Iris_Work_Mode
	{
		IKIrisWorkModeIdle = -1,		/*!< ����ģʽ*/
		IKIrisWorkModeEnroll = 0,		/*!< ע��ģʽ*/
		IKIrisWorkModeIdent = 1,		/*!< ʶ��ģʽ*/
		IKIrisWorkModeCapture = 2, /*!< ���ٲɼ�ģʽ*/
	};
	public value struct IK_Config_Info_Struct
	{
	public:
		//IK_Config_Info_Struct();
		IK_Enroll_Ident_Mode mode; /*!< ��ģ̬ע��ʶ��ģʽ*/
		IK_Iris_Mode irisMode; /*!< ��Ĥע��ʶ��ģʽ*/
		bool irisEnrollIsEnforce;/*!< ��Ĥע���Ƿ�ǿ��,���δ��ȷ˵����Ҫǿ���������Ϊfalse*/
		IK_Iris_Work_Mode irisWorkMode; /*!< ��Ĥ,���ݸ��㷨�Ĺ���ģʽ���û�ʹ��һ������²���Ҫ���ã���Ҫ���õĺ�Ի��ر�����*/
		int irisCount;/*!<��Ĥע������*/
		int faceCount;/*!<����ע������*/
		int overTime;/*!<��ʱʱ�䣬��λ:��*/

	};


	/// <summary>
	/// �ȶ������Ϣ
	/// </summary>
	public value struct IK_Match_Output_Struct
	{
	public:
		int matchScore;/*!< ����*/
		int matchIndex;/*!< �ȶԳɹ������������������б��е�index*/

	};


	/// <summary>
	/// �ȶ�ģʽ
	/// </summary>
	public enum class  IK_Match_Mode
	{
		IKMatchModeIris = 0,	/*!< ��Ĥ*/
		IKMatchModeFace = 1,	/*!< ����*/
	};



	/// <summary>
	///  Camera����
	/// </summary>
	public enum class IK_COMPONENT_TYPE
	{
		IKCOMPONENT_InfraredLamp = 0,/*!< �����*/
		IKCOMPONENT_FillLight = 1,/*!< �����*/
		IKCOMPONENT_OUTPUTRGB = 2,/*!< �����mjpeg�����rgb���*/
		IKCOMPONENT_IRISDIVECE_SN = 3,
		IKCOMPONENT_FACEDIVECE_SN = 4,
		IKCOMPONENT_PTZ_CALIBRATION = 5, /*!< ���Y����У׼*/
		IKCOMPONENT_PTZ_HOMING = 6, /*!< ���Y����λ*/
		IKCOMPONENT_PTZ_TEST = 7, /*!< ���Y���������*/
	};


	/// <summary>
	/// Camera����״ֵ̬
	/// </summary>
	public enum class IK_COMPONENT_STATUS
	{
		IKCOMPONENTUNKNOWN = -1,
		IKCOMPONENTOFF = 0,/*!< */
		IKCOMPONENTON = 1,/*!< */
	};


	/// <summary>
	/// ͼ���ʽ
	/// ĿǰirisAPIֻ����IK_Frame_Format_Gray_8����ͼ������;faceAPIֻ����IK_Frame_Format_RGB����ͼ������
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
	/// ͼ������
	/// </summary>
	public enum class IK_Frame_Type
	{
		IK_Frame_Light = 0,/*!< ����ͼ��*/
		IK_Frame_Dark, /*!< */
		IK_Frame_Depth,/*!< ���ͼ��*/
		IK_Frame_IR,/*!< ����ͼ��*/
		IK_Frame_IRIS,/*!< ��Ĥ��ͼ*/
		IK_Frame_IRIS_VGA_L,/*!< ��ĤVGAͼ����*/
		IK_Frame_IRIS_VGA_R,/*!< ��ĤVGAͼ����*/
		IK_Frame_IRIS_VGA_LR,/*!< ��ĤVGAͼ˫�ۣ�Ĭ�Ϸ���˳��������ǰ�����ں�*/
		IK_Frame_Unknown = 9999,/*!< δ֪*/
	};


	/// <summary>
	/// Camera�Ƶ�����ģʽ
	/// </summary>
	public enum class  IK_LIGHT_MODE
	{
		MODE_DEGUALT = 0,/*!<Ĭ��*/
		MODE_ASYNFREQUENT = 1,/*!<�첽Ƶ��*/
		MODE_SYNFREQUENT = 2,/*!<ͬ��Ƶ��*/
		MODE_LOWCONTINUOUS = 3,/*!<������*/
		MODE_HIGHCONTINUOUS = 4,/*!<ǿ����*/
	};



	/// <summary>
	/// camera�Ȳ�λص��¼�ö������
	/// </summary>
	public enum class IK_Camera_Event {
		IKUSB_HOTPLUG_EVENT_DEVICE_ARRIVED = (1 << 0),/*!< �豸�Ѳ��벢����ʹ��*/
		IKUSB_HOTPLUG_EVENT_DEVICE_LEFT = (1 << 1),/*!< �豸���뿪�����ٿ���*/
		IKUSB_EVENT_DEVICE_UPSIDE = (1 << 2),/*!< �豸����*/
		IKUSB_MIRRORFLAG_CHECK_ERROR = (1 << 3),/*!< camera�ص���ͼ�����SDK���õĲ�һ�£�����*/
	};

	public value struct IK_Frame
	{
		cli::array<unsigned char, 1>^ data;/*!< ͼ������*/
		long data_len;/*!< ͼ�����ݳ���*/
		int width;/*!< ͼ��Ŀ�*/
		int height;/*!< ͼ��ĸ�*/
		int rotation;/*!< ��ת�Ƕȣ���ʱδʹ��*/
		IK_Frame_Format format;/*!< ͼ���ʽ*/
		IK_Frame_Type frame_type;/*!< ͼ������*/
	};


	public value struct IK_Camera_Updated {
		IK_Frame frame; /*!< ͼ��ָ֡��*/
		bool mirrorFlag; /*!< ͼ��֡�Ƿ�Ϊ����ͼ*/
		IK_Camera_Event event; /*!< Camera�¼��ص�*/
		int deviceType; /*!< Camera�豸����*/
		IK_LIGHT_MODE lightMode; /*!< ����Ƶ�����ģʽ*/
		System::String^ deviceSN;
		int deviceSNLen;
		System::String^ deviceTypeString;
		int deviceTypeStringLen;
	};




	/// <summary>
	///  ע�ᡢʶ��ʱ�ĳɹ�,ʧ����ʾ(������ģ̬ע��ʶ��ɹ���ʧ�ܵ�ģ̬���)
	/// </summary>
	public enum class IK_Enroll_Ident_Result_Flag
	{
		IKEnrRecIrisFaceFailed = -3,    /*!< ��Ĥ����ע��orʶ���ʧ��,���Խ��ʧ��*/
		IKEnrRecFaceFailed = -2,		/*!< ����ע��orʶ��ʧ��,���Խ��ʧ��*/
		IKEnrRecIrisFailed = -1,		/*!< ��Ĥע��orʶ��ʧ��,���Խ��ʧ��*/
		IKEnrRecUnknown = 0,			/*!< δ֪*/
		IKEnrRecIrisSuccess = 1,		/*!< ��Ĥע��orʶ��ɹ�,���Խ���ɹ�*/
		IKEnrRecFaceSuccess = 2,     /*!< ����ע��orʶ��ɹ�,���Խ���ɹ�*/
		IKEnrRecIrisFaceSuccess = 3,  /*!< ��Ĥ����ע��orʶ����ɹ�,���Խ���ɹ�*/
	};



	/// <summary>
	/// ע�ᡢʶ�𡢻�ȡ����ʱ�ĳɹ�, ʧ����ʾ
	/// </summary>
	public enum class IK_Iris_Result_Flag
	{
		IKIrisEnrRecBothFailed = -3,/*!< ע�ᡢʶ�𡢻�ȡ����ʱ�����۾�ע���ʶ��ʧ��*/
		IKIrisEnrRecRightFailed = -2,/*!< ����ע�ᡢʶ�𡢻�ȡ����ʧ�ܵ���ע�ᡢʶ�𡢻�ȡ����ʧ��,�������δ֪*/
		IKIrisEnrRecLeftFailed = -1,/*!< ����ע�ᡢʶ�𡢻�ȡ����ʧ�ܵ���ע�ᡢʶ�𡢻�ȡ����ʧ��,�������δ֪*/

		IKIrisEnrRecUnknown = 0,	/*!< ע�ᡢʶ�𡢻�ȡ�������δ֪*/

		IKIrisEnrRecLeftSuccess = 1,/*!< ע�ᡢʶ�𡢻�ȡ����ʱ������ע�ᡢʶ�𡢻�ȡ�����ɹ�*/
		IKIrisEnrRecRightSuccess = 2,/*!< ע�ᡢʶ�𡢻�ȡ����ʱ������ע�ᡢʶ�𡢻�ȡ�����ɹ�*/
		IKIrisEnrRecBothSuccess = 3, /*!< ע�ᡢʶ�𡢻�ȡ����ʱ�����۾�ע�ᡢʶ�𡢻�ȡ�����ɹ�*/
	};


	/// <summary>
	/// �ȶԽ����Ϣ
	/// </summary>
	public value struct IK_Iris_Match_Output
	{
		int matchScore;/*!< ����*/
		int matchIndex;/*!< �����������б��е�indexֵ*/
	};


	/*!
	* @brief ��Ĥͼ��ṹ��Ϣ
	*/
	public value struct IK_Iris_Info
	{
		int ImgHeight;/*!< ��Ĥͼ��ĸ߶�,��ǰ����̶�Ϊ480*/
		int ImgWidth;/*!< ��Ĥͼ��Ŀ��,��ǰ����̶�Ϊ640*/
		int ImgType;/*!< ��Ĥͼ�����ͣ����ۡ�����ORδ֪*/
		int IrisRow;/*!< ��Ĥͼ���к�Ĥ���ĵ�����������Χ��1��IK_IRIS_IMG_HEIGHT*/
		int IrisCol;/*!< ��Ĥͼ���к�Ĥ���ĵ�����������Χ��1��IK_IRIS_IMG_WIDTH*/
		int IrisRadius;/*!< ��Ĥͼ���еĺ�Ĥ�뾶*/
		int FocusScore;/*!< ��Ĥͼ��۽������ָʾ������Χ��0��100*/
		int PercentVisible;/*!< ��Ĥ�ɼ����ֵİٷֱȣ���Χ��0��100*/
		int Brightness;/*!< ����*/
		int MotionBlur;/*!< �˶�ģ��*/
		int QualityScore;
		cli::array<unsigned char>^ imgData;/*!< ԭʼ��Ĥͼ�������ǿ��ֵ��һά����*/
		int imgDataLen; /*!< IK_IRIS_IMG_SIZE*/
		cli::array<unsigned char>^ imgDataMat;/*!< ��Ĥͼ���㷨��Ϣ*/
		int imgDataMatLen; /*!< IK_CompleteInfoByte_IrisImFE*/
		cli::array<unsigned char>^ irisEnrTemplate;/*!< ��Ĥͼ������ģ����ע�ᵽ���ݿ��У��̶�����Ϊ512�ֽ�*/
		int irisEnrTemplateLen; /*!< IK_IRIS_ENROLL_FEATURE_SIZE*/
		cli::array<unsigned char>^ irisRecTemplate;/*!< ʶ��ͼ��ĺ�Ĥͼ������ģ�壬�̶�����1024�ֽ�*/
		int irisRecTemplateLen; /*!< IK_IRIS_IDEN_FEATURE_SIZE*/
		cli::array<int>^ irisInfoUnkonwn;/*!< Ԥ����Ϣ: [10]����Ƿ����IDQT����"1000"��ʶ����IDQT����������δ����*/
		int irisInfoUnkonwnLen; /*!< IK_UnknownInfoLen*/
	};


	/*!
	* @brief ��Ĥʶ��������
	*/
	public value struct IK_Iris_Ident_Processed_Result_Struct
	{

		int _nFunResult;/*!< ʶ��������ֵ,�ɹ�����IKIris_Fun_Success,ʧ�ܷ��ش�����*/
		IK_Iris_Mode _irisMode;/*!< ʶ��ģʽ*/
		IK_Iris_Result_Flag _flag;/*!< ��Ĥʶ������־�����ͺ�Ĥʶ��ɹ���ʧ�ܵľ���ԭ��*/
		IK_Iris_Match_Output _matchOutputL, _matchOutputR;/*!< ʶ���������۾�����Ϣ*/
		IK_Iris_Info _irisInfoL, _irisInfoR;
	};

	/// <summary>
	/// �ȶԽ���ṹ��
	/// </summary>
	public value struct IK_Face_Match_Output
	{
		int matchScore;/*!< �ȶԳɹ�����������*/
		int matchIndex;/*!< �ȶԳɹ��������������б��е�index*/
	};

	/// <summary>
	///  ͨ�þ�������ṹ
	/// </summary>
	public value struct  SELF_RECT
	{
		long    left;/*!< ��߽�����*/
		long    top;/*!< �ϱ߽�����*/
		long    right;/*!< �ұ߽�����*/
		long    bottom;/*!< �±߽�����*/
	};


	/// <summary>
	/// �������Ƕ�
	/// </summary>
	public value struct IK_Face_Qulity_Info
	{
		float   yaw;/*!< ��������ҡͷ��̬, ��ΧΪ(-50,50)*/
		float   pitch;/*!< ��������̧��ͷ��̬, ��ΧΪ(-50,50)*/
		float   roll;/*!< ����������ͷ��̬����ΧΪ(-90, 90)*/
		float confidence;/*!< �����÷֣���ΧΪ(0,1)*/
	};

	/// <summary>
	/// ����ģ̬��Ϣ�ṹ�壬������ͼ�������������ȱ�Ҫ��Ϣ
	/// </summary>
	public value struct IK_Face_Processed_Result
	{
		SELF_RECT		m_rcFace;/*!< �ɼ��������������*/
		IK_Face_Qulity_Info	 m_faceQuality;/*!< �������Ƕ�*/
		cli::array<unsigned char>^ m_detectImageData; /*!< �����Ŀɼ������ͼ������*/
		int m_detectImageSize;/*!< �����ɼ������ͼ���С*/
		int m_detectImageH;/*!< �����ɼ������ͼ���*/
		int m_detectImageW;/*!< �����ɼ������ͼ���*/

		cli::array<unsigned char>^ m_imageData; /*!< ������ԭʼͼ������*/
		int m_imageSize;/*!< ����ԭʼͼ���С*/
		int m_imageH;/*!< ����ԭʼͼ���*/
		int m_imageW;/*!< ����ԭʼͼ���*/

		cli::array<unsigned char>^ m_enrTemplate;/*!< ������ע������*/
		int m_enrTemplateSize;	/*!< ������ע����������*/
		cli::array<unsigned char>^ m_recTemplate; /*!< ������ʶ������*/
		int m_recTemplateSize;/*!< ������ʶ����������*/
	};

	/// <summary>
	/// ʶ�����ṹ��
	/// </summary>
	public value struct IK_Face_Ident_Output_Struct
	{
		int identResult;/*!< ʶ��������ֵ���ɹ�����IKFace_Fun_Success,ʧ�ܷ��ش�����*/
		IK_Face_Match_Output matchResult;/*!< ʶ����������Ϣ*/
		IK_Face_Processed_Result resultInfo;
	};

	/// <summary>
	/// ��ģ̬ʶ������Ϣ�ṹ��
	/// </summary>
	public value struct IK_Ident_Processed_Result_Struct
	{
		IK_Enroll_Ident_Result_Flag _enrollIdentResFlag;/*!< ������ģ̬ʶ����*/
		IK_Enroll_Ident_Mode _enrollIdentMode;/*!< ʶ��ģʽ*/
		IK_Iris_Ident_Processed_Result_Struct _irisIdentResult;/*!< ��Ĥʶ����*/
		IK_Face_Ident_Output_Struct _faceIdentResult;/*!< ����ʶ����*/

	};


	/// <summary>
	/// log����ö��
	/// </summary>
	public enum class IK_Log {
		IK_Log_STATUS = 1,/*!< ֻ���֡���������״̬�ص���Ϣ,����ͼ���̼�ԭ��*/
		IK_Log_VERBOSE = 2,/*!< ��ע��ʶ�����ʱ�Ὣ����ע�������ÿһ֡�����ͼ�������ۺ����*/
		IK_Log_DEBUG = 3, /*!< ע��ʶ��Ĺ�����Ϣ*/
		IK_Log_INFO = 4, /*!< ��ʱֻ���֡��*/
		IK_Log_WARN = 5, /*!< ��δʹ��*/
		IK_Log_ERROR = 6, /*!< ��⵽����*/
		IK_Log_Performance = 7,/*!< ���ܲ������log���������time*/
	};





	/// <summary>
	///  �ص���Ϣ��������Ĥ��Ϣ��Чö������(ÿֻ֡��һ��������Ч)
	/// </summary>
	public enum class IK_Iris_And_Face_Data_Valid_Flag
	{
		DataNone = 0, /*!< ����Ч*/
		IrisDataValid = 1,/*!< ��Ĥ״̬��Ϣ��Ч*/
		FaceDataValid = 2,/*!< ����״̬��Ϣ��Ч*/
	};


	/// <summary>
	///  ��Ĥλ����Ϣ
	/// </summary>
	public value  struct  IK_Iris_Pos
	{
		value  struct Iris_Pos {
			int xPixel;/*!< x����*/
			int yPixel;/*!< y����*/
			int radius;/*!< �뾶*/
		}leftIrisPos, rightIrisPos; /*!< �����ۺ�Ĥ����������Ϣ*/
		int dist; /*!< ��Ĥ������ͷ֮��Ĺ������*/
	};


	/// <summary>
	/// ��Ĥ�㷨��ʾ��״̬��Ϣ
	/// </summary>
	public value  struct IK_Iris_Processor_State {
		IK_Iris_Work_Mode workMode;/*!< ����ģʽ,���л���ע��orʶ��*/
		int detectType;/*!< �۾���⺯����⵽���۾�����*/
		IK_Iris_Mode irisMode;		/*!< ��Ĥ��ͼ������*/
		float leftIrisProgress;	/*!< ���۽��Ȱٷֱ�*/
		float rightIrisProgress;		/*!< ���۽��Ȱٷֱ�*/
		int imageW; /*!< ��Ĥλ����Ϣ��Ӧ��ͼ��Ŀ�*/
		int imageH;  /*!< ��Ĥλ����Ϣ��Ӧ��ͼ��ĸ�*/
		IK_Iris_Pos irisPos;	/*!< ��Ĥλ����Ϣ*/
		int throwAwayFrameStatus; /*!< ÿ֡����ʧ�ܵ�ԭ�� <=0��������Ч����*/
		int irisID;/*!< irisID*/
		int faceID;/*!< faceID*/
		int traceID;/*!< traceID*/
		int irisLeftMargin; /*!< ��Ĥע��ʶ����������,ͼ����������Ԥ�����*/
		int irisRightMargin;
		int irisTopMargin;
		int irisBottomMargin;
		//int reservedInfo[IKIris_RESERVEDINFO_LEN]; /*!< Ԥ����Ϣ*/
	};


	/// <summary>
	/// ��������ģʽö��
	/// </summary>
	public enum class IK_Face_Work_Mode
	{
		IKFace_WorkMode_Enroll = 0,/*!< ע��ģʽ*/
		IKFace_WorkMode_Iden = 1,/*!< ʶ��ģʽ*/
		IKFace_WorkMode_Idle = -1,/*!< ����ģʽ*/
	};


	/// <summary>
	/// ͨ�õ�����ṹ
	/// </summary>
	public value  struct SELF_POINT
	{
		long  x;/*!< x����*/
		long  y;/*!< y����*/
	};

	/// <summary>
	/// ����ROI������Ϣ
	/// </summary>
	public value  struct IK_Face_ROI_Info
	{
		bool		        ifValid;/*!< ������������Ƿ���Ч*/
		SELF_RECT		rcFace;/*!< ��������*/
		SELF_POINT		ptLeftEye;/*!< ��������*/
		SELF_POINT		ptRightEye;/*!< ��������*/
		SELF_POINT		ptMouthLeft;/*!< �������*/
		SELF_POINT		ptMouthRight;/*!< �������*/
		SELF_POINT		ptNose;/*!< ��������*/
		IK_Face_Qulity_Info	fAngle;/*!< �����Ƕ�*/
	};

	/// <summary>
	/// ����״̬�ص���Ϣ�ṹ��
	/// </summary>
	public value  struct IK_Face_Processor_State
	{

		IK_Face_Work_Mode workMode;/*!< ����ģʽ*/
		IK_Face_ROI_Info faceROIInfo; /*!< ��������ROI������Ϣ*/
		int dist; /*!< ����������ͷ֮��Ĺ������*/
		float lightScore; /*!< ͼ������*/
		int imageW; /*!< ԭʼͼ���*/
		int imageH; /*!< ԭʼͼ���*/
		int detectBeginX; /*!< �����ʼx����*/
		int detectBeginY; /*!< �����ʼy����*/
		int detectW; /*!< ���ͼ���*/
		int detectH; /*!< ���ͼ���*/
		float faceProgress; /*!< ע��ʶ����Ȱٷֱ�*/
		int throwAwayFrameStatus;/*!< ÿ֡����ʧ�ܵ�ԭ�� <=0��������Ч����*/
		int imageIndex;/*!< */
	};

	/// <summary>
	/// ��ģ̬״̬�ص���Ϣ�ṹ��
	/// </summary>
	public value struct IK_Processor_State
	{
		IK_Enroll_Ident_Mode mode;/*!< ע��ʶ��ģʽ*/
		IK_Iris_And_Face_Data_Valid_Flag dataValidFlag;/*!< ������Ĥ��Ϣ��Ч��־*/
		IK_Iris_Processor_State pIrisState;/*!< ��Ĥ״̬��Ϣ*/
		IK_Face_Processor_State pFaceState;/*!< ����״̬��Ϣ*/
	};



	/// <summary>
	///  ��Ĥע����֡����
	/// </summary>
	public value struct IK_Iris_Processed_Result
	{
		IK_Iris_Mode irisMode;/*!< ע��ģʽ*/
		IK_Iris_Result_Flag flag;/*!< ��Ĥע������־�����ͺ�Ĥע��ɹ���ʧ�ܵľ���ԭ��*/
		IK_Iris_Info irisInfo;/*!< ��Ĥͼ���Ӧ�ľ�����Ϣ*/
	};


	///
	///brief ��ģ̬ע������Ϣ��
	/// 
	public ref  class IK_Base_Enroll_Processed_Result {
	private:
		IKBaseEnrollProcessedResult* _ikBaseEnrollProcessedResult;
	public:

		IK_Base_Enroll_Processed_Result(IKBaseEnrollProcessedResult& _ikBaseEnrollProcessedResult);
		/*!
			@brief ����ע��ʶ��ģʽ
			@param[in] mode ע��ʶ��ģʽ
			@return ��
			*/
		void setEnrollIdentMode(IK_Enroll_Ident_Mode mode);

		/*!
			@brief ��ȡע��ʶ��ģʽ
			@param ��
			@return ע��ʶ��ģʽ
		   */
		IK_Enroll_Ident_Mode getEnrollIdentMode();

		/*!
			@brief ����ע��ʶ������־
			@note ������ģ̬ע��ʶ��ɹ���ʧ�ܵ�ģ̬���
			@param[in] flag ��־
			@return ��
		   */
		void setEnrollIdentResFlag(IK_Enroll_Ident_Result_Flag flag);

		/*!
		  @brief ��ȡע��ʶ������־
		  @param ��
		  @return  �����־
		  */
		IK_Enroll_Ident_Result_Flag getEnrollIdentResFlag();

		/*!
			@brief ��Ӻ�Ĥ�㷨������
			@param algResultData ��Ĥ�㷨����
			@return ��
			*/
		void addIrisData(IK_Iris_Processed_Result% algResultData);


		/*!
			 @brief ��������㷨������
			 @param[in] algResultData ��Ĥ�㷨����
			 @return ��
			 */
		void addFaceData(IK_Face_Processed_Result% algResultData);

		/*!
			 @brief ��ȡ��Ĥ�㷨�������(index��Ӧ֡)
			 @param[in] index ��������
			 @param[in] data �㷨�������
			 @return �ɹ�ȡ���㷨���ݷ���true������Ϊfalse
			 */
		bool getIrisResultData(int index, IK_Iris_Processed_Result% data);

		/*!
			 @brief ��ȡ�����㷨�������(index��Ӧ֡)
			 @param[in] index ��������
			 @param[in] data �㷨�������
			 @return �ɹ�ȡ���㷨���ݷ���true������Ϊfalse
			 */
		bool getFaceResultData(int index, IK_Face_Processed_Result% data);

		/*!
			 @brief ��ȡ��Ĥע�������ݵ�����
			 @param ��
			 @return ע�������ݵ�����
			 */
		int getIrisFrameNum();

		/*!
			 @brief ��ȡ����ע�������ݵ�����
			 @param ��
			 @return ע�������ݵ�����
			 */
		int getFaceFrameNum();

		/*!
			 @brief ���ú�Ĥע����
			 @param[in] ��Ĥע����
			 @return ��
			 */
		void setIrisRes(int res);
		/*!
			 @brief ��������ע����
			 @param[in] ����ע����
			 @return ��
			 */
		void setFaceRes(int res);
		/*!
			 @brief ��ȡ��Ĥע����
			 @param ��
			 @return ע����,ע��ɹ�����ֵΪIKIris_Fun_Success,ʧ�ܷ��ض�Ӧ������
			 */
		int getIrisRes();
		/*!
			 @brief ��ȡ����ע����
			 @param ��
			 @return ע����,ע��ɹ�����ֵΪIKFace_Fun_Success,ʧ�ܷ��ض�Ӧ������
			 */
		int getFaceRes();

	};

}