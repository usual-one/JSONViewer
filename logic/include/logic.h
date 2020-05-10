#ifndef LOGICS_H
#define LOGICS_H

#include <string>

enum err_t {
    OK
};

class Operation {
public:
    std::string loadFile(const std::string &path);

    std::string parseJSON(const std::string &json_string);
private:
};

#endif // LOGICS_H
