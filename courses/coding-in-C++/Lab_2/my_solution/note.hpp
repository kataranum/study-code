#include <string>

class Note {
private:
    std::string* text;

public:
    Note(const std::string& text);
    Note(const Note& note);
    ~Note();

    void display();
};
