#include "pch.h"
#include "IKSDKE30.h"

Irisking::IK_SDK_E30::IK_SDK_E30()
{
}
Irisking::IK_SDK_E30::~IK_SDK_E30()
{

}

bool Irisking::IK_SDK_E30::CreateSDKObject()
{
	_baseSDKAPI = CreateSDKObj();

	if (_baseSDKAPI == nullptr) {
		return false;
	}
	return true;
}

bool Irisking::IK_SDK_E30::DestroySDKObject()
{
	pin_ptr<IKBaseSDKAPI*> _baseSDKAPIPoint = &_baseSDKAPI;
	DestroySDKObj(_baseSDKAPIPoint);
	return true;
}


void Irisking::IK_SDK_E30::GetVersion(String^% versionStr)
{
	char* cstr = (char*)malloc(1000);
	_baseSDKAPI->GetVersion(cstr);
	versionStr = gcnew String(cstr);
	free(cstr);
}

int Irisking::IK_SDK_E30::InitDevice(IK_Init_Mode ik_init_mode)
{
	_ikBaseProcessor = new IKBaseProcessor;
	IKInitMode initDeviceMode;
	initDeviceMode = (IKInitMode)ik_init_mode;
	int res = _baseSDKAPI->Init(_ikBaseProcessor, initDeviceMode);

	return res;
}

int Irisking::IK_SDK_E30::Config(IK_Config_Info_Struct config)
{
	IKConfigInfoStruct _config;
	_config.mode = (IKEnrollIdentMode)config.mode;
	_config.irisMode = (IKIrisMode)config.irisMode;
	_config.irisEnrollIsEnforce = config.irisEnrollIsEnforce;
	_config.irisWorkMode = (IKIrisWorkMode)config.irisWorkMode;
	_config.irisCount = config.irisCount;
	_config.faceCount = config.faceCount;
	_config.overTime = config.overTime;

	int res = _baseSDKAPI->Config(_config);
	return res;
}

int Irisking::IK_SDK_E30::StartEnroll()
{
	int res = _baseSDKAPI->StartEnroll();
	return res;
}

int Irisking::IK_SDK_E30::StopEnroll()
{
	int res = _baseSDKAPI->StopEnroll();
	return res;
}

int Irisking::IK_SDK_E30::StartIdent(cli::array<System::Byte>^ pCodeListL, int codeNumL, cli::array<System::Byte>^ pCodeListR, int codeNumR, cli::array<System::Byte>^ pCodeListF, int codeNumF)
{
	pin_ptr<System::Byte> ptrL = pCodeListL == nullptr ? nullptr : &pCodeListL[0];
	unsigned char* _pCodeListL = ptrL;

	pin_ptr<System::Byte> ptrR = pCodeListR == nullptr ? nullptr : &pCodeListR[0];
	unsigned char* _pCodeListR = ptrR;

	pin_ptr<System::Byte> ptrF = pCodeListF == nullptr?nullptr: &pCodeListF[0];
	unsigned char* _pCodeListF = ptrF;

	int res = _baseSDKAPI->StartIdent(_pCodeListL, codeNumL, _pCodeListR, codeNumR, _pCodeListF, codeNumF);

	return res;
}

int Irisking::IK_SDK_E30::StopIdent()
{
	int res = _baseSDKAPI->StopIdent();
	return res;
}

int Irisking::IK_SDK_E30::Reset()
{
	int res = _baseSDKAPI->Reset();
	return res;

}

int Irisking::IK_SDK_E30::MatchFeature(cli::array<System::Byte>^ code, cli::array<System::Byte>^ pCodeList, int codeNum, IK_Match_Output_Struct% pMatchOutput, IK_Match_Mode matchMode)
{
	pin_ptr<System::Byte> _ptrCode = code == nullptr ? nullptr : &code[0];
	unsigned char* _pCode = _ptrCode;

	pin_ptr<System::Byte> _ptrCodeList = pCodeList == nullptr ? nullptr : &pCodeList[0];
	unsigned char* _pCodeList = _ptrCodeList;

	IKMatchOutputStruct _ikMatchOutputStruct;

	int res = _baseSDKAPI->MatchFeature(_pCode, _pCodeList, codeNum, &_ikMatchOutputStruct, (IKMatchMode)matchMode);
	pMatchOutput.matchIndex = _ikMatchOutputStruct.matchIndex;
	pMatchOutput.matchScore = _ikMatchOutputStruct.matchScore;
	return res;
}

int Irisking::IK_SDK_E30::Release()
{
	int res = _baseSDKAPI->Release();

	return res;
}

int Irisking::IK_SDK_E30::WriteParameter(IK_COMPONENT_TYPE type, IK_COMPONENT_STATUS status, int value, IK_LIGHT_MODE mode)
{
	int res = _baseSDKAPI->WriteParameter((IKCOMPONENTTYPE)type, (IKCOMPONENTSTATUS)status, value, (IKLIGHTMODE)mode);
	return res;
}



