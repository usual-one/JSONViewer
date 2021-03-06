QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 \
    warn_on

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    logic/src/files/filedispatcher.cpp \
    logic/src/files/fileexception.cpp \
    logic/src/json/data_types/complex/array.cpp \
    logic/src/json/data_types/complex/object.cpp \
    logic/src/json/data_types/complex/inner/keyvaluepair.cpp \
    logic/src/json/data_types/simple/boolean.cpp \
    logic/src/json/data_types/simple/null.cpp \
    logic/src/json/data_types/simple/number.cpp \
    logic/src/json/data_types/simple/string.cpp \
    logic/src/json/data_types/jsondt.cpp \
    logic/src/json/exception/jsonexception.cpp \
    logic/src/json/syntax/charsets/dt/arraycharset.cpp \
    logic/src/json/syntax/charsets/dt/booleancharset.cpp \
    logic/src/json/syntax/charsets/dt/dtcharset.cpp \
    logic/src/json/syntax/charsets/dt/nullcharset.cpp \
    logic/src/json/syntax/charsets/dt/numbercharset.cpp \
    logic/src/json/syntax/charsets/dt/objectcharset.cpp \
    logic/src/json/syntax/charsets/dt/stringcharset.cpp \
    logic/src/json/syntax/charsets/ignoredcharset.cpp \
    logic/src/json/syntax/single_elements/indentsyntaxelement.cpp \
    logic/src/json/syntax/single_elements/keyvalueseparator.cpp \
    logic/src/json/syntax/single_elements/lineseparator.cpp \
    logic/src/json/syntax/single_elements/spacesyntaxelement.cpp \
    logic/src/json/syntax/single_elements/valueseparator.cpp \
    logic/src/json/jsonparser.cpp \
    logic/src/text/indent.cpp \
    logic/src/text/textelement.cpp \
    logic/src/text/textmistake.cpp \
    logic/src/text/textposition.cpp \
    logic/src/utils/string_utils.cpp \
    logic/src/facade.cpp \
    UI/src/colors/settings/setting_palettes.cpp \
    UI/src/output/texthighlighter.cpp \
    UI/src/mainwindow.cpp \
    main.cpp

HEADERS += \
    logic/include/files/filedispatcher.h \
    logic/include/files/fileexception.h \
    logic/include/json/data_types/complex/array.h \
    logic/include/json/data_types/complex/complexdt.h \
    logic/include/json/data_types/complex/object.h \
    logic/include/json/data_types/complex/inner/innerdt.h \
    logic/include/json/data_types/complex/inner/keyvaluepair.h \
    logic/include/json/data_types/dtname.h \
    logic/include/json/data_types/simple/boolean.h \
    logic/include/json/data_types/simple/null.h \
    logic/include/json/data_types/simple/number.h \
    logic/include/json/data_types/simple/simpledt.h \
    logic/include/json/data_types/simple/string.h \
    logic/include/json/data_types/dt_headers.h \
    logic/include/json/data_types/jsondt.h \
    logic/include/json/exception/arrayexception.h \
    logic/include/json/exception/booleanexception.h \
    logic/include/json/exception/dt_exception_headers.h \
    logic/include/json/exception/keyvaluepairexception.h \
    logic/include/json/exception/nullexception.h \
    logic/include/json/exception/numberexception.h \
    logic/include/json/exception/objectexception.h \
    logic/include/json/exception/stringexception.h \
    logic/include/json/exception/jsonexception.h \
    logic/include/json/jsonparser.h \
    logic/include/json/syntax/syntax.h \
    logic/include/json/syntax/charsets/charset.h \
    logic/include/json/syntax/charsets/dt/arraycharset.h \
    logic/include/json/syntax/charsets/dt/booleancharset.h \
    logic/include/json/syntax/charsets/dt/dtcharset.h \
    logic/include/json/syntax/charsets/dt/nullcharset.h \
    logic/include/json/syntax/charsets/dt/numbercharset.h \
    logic/include/json/syntax/charsets/dt/objectcharset.h \
    logic/include/json/syntax/charsets/dt/stringcharset.h \
    logic/include/json/syntax/charsets/ignoredcharset.h \
    logic/include/json/syntax/single_elements/indentsyntaxelement.h \
    logic/include/json/syntax/single_elements/keyvalueseparator.h \
    logic/include/json/syntax/single_elements/lineseparator.h \
    logic/include/json/syntax/single_elements/singlesyntaxelement.h \
    logic/include/json/syntax/single_elements/spacesyntaxelement.h \
    logic/include/json/syntax/single_elements/valueseparator.h \
    logic/include/json/syntax/syntaxelement.h \
    logic/include/text/charformatname.h \
    logic/include/text/indent.h \
    logic/include/text/textelement.h \
    logic/include/text/textmistake.h \
    logic/include/text/textposition.h \
    logic/include/utils/string_utils.h \
    logic/include/facade.h \
    UI/include/colors/color_scheme/editor_color_schemes/qcivic.h \
    UI/include/colors/color_scheme/editor_color_schemes/gruvbox_dark.h \
    UI/include/colors/color_scheme/editor_color_schemes/gruvbox_light.h \
    UI/include/colors/color_scheme/editor_color_schemes/monokai.h \
    UI/include/colors/color_scheme/global_color_schemes/yaru_dark.h \
    UI/include/colors/color_scheme/global_color_schemes/yaru_light.h \
    UI/include/colors/color_scheme/color_scheme_defines.h \
    UI/include/colors/settings/setting_palettes.h \
    UI/include/output/texthighlighter.h \
    UI/include/mainwindow.h \
    config.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
