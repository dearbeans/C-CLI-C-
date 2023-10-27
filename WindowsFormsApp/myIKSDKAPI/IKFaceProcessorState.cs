//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKFaceProcessorState : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKFaceProcessorState(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKFaceProcessorState obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKFaceProcessorState obj) {
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

  ~IKFaceProcessorState() {
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
          dllmainPINVOKE.delete_IKFaceProcessorState(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public void Init() {
    dllmainPINVOKE.IKFaceProcessorState_Init(swigCPtr);
  }

  public IKFaceWorkMode workMode {
    set {
      dllmainPINVOKE.IKFaceProcessorState_workMode_set(swigCPtr, (int)value);
    } 
    get {
      IKFaceWorkMode ret = (IKFaceWorkMode)dllmainPINVOKE.IKFaceProcessorState_workMode_get(swigCPtr);
      return ret;
    } 
  }

  public IKFaceROIInfo faceROIInfo {
    set {
      dllmainPINVOKE.IKFaceProcessorState_faceROIInfo_set(swigCPtr, IKFaceROIInfo.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceProcessorState_faceROIInfo_get(swigCPtr);
      IKFaceROIInfo ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKFaceROIInfo(cPtr, false);
      return ret;
    } 
  }

  public int dist {
    set {
      dllmainPINVOKE.IKFaceProcessorState_dist_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_dist_get(swigCPtr);
      return ret;
    } 
  }

  public float lightScore {
    set {
      dllmainPINVOKE.IKFaceProcessorState_lightScore_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKFaceProcessorState_lightScore_get(swigCPtr);
      return ret;
    } 
  }

  public int imageW {
    set {
      dllmainPINVOKE.IKFaceProcessorState_imageW_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_imageW_get(swigCPtr);
      return ret;
    } 
  }

  public int imageH {
    set {
      dllmainPINVOKE.IKFaceProcessorState_imageH_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_imageH_get(swigCPtr);
      return ret;
    } 
  }

  public int detectBeginX {
    set {
      dllmainPINVOKE.IKFaceProcessorState_detectBeginX_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_detectBeginX_get(swigCPtr);
      return ret;
    } 
  }

  public int detectBeginY {
    set {
      dllmainPINVOKE.IKFaceProcessorState_detectBeginY_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_detectBeginY_get(swigCPtr);
      return ret;
    } 
  }

  public int detectW {
    set {
      dllmainPINVOKE.IKFaceProcessorState_detectW_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_detectW_get(swigCPtr);
      return ret;
    } 
  }

  public int detectH {
    set {
      dllmainPINVOKE.IKFaceProcessorState_detectH_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_detectH_get(swigCPtr);
      return ret;
    } 
  }

  public float faceProgress {
    set {
      dllmainPINVOKE.IKFaceProcessorState_faceProgress_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKFaceProcessorState_faceProgress_get(swigCPtr);
      return ret;
    } 
  }

  public int throwAwayFrameStatus {
    set {
      dllmainPINVOKE.IKFaceProcessorState_throwAwayFrameStatus_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_throwAwayFrameStatus_get(swigCPtr);
      return ret;
    } 
  }

  public int imageIndex {
    set {
      dllmainPINVOKE.IKFaceProcessorState_imageIndex_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFaceProcessorState_imageIndex_get(swigCPtr);
      return ret;
    } 
  }

  public IKFaceProcessorState() : this(dllmainPINVOKE.new_IKFaceProcessorState(), true) {
  }

}