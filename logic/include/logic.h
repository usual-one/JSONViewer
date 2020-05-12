#ifndef LOGICS_H
#define LOGICS_H

#include <string>
#include <memory>
#include "logic/include/JSON_data_types/JSONDT.h"
#include "UI/include/printing/TextHighlighter.h"

enum err_t {
    OK
};

class Operation {
public:
    std::string loadFile(const std::string &path);

    std::unique_ptr<JSONDT> parseJSON(const std::string &json_string);

    void printOnWidget(JSONDT &json, TextHighlighter &highlighter, const std::string &prefix);

    void saveFile(const std::string &path, const std::string &data);
private:
};

#endif // LOGICS_H
