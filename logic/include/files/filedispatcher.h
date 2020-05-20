#ifndef FILEDISPATCHER_H
#define FILEDISPATCHER_H

#include <string>

class FileDispatcher {
public:
    FileDispatcher();

    void clear();

    bool hasPath();

    std::string read(const std::string &path);

    void writeTo(const std::string &path, const std::string &data);

    void write(const std::string &data);

private:
    std::string current_path_;
};

#endif // FILEDISPATCHER_H
