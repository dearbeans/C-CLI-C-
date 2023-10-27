// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "IKBaseSDKAPI.h"
HINSTANCE mhin;
/*!
     * @brief 创建多模态SDKAPI实例
     *
     * @param 无
     * @return 创建成功返回多模态SDKAPI实例,创建失败返回NULL
     **/
__IKBaseSDKAPI_CLASS_ IKBaseSDKAPI* __IK_STYLE_CALL CreateSDKObj();

/*!
     * @brief 释放多模态SDKAPI实例
     *
     * @param[in] irisApi 多模态SDKAPI实例指针的地址
     * @return 无
     **/
__IKBaseSDKAPI_CLASS_ void __IK_STYLE_CALL DestroySDKObj(IKBaseSDKAPI** api);

typedef IKBaseSDKAPI *(*  CREATEOBJ)(void);
void initdll()
{
	
	mhin = LoadLibraryA("IKSDKAPI.dll");
}
IKBaseSDKAPI* creatobj(void)
{
	CREATEOBJ mycreat = (CREATEOBJ)GetProcAddress(mhin, "CreateSDKObj");
	return mycreat();
}
