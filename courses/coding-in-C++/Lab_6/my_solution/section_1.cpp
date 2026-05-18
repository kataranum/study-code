#include <exception>
#include <string>

class ExMissing : public std::exception {

};

class ExInvalid : public std::exception {

};

class ConfigLoader {
public:
    void load(std::string filename) {
        if (filename.empty()) {
            throw ExMissing();
        }
    }
};
