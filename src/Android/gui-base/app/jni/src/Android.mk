LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := main.cpp class/text.cpp class/load_file.cpp \
class/font.cpp class/image.cpp class/voice.cpp class/mouse.cpp class/checkbox.cpp


LOCAL_SHARED_LIBRARIES := SDL2 \
                          SDL2_image \
                          SDL2_mixer \
                          SDL2_ttf \


LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid

include $(BUILD_SHARED_LIBRARY)
