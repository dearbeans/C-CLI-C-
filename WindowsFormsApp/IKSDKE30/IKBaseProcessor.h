#pragma once
#include "IKBaseSDKAPIStruct.h"

namespace Irisking {
	/// <summary>
	///  µœ÷IKBaseProcessorCallback
	/// </summary>
	public class IKBaseProcessor:public IKBaseProcessorCallback
	{
	public:
		IKBaseProcessor();
		~IKBaseProcessor();
		void handleInitCompleted(int initRes);

		void handleProcessCompleted(IKBaseEnrollProcessedResult& result);

		void handleIdentProcessCompleted(const IKIdentProcessedResultStruct& result);

		void handleStateUpdated(const IKProcessorState& state);

		void handleCameraUpdated(const IKCameraUpdated& cameraUpdate);

		void handleLog(const char* logType, IKLog logLevel, const char* logInfo);
	};
}