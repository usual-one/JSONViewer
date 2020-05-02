QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logics/src/exception/JSONException.cpp \
    logics/src/logics.cpp \
    main.cpp \
    UI/src/mainwindow.cpp

HEADERS += \
    UI/include/color_scheme/editor_color_schemes/monokai.h \
    UI/include/color_scheme/global_color_schemes/dark_yaru.h \
    UI/include/config.h \
    UI/include/mainwindow.h \
    logics/include/JSON_data_types/JSONDT.h \
    logics/include/JSON_data_types/complex/Array.h \
    logics/include/JSON_data_types/complex/ComplexDT.h \
    logics/include/JSON_data_types/complex/KeyValuePair.h \
    logics/include/JSON_data_types/complex/Object.h \
    logics/include/JSON_data_types/simple/Boolean.h \
    logics/include/JSON_data_types/simple/Null.h \
    logics/include/JSON_data_types/simple/Number.h \
    logics/include/JSON_data_types/simple/SimpleDT.h \
    logics/include/JSON_data_types/simple/String.h \
    logics/include/exception/FileException.h \
    logics/include/exception/JSONException.h \
    logics/include/logics.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
