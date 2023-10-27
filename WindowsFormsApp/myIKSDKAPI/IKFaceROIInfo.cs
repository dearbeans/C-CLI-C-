//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKFaceROIInfo : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKFaceROIInfo(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKFaceROIInfo obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKFaceROIInfo obj) {
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

  ~IKFaceROIInfo() {
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
          dllmainPINVOKE.delete_IKFaceROIInfo(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public bool ifValid {
    set {
      dllmainPINVOKE.IKFaceROIInfo_ifValid_set(swigCPtr, value);
    } 
    get {
      bool ret = dllmainPINVOKE.IKFaceROIInfo_ifValid_get(swigCPtr);
      return ret;
    } 
  }

  public SELFRECT rcFace {
    set {
      dllmainPINVOKE.IKFaceROIInfo_rcFace_set(swigCPtr, SELFRECT.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceROIInfo_rcFace_get(swigCPtr);
      SELFRECT ret = (cPtr == global::System.IntPtr.Zero) ? null : new SELFRECT(cPtr, false);
      return ret;
    } 
  }

  public SELFPOINT ptLeftEye {
    set {
      dllmainPINVOKE.IKFaceROIInfo_ptLeftEye_set(swigCPtr, SELFPOINT.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceROIInfo_ptLeftEye_get(swigCPtr);
      SELFPOINT ret = (cPtr == global::System.IntPtr.Zero) ? null : new SELFPOINT(cPtr, false);
      return ret;
    } 
  }

  public SELFPOINT ptRightEye {
    set {
      dllmainPINVOKE.IKFaceROIInfo_ptRightEye_set(swigCPtr, SELFPOINT.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceROIInfo_ptRightEye_get(swigCPtr);
      SELFPOINT ret = (cPtr == global::System.IntPtr.Zero) ? null : new SELFPOINT(cPtr, false);
      return ret;
    } 
  }

  public SELFPOINT ptMouthLeft {
    set {
      dllmainPINVOKE.IKFaceROIInfo_ptMouthLeft_set(swigCPtr, SELFPOINT.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceROIInfo_ptMouthLeft_get(swigCPtr);
      SELFPOINT ret = (cPtr == global::System.IntPtr.Zero) ? null : new SELFPOINT(cPtr, false);
      return ret;
    } 
  }

  public SELFPOINT ptMouthRight {
    set {
      dllmainPINVOKE.IKFaceROIInfo_ptMouthRight_set(swigCPtr, SELFPOINT.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceROIInfo_ptMouthRight_get(swigCPtr);
      SELFPOINT ret = (cPtr == global::System.IntPtr.Zero) ? null : new SELFPOINT(cPtr, false);
      return ret;
    } 
  }

  public SELFPOINT ptNose {
    set {
      dllmainPINVOKE.IKFaceROIInfo_ptNose_set(swigCPtr, SELFPOINT.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceROIInfo_ptNose_get(swigCPtr);
      SELFPOINT ret = (cPtr == global::System.IntPtr.Zero) ? null : new SELFPOINT(cPtr, false);
      return ret;
    } 
  }

  public IKFaceQulityInfo fAngle {
    set {
      dllmainPINVOKE.IKFaceROIInfo_fAngle_set(swigCPtr, IKFaceQulityInfo.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKFaceROIInfo_fAngle_get(swigCPtr);
      IKFaceQulityInfo ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKFaceQulityInfo(cPtr, false);
      return ret;
    } 
  }

  public IKFaceROIInfo() : this(dllmainPINVOKE.new_IKFaceROIInfo(), true) {
  }

}
