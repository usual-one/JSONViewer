#include "logic/include/files/filedispatcher.h"
#include "logic/include/files/fileexception.h"

#include <fstream>

FileDispatcher::FileDispatcher() {
    current_path_.clear();
}

void FileDispatcher::clear() {
    current_path_.clear();
}

bool FileDispatcher::hasPath() {
    return current_path_.size();
}

std::string FileDispatcher::read(const std::string &path) {
    current_path_ = path;

    std::ifstream file(path);
    if (!file.is_open()) {
        throw FileOpeningException("can't open the file");
    }

    std::string file_text;
    file_text.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

    file.close();
    return file_text;
}

void FileDispatcher::writeTo(const std::string &path, const std::string &data) {
    current_path_ = path;
    std::ofstream file(path);
    file.write(data.data(), data.size());
    file.close();
}

void FileDispatcher::write(const std::string &data) {
    std::ofstream file(current_path_);
    file.write(data.data(), data.size());
    file.close();
}
