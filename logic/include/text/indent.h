#ifndef PRINTING_INDENT_H
#define PRINTING_INDENT_H

#include <string>

class Indent {
public:
    Indent();

    Indent(const std::string &own);

    Indent(const std::string &own, const std::string &begin, const std::string &end);

    std::string own_;

    std::string begin_;

    std::string end_;
};

#endif // PRINTING_INDENT_H
