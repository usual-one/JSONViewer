#include "logic/include/utils/string_utils.h"

std::string mulString(std::string string, size_t number) {
    std::string product = "";
    for (size_t i = 0; i < number; i++) {
        product.append(string);
    }
    return product;
}
