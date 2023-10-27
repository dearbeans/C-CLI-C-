//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKIdentProcessedResultStruct : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKIdentProcessedResultStruct(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKIdentProcessedResultStruct obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKIdentProcessedResultStruct obj) {
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

  ~IKIdentProcessedResultStruct() {
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
          dllmainPINVOKE.delete_IKIdentProcessedResultStruct(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public IKEnrollIdentResultFlag _enrollIdentResFlag {
    set {
      dllmainPINVOKE.IKIdentProcessedResultStruct__enrollIdentResFlag_set(swigCPtr, (int)value);
    } 
    get {
      IKEnrollIdentResultFlag ret = (IKEnrollIdentResultFlag)dllmainPINVOKE.IKIdentProcessedResultStruct__enrollIdentResFlag_get(swigCPtr);
      return ret;
    } 
  }

  public IKEnrollIdentMode _enrollIdentMode {
    set {
      dllmainPINVOKE.IKIdentProcessedResultStruct__enrollIdentMode_set(swigCPtr, (int)value);
    } 
    get {
      IKEnrollIdentMode ret = (IKEnrollIdentMode)dllmainPINVOKE.IKIdentProcessedResultStruct__enrollIdentMode_get(swigCPtr);
      return ret;
    } 
  }

  public IKIrisIdentProcessedResultStruct _irisIdentResult {
    set {
      dllmainPINVOKE.IKIdentProcessedResultStruct__irisIdentResult_set(swigCPtr, IKIrisIdentProcessedResultStruct.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIdentProcessedResultStruct__irisIdentResult_get(swigCPtr);
      IKIrisIdentProcessedResultStruct ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKIrisIdentProcessedResultStruct(cPtr, false);
      return ret;
    } 
  }

  public IKFaceIdentOutputStruct _faceIdentResult {
    set {
      dllmainPINVOKE.IKIdentProcessedResultStruct__faceIdentResult_set(swigCPtr, IKFaceIdentOutputStruct.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIdentProcessedResultStruct__faceIdentResult_get(swigCPtr);
      IKFaceIdentOutputStruct ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKFaceIdentOutputStruct(cPtr, false);
      return ret;
    } 
  }

  public IKIdentProcessedResultStruct() : this(dllmainPINVOKE.new_IKIdentProcessedResultStruct(), true) {
  }

}
