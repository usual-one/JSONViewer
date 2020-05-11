#include "logic/include/logic.h"
#include "logic/include/exception/FileException.h"
#include "logic/include/JSON_data_types/complex/Array.h"
#include "logic/include/JSON_data_types/complex/Object.h"
#include "logic/include/exception/JSONException.h"

#include <fstream>

std::string Operation::loadFile(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        throw FileOpeningException("can't open the file");
    }

    std::string file_text;
    file_text.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

    file.close();
    return file_text;
}

std::string Operation::parseJSON(const std::string &json_string)
{
    if (!json_string.size()) {
        return std::string("");
    }
    if (json_string[0] == '[') {
        Array json;
        json.fromStdString(json_string);
        return json.toStdString();
    }
    if (json_string[0] == '{') {
        Object json;
        json.fromStdString(json_string);
        return json.toStdString();
    }
    throw JSONException("unexpected character");
}

void Operation::saveFile(const std::string &path, const std::string &data)
{
    std::ofstream file(path);
    file.write(data.data(), data.size());
}
