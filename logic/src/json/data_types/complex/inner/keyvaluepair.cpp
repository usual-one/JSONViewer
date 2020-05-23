#include "logic/include/json/data_types/complex/inner/keyvaluepair.h"
#include "logic/include/json/exception/keyvaluepairexception.h"
#include "logic/include/json/data_types/dt_headers.h"
#include "logic/include/utils/string_utils.h"
#include "logic/include/json/syntax/single_elements/lineseparator.h"
#include "logic/include/json/syntax/single_elements/keyvalueseparator.h"
#include "logic/include/json/syntax/single_elements/spacesyntaxelement.h"
#include "logic/include/json/syntax/charsets/dt/dtcharset.h"
#include "logic/include/json/syntax/charsets/ignoredcharset.h"

KeyValuePair::KeyValuePair() {
    key_ = nullptr;
    value_ = nullptr;
}

size_t KeyValuePair::fromStdString(const std::string &string) {
    key_ = std::make_unique<String>();
    key_->setBeginPos(getBeginPos());
    size_t key_consumed = key_->fromStdString(string);

    setEndPos(key_->getEndPos());

    size_t separator_pos = string.size();
    for (size_t i = key_consumed; i < string.size(); i++) {
        getEndPos().nextCharacter();
        if (LineSeparator::isEqual(string[i])) {
            getEndPos().nextLine();
        } else if (IgnoredCharSet::isInside(string[i])) {
            continue;
        } else if (KeyValueSeparator::isEqual(string[i])) {
            separator_pos = i;
            break;
        } else {
            throw KeyValuePairUnexpectedException(string[i], getEndPos());
        }
    }

    if (separator_pos == string.size()) {
        throw KeyValuePairNoSeparatorException("separator not found", getEndPos());
    }

    size_t char_consumed = separator_pos + 1;

    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().nextCharacter();
        if (DTCharSet::canBeStart(string[i])) {
            value_ = DTCharSet::createDTFromStart(string.substr(i));
            value_->setBeginPos(getEndPos());
            char_consumed = i + value_->fromStdString(string.substr(i));
            setEndPos(value_->getEndPos());
            break;
        } else if (LineSeparator::isEqual(string[i])) {
            getEndPos().nextLine();
        } else if (IgnoredCharSet::isInside(string[i])) {
            continue;
        } else {
            throw KeyValuePairUnexpectedException(string[i], getEndPos());
        }
    }

    if (!value_) {
        throw KeyValuePairNoValueException("no value found", getEndPos());
    }

    return char_consumed;
}

std::string KeyValuePair::toStdString() {
    return key_->toStdString() + KeyValueSeparator::toStdString() +
            SpaceSyntaxElement::toStdString() + value_->toStdString();
}

std::vector<TextElement> KeyValuePair::toTextElements(Indent indent) {
    std::vector<TextElement> elements = {};
    elements.push_back(TextElement(key_->toStdString(), indent, KEY_F));
    elements.push_back(TextElement(KeyValueSeparator::toStdString() + SpaceSyntaxElement::toStdString()));

    std::vector value_elements = value_->toTextElements(Indent("", "", indent.own_));
    elements.insert(elements.end(), value_elements.begin(), value_elements.end());
    return elements;
}
