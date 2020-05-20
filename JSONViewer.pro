QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 \
    warn_on

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
    UI/src/printing/Indent.cpp \
    UI/src/colors/setting_palettes.cpp \
    UI/src/printing/texthighlighter.cpp \
    logic/src/JSON_data_types/JSONDT.cpp \
    logic/src/JSON_data_types/complex/Array.cpp \
    logic/src/JSON_data_types/complex/KeyValuePair.cpp \
    logic/src/JSON_data_types/complex/Object.cpp \
    logic/src/JSON_data_types/simple/Boolean.cpp \
    logic/src/JSON_data_types/simple/Null.cpp \
    logic/src/JSON_data_types/simple/Number.cpp \
    logic/src/JSON_data_types/simple/String.cpp \
    logic/src/exception/JSONException.cpp \
    logic/src/facade.cpp \
    logic/src/files/filedispatcher.cpp \
    logic/src/files/fileexception.cpp \
    logic/src/textmistake.cpp \
    logic/src/utils/JSON.cpp \
    logic/src/utils/TextElement.cpp \
    logic/src/utils/TextPosition.cpp \
    logic/src/utils/string.cpp \
    main.cpp \
    UI/src/mainwindow.cpp

HEADERS += \
    UI/include/colors/color_scheme/editor_color_schemes/qcivic.h \
    UI/include/printing/CharFormatName.h \
    UI/include/colors/color_scheme/color_scheme_defines.h \
    UI/include/colors/color_scheme/editor_color_schemes/gruvbox_dark.h \
    UI/include/colors/color_scheme/editor_color_schemes/gruvbox_light.h \
    UI/include/colors/color_scheme/editor_color_schemes/monokai.h \
    UI/include/colors/color_scheme/global_color_schemes/yaru_dark.h \
    UI/include/colors/color_scheme/global_color_schemes/yaru_light.h \
    UI/include/colors/text_highlighting.h \
    UI/include/printing/texthighlighter.h \
    config.h \
    UI/include/mainwindow.h \
    UI/include/colors/setting_palettes.h \
    UI/include/printing/Indent.h \
    logic/include/JSON_data_types/DT_headers.h \
    logic/include/JSON_data_types/JSONDT.h \
    logic/include/JSON_data_types/complex/Array.h \
    logic/include/JSON_data_types/complex/ComplexDT.h \
    logic/include/JSON_data_types/complex/KeyValuePair.h \
    logic/include/JSON_data_types/complex/Object.h \
    logic/include/JSON_data_types/simple/Boolean.h \
    logic/include/JSON_data_types/simple/Null.h \
    logic/include/JSON_data_types/simple/Number.h \
    logic/include/JSON_data_types/simple/SimpleDT.h \
    logic/include/JSON_data_types/simple/String.h \
    logic/include/exception/JSON_DT/ArrayException.h \
    logic/include/exception/JSON_DT/BooleanException.h \
    logic/include/exception/JSONException.h \
    logic/include/exception/JSON_DT/DT_exception_headers.h \
    logic/include/exception/JSON_DT/KeyValuePairException.h \
    logic/include/exception/JSON_DT/NullException.h \
    logic/include/exception/JSON_DT/NumberException.h \
    logic/include/exception/JSON_DT/ObjectException.h \
    logic/include/exception/JSON_DT/StringException.h \
    logic/include/facade.h \
    logic/include/files/filedispatcher.h \
    logic/include/files/fileexception.h \
    logic/include/syntax_config.h \
    logic/include/textmistake.h \
    logic/include/utils/JSON.h \
    logic/include/utils/TextElement.h \
    logic/include/utils/TextPosition.h \
    logic/include/utils/string.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
