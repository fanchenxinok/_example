LOCAL_PATH:= $(call my-dir)
#LOCAL_CFLAGS_ALL :=-I. -I$(LOCAL_PATH)/..

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_XXXXService.cpp \
	XXXXService.cpp \
	../Interface/IXXXXService.cpp \
	../Interface/ICallback.cpp

LOCAL_SHARED_LIBRARIES := \
	liblog libcutils libutils libbinder libdl 
	
LOCAL_C_INCLUDES := \
	frameworks/base/include \
	frameworks/native/include \
	$(VENDOR_SDK_INCLUDES) 

LOCAL_MODULE:= test_binder_server
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)