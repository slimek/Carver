#
# Store the local path
#

CARVER_LOCAL_PATH := $(call my-dir)


#
# Include Brittle Settings
#

include ../../Brittle/proj.android/jni/BrittleApp.mk


#
# Build Carver App
#

LOCAL_PATH := $(CARVER_LOCAL_PATH)

LOCAL_MODULE := Carver

CARVER_SRC := ../../src

LOCAL_SRC_FILES := \
	$(CARVER_SRC)/CarverPch.cpp \
	$(CARVER_SRC)/CarverApp.cpp \
	$(CARVER_SRC)/Clock/ClockScene.cpp \
	$(CARVER_SRC)/Menu/MenuScene.cpp \
	$(CARVER_SRC)/Whack/WhackScene.cpp \
	$(CARVER_SRC).android/NativeInit.cpp


LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../src \
	$(BRITTLE_C_INCLUDES)
	
LOCAL_WHOLE_STATIC_LIBRARIES := \
	$(BRITTLE_PREBUILT_STATIC_LIBRARIES)

LOCAL_LDLIBS := \
	$(BRITTLE_LDLIBS)	
	

include $(BUILD_SHARED_LIBRARY)
	