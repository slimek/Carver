APP_PLATFORM := android-15
APP_ABI := x86 armeabi

APP_STL := c++_static
NDK_TOOLCHAIN_VERSION := 4.8

APP_CFLAGS := -fexceptions -D__STDC_LIMIT_MACROS
APP_CPPFLAGS := \
	-std=c++11 -frtti -fsigned-char -Wno-extern-c-compat \
	-DCC_ENABLE_CHIPMUNK_INTEGRATION=1


ifeq ($(NDEBUG),1)

# Release
APP_OPTIM := release
BRITTLE_CONFIG := gcc48.Release

else

# Debug
APP_OPTIM := debug
BRITTLE_CONFIG := gcc48.Debug

APP_CFLAGS += -g -DCOCOS2D_DEBUG=1

endif

NDK_APP_OUT := obj/$(BRITTLE_CONFIG)

