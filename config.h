#ifndef CONFIG_H
#define CONFIG_H

#include <cstddef>

#include <QString>

#include "UI/include/colors/color_scheme/color_scheme_defines.h"

// color schemes
#define EDITOR_COLOR_SCHEME EDITOR_GRUVBOX_LIGHT

#define GLOBAL_COLOR_SCHEME GLOBAL_YARU_LIGHT

// status bar -----
const size_t STATUS_DISPLAYING_TIMEOUT = 3000;

const size_t ERROR_DISPLAYING_TIMEOUT = 7000;

// messages
const QString NEW_FILE_MESSAGE = "New file";

const QString OPEN_FILE_MESSAGE = "Opening file";

const QString SAVE_FILE_MESSAGE = "Successfully saved";

const QString SAVED_AS_MESSAGE = "Successfully saved as ";

const std::string NO_MISTAKES_MESSAGE = "No mistakes found!";

const std::string ARRAY_MISTAKE_MESSAGE = "Found Array mistake";

const std::string OBJECT_MISTAKE_MESSAGE = "Found Object mistake";

const std::string BOOLEAN_MISTAKE_MESSAGE = "Found Boolean mistake";

const std::string NULL_MISTAKE_MESSAGE = "Found Null mistake";

const std::string NUMBER_MISTAKE_MESSAGE = "Found Number mistake";

const std::string STRING_MISTAKE_MESSAGE = "Found String mistake";

const std::string JSON_MISTAKE_MESSAGE = "Found unknown JSON mistake";

const std::string UNKNOWN_MISTAKE_MESSAGE = "Found unknown mistake";

#endif // CONFIG_H
