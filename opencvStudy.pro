TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
TARGET = opencvStudy

SOURCES += main.cpp \
    test/video_display.cpp \
    test/gui_trackbar.cpp \
    test/gui_mouse.cpp \
    test/core_mat_pix.cpp

LIBS += -L/usr/local/lib -opencv_calib3d -lopencv_core -lopencv_dnn \
  -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc \
    -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_shape -lopencv_stitching \
    -lopencv_superres -lopencv_videoio -lopencv_video -lopencv_videostab

HEADERS += \
    test/video_display.h \
    test/gui_trackbar.h \
    test/gui_mouse.h \
    test/core_mat_pix.h
