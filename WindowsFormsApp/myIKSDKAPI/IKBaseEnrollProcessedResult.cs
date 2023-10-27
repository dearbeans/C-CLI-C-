//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKBaseEnrollProcessedResult : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKBaseEnrollProcessedResult(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKBaseEnrollProcessedResult obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKBaseEnrollProcessedResult obj) {
    if (obj != null) {
      if (!obj.swigCMemOwn)
        throw new global::System.ApplicationException("Cannot release ownership as memory is not owned");
      global::System.Runtime.InteropServices.HandleRef ptr = obj.swigCPtr;
      obj.swigCMemOwn = false;
      obj.Dispose();
      return ptr;
    } else {
      return new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
    }
  }

  ~IKBaseEnrollProcessedResult() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          dllmainPINVOKE.delete_IKBaseEnrollProcessedResult(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public virtual void setEnrollIdentMode(IKEnrollIdentMode mode) {
    dllmainPINVOKE.IKBaseEnrollProcessedResult_setEnrollIdentMode(swigCPtr, (int)mode);
  }

  public virtual IKEnrollIdentMode getEnrollIdentMode() {
    IKEnrollIdentMode ret = (IKEnrollIdentMode)dllmainPINVOKE.IKBaseEnrollProcessedResult_getEnrollIdentMode(swigCPtr);
    return ret;
  }

  public virtual void setEnrollIdentResFlag(IKEnrollIdentResultFlag flag) {
    dllmainPINVOKE.IKBaseEnrollProcessedResult_setEnrollIdentResFlag(swigCPtr, (int)flag);
  }

  public virtual IKEnrollIdentResultFlag getEnrollIdentResFlag() {
    IKEnrollIdentResultFlag ret = (IKEnrollIdentResultFlag)dllmainPINVOKE.IKBaseEnrollProcessedResult_getEnrollIdentResFlag(swigCPtr);
    return ret;
  }

  public virtual void addIrisData(IKIrisProcessedResult algResultData) {
    dllmainPINVOKE.IKBaseEnrollProcessedResult_addIrisData(swigCPtr, IKIrisProcessedResult.getCPtr(algResultData));
    if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void addFaceData(IKFaceProcessedResult algResultData) {
    dllmainPINVOKE.IKBaseEnrollProcessedResult_addFaceData(swigCPtr, IKFaceProcessedResult.getCPtr(algResultData));
    if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual bool getIrisResultData(int index, IKIrisProcessedResult data) {
    bool ret = dllmainPINVOKE.IKBaseEnrollProcessedResult_getIrisResultData(swigCPtr, index, IKIrisProcessedResult.getCPtr(data));
    if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual bool getFaceResultData(int index, IKFaceProcessedResult data) {
    bool ret = dllmainPINVOKE.IKBaseEnrollProcessedResult_getFaceResultData(swigCPtr, index, IKFaceProcessedResult.getCPtr(data));
    if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public virtual int getIrisFrameNum() {
    int ret = dllmainPINVOKE.IKBaseEnrollProcessedResult_getIrisFrameNum(swigCPtr);
    return ret;
  }

  public virtual int getFaceFrameNum() {
    int ret = dllmainPINVOKE.IKBaseEnrollProcessedResult_getFaceFrameNum(swigCPtr);
    return ret;
  }

  public virtual void setIrisRes(int res) {
    dllmainPINVOKE.IKBaseEnrollProcessedResult_setIrisRes(swigCPtr, res);
  }

  public virtual void setFaceRes(int res) {
    dllmainPINVOKE.IKBaseEnrollProcessedResult_setFaceRes(swigCPtr, res);
  }

  public virtual int getIrisRes() {
    int ret = dllmainPINVOKE.IKBaseEnrollProcessedResult_getIrisRes(swigCPtr);
    return ret;
  }

  public virtual int getFaceRes() {
    int ret = dllmainPINVOKE.IKBaseEnrollProcessedResult_getFaceRes(swigCPtr);
    return ret;
  }

}
