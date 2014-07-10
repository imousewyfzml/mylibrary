LOCAL_PATH:= $(call my-dir)

# Build the Phone app which includes the emergency dialer. See Contacts
# for the 'other' dialer.
include $(CLEAR_VARS)

LOCAL_AAPT_FLAGS += --utf16
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_SRC_FILES += \
        src/com/orangelabs/rcs/service/api/client/media/IMediaEventListener.aidl \
        src/com/orangelabs/rcs/service/api/client/media/IMediaPlayer.aidl \
        src/com/orangelabs/rcs/service/api/client/media/IMediaRenderer.aidl

LOCAL_PACKAGE_NAME := rtspcamera

LOCAL_CERTIFICATE := platform
LOCAL_PRIVILEGED_MODULE := true



include $(BUILD_PACKAGE)

# Build the test package
include $(call all-makefiles-under,$(LOCAL_PATH))
