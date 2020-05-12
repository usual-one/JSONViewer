#include "logic/include/JSON_data_types/complex/Object.h"
#include "logic/include/exception/JSON_DT/ObjectException.h"
#include "logic/include/utils/JSON.h"

size_t Object::fromStdString(const std::string &string)
{
    size_t char_consumed = 0;
    setEndPos(getBeginPos());

    if (string[0] != '{') {
        throw ObjectBracketBeginException("no begin bracket found", getEndPos());
    }
    char_consumed++;

    bool end_found = false;
    bool comma_found = true;
    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (string[i] == ',') {
            if (comma_found) {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
            comma_found = true;
        } else {
            comma_found = false;
            if (string[i] == '"') {
                instance_.push_back(std::make_unique<KeyValuePair>());
                instance_[instance_.size() - 1]->setBeginPos(getEndPos());
                i += instance_[instance_.size() - 1]->fromStdString(string.substr(i));
                setEndPos(instance_[instance_.size() - 1]->getEndPos());
                i--;
            } else if (string[i] == '}') {
                end_found = true;
                char_consumed = i + 1;
                break;
            } else if (string[i] == '\n') {
                getEndPos().setRow(getEndPos().getRow() + 1);
                getEndPos().setColumn(-1);
            } else if (isJSONIgnored(string[i])) {
                continue;
            } else {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
        }
    }

    if (!end_found) {
        throw ObjectBracketEndException("no end bracket found", getEndPos());
    }

    return char_consumed;
}

std::string Object::toStdString() {
    std::string str = "{\n";
    for (size_t i = 0; i < instance_.size() - 1; i++) {
        str.append(instance_[i]->toStdString() + ",\n");
    }
    str.append(instance_[instance_.size() - 1]->toStdString() + "\n");
    str.append("}");
    return str;
}

void Object::printOnWidget(TextHighlighter &highlighter, const std::string &prefix) {
    highlighter.print((prefix + "{\n").data());
    for (size_t i = 0; i < instance_.size() - 1; i++) {
        highlighter.print(prefix.data());
        instance_[i]->printOnWidget(highlighter, prefix);
        highlighter.print(",\n");
    }
    highlighter.print(prefix.data());
    instance_[instance_.size() - 1]->printOnWidget(highlighter, prefix);
    highlighter.print("\n}");
}

std::vector<std::unique_ptr<KeyValuePair>> &Object::getInstance(){
    return instance_;
}
