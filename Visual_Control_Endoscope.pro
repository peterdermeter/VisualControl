#-------------------------------------------------
#
# Project created by QtCreator 2013-08-16T00:31:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visual_Control_Endoscope
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    histogram.cpp \
    Epiphan2USB.cpp \
    imageFunctions.cpp

HEADERS  += dialog.h \
    v2u_ioctl.h \
    v2u_id.h \
    v2u_defs.h \
    histogram.h \
    frmgrab.h \
    Epiphan2USB.h \
    imageFunctions.h

FORMS    += dialog.ui

INCLUDEPATH += C:/OpenCV-2.4.6/mybuild/include

LIBS += -LC:/OpenCV-2.4.6/mybuild/lib \
  -lopencv_calib3d246 \
  -lopencv_contrib246 \
  -lopencv_core246 \
  -lopencv_features2d246 \
  -lopencv_flann246 \
  -lopencv_gpu246 \
  -lopencv_highgui246 \
  -lopencv_imgproc246 \
  -lopencv_legacy246 \
  -lopencv_ml246 \
  -lopencv_nonfree246 \
  -lopencv_objdetect246 \
  -lopencv_photo246 \
  -lopencv_stitching246 \
  -lopencv_superres246 \
  -lopencv_ts246 \
  -lopencv_video246 \
  -lopencv_videostab246 \

LIBS += -LC:/Users/Eugen/Documents/Qt-Projekte/Visual_Control_Endoscope \
  -lfrmgrab

DEFINES += _CRT_SECURE_NO_WARNINGS

CONFIG += serialport

RESOURCES += \
    EndoscopeRes.qrc

