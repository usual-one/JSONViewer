#include "UI/include/setting_palettes.h"
#include "UI/include/config.h"
#include EDITOR_COLOR_SCHEME
#include GLOBAL_COLOR_SCHEME

void setDefaultPalette(QPlainTextEdit *widget) {
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Base, EDITOR_BACKGROUND_COLOR);
    palette.setColor(QPalette::Highlight, EDITOR_SELECTED_BACKGROUND_COLOR);
    palette.setColor(QPalette::Text, EDITOR_DEFAULT_TEXT_COLOR);
    widget->setPalette(palette);
}

void setDefaultPalette(QMainWindow *widget) {
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Window, GLOBAL_BACKGROUND_COLOR); // global window color
    palette.setColor(QPalette::WindowText, GLOBAL_DEFAULT_TEXT_COLOR); // statusbar text color
    palette.setColor(QPalette::Highlight, GLOBAL_SELECTED_BACKGROUND_COLOR); // menu selected background color
    palette.setColor(QPalette::HighlightedText, GLOBAL_DEFAULT_TEXT_COLOR); // menu selected text color
    palette.setColor(QPalette::ButtonText, GLOBAL_DEFAULT_TEXT_COLOR); // menu text color
    palette.setColor(QPalette::Button, GLOBAL_BACKGROUND_COLOR); // scrollbar color
    widget->setPalette(palette);
}

void setDefaultPalette(QMenu *widget) {
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Base, GLOBAL_BACKGROUND_COLOR); // global window color
    palette.setColor(QPalette::Text, GLOBAL_DEFAULT_TEXT_COLOR); // statusbar text color
    palette.setColor(QPalette::Highlight, GLOBAL_SELECTED_BACKGROUND_COLOR); // menu selected background color
    palette.setColor(QPalette::HighlightedText, GLOBAL_DEFAULT_TEXT_COLOR); // menu selected text color
    widget->setPalette(palette);
}
