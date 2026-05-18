#include <exception>
#include <string>
#include <iostream>

class ExEmpty : public std::exception {};

class ExFileSuffix : public std::exception {};

class ExMissing : public std::exception {};

class ExInvalid : public std::exception {};

class ConfigLoader {
public:
    static void load(const std::string& filename) {
        if (filename.empty()) {
            throw ExEmpty();
        }

        if (filename.length() < 4 ||
            filename.substr(filename.length() - 4) != ".cfg") {
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

int main(void) {
    try {
        ConfigLoader::load("");
        std::cout << "(This should throw an exception)" << std::endl;
        return 1;
    }
    catch (const ExEmpty& e) {
        std::cout << "Error: Filename cannot be empty" << std::endl;
    }

    try {
        ConfigLoader::load("abc");
        std::cout << "(This should throw an exception)" << std::endl;
        return 1;
    }
    catch (const ExFileSuffix& e) {
        std::cout << "Error: File suffix is not .cfg" << std::endl;
    }

    try {
        ConfigLoader::load("missing.cfg");
        std::cout << "(This should throw an exception)" << std::endl;
        return 1;
    }
    catch (const ExMissing& e) {
        std::cout << "Error: Missing config file" << std::endl;
    }

    try {
        ConfigLoader::load("invalid.cfg");
        std::cout << "(This should throw an exception)" << std::endl;
        return 1;
    }
    catch (const ExInvalid& e) {
        std::cout << "Error: Invalid config" << std::endl;
    }

    try {
        ConfigLoader::load("normal.cfg");
        std::cout << "Normal config loaded successfully" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: This actually shouldn't trigger D:" << std::endl;
        return 1;
    }

    return 0;
}
