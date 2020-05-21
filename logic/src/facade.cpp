#include "logic/include/facade.h"
#include "logic/include/json/data_types/complex/array.h"
#include "logic/include/json/data_types/complex/object.h"
#include "logic/include/json/exception/dt_exception_headers.h"
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

std::shared_ptr<JSONDT> Facade::parseJSON(const std::string &json_string) {
    return json_parser_.parse(json_string);
}
