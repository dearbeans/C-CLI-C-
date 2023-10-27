//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKFaceQulityInfo : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKFaceQulityInfo(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKFaceQulityInfo obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKFaceQulityInfo obj) {
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

  ~IKFaceQulityInfo() {
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
          dllmainPINVOKE.delete_IKFaceQulityInfo(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public float yaw {
    set {
      dllmainPINVOKE.IKFaceQulityInfo_yaw_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKFaceQulityInfo_yaw_get(swigCPtr);
      return ret;
    } 
  }

  public float pitch {
    set {
      dllmainPINVOKE.IKFaceQulityInfo_pitch_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKFaceQulityInfo_pitch_get(swigCPtr);
      return ret;
    } 
  }

  public float roll {
    set {
      dllmainPINVOKE.IKFaceQulityInfo_roll_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKFaceQulityInfo_roll_get(swigCPtr);
      return ret;
    } 
  }

  public float confidence {
    set {
      dllmainPINVOKE.IKFaceQulityInfo_confidence_set(swigCPtr, value);
    } 
    get {
      float ret = dllmainPINVOKE.IKFaceQulityInfo_confidence_get(swigCPtr);
      return ret;
    } 
  }

  public IKFaceQulityInfo() : this(dllmainPINVOKE.new_IKFaceQulityInfo(), true) {
  }

}
