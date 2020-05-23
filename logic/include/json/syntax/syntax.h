#ifndef JSON_SYNTAX_H
#define JSON_SYNTAX_H

#include <set>
#include <string>
#include <vector>

// null
const std::string NULL_VALUE = "null";

// number
const std::set<std::string> UNARY_SIGNS = {"+", "-"};

const std::set<std::string> EULERS_NUMBER = {"E", "e"};

const std::string DECIMAL_SEPARATOR = ".";

// boolean
const std::string TRUE_VALUE = "true";

const std::string FALSE_VALUE = "false";

// string
const std::string STRING_BORDER = "\"";

// array
const std::vector<std::string> ARRAY_BORDERS = {"[", "]"};

// object
const std::vector<std::string> OBJECT_BORDERS = {"{", "}"};

// key-valuepair
const std::string KEY_VALUE_SEPARATOR = ":";

// default chars
const std::string DEFAULT_INDENT = "  ";

const std::string DEFAULT_SPACE = " ";

const std::string DEFAULT_VALUE_SEPARATOR = ",";

const std::string DEFAULT_LINE_SEPARATOR = "\n";

#endif // JSON_SYNTAX_H
