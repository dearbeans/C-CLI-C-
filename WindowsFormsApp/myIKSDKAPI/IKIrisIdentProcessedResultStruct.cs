//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKIrisIdentProcessedResultStruct : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKIrisIdentProcessedResultStruct(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKIrisIdentProcessedResultStruct obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKIrisIdentProcessedResultStruct obj) {
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

  ~IKIrisIdentProcessedResultStruct() {
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
          dllmainPINVOKE.delete_IKIrisIdentProcessedResultStruct(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public int _nFunResult {
    set {
      dllmainPINVOKE.IKIrisIdentProcessedResultStruct__nFunResult_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKIrisIdentProcessedResultStruct__nFunResult_get(swigCPtr);
      return ret;
    } 
  }

  public IKIrisMode _irisMode {
    set {
      dllmainPINVOKE.IKIrisIdentProcessedResultStruct__irisMode_set(swigCPtr, (int)value);
    } 
    get {
      IKIrisMode ret = (IKIrisMode)dllmainPINVOKE.IKIrisIdentProcessedResultStruct__irisMode_get(swigCPtr);
      return ret;
    } 
  }

  public IKIrisResultFlag _flag {
    set {
      dllmainPINVOKE.IKIrisIdentProcessedResultStruct__flag_set(swigCPtr, (int)value);
    } 
    get {
      IKIrisResultFlag ret = (IKIrisResultFlag)dllmainPINVOKE.IKIrisIdentProcessedResultStruct__flag_get(swigCPtr);
      return ret;
    } 
  }

  public IKIrisMatchOutput _matchOutputL {
    set {
      dllmainPINVOKE.IKIrisIdentProcessedResultStruct__matchOutputL_set(swigCPtr, IKIrisMatchOutput.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIrisIdentProcessedResultStruct__matchOutputL_get(swigCPtr);
      IKIrisMatchOutput ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKIrisMatchOutput(cPtr, false);
      return ret;
    } 
  }

  public IKIrisMatchOutput _matchOutputR {
    set {
      dllmainPINVOKE.IKIrisIdentProcessedResultStruct__matchOutputR_set(swigCPtr, IKIrisMatchOutput.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIrisIdentProcessedResultStruct__matchOutputR_get(swigCPtr);
      IKIrisMatchOutput ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKIrisMatchOutput(cPtr, false);
      return ret;
    } 
  }

  public IKIrisInfo _irisInfoL {
    set {
      dllmainPINVOKE.IKIrisIdentProcessedResultStruct__irisInfoL_set(swigCPtr, IKIrisInfo.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIrisIdentProcessedResultStruct__irisInfoL_get(swigCPtr);
      IKIrisInfo ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKIrisInfo(cPtr, false);
      return ret;
    } 
  }

  public IKIrisInfo _irisInfoR {
    set {
      dllmainPINVOKE.IKIrisIdentProcessedResultStruct__irisInfoR_set(swigCPtr, IKIrisInfo.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = dllmainPINVOKE.IKIrisIdentProcessedResultStruct__irisInfoR_get(swigCPtr);
      IKIrisInfo ret = (cPtr == global::System.IntPtr.Zero) ? null : new IKIrisInfo(cPtr, false);
      return ret;
    } 
  }

  public IKIrisIdentProcessedResultStruct() : this(dllmainPINVOKE.new_IKIrisIdentProcessedResultStruct(), true) {
  }

}
