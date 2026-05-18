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

        std::string expected_end = ".cfg";
        if (!filename.compare(
                filename.length() - expected_end.length(),
                expected_end.length(),
                expected_end  
        )) {
            throw ExInvalid();
        }
    }
};
