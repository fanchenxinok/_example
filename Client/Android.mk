LOCAL_PATH:= $(call my-dir)
#LOCAL_CFLAGS_ALL :=-I. -I$(LOCAL_PATH)/..

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_client.cpp \
	../Interface/IXXXXService.cpp
	
LOCAL_SHARED_LIBRARIES := \
	liblog libui libcutils libutils libbinder
	
LOCAL_C_INCLUDES := \
	frameworks/base/include \
	frameworks/native/include \
	$(VENDOR_SDK_INCLUDES)

LOCAL_MODULE:= test_binder_client
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)