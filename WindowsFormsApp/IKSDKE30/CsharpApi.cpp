#include "pch.h"
#include "CsharpApi.h"

Irisking::IK_Base_Enroll_Processed_Result::IK_Base_Enroll_Processed_Result(IKBaseEnrollProcessedResult& _ikBaseEnrollProcessedResult)
{
	this->_ikBaseEnrollProcessedResult = &_ikBaseEnrollProcessedResult;
}

void Irisking::IK_Base_Enroll_Processed_Result::setEnrollIdentMode(IK_Enroll_Ident_Mode mode)
{
	IKEnrollIdentMode _mode = (IKEnrollIdentMode)mode;
	_ikBaseEnrollProcessedResult->setEnrollIdentMode(_mode);
}

Irisking::IK_Enroll_Ident_Mode Irisking::IK_Base_Enroll_Processed_Result::getEnrollIdentMode()
{
	IKEnrollIdentMode result = _ikBaseEnrollProcessedResult->getEnrollIdentMode();
	IK_Enroll_Ident_Mode mode = (IK_Enroll_Ident_Mode)result;
	return mode;
}

void Irisking::IK_Base_Enroll_Processed_Result::setEnrollIdentResFlag(IK_Enroll_Ident_Result_Flag flag)
{
	IKEnrollIdentResultFlag _flag = (IKEnrollIdentResultFlag)flag;
	_ikBaseEnrollProcessedResult->setEnrollIdentResFlag(_flag);
}

Irisking::IK_Enroll_Ident_Result_Flag Irisking::IK_Base_Enroll_Processed_Result::getEnrollIdentResFlag()
{
	auto flag = _ikBaseEnrollProcessedResult->getEnrollIdentResFlag();
	IK_Enroll_Ident_Result_Flag _flag = (IK_Enroll_Ident_Result_Flag)flag;
	return _flag;
}

int Irisking::IK_Base_Enroll_Processed_Result::getIrisFrameNum()
{
return	_ikBaseEnrollProcessedResult->getIrisFrameNum();
}

int Irisking::IK_Base_Enroll_Processed_Result::getFaceFrameNum()
{
	return _ikBaseEnrollProcessedResult->getFaceFrameNum();
}

void Irisking::IK_Base_Enroll_Processed_Result::setIrisRes(int res)
{
	_ikBaseEnrollProcessedResult->setIrisRes(res);
}

void Irisking::IK_Base_Enroll_Processed_Result::setFaceRes(int res)
{
	_ikBaseEnrollProcessedResult->setFaceRes(res);
}

int Irisking::IK_Base_Enroll_Processed_Result::getIrisRes()
{
	return _ikBaseEnrollProcessedResult->getIrisRes();
}

int Irisking::IK_Base_Enroll_Processed_Result::getFaceRes()
{
	return _ikBaseEnrollProcessedResult->getFaceRes();
}

bool Irisking::IK_Base_Enroll_Processed_Result::getFaceResultData(int index, IK_Face_Processed_Result% algResultData)
{
	IKFaceProcessedResult result;
	_ikBaseEnrollProcessedResult->getFaceResultData(index,result);

#pragma region algResultData.m_rcFace
	algResultData.m_rcFace.left = result.m_rcFace.left;
	algResultData.m_rcFace.top = result.m_rcFace.top;
	algResultData.m_rcFace.right = result.m_rcFace.right;
	algResultData.m_rcFace.bottom = result.m_rcFace.bottom;
#pragma endregion


#pragma region algResultData.m_faceQuality
	algResultData.m_faceQuality.yaw = result.m_faceQuality.yaw;
	algResultData.m_faceQuality.pitch = result.m_faceQuality.pitch;
	algResultData.m_faceQuality.roll = result.m_faceQuality.roll;
	algResultData.m_faceQuality.confidence = result.m_faceQuality.confidence;
#pragma endregion


#pragma region algResultData.m_detectImageData
	algResultData.m_detectImageData = gcnew cli::array<unsigned char>(result.m_detectImageSize);
	for (int i = 0; i < result.m_detectImageSize; i++)
	{
		algResultData.m_detectImageData[i] = result.m_detectImageData[i];
	}
#pragma endregion
	algResultData.m_detectImageSize = result.m_detectImageSize;
	algResultData.m_detectImageH = result.m_detectImageH;
	algResultData.m_detectImageW = result.m_detectImageW;

#pragma region algResultData.m_imageData
	algResultData.m_imageData = gcnew cli::array<unsigned char>(result.m_imageSize);
	for (int i = 0; i < result.m_imageSize; i++)
	{
		algResultData.m_imageData[i] = result.m_imageData[i];
	}
#pragma endregion
	algResultData.m_imageSize = result.m_imageSize;
	algResultData.m_imageH = result.m_imageH;
	algResultData.m_imageW = result.m_imageW;

#pragma region algResultData.m_enrTemplate
	algResultData.m_enrTemplate = gcnew cli::array<unsigned char>(result.m_enrTemplateSize);
	for (int i = 0; i < result.m_enrTemplateSize; i++)
	{
		algResultData.m_enrTemplate[i] = result.m_enrTemplate[i];
	}
#pragma endregion

	algResultData.m_enrTemplateSize = result.m_enrTemplateSize;

#pragma region algResultData.m_recTemplate
	algResultData.m_recTemplate = gcnew cli::array<unsigned char>(result.m_recTemplateSize);
	for (int i = 0; i < result.m_recTemplateSize; i++)
	{
		algResultData.m_recTemplate[i] = result.m_recTemplate[i];
	}
#pragma endregion
	algResultData.m_recTemplateSize = result.m_recTemplateSize;
	return false;
}

void Irisking::IK_Base_Enroll_Processed_Result::addIrisData(IK_Iris_Processed_Result% algResultData)
{
	IKIrisProcessedResult data;
	_ikBaseEnrollProcessedResult->addIrisData(data);

	algResultData.irisMode = (IK_Iris_Mode)data.irisMode;
	algResultData.flag = (IK_Iris_Result_Flag)data.flag;
#pragma region algResultData.irisInfo
	algResultData.irisInfo.ImgHeight = data.irisInfo.ImgHeight;
	algResultData.irisInfo.ImgWidth = data.irisInfo.ImgWidth;
	algResultData.irisInfo.ImgType = data.irisInfo.ImgType;
	algResultData.irisInfo.IrisRow = data.irisInfo.IrisRow;
	algResultData.irisInfo.IrisCol = data.irisInfo.IrisCol;
	algResultData.irisInfo.IrisRadius = data.irisInfo.IrisRadius;
	algResultData.irisInfo.FocusScore = data.irisInfo.FocusScore;
	algResultData.irisInfo.PercentVisible = data.irisInfo.PercentVisible;
	algResultData.irisInfo.Brightness = data.irisInfo.Brightness;
	algResultData.irisInfo.MotionBlur = data.irisInfo.MotionBlur;
	algResultData.irisInfo.QualityScore = data.irisInfo.QualityScore;
	algResultData.irisInfo.imgDataLen = data.irisInfo.imgDataLen;

#pragma region algResultData.irisInfo.imgData
	unsigned char* imgDataBuffer = new unsigned char[data.irisInfo.imgDataLen];
	memcpy(imgDataBuffer, data.irisInfo.imgData, data.irisInfo.imgDataLen);
	algResultData.irisInfo.imgData = gcnew cli::array<unsigned char>(data.irisInfo.imgDataLen);
	for (int i = 0; i < data.irisInfo.imgDataLen; i++)
	{
		algResultData.irisInfo.imgData[i] = imgDataBuffer[i];
	}
	delete[] imgDataBuffer;
	imgDataBuffer = nullptr;
#pragma endregion

	algResultData.irisInfo.imgDataMatLen = data.irisInfo.imgDataMatLen;

#pragma region algResultData.irisInfo.imgDataMat
	unsigned char* imgDataMatBuffer = new unsigned char[data.irisInfo.imgDataMatLen];
	memcpy(imgDataMatBuffer, data.irisInfo.imgDataMat, data.irisInfo.imgDataMatLen);
	algResultData.irisInfo.imgDataMat = gcnew cli::array<unsigned char>(data.irisInfo.imgDataMatLen);
	for (int i = 0; i < data.irisInfo.imgDataMatLen; i++)
	{
		algResultData.irisInfo.imgData[i] = imgDataMatBuffer[i];
	}
	delete[] imgDataMatBuffer;
	imgDataMatBuffer = nullptr;

#pragma endregion

	algResultData.irisInfo.irisEnrTemplateLen = data.irisInfo.irisEnrTemplateLen;

#pragma region algResultData.irisInfo.irisEnrTemplate
	unsigned char* irisEnrTemplateBuffer = new unsigned char[data.irisInfo.irisEnrTemplateLen];
	memcpy(irisEnrTemplateBuffer, data.irisInfo.irisEnrTemplate, data.irisInfo.irisEnrTemplateLen);
	algResultData.irisInfo.irisEnrTemplate = gcnew cli::array<unsigned char>(data.irisInfo.irisEnrTemplateLen);
	for (int i = 0; i < data.irisInfo.irisEnrTemplateLen; i++)
	{
		algResultData.irisInfo.irisEnrTemplate[i] = irisEnrTemplateBuffer[i];
	}
	delete[] irisEnrTemplateBuffer;
	irisEnrTemplateBuffer = nullptr;

#pragma endregion
	algResultData.irisInfo.irisRecTemplateLen = data.irisInfo.irisRecTemplateLen;
#pragma region algResultData.irisInfo.irisRecTemplate
	unsigned char* irisRecTemplateBuffer = new unsigned char[data.irisInfo.irisRecTemplateLen];
	memcpy(irisRecTemplateBuffer, data.irisInfo.irisRecTemplate, data.irisInfo.irisRecTemplateLen);
	algResultData.irisInfo.irisRecTemplate = gcnew cli::array<unsigned char>(data.irisInfo.irisRecTemplateLen);
	for (int i = 0; i < data.irisInfo.irisRecTemplateLen; i++)
	{
		algResultData.irisInfo.irisRecTemplate[i] = irisRecTemplateBuffer[i];
	}
	delete[] irisRecTemplateBuffer;
	irisRecTemplateBuffer = nullptr;

#pragma endregion

	algResultData.irisInfo.irisInfoUnkonwnLen = data.irisInfo.irisInfoUnkonwnLen;
#pragma region algResultData.irisInfo.irisInfoUnkonwn
	int* irisInfoUnkonwnBuffer = new int[data.irisInfo.irisInfoUnkonwnLen];
	memcpy(irisInfoUnkonwnBuffer, data.irisInfo.irisInfoUnkonwn, data.irisInfo.irisInfoUnkonwnLen);
	algResultData.irisInfo.irisInfoUnkonwn = gcnew cli::array<int>(data.irisInfo.irisInfoUnkonwnLen);
	for (int i = 0; i < data.irisInfo.irisInfoUnkonwnLen; i++)
	{
		algResultData.irisInfo.irisInfoUnkonwn[i] = irisInfoUnkonwnBuffer[i];
	}
	delete[] irisInfoUnkonwnBuffer;
	irisInfoUnkonwnBuffer = nullptr;

#pragma endregion

#pragma endregion

}

bool Irisking::IK_Base_Enroll_Processed_Result::getIrisResultData(int index, IK_Iris_Processed_Result% algResultData)
{
	IKIrisProcessedResult data;
	bool state = _ikBaseEnrollProcessedResult->getIrisResultData(index, data);
	algResultData.irisMode = (IK_Iris_Mode)data.irisMode;
	algResultData.flag = (IK_Iris_Result_Flag)data.flag;

#pragma region algResultData.irisInfo
	algResultData.irisInfo.ImgHeight = data.irisInfo.ImgHeight;
	algResultData.irisInfo.ImgWidth = data.irisInfo.ImgWidth;
	algResultData.irisInfo.ImgType = data.irisInfo.ImgType;
	algResultData.irisInfo.IrisRow = data.irisInfo.IrisRow;
	algResultData.irisInfo.IrisCol = data.irisInfo.IrisCol;
	algResultData.irisInfo.IrisRadius = data.irisInfo.IrisRadius;
	algResultData.irisInfo.FocusScore = data.irisInfo.FocusScore;
	algResultData.irisInfo.PercentVisible = data.irisInfo.PercentVisible;
	algResultData.irisInfo.Brightness = data.irisInfo.Brightness;
	algResultData.irisInfo.MotionBlur = data.irisInfo.MotionBlur;
	algResultData.irisInfo.QualityScore = data.irisInfo.QualityScore;
	algResultData.irisInfo.imgDataLen = data.irisInfo.imgDataLen;

#pragma region algResultData.irisInfo.imgData
	unsigned char* imgDataBuffer = new unsigned char[data.irisInfo.imgDataLen];
	memcpy(imgDataBuffer, data.irisInfo.imgData, data.irisInfo.imgDataLen);
	algResultData.irisInfo.imgData = gcnew cli::array<unsigned char>(data.irisInfo.imgDataLen);
	for (int i = 0; i < data.irisInfo.imgDataLen; i++)
	{
		algResultData.irisInfo.imgData[i] = imgDataBuffer[i];
	}
	delete[] imgDataBuffer;
	imgDataBuffer = nullptr;
#pragma endregion

	algResultData.irisInfo.imgDataMatLen = data.irisInfo.imgDataMatLen;

#pragma region algResultData.irisInfo.imgDataMat
	unsigned char* imgDataMatBuffer = new unsigned char[data.irisInfo.imgDataMatLen];
	memcpy(imgDataMatBuffer, data.irisInfo.imgDataMat, data.irisInfo.imgDataMatLen);
	algResultData.irisInfo.imgDataMat = gcnew cli::array<unsigned char>(data.irisInfo.imgDataMatLen);
	for (int i = 0; i < data.irisInfo.imgDataMatLen; i++)
	{
		algResultData.irisInfo.imgData[i] = imgDataMatBuffer[i];
	}
	delete[] imgDataMatBuffer;
	imgDataMatBuffer = nullptr;

#pragma endregion

	algResultData.irisInfo.irisEnrTemplateLen = data.irisInfo.irisEnrTemplateLen;

#pragma region algResultData.irisInfo.irisEnrTemplate
	unsigned char* irisEnrTemplateBuffer = new unsigned char[data.irisInfo.irisEnrTemplateLen];
	memcpy(irisEnrTemplateBuffer, data.irisInfo.irisEnrTemplate, data.irisInfo.irisEnrTemplateLen);
	algResultData.irisInfo.irisEnrTemplate = gcnew cli::array<unsigned char>(data.irisInfo.irisEnrTemplateLen);
	for (int i = 0; i < data.irisInfo.irisEnrTemplateLen; i++)
	{
		algResultData.irisInfo.irisEnrTemplate[i] = irisEnrTemplateBuffer[i];
	}
	delete[] irisEnrTemplateBuffer;
	irisEnrTemplateBuffer = nullptr;

#pragma endregion
	algResultData.irisInfo.irisRecTemplateLen = data.irisInfo.irisRecTemplateLen;
#pragma region algResultData.irisInfo.irisRecTemplate
	unsigned char* irisRecTemplateBuffer = new unsigned char[data.irisInfo.irisRecTemplateLen];
	memcpy(irisRecTemplateBuffer, data.irisInfo.irisRecTemplate, data.irisInfo.irisRecTemplateLen);
	algResultData.irisInfo.irisRecTemplate = gcnew cli::array<unsigned char>(data.irisInfo.irisRecTemplateLen);
	for (int i = 0; i < data.irisInfo.irisRecTemplateLen; i++)
	{
		algResultData.irisInfo.irisRecTemplate[i] = irisRecTemplateBuffer[i];
	}
	delete[] irisRecTemplateBuffer;
	irisRecTemplateBuffer = nullptr;

#pragma endregion

	algResultData.irisInfo.irisInfoUnkonwnLen = data.irisInfo.irisInfoUnkonwnLen;
#pragma region algResultData.irisInfo.irisInfoUnkonwn
	int* irisInfoUnkonwnBuffer = new int[data.irisInfo.irisInfoUnkonwnLen];
	memcpy(irisInfoUnkonwnBuffer, data.irisInfo.irisInfoUnkonwn, data.irisInfo.irisInfoUnkonwnLen);
	algResultData.irisInfo.irisInfoUnkonwn = gcnew cli::array<int>(data.irisInfo.irisInfoUnkonwnLen);
	for (int i = 0; i < data.irisInfo.irisInfoUnkonwnLen; i++)
	{
		algResultData.irisInfo.irisInfoUnkonwn[i] = irisInfoUnkonwnBuffer[i];
	}
	delete[] irisInfoUnkonwnBuffer;
	irisInfoUnkonwnBuffer = nullptr;

#pragma endregion
#pragma endregion

	return state;
}

void Irisking::IK_Base_Enroll_Processed_Result::addFaceData(IK_Face_Processed_Result% algResultData)
{
	IKFaceProcessedResult result;
	_ikBaseEnrollProcessedResult->addFaceData(result);

#pragma region algResultData.m_rcFace
	algResultData.m_rcFace.left = result.m_rcFace.left;
	algResultData.m_rcFace.top = result.m_rcFace.top;
	algResultData.m_rcFace.right = result.m_rcFace.right;
	algResultData.m_rcFace.bottom = result.m_rcFace.bottom;
#pragma endregion

#pragma region algResultData.m_faceQuality
	algResultData.m_faceQuality.yaw = result.m_faceQuality.yaw;
	algResultData.m_faceQuality.pitch = result.m_faceQuality.pitch;
	algResultData.m_faceQuality.roll = result.m_faceQuality.roll;
	algResultData.m_faceQuality.confidence = result.m_faceQuality.confidence;
#pragma endregion

#pragma region algResultData.m_detectImageData
	algResultData.m_detectImageData = gcnew cli::array<unsigned char>(result.m_detectImageSize);
	for (int i = 0; i < result.m_detectImageSize; i++)
	{
		algResultData.m_detectImageData[i] = result.m_detectImageData[i];
	}
#pragma endregion
	algResultData.m_detectImageSize = result.m_detectImageSize;
	algResultData.m_detectImageH = result.m_detectImageH;
	algResultData.m_detectImageW = result.m_detectImageW;

#pragma region algResultData.m_imageData
	algResultData.m_imageData = gcnew cli::array<unsigned char>(result.m_imageSize);
	for (int i = 0; i < result.m_imageSize; i++)
	{
		algResultData.m_imageData[i] = result.m_imageData[i];
	}
#pragma endregion
	algResultData.m_imageSize = result.m_imageSize;
	algResultData.m_imageH = result.m_imageH;
	algResultData.m_imageW = result.m_imageW;

#pragma region algResultData.m_enrTemplate
	algResultData.m_enrTemplate = gcnew cli::array<unsigned char>(result.m_enrTemplateSize);
	for (int i = 0; i < result.m_enrTemplateSize; i++)
	{
		algResultData.m_enrTemplate[i] = result.m_enrTemplate[i];
	}
#pragma endregion

	algResultData.m_enrTemplateSize = result.m_enrTemplateSize;

#pragma region algResultData.m_recTemplate
	algResultData.m_recTemplate = gcnew cli::array<unsigned char>(result.m_recTemplateSize);
	for (int i = 0; i < result.m_recTemplateSize; i++)
	{
		algResultData.m_recTemplate[i] = result.m_recTemplate[i];
	}
#pragma endregion
	algResultData.m_recTemplateSize = result.m_recTemplateSize;

}
