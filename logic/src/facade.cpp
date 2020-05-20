#include "logic/include/facade.h"
#include "logic/include/JSON_data_types/complex/Array.h"
#include "logic/include/JSON_data_types/complex/Object.h"
#include "logic/include/exception/JSON_DT/DT_exception_headers.h"
#include "config.h"

Facade::Facade() {
    has_mistake_ = false;
}

TextMistake Facade::checkJSONMistakes(const std::string &json) {
    TextMistake mistake(NO_MISTAKES_MESSAGE, {0, 0});
    has_mistake_ = true;

    try {
        json_ = parseJSON(json);
        has_mistake_ = false;
    } catch (ArrayException &err) {
        mistake.setMessage(ARRAY_MISTAKE_MESSAGE + ": " + err.what());
        mistake.setPosition(err.getPosition());
    } catch (ObjectException &err) {
        mistake.setMessage(OBJECT_MISTAKE_MESSAGE + ": " + err.what());
        mistake.setPosition(err.getPosition());
    } catch (BooleanException &err) {
        mistake.setMessage(BOOLEAN_MISTAKE_MESSAGE + ": " + err.what());
        mistake.setPosition(err.getPosition());
    } catch (NullException &err) {
        mistake.setMessage(NULL_MISTAKE_MESSAGE + ": " + err.what());
        mistake.setPosition(err.getPosition());
    } catch (NumberException &err) {
        mistake.setMessage(NUMBER_MISTAKE_MESSAGE + ": " + err.what());
        mistake.setPosition(err.getPosition());
    } catch (StringException &err) {
        mistake.setMessage(STRING_MISTAKE_MESSAGE + ": " + err.what());
        mistake.setPosition(err.getPosition());
    } catch (JSONException &err) {
        mistake.setMessage(JSON_MISTAKE_MESSAGE + ": " + err.what());
        mistake.setPosition(err.getPosition());
    } catch (std::exception &err) {
        mistake.setMessage(UNKNOWN_MISTAKE_MESSAGE + ": " + err.what());
    }

    return mistake;
}

std::vector<TextElement> Facade::convertJSONToTextElements() {
    if (!json_) {
        throw JSONException("JSON is empty");
    }
    return json_->toTextElements(Indent());
}

bool Facade::hasMistake() {
    return has_mistake_;
}

std::string Facade::load(const std::string &path) {
    return file_dispatcher_.read(path);
}

void Facade::openNew() {
    file_dispatcher_.clear();
}

bool Facade::pathSet() {
    return file_dispatcher_.hasPath();
}

void Facade::save(const std::string &data) {
    file_dispatcher_.write(data);
}

void Facade::saveTo(const std::string &path, const std::string &data) {
    file_dispatcher_.writeTo(path, data);
}

std::shared_ptr<JSONDT> Facade::parseJSON(const std::string &json_string)
{
    if (!json_string.size()) {
        return nullptr;
    }
    if (json_string[0] == '[') {
        auto json = std::make_shared<Array>();
        json->fromStdString(json_string);
        return json;
    }
    if (json_string[0] == '{') {
        auto json = std::make_shared<Object>();
        json->fromStdString(json_string);
        return json;
    }
    throw JSONException("unexpected character");
}
