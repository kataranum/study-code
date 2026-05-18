#include <exception>
#include <string>

class ExEmpty : public std::exception {

};

class ExFileSuffix : public std::exception {

};

class ConfigLoader {
public:
    void load(std::string filename) {
        if (filename.empty()) {
            throw ExEmpty();
        }

        std::string expected_end = ".cfg";
        if (!filename.compare(
                filename.length() - expected_end.length(),
                expected_end.length(),
                expected_end  
        )) {
            throw ExFileSuffix();
        }
    }
};
