#include "pch.h"
#include "IKBaseProcessor.h"
#include <IKSDKE30.h>


Irisking::IKBaseProcessor::IKBaseProcessor()
{

}

Irisking::IKBaseProcessor::~IKBaseProcessor()
{

}

void Irisking::IKBaseProcessor::handleInitCompleted(int initRes)
{
	if (Irisking::IK_SDK_E30::HandleInitCompleted != nullptr) {
		Irisking::IK_SDK_E30::HandleInitCompleted(initRes);
	}
}

void Irisking::IKBaseProcessor::handleProcessCompleted(IKBaseEnrollProcessedResult& result)
{
	IK_Base_Enroll_Processed_Result^ _result = gcnew IK_Base_Enroll_Processed_Result(result);
	Irisking::IK_SDK_E30::HandleProcessCompleted(_result);
}

void Irisking::IKBaseProcessor::handleIdentProcessCompleted(const IKIdentProcessedResultStruct& result)
{
	IK_Ident_Processed_Result_Struct _result;

	_result._enrollIdentResFlag = (IK_Enroll_Ident_Result_Flag)result._enrollIdentResFlag;
	_result._enrollIdentMode = (IK_Enroll_Ident_Mode)result._enrollIdentMode;
#pragma region _irisIdentResult ×ª»»
	_result._irisIdentResult._nFunResult = result._irisIdentResult._nFunResult;
	_result._irisIdentResult._irisMode = (IK_Iris_Mode)result._irisIdentResult._irisMode;
	_result._irisIdentResult._flag = (IK_Iris_Result_Flag)result._irisIdentResult._flag;
#pragma region _result._irisIdentResult._matchOutputL
	_result._irisIdentResult._matchOutputL.matchIndex = result._irisIdentResult._matchOutputL.matchIndex;
	_result._irisIdentResult._matchOutputL.matchScore = result._irisIdentResult._matchOutputL.matchScore;
#pragma endregion
#pragma region _result._irisIdentResult._matchOutputR
	_result._irisIdentResult._matchOutputR.matchIndex = result._irisIdentResult._matchOutputR.matchIndex;
	_result._irisIdentResult._matchOutputR.matchScore = result._irisIdentResult._matchOutputR.matchScore;
#pragma endregion
#pragma region _result._irisIdentResult._irisInfoL
	_result._irisIdentResult._irisInfoL.ImgHeight = result._irisIdentResult._irisInfoL->ImgHeight;
	_result._irisIdentResult._irisInfoL.ImgWidth = result._irisIdentResult._irisInfoL->ImgWidth;
	_result._irisIdentResult._irisInfoL.ImgType = result._irisIdentResult._irisInfoL->ImgType;
	_result._irisIdentResult._irisInfoL.IrisRow = result._irisIdentResult._irisInfoL->IrisRow;
	_result._irisIdentResult._irisInfoL.IrisCol = result._irisIdentResult._irisInfoL->IrisCol;
	_result._irisIdentResult._irisInfoL.IrisRadius = result._irisIdentResult._irisInfoL->IrisRadius;
	_result._irisIdentResult._irisInfoL.FocusScore = result._irisIdentResult._irisInfoL->FocusScore;
	_result._irisIdentResult._irisInfoL.PercentVisible = result._irisIdentResult._irisInfoL->PercentVisible;
	_result._irisIdentResult._irisInfoL.Brightness = result._irisIdentResult._irisInfoL->Brightness;
	_result._irisIdentResult._irisInfoL.MotionBlur = result._irisIdentResult._irisInfoL->MotionBlur;
	_result._irisIdentResult._irisInfoL.QualityScore = result._irisIdentResult._irisInfoL->QualityScore;
#pragma region _result._irisIdentResult._irisInfoL.imgData
	_result._irisIdentResult._irisInfoL.imgData = gcnew cli::array<unsigned char>(result._irisIdentResult._irisInfoL->imgDataLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoL->imgDataLen; i++)
	{
		_result._irisIdentResult._irisInfoL.imgData[i] = result._irisIdentResult._irisInfoL->imgData[i];
	}
#pragma endregion
	_result._irisIdentResult._irisInfoL.imgDataLen = result._irisIdentResult._irisInfoL->imgDataLen;

#pragma region _result._irisIdentResult._irisInfoL.imgDataMat
	_result._irisIdentResult._irisInfoL.imgDataMat = gcnew cli::array<unsigned char>(result._irisIdentResult._irisInfoL->imgDataMatLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoL->imgDataMatLen; i++)
	{
		_result._irisIdentResult._irisInfoL.imgDataMat[i] = result._irisIdentResult._irisInfoL->imgDataMat[i];
	}
#pragma endregion
	_result._irisIdentResult._irisInfoL.imgDataMatLen = result._irisIdentResult._irisInfoL->imgDataMatLen;
#pragma region _result._irisIdentResult._irisInfoL.irisEnrTemplate
	_result._irisIdentResult._irisInfoL.irisEnrTemplate = gcnew cli::array<unsigned char>(result._irisIdentResult._irisInfoL->irisEnrTemplateLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoL->irisEnrTemplateLen; i++)
	{
		_result._irisIdentResult._irisInfoL.irisEnrTemplate[i] = result._irisIdentResult._irisInfoL->irisEnrTemplate[i];
	}
#pragma endregion
	_result._irisIdentResult._irisInfoL.irisRecTemplateLen = result._irisIdentResult._irisInfoL->irisRecTemplateLen;


	_result._irisIdentResult._irisInfoL.irisInfoUnkonwnLen = result._irisIdentResult._irisInfoL->irisInfoUnkonwnLen;

#pragma region _result._irisIdentResult._irisInfoL.irisInfoUnkonwn
	int* irisInfoLUnkonwnBuffer = new int[result._irisIdentResult._irisInfoL->irisInfoUnkonwnLen];
	memcpy(irisInfoLUnkonwnBuffer, result._irisIdentResult._irisInfoL->irisInfoUnkonwn, result._irisIdentResult._irisInfoL->irisInfoUnkonwnLen);
	_result._irisIdentResult._irisInfoL.irisInfoUnkonwn = gcnew cli::array<int>(result._irisIdentResult._irisInfoL->irisInfoUnkonwnLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoL->irisInfoUnkonwnLen; i++)
	{
		result._irisIdentResult._irisInfoL->irisInfoUnkonwn[i] = irisInfoLUnkonwnBuffer[i];
	}
	delete[] irisInfoLUnkonwnBuffer;
	irisInfoLUnkonwnBuffer = nullptr;

#pragma endregion


#pragma endregion
#pragma region _result._irisIdentResult._irisInfoR
	_result._irisIdentResult._irisInfoR.ImgHeight = result._irisIdentResult._irisInfoR->ImgHeight;
	_result._irisIdentResult._irisInfoR.ImgWidth = result._irisIdentResult._irisInfoR->ImgWidth;
	_result._irisIdentResult._irisInfoR.ImgType = result._irisIdentResult._irisInfoR->ImgType;
	_result._irisIdentResult._irisInfoR.IrisRow = result._irisIdentResult._irisInfoR->IrisRow;
	_result._irisIdentResult._irisInfoR.IrisCol = result._irisIdentResult._irisInfoR->IrisCol;
	_result._irisIdentResult._irisInfoR.IrisRadius = result._irisIdentResult._irisInfoR->IrisRadius;
	_result._irisIdentResult._irisInfoR.FocusScore = result._irisIdentResult._irisInfoR->FocusScore;
	_result._irisIdentResult._irisInfoR.PercentVisible = result._irisIdentResult._irisInfoR->PercentVisible;
	_result._irisIdentResult._irisInfoR.Brightness = result._irisIdentResult._irisInfoR->Brightness;
	_result._irisIdentResult._irisInfoR.MotionBlur = result._irisIdentResult._irisInfoR->MotionBlur;
	_result._irisIdentResult._irisInfoR.QualityScore = result._irisIdentResult._irisInfoR->QualityScore;
#pragma region _result._irisIdentResult._irisInfoR.imgData
	_result._irisIdentResult._irisInfoR.imgData = gcnew cli::array<unsigned char>(result._irisIdentResult._irisInfoR->imgDataLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoR->imgDataLen; i++)
	{
		_result._irisIdentResult._irisInfoR.imgData[i] = result._irisIdentResult._irisInfoR->imgData[i];
	}
#pragma endregion
	_result._irisIdentResult._irisInfoR.imgDataLen = result._irisIdentResult._irisInfoR->imgDataLen;

#pragma region _result._irisIdentResult._irisInfoR.imgDataMat
	_result._irisIdentResult._irisInfoR.imgDataMat = gcnew cli::array<unsigned char>(result._irisIdentResult._irisInfoR->imgDataMatLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoR->imgDataMatLen; i++)
	{
		_result._irisIdentResult._irisInfoR.imgDataMat[i] = result._irisIdentResult._irisInfoR->imgDataMat[i];
	}
#pragma endregion
	_result._irisIdentResult._irisInfoR.imgDataMatLen = result._irisIdentResult._irisInfoR->imgDataMatLen;
#pragma region _result._irisIdentResult._irisInfoR.irisEnrTemplate
	_result._irisIdentResult._irisInfoR.irisEnrTemplate = gcnew cli::array<unsigned char>(result._irisIdentResult._irisInfoR->irisEnrTemplateLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoR->irisEnrTemplateLen; i++)
	{
		_result._irisIdentResult._irisInfoR.irisEnrTemplate[i] = result._irisIdentResult._irisInfoR->irisEnrTemplate[i];
	}
#pragma endregion
	_result._irisIdentResult._irisInfoR.irisRecTemplateLen = result._irisIdentResult._irisInfoR->irisRecTemplateLen;
	
	
	_result._irisIdentResult._irisInfoR.irisInfoUnkonwnLen = result._irisIdentResult._irisInfoR->irisInfoUnkonwnLen;

#pragma region _irisIdentResult._irisInfoR.irisInfoUnkonwn
	int* irisInfoRUnkonwnBuffer = new int[result._irisIdentResult._irisInfoR->irisInfoUnkonwnLen];
	memcpy(irisInfoRUnkonwnBuffer, result._irisIdentResult._irisInfoR->irisInfoUnkonwn, result._irisIdentResult._irisInfoR->irisInfoUnkonwnLen);
	_result._irisIdentResult._irisInfoR.irisInfoUnkonwn = gcnew cli::array<int>(result._irisIdentResult._irisInfoR->irisInfoUnkonwnLen);
	for (int i = 0; i < result._irisIdentResult._irisInfoR->irisInfoUnkonwnLen; i++)
	{
		result._irisIdentResult._irisInfoR->irisInfoUnkonwn[i] = irisInfoRUnkonwnBuffer[i];
	}
	delete[] irisInfoRUnkonwnBuffer;
	irisInfoRUnkonwnBuffer = nullptr;


#pragma endregion


#pragma endregion

#pragma endregion

#pragma region _faceIdentResult ×ª»»
	_result._faceIdentResult.identResult = result._faceIdentResult.identResult;
#pragma region _result._faceIdentResult.matchResult
	_result._faceIdentResult.matchResult.matchIndex = result._faceIdentResult.matchResult.matchIndex;
	_result._faceIdentResult.matchResult.matchScore = result._faceIdentResult.matchResult.matchScore;
#pragma endregion
#pragma region _result._faceIdentResult.resultInfo
	if (result._faceIdentResult.resultInfo != nullptr) {
#pragma region result._faceIdentResult.resultInfo.m_rcFace

	_result._faceIdentResult.resultInfo.m_rcFace.left = result._faceIdentResult.resultInfo->m_rcFace.left;
	_result._faceIdentResult.resultInfo.m_rcFace.top = result._faceIdentResult.resultInfo->m_rcFace.top;
	_result._faceIdentResult.resultInfo.m_rcFace.right = result._faceIdentResult.resultInfo->m_rcFace.right;
	_result._faceIdentResult.resultInfo.m_rcFace.bottom = result._faceIdentResult.resultInfo->m_rcFace.bottom;

#pragma endregion


#pragma region _result._faceIdentResult.resultInfo.m_faceQuality
	_result._faceIdentResult.resultInfo.m_faceQuality.yaw = result._faceIdentResult.resultInfo->m_faceQuality.yaw;
	_result._faceIdentResult.resultInfo.m_faceQuality.pitch = result._faceIdentResult.resultInfo->m_faceQuality.pitch;
	_result._faceIdentResult.resultInfo.m_faceQuality.roll = result._faceIdentResult.resultInfo->m_faceQuality.roll;
	_result._faceIdentResult.resultInfo.m_faceQuality.confidence = result._faceIdentResult.resultInfo->m_faceQuality.confidence;
#pragma endregion


#pragma region _result._faceIdentResult.resultInfo.m_detectImageData
	_result._faceIdentResult.resultInfo.m_detectImageData = gcnew cli::array<unsigned char>(result._faceIdentResult.resultInfo->m_detectImageSize);
	for (int i = 0; i < result._faceIdentResult.resultInfo->m_detectImageSize; i++)
	{
		_result._faceIdentResult.resultInfo.m_detectImageData[i] = result._faceIdentResult.resultInfo->m_detectImageData[i];
	}
#pragma endregion
	_result._faceIdentResult.resultInfo.m_detectImageSize = result._faceIdentResult.resultInfo->m_detectImageSize;
	_result._faceIdentResult.resultInfo.m_detectImageH = result._faceIdentResult.resultInfo->m_detectImageH;
	_result._faceIdentResult.resultInfo.m_detectImageW = result._faceIdentResult.resultInfo->m_detectImageW;

#pragma region _result._faceIdentResult.resultInfo.m_imageData
	_result._faceIdentResult.resultInfo.m_imageData = gcnew cli::array<unsigned char>(result._faceIdentResult.resultInfo->m_imageSize);
	for (int i = 0; i < result._faceIdentResult.resultInfo->m_imageSize; i++)
	{
		_result._faceIdentResult.resultInfo.m_imageData[i] = result._faceIdentResult.resultInfo->m_imageData[i];
	}
#pragma endregion
	_result._faceIdentResult.resultInfo.m_imageSize = result._faceIdentResult.resultInfo->m_imageSize;
	_result._faceIdentResult.resultInfo.m_imageH = result._faceIdentResult.resultInfo->m_imageH;
	_result._faceIdentResult.resultInfo.m_imageW = result._faceIdentResult.resultInfo->m_imageW;

#pragma region _result._faceIdentResult.resultInfo.m_enrTemplate
	_result._faceIdentResult.resultInfo.m_enrTemplate = gcnew cli::array<unsigned char>(result._faceIdentResult.resultInfo->m_enrTemplateSize);
	for (int i = 0; i < result._faceIdentResult.resultInfo->m_enrTemplateSize; i++)
	{
		_result._faceIdentResult.resultInfo.m_enrTemplate[i] = result._faceIdentResult.resultInfo->m_enrTemplate[i];
	}
#pragma endregion

	_result._faceIdentResult.resultInfo.m_enrTemplateSize = result._faceIdentResult.resultInfo->m_enrTemplateSize;

#pragma region _result._faceIdentResult.resultInfo.m_recTemplate
	_result._faceIdentResult.resultInfo.m_recTemplate = gcnew cli::array<unsigned char>(result._faceIdentResult.resultInfo->m_recTemplateSize);
	for (int i = 0; i < result._faceIdentResult.resultInfo->m_recTemplateSize; i++)
	{
		_result._faceIdentResult.resultInfo.m_recTemplate[i] = result._faceIdentResult.resultInfo->m_recTemplate[i];
	}
#pragma endregion
	_result._faceIdentResult.resultInfo.m_recTemplateSize = result._faceIdentResult.resultInfo->m_recTemplateSize;

	}
#pragma endregion

#pragma endregion
	if (Irisking::IK_SDK_E30::HandleIdentProcessCompleted != nullptr) {
		Irisking::IK_SDK_E30::HandleIdentProcessCompleted(_result);
	}
}

void Irisking::IKBaseProcessor::handleStateUpdated(const IKProcessorState& state)
{
	IK_Processor_State _state;

	_state.mode = (IK_Enroll_Ident_Mode)state.mode;
	_state.dataValidFlag = (IK_Iris_And_Face_Data_Valid_Flag)state.dataValidFlag;
#pragma region _state.pIrisState

	_state.pIrisState.workMode = (IK_Iris_Work_Mode)state.pIrisState->workMode;
	_state.pIrisState.detectType = state.pIrisState->detectType;
	_state.pIrisState.irisMode = (IK_Iris_Mode)state.pIrisState->irisMode;
	_state.pIrisState.leftIrisProgress = state.pIrisState->leftIrisProgress;
	_state.pIrisState.rightIrisProgress = state.pIrisState->rightIrisProgress;
	_state.pIrisState.imageW = state.pIrisState->imageW;
	_state.pIrisState.imageH = state.pIrisState->imageH;

#pragma region _state.pIrisState.irisPos 
	_state.pIrisState.irisPos.dist = state.pIrisState->irisPos.dist;

#pragma region _state.pIrisState.irisPos.leftIrisPos 
	_state.pIrisState.irisPos.leftIrisPos.xPixel = state.pIrisState->irisPos.leftIrisPos.xPixel;
	_state.pIrisState.irisPos.leftIrisPos.yPixel = state.pIrisState->irisPos.leftIrisPos.yPixel;
	_state.pIrisState.irisPos.leftIrisPos.radius = state.pIrisState->irisPos.leftIrisPos.radius;
#pragma endregion
#pragma region _state.pIrisState.irisPos.rightIrisPos 
	_state.pIrisState.irisPos.rightIrisPos.xPixel = state.pIrisState->irisPos.rightIrisPos.xPixel;
	_state.pIrisState.irisPos.rightIrisPos.yPixel = state.pIrisState->irisPos.rightIrisPos.yPixel;
	_state.pIrisState.irisPos.rightIrisPos.radius = state.pIrisState->irisPos.rightIrisPos.radius;
#pragma endregion

#pragma endregion

	_state.pIrisState.throwAwayFrameStatus = state.pIrisState->throwAwayFrameStatus;
	_state.pIrisState.irisID = state.pIrisState->irisID;
	_state.pIrisState.faceID = state.pIrisState->faceID;
	_state.pIrisState.traceID = state.pIrisState->traceID;
	_state.pIrisState.irisLeftMargin = state.pIrisState->irisLeftMargin;
	_state.pIrisState.irisRightMargin = state.pIrisState->irisRightMargin;
	_state.pIrisState.irisTopMargin = state.pIrisState->irisTopMargin;
	_state.pIrisState.irisBottomMargin = state.pIrisState->irisBottomMargin;

#pragma region _state.pFaceState
	if (state.pFaceState != nullptr) {
		_state.pFaceState.workMode = (IK_Face_Work_Mode)state.pFaceState->workMode;

#pragma region state.pFaceState.faceROIInfo
		_state.pFaceState.faceROIInfo.ifValid = state.pFaceState->faceROIInfo.ifValid;

#pragma region _state.pFaceState.faceROIInfo.rcFace
		_state.pFaceState.faceROIInfo.rcFace.left = state.pFaceState->faceROIInfo.rcFace.left;
		_state.pFaceState.faceROIInfo.rcFace.top = state.pFaceState->faceROIInfo.rcFace.top;
		_state.pFaceState.faceROIInfo.rcFace.right = state.pFaceState->faceROIInfo.rcFace.right;
		_state.pFaceState.faceROIInfo.rcFace.bottom = state.pFaceState->faceROIInfo.rcFace.bottom;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptLeftEye
		_state.pFaceState.faceROIInfo.ptLeftEye.x = state.pFaceState->faceROIInfo.ptLeftEye.x;
		_state.pFaceState.faceROIInfo.ptLeftEye.y = state.pFaceState->faceROIInfo.ptLeftEye.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptRightEye
		_state.pFaceState.faceROIInfo.ptRightEye.x = state.pFaceState->faceROIInfo.ptRightEye.x;
		_state.pFaceState.faceROIInfo.ptRightEye.y = state.pFaceState->faceROIInfo.ptRightEye.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptMouthLeft
		_state.pFaceState.faceROIInfo.ptMouthLeft.x = state.pFaceState->faceROIInfo.ptMouthLeft.x;
		_state.pFaceState.faceROIInfo.ptMouthLeft.y = state.pFaceState->faceROIInfo.ptMouthLeft.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptMouthRight
		_state.pFaceState.faceROIInfo.ptMouthRight.x = state.pFaceState->faceROIInfo.ptMouthRight.x;
		_state.pFaceState.faceROIInfo.ptMouthRight.y = state.pFaceState->faceROIInfo.ptMouthRight.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptNose
		_state.pFaceState.faceROIInfo.ptNose.x = state.pFaceState->faceROIInfo.ptNose.x;
		_state.pFaceState.faceROIInfo.ptNose.y = state.pFaceState->faceROIInfo.ptNose.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.fAngle
		_state.pFaceState.faceROIInfo.fAngle.yaw = state.pFaceState->faceROIInfo.fAngle.yaw;
		_state.pFaceState.faceROIInfo.fAngle.pitch = state.pFaceState->faceROIInfo.fAngle.pitch;
		_state.pFaceState.faceROIInfo.fAngle.roll = state.pFaceState->faceROIInfo.fAngle.roll;
		_state.pFaceState.faceROIInfo.fAngle.confidence = state.pFaceState->faceROIInfo.fAngle.confidence;
#pragma endregion
#pragma endregion

		_state.pFaceState.dist = state.pFaceState->dist;
		_state.pFaceState.lightScore = state.pFaceState->lightScore;
		_state.pFaceState.imageW = state.pFaceState->imageW;
		_state.pFaceState.imageH = state.pFaceState->imageH;
		_state.pFaceState.detectBeginX = state.pFaceState->detectBeginX;
		_state.pFaceState.detectBeginY = state.pFaceState->detectBeginY;
		_state.pFaceState.detectW = state.pFaceState->detectW;
		_state.pFaceState.detectH = state.pFaceState->detectH;
		_state.pFaceState.faceProgress = state.pFaceState->faceProgress;
		_state.pFaceState.throwAwayFrameStatus = state.pFaceState->throwAwayFrameStatus;
		_state.pFaceState.imageIndex = state.pFaceState->imageIndex;
	}
#pragma endregion



#pragma endregion

#pragma region _state.pFaceState
	if (state.pFaceState != nullptr) {
		_state.pFaceState.workMode = (IK_Face_Work_Mode)state.pFaceState->workMode;

#pragma region _state.pFaceState.faceROIInfo
		_state.pFaceState.faceROIInfo.ifValid = state.pFaceState->faceROIInfo.ifValid;

#pragma region _state.pFaceState.faceROIInfo.rcFace
		_state.pFaceState.faceROIInfo.rcFace.left = state.pFaceState->faceROIInfo.rcFace.left;
		_state.pFaceState.faceROIInfo.rcFace.top = state.pFaceState->faceROIInfo.rcFace.top;
		_state.pFaceState.faceROIInfo.rcFace.right = state.pFaceState->faceROIInfo.rcFace.right;
		_state.pFaceState.faceROIInfo.rcFace.bottom = state.pFaceState->faceROIInfo.rcFace.bottom;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptLeftEye
		_state.pFaceState.faceROIInfo.ptLeftEye.x = state.pFaceState->faceROIInfo.ptLeftEye.x;
		_state.pFaceState.faceROIInfo.ptLeftEye.y = state.pFaceState->faceROIInfo.ptLeftEye.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptRightEye
		_state.pFaceState.faceROIInfo.ptRightEye.x = state.pFaceState->faceROIInfo.ptRightEye.x;
		_state.pFaceState.faceROIInfo.ptRightEye.y = state.pFaceState->faceROIInfo.ptRightEye.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptMouthLeft
		_state.pFaceState.faceROIInfo.ptMouthLeft.x = state.pFaceState->faceROIInfo.ptMouthLeft.x;
		_state.pFaceState.faceROIInfo.ptMouthLeft.y = state.pFaceState->faceROIInfo.ptMouthLeft.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptMouthRight
		_state.pFaceState.faceROIInfo.ptMouthRight.x = state.pFaceState->faceROIInfo.ptMouthRight.x;
		_state.pFaceState.faceROIInfo.ptMouthRight.y = state.pFaceState->faceROIInfo.ptMouthRight.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.ptNose
		_state.pFaceState.faceROIInfo.ptNose.x = state.pFaceState->faceROIInfo.ptNose.x;
		_state.pFaceState.faceROIInfo.ptNose.y = state.pFaceState->faceROIInfo.ptNose.y;
#pragma endregion

#pragma region _state.pFaceState.faceROIInfo.fAngle
		_state.pFaceState.faceROIInfo.fAngle.yaw = state.pFaceState->faceROIInfo.fAngle.yaw;
		_state.pFaceState.faceROIInfo.fAngle.pitch = state.pFaceState->faceROIInfo.fAngle.pitch;
		_state.pFaceState.faceROIInfo.fAngle.roll = state.pFaceState->faceROIInfo.fAngle.roll;
		_state.pFaceState.faceROIInfo.fAngle.confidence = state.pFaceState->faceROIInfo.fAngle.confidence;
#pragma endregion


#pragma endregion

		_state.pFaceState.dist = state.pFaceState->dist;
		_state.pFaceState.lightScore = state.pFaceState->lightScore;
		_state.pFaceState.imageW = state.pFaceState->imageW;
		_state.pFaceState.imageH = state.pFaceState->imageH;
		_state.pFaceState.detectBeginX = state.pFaceState->detectBeginX;
		_state.pFaceState.detectBeginY = state.pFaceState->detectBeginY;
		_state.pFaceState.detectW = state.pFaceState->detectW;
		_state.pFaceState.detectH = state.pFaceState->detectH;
		_state.pFaceState.faceProgress = state.pFaceState->faceProgress;
		_state.pFaceState.throwAwayFrameStatus = state.pFaceState->throwAwayFrameStatus;
		_state.pFaceState.imageIndex = state.pFaceState->imageIndex;
	}
#pragma endregion

	if (Irisking::IK_SDK_E30::HandleStateUpdated != nullptr) {
		Irisking::IK_SDK_E30::HandleStateUpdated(_state);
	}

}

void Irisking::IKBaseProcessor::handleCameraUpdated(const IKCameraUpdated& cameraUpdate)
{
	IK_Frame frame;

#pragma region frame ×ª»»
#pragma region frame->image_data
	unsigned char* imageBuffer = new unsigned char[1024 * 1024];
	memcpy(imageBuffer, cameraUpdate.frame->image_data.get(), cameraUpdate.frame->data_len);
	frame.data = gcnew cli::array<unsigned char>(cameraUpdate.frame->data_len);
	for (int i = 0; i < cameraUpdate.frame->data_len; i++)
	{
		frame.data[i] = imageBuffer[i];
	}
	delete[] imageBuffer;
	imageBuffer = nullptr;
#pragma endregion

	frame.data_len = cameraUpdate.frame->data_len;
	frame.height = cameraUpdate.frame->height;
	frame.width = cameraUpdate.frame->width;
	frame.rotation = cameraUpdate.frame->rotation;
	frame.frame_type = (IK_Frame_Type)cameraUpdate.frame->frame_type;
	frame.format = (IK_Frame_Format)cameraUpdate.frame->format;

#pragma endregion

	IK_Camera_Updated _ikCameraUpdated;
	_ikCameraUpdated.frame = frame;
	_ikCameraUpdated.mirrorFlag = cameraUpdate.mirrorFlag;
	_ikCameraUpdated.event = (IK_Camera_Event)cameraUpdate.event;
	_ikCameraUpdated.deviceType = cameraUpdate.deviceType;
	_ikCameraUpdated.lightMode = (IK_LIGHT_MODE)cameraUpdate.lightMode;

	_ikCameraUpdated.deviceSN = gcnew String(cameraUpdate.deviceSN);
	_ikCameraUpdated.deviceSNLen = cameraUpdate.deviceSNLen;
	_ikCameraUpdated.deviceTypeString = gcnew String(cameraUpdate.deviceTypeString);
	_ikCameraUpdated.deviceTypeStringLen = cameraUpdate.deviceTypeStringLen;

	if (Irisking::IK_SDK_E30::HandleCameraUpdated != nullptr) {
		Irisking::IK_SDK_E30::HandleCameraUpdated(_ikCameraUpdated);
	}
}

void Irisking::IKBaseProcessor::handleLog(const char* logType, IKLog logLevel, const char* logInfo)
{
	System::String^ _logType = gcnew System::String(logType);
	System::String^ _logInfo = gcnew System::String(logInfo);
	IK_Log _logLevel = (IK_Log)logLevel;
	if (Irisking::IK_SDK_E30::HandleLog != nullptr) {
		Irisking::IK_SDK_E30::HandleLog("", _logLevel, "");
	}
}

