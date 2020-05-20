#ifndef SYNTAX_CONFIG_H
#define SYNTAX_CONFIG_H

#include <string>

// null
const std::string NULL_VALUE = "null";

// boolean
const std::string TRUE_VALUE = "true";

const std::string FALSE_VALUE = "false";

// string
const std::string STRING_BORDER = "\"";

// array
const std::string ARRAY_BORDER_BEGIN = "[";

const std::string ARRAY_BORDER_END = "]";

// object
const std::string OBJECT_BORDER_BEGIN = "{";

const std::string OBJECT_BORDER_END = "}";

// key-valuepair
const std::string KEY_VALUE_PAIR_SEPARATOR = ":";

// default chars
const std::string DEFAULT_INDENT = "  ";

const std::string DEFAULT_SPACE = " ";

const std::string DEFAULT_VALUE_SEPARATOR = ",";

const std::string DEFAULT_LINE_SEPARATOR = "\n";

#endif // SYNTAX_CONFIG_H
