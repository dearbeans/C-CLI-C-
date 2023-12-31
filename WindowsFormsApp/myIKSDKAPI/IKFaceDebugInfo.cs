//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKFaceDebugInfo : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKFaceDebugInfo(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKFaceDebugInfo obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKFaceDebugInfo obj) {
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

  ~IKFaceDebugInfo() {
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
          dllmainPINVOKE.delete_IKFaceDebugInfo(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public int throwAwayFrameStatus {
    set {
      dllmainPINVOKE.IKFaceDebugInfo_throwAwayFrameStatus_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceDebugInfo_throwAwayFrameStatus_get(swigCPtr);
      return ret;
    } 
  }

  public int faceInfoNum {
    set {
      dllmainPINVOKE.IKFaceDebugInfo_faceInfoNum_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceDebugInfo_faceInfoNum_get(swigCPtr);
      return ret;
    } 
  }

  public IKFaceProcessedResult faceInfo {
    set {
      dllmainPINVOKE.IKFaceDebugInfo_faceInfo_set(swigCPtr, IKFaceProcessedResult.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceDebugInfo_faceInfo_get(swigCPtr);
      IKFaceProcessedResult ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKFaceProcessedResult(cPtr, false);
      return ret;
    } 
  }

  public IKFaceDebugInfo() : this(dllmainPINVOKE.new_IKFaceDebugInfo(), true) {
  }

}
