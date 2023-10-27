//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.1.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class IKFrame : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal IKFrame(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(IKFrame obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(IKFrame obj) {
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

  ~IKFrame() {
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
          dllmainPINVOKE.delete_IKFrame(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public IKFrame() : this(dllmainPINVOKE.new_IKFrame__SWIG_0(), true) {
  }

  public IKFrame(int w, int h, int angle, IKFrameFormat color_space, IKFrameType brightness) : this(dllmainPINVOKE.new_IKFrame__SWIG_1(w, h, angle, (int)color_space, (int)brightness), true) {
  }

  public IKFrame(IKFrame src) : this(dllmainPINVOKE.new_IKFrame__SWIG_2(IKFrame.getCPtr(src)), true) {
    if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
  }

  public IKFrame eq(IKFrame src) {
    IKFrame ret = new IKFrame(dllmainPINVOKE.IKFrame_eq(swigCPtr, IKFrame.getCPtr(src)), false);
    if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public IKFrame simpleCpy(IKFrame src) {
    IKFrame ret = new IKFrame(dllmainPINVOKE.IKFrame_simpleCpy(swigCPtr, IKFrame.getCPtr(src)), false);
    if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool empty() {
    bool ret = dllmainPINVOKE.IKFrame_empty(swigCPtr);
    return ret;
  }

  public bool clear() {
    bool ret = dllmainPINVOKE.IKFrame_clear(swigCPtr);
    return ret;
  }

  public SWIGTYPE_p_std__shared_ptrT_unsigned_char_t image_data {
    set {
      dllmainPINVOKE.IKFrame_image_data_set(swigCPtr, SWIGTYPE_p_std__shared_ptrT_unsigned_char_t.getCPtr(value));
      if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      SWIGTYPE_p_std__shared_ptrT_unsigned_char_t ret = new SWIGTYPE_p_std__shared_ptrT_unsigned_char_t(dllmainPINVOKE.IKFrame_image_data_get(swigCPtr), true);
      if (dllmainPINVOKE.SWIGPendingException.Pending) throw dllmainPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int data_len {
    set {
      dllmainPINVOKE.IKFrame_data_len_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFrame_data_len_get(swigCPtr);
      return ret;
    } 
  }

  public int width {
    set {
      dllmainPINVOKE.IKFrame_width_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFrame_width_get(swigCPtr);
      return ret;
    } 
  }

  public int height {
    set {
      dllmainPINVOKE.IKFrame_height_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFrame_height_get(swigCPtr);
      return ret;
    } 
  }

  public int rotation {
    set {
      dllmainPINVOKE.IKFrame_rotation_set(swigCPtr, value);
    } 
    get {
      int ret = dllmainPINVOKE.IKFrame_rotation_get(swigCPtr);
      return ret;
    } 
  }

  public IKFrameFormat format {
    set {
      dllmainPINVOKE.IKFrame_format_set(swigCPtr, (int)value);
    } 
    get {
      IKFrameFormat ret = (IKFrameFormat)dllmainPINVOKE.IKFrame_format_get(swigCPtr);
      return ret;
    } 
  }

  public IKFrameType frame_type {
    set {
      dllmainPINVOKE.IKFrame_frame_type_set(swigCPtr, (int)value);
    } 
    get {
      IKFrameType ret = (IKFrameType)dllmainPINVOKE.IKFrame_frame_type_get(swigCPtr);
      return ret;
    } 
  }

}