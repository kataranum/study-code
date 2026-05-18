#include <exception>
#include <string>

class ExEmpty : public std::exception {};

class ExFileSuffix : public std::exception {};

class ExMissing : public std::exception {};

class ExInvalid : public std::exception {};

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

        // simulate missing file
        if (filename == "missing.cfg") {
            throw ExMissing();
        }

        // simulate system-specific misconfiguration
        if (filename == "invalid.cfg") {
            throw ExInvalid();
        }
    }
};
