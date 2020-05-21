#include "logic/include/text/indent.h"

Indent::Indent() {
    own_ = "";
    begin_ = "";
    end_ = "";
}

Indent::Indent(const std::string &own) {
    own_ = own;
    begin_ = own;
    end_ = own;
}

Indent::Indent(const std::string &own, const std::string &begin, const std::string &end) {
    own_ = own;
    begin_ = begin;
    end_ = end;
}
