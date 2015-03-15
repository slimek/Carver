NDK_TOOLCHAIN_VERSION := 4.8

APP_PLATFORM := android-15
APP_STL := gnustl_static

APP_CPPFLAGS := \
	-std=c++11 -fexceptions -frtti -fsigned-char \
	-DCC_ENABLE_CHIPMUNK_INTEGRATION=1
	
APP_LDFLAGS := -latomic


ifeq ($(NDK_DEBUG),1)

# Debug
APP_OPTIM := debug
BRITTLE_CONFIG := gcc48.Debug

#APP_ABI := armeabi
APP_ABI := x86

APP_CFLAGS += -DCOCOS2D_DEBUG=1

else

# Release
APP_OPTIM := release
BRITTLE_CONFIG := gcc48.Release

APP_ABI := x86 armeabi

endif

NDK_APP_OUT := obj/$(BRITTLE_CONFIG)
