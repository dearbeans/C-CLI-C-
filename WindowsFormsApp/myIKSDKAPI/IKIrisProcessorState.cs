//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKIrisProcessorState : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKIrisProcessorState(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKIrisProcessorState obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKIrisProcessorState obj) {
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

  ~IKIrisProcessorState() {
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
          dllmainPINVOKE.delete_IKIrisProcessorState(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public IKIrisWorkMode workMode {
    set {
      dllmainPINVOKE.IKIrisProcessorState_workMode_set(swigCPtr, (int)value);
    } 
    get {
      IKIrisWorkMode ret = (IKIrisWorkMode)dllmainPINVOKE.IKIrisProcessorState_workMode_get(swigCPtr);
      return ret;
    } 
  }

  public int detectType {
    set {
      dllmainPINVOKE.IKIrisProcessorState_detectType_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_detectType_get(swigCPtr);
      return ret;
    } 
  }

  public IKIrisMode irisMode {
    set {
      dllmainPINVOKE.IKIrisProcessorState_irisMode_set(swigCPtr, (int)value);
    } 
    get {
      IKIrisMode ret = (IKIrisMode)dllmainPINVOKE.IKIrisProcessorState_irisMode_get(swigCPtr);
      return ret;
    } 
  }

  public float leftIrisProgress {
    set {
      dllmainPINVOKE.IKIrisProcessorState_leftIrisProgress_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKIrisProcessorState_leftIrisProgress_get(swigCPtr);
      return ret;
    } 
  }

  public float rightIrisProgress {
    set {
      dllmainPINVOKE.IKIrisProcessorState_rightIrisProgress_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKIrisProcessorState_rightIrisProgress_get(swigCPtr);
      return ret;
    } 
  }

  public int imageW {
    set {
      dllmainPINVOKE.IKIrisProcessorState_imageW_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_imageW_get(swigCPtr);
      return ret;
    } 
  }

  public int imageH {
    set {
      dllmainPINVOKE.IKIrisProcessorState_imageH_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_imageH_get(swigCPtr);
      return ret;
    } 
  }

  public IKIrisPos irisPos {
    set {
      dllmainPINVOKE.IKIrisProcessorState_irisPos_set(swigCPtr, IKIrisPos.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIrisProcessorState_irisPos_get(swigCPtr);
      IKIrisPos ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKIrisPos(cPtr, false);
      return ret;
    } 
  }

  public int throwAwayFrameStatus {
    set {
      dllmainPINVOKE.IKIrisProcessorState_throwAwayFrameStatus_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_throwAwayFrameStatus_get(swigCPtr);
      return ret;
    } 
  }

  public int irisID {
    set {
      dllmainPINVOKE.IKIrisProcessorState_irisID_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_irisID_get(swigCPtr);
      return ret;
    } 
  }

  public int faceID {
    set {
      dllmainPINVOKE.IKIrisProcessorState_faceID_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_faceID_get(swigCPtr);
      return ret;
    } 
  }

  public int traceID {
    set {
      dllmainPINVOKE.IKIrisProcessorState_traceID_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_traceID_get(swigCPtr);
      return ret;
    } 
  }

  public int irisLeftMargin {
    set {
      dllmainPINVOKE.IKIrisProcessorState_irisLeftMargin_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_irisLeftMargin_get(swigCPtr);
      return ret;
    } 
  }

  public int irisRightMargin {
    set {
      dllmainPINVOKE.IKIrisProcessorState_irisRightMargin_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_irisRightMargin_get(swigCPtr);
      return ret;
    } 
  }

  public int irisTopMargin {
    set {
      dllmainPINVOKE.IKIrisProcessorState_irisTopMargin_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_irisTopMargin_get(swigCPtr);
      return ret;
    } 
  }

  public int irisBottomMargin {
    set {
      dllmainPINVOKE.IKIrisProcessorState_irisBottomMargin_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisProcessorState_irisBottomMargin_get(swigCPtr);
      return ret;
    } 
  }

  public SWIGTYPE_p_int reservedInfo {
    set {
      dllmainPINVOKE.IKIrisProcessorState_reservedInfo_set(swigCPtr, SWIGTYPE_p_int.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIrisProcessorState_reservedInfo_get(swigCPtr);
      SWIGTYPE_p_int ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_int(cPtr, false);
      return ret;
    } 
  }

  public IKIrisProcessorState() : this(dllmainPINVOKE.new_IKIrisProcessorState(), true) {
  }

}