#pragma once
#include "IKBaseSDKAPI.h"
#include "IKBaseProcessor.h"
#include "CsharpApi.h"
using namespace System;
using namespace System::Runtime::InteropServices;
namespace Irisking {
	public	delegate void  DelegateInitCompleted(int initRes);
	public	delegate void  DelegateProcessCompleted(IK_Base_Enroll_Processed_Result^ result);
	public	delegate void  DelegateIdentProcessCompleted(IK_Ident_Processed_Result_Struct result);
	public	delegate void  DelegateStateUpdated(IK_Processor_State state);
	public	delegate void  DelegateCameraUpdated(IK_Camera_Updated ikCameraUpdated);
	public	delegate void  DelegateLog(String^ logType, IK_Log logLevel,String^ logInfo);
	public ref class IK_SDK_E30
	{
	private:
		IKBaseProcessor* _ikBaseProcessor;
		IKBaseSDKAPI* _baseSDKAPI;

		~IK_SDK_E30();
	public:
		static DelegateInitCompleted^ HandleInitCompleted;
		static DelegateProcessCompleted^ HandleProcessCompleted;
		static DelegateIdentProcessCompleted^ HandleIdentProcessCompleted;
		static DelegateStateUpdated^ HandleStateUpdated;
		static DelegateCameraUpdated^ HandleCameraUpdated;
		static DelegateLog^ HandleLog;
		IK_SDK_E30();

		/// <summary>
		/// 初始化SDK,创建对象
		/// </summary>
		/// <returns>bool</returns>
		bool CreateSDKObject();
		/// <summary>
		/// 释放多模态SDKAPI实例
		/// </summary>
		/// <returns></returns>
		bool DestroySDKObject();

		/// <summary>
		/// 获取版本信息
		/// </summary>
		/// <param name="versionStr">ref string</param>
		void GetVersion(String^% versionStr);
		/// <summary>
		/// 初始化设备及使用的相关资源
		/// </summary>
		int InitDevice(IK_Init_Mode ik_init_mode);
		/// <summary>
		/// 注册识别配置信息
		/// </summary>
		/// <param name="config"></param>
		/// <returns></returns>
		int Config(IK_Config_Info_Struct config);
		/// <summary>
		/// 开启注册线程
		/// </summary>
		/// <returns></returns>
		int StartEnroll();
		/// <summary>
		/// 停止注册
		/// </summary>
		/// <returns></returns>
		int StopEnroll();
		/// <summary>
		/// 开启识别线程
		/// </summary>
		/// <param name="pCodeListL"></param>
		/// <param name="codeNumL"></param>
		/// <param name="pCodeListR"></param>
		/// <param name="codeNumR"></param>
		/// <param name="pCodeListF"></param>
		/// <param name="codeNumF"></param>
		/// <returns></returns>
		int StartIdent(cli::array<System::Byte>^ pCodeListL, int codeNumL, cli::array<System::Byte>^ pCodeListR, int codeNumR, cli::array<System::Byte>^ pCodeListF, int codeNumF);
		/// <summary>
		/// 停止注册
		/// </summary>
		/// <returns></returns>
		int StopIdent();
		/// <summary>
		/// 清除缓存
		/// </summary>
		/// <returns></returns>
		int Reset();
		/// <summary>
		/// 算法比对
		/// </summary>
		/// <param name="code"></param>
		/// <param name="pCodeList"></param>
		/// <param name="codeNum"></param>
		/// <param name="pMatchOutput"></param>
		/// <param name="matchMode"></param>
		/// <returns></returns>
		int MatchFeature(cli::array<System::Byte>^ code, cli::array<System::Byte>^ pCodeList, int codeNum, IK_Match_Output_Struct% pMatchOutput, IK_Match_Mode matchMode);
		/// <summary>
		/// 释放所有资源
		/// </summary>
		/// <returns></returns>
		int Release();
		/// <summary>
		/// 设备部件操作
		/// </summary>
		/// <param name="type"></param>
		/// <param name="status"></param>
		/// <param name="value"></param>
		/// <param name="mode"></param>
		/// <returns></returns>
		int WriteParameter(IK_COMPONENT_TYPE type, IK_COMPONENT_STATUS status, int value, IK_LIGHT_MODE mode);
	};
}
