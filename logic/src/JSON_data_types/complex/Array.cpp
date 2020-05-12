#include "logic/include/JSON_data_types/DT_headers.h"
#include "logic/include/exception/JSON_DT/ArrayException.h"
#include "logic/include/utils/JSON.h"

size_t Array::fromStdString(const std::string &string)
{
    size_t char_consumed = 0;
    setEndPos(getBeginPos());

    if (string[0] != '[') {
        throw ArrayBracketBeginException("no begin bracket found", getEndPos());
    }
    char_consumed++;

    bool end_found = false;
    bool comma_found = true;
    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (string[i] == ',') {
            if (comma_found) {
                throw ArrayUnexpectedException(string[i], getEndPos());
            }
            comma_found = true;
        } else {
            comma_found = false;
            if (isJSONDTStartedWith(string[i])) {
                if (string[i] == '[') {
                    instance_.push_back(std::make_unique<Array>());
                } else if (string[i] == '{') {
                    instance_.push_back(std::make_unique<Object>());
                } else if (string[i] == '"') {
                    instance_.push_back(std::make_unique<String>());
                } else if (string[i] == 't') {
                    instance_.push_back(std::make_unique<Boolean>());
                } else if (string[i] == 'n') {
                    instance_.push_back(std::make_unique<Null>());
                } else if (isFromJSONNumber(string[i])) {
                    instance_.push_back(std::make_unique<Number>());
                }
                instance_[instance_.size() - 1]->setBeginPos(getEndPos());
                i += instance_[instance_.size() - 1]->fromStdString(string.substr(i));
                setEndPos(instance_[instance_.size() - 1]->getEndPos());
                i--;
            } else {
                if (string[i] == ']') {
                    end_found = true;
                    char_consumed = i + 1;
                    break;
                } else if (string[i] == '\n') {
                    getEndPos().setRow(getEndPos().getRow() + 1);
                    getEndPos().setColumn(-1);
                } else if (isJSONIgnored(string[i])) {
                    continue;
                } else {
                    throw ArrayUnexpectedException(string[i], getEndPos());
                }
            }
        }
    }

    if (!end_found) {
        throw ArrayBracketEndException("no end bracket found", getEndPos());
    }

    return char_consumed;
}

std::string Array::toStdString()
{
    std::string str = "[\n";
    for (size_t i = 0; i < instance_.size() - 1; i++) {
        str.append(instance_[i]->toStdString() + ",\n");
    }
    str.append(instance_[instance_.size() - 1]->toStdString() + "\n");
    str.append("}");
    return str;
}

void Array::printOnWidget(TextHighlighter &highlighter, const std::string &prefix) {
    highlighter.print((prefix + "[\n").data());
    for (size_t i = 0; i < instance_.size() - 1; i++) {
        highlighter.print(prefix.data());
        instance_[i]->printOnWidget(highlighter, prefix);
        highlighter.print(",\n");
    }
    highlighter.print(prefix.data());
    instance_[instance_.size() - 1]->printOnWidget(highlighter, prefix);
    highlighter.print("\n}");
}

std::vector<std::unique_ptr<JSONDT>> &Array::getInstance() {
    return instance_;
}
