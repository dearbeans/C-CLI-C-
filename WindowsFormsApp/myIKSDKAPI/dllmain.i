/* File: example.i */
%module(directors="1") dllmain
%{
#include "IKBaseFaceAPIStruct.h"
#include "IKBaseIrisAPIStruct.h"
#include "IKBaseSDKAPIStruct.h"
#include "IKFrame.h"
#include "dllmain.h"
#include "IKBaseSDKAPI.h"
%}
%include "IKBaseSDKAPI.h"
%include "IKBaseFaceAPIStruct.h"
%include "IKBaseIrisAPIStruct.h"
%include "dllmain.h"
%include "IKBaseSDKAPIStruct.h"
%feature("director") IKBaseProcessorCallback;
%rename(eq) operator=;
%include "IKFrame.h"