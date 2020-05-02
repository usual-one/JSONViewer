#ifndef LOGICS_H
#define LOGICS_H

#include <string>

enum err_t {
    OK
};

class Operation {
public:
    std::string load_file(const std::string &path);
private:
};

#endif // LOGICS_H
