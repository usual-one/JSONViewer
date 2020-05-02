#include "logics/include/logics.h"
#include "logics/include/exception/FileException.h"

#include <fstream>

std::string Operation::load_file(const std::string &path)
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
