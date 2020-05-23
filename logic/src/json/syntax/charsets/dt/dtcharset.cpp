#include "logic/include/json/syntax/charsets/dt/dtcharset.h"
#include "logic/include/json/syntax/charsets/dt/numbercharset.h"
#include "logic/include/json/syntax/charsets/dt/arraycharset.h"
#include "logic/include/json/syntax/charsets/dt/objectcharset.h"
#include "logic/include/json/syntax/charsets/dt/stringcharset.h"
#include "logic/include/json/syntax/charsets/dt/booleancharset.h"
#include "logic/include/json/syntax/charsets/dt/nullcharset.h"
#include "logic/include/json/exception/jsonexception.h"
#include "logic/include/json/data_types/dt_headers.h"

bool DTCharSet::startsLike(const std::string &other, DTName dt) {
    if (dt == ARRAY_DT) {
        return other.size() >= ArrayCharSet::getBorders()[0].size() &&
                !other.compare(0, ArrayCharSet::getBorders()[0].size(), ArrayCharSet::getBorders()[0]);
    } else if (dt == OBJECT_DT) {
        return other.size() >= ObjectCharSet::getBorders()[0].size() &&
                !other.compare(0, ObjectCharSet::getBorders()[0].size(), ObjectCharSet::getBorders()[0]);
    } else if (dt == BOOLEAN_DT) {
        return other.size() &&
                (other[0] == BooleanCharSet::getTrue()[0] || other[0] == BooleanCharSet::getFalse()[0]);
    } else if (dt == NULL_DT) {
        return other.size() && (other[0] == NullCharSet::toStdString()[0]);
    } else if (dt == NUMBER_DT) {
        return other.size() && NumberCharSet::isInside(other[0]);
    } else if (dt == STRING_DT) {
        return other.size() >= StringCharSet::getBorder().size() &&
                !other.compare(0, StringCharSet::getBorder().size(), StringCharSet::getBorder());
    }
    return false;
}

bool DTCharSet::endsLike(const std::string &other, DTName dt) {
    if (dt == ARRAY_DT) {
        return other.size() >= ArrayCharSet::getBorders()[1].size() &&
                !other.compare(other.size() - ArrayCharSet::getBorders()[1].size(),
                other.size(), ArrayCharSet::getBorders()[1]);
    } else if (dt == OBJECT_DT) {
        return other.size() >= ObjectCharSet::getBorders()[1].size() &&
                !other.compare(other.size() - ObjectCharSet::getBorders()[1].size(),
                other.size(), ObjectCharSet::getBorders()[1]);
    } else if (dt == BOOLEAN_DT) {
        return other.size() &&
                (other[other.size() - 1] == BooleanCharSet::getTrue()[BooleanCharSet::getTrue().size() - 1] ||
                other[other.size() - 1] == BooleanCharSet::getFalse()[BooleanCharSet::getFalse().size() - 1]);
    } else if (dt == NULL_DT) {
        return other.size() &&
                (other[other.size() - 1] == NullCharSet::toStdString()[NullCharSet::toStdString().size() - 1]);
    } else if (dt == NUMBER_DT) {
        return other.size() && NumberCharSet::isInside(other[other.size() - 1]);
    } else if (dt == STRING_DT) {
        return other.size() >= StringCharSet::getBorder().size() &&
                !other.compare(other.size() - StringCharSet::getBorder().size(), other.size(), StringCharSet::getBorder());
    }
    return false;
}

bool DTCharSet::canBeStart(char other) {
    return other == ArrayCharSet::getBorders()[0][0] ||
            other == ObjectCharSet::getBorders()[0][0] ||
            other == BooleanCharSet::getTrue()[0] ||
            other == BooleanCharSet::getFalse()[0] ||
            other == NullCharSet::toStdString()[0] ||
            other == StringCharSet::getBorder()[0] ||
            NumberCharSet::isInside(other);
}

std::unique_ptr<JSONDT> DTCharSet::createDTFromStart(const std::string &other) {
    if (startsLike(other, ARRAY_DT)) {
        return std::make_unique<Array>();
    } else if (startsLike(other, OBJECT_DT)) {
        return std::make_unique<Object>();
    } else if (startsLike(other, STRING_DT)) {
        return std::make_unique<String>();
    } else if (startsLike(other, BOOLEAN_DT)) {
        return std::make_unique<Boolean>();
    } else if (startsLike(other, NULL_DT)) {
        return std::make_unique<Null>();
    } else if (startsLike(other, NUMBER_DT)) {
        return std::make_unique<Number>();
    }
    throw JSONException("nothing to create");
}
