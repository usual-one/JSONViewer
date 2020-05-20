#ifndef LOGICS_H
#define LOGICS_H

#include <string>
#include <memory>

#include "logic/include/JSON_data_types/JSONDT.h"
#include "logic/include/files/filedispatcher.h"
#include "logic/include/textmistake.h"

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

    bool has_mistake_;

    std::shared_ptr<JSONDT> json_;
};

#endif // LOGICS_H
