#ifndef LOGICS_H
#define LOGICS_H

#include <string>
#include <memory>

#include "logic/include/json/jsonparser.h"
#include "logic/include/files/filedispatcher.h"
#include "logic/include/text/textmistake.h"

class Facade {
public:
    Facade();

    TextMistake checkJSONMistakes(const std::string &json);

    std::vector<TextElement> convertJSONToTextElements();

    bool hasMistake();

    std::string load(const std::string &path);

    void openNew();

    bool pathSet();

    void save(const std::string &data);

    void saveTo(const std::string &path, const std::string &data);

    std::shared_ptr<JSONDT> parseJSON(const std::string &json_string);

private:
    FileDispatcher file_dispatcher_;

    JSONParser json_parser_;

    std::shared_ptr<JSONDT> json_;

    bool has_mistake_;
};

#endif // LOGICS_H
