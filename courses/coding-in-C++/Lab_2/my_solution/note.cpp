#include "note.hpp"
#include <iostream>

Note::Note(const std::string& text) {
    this->text = new std::string(text);
}

Note::Note(const Note& note) {
    this->text = new std::string(*note.text);
}

Note::~Note() {
    delete this->text;
    this->text = nullptr; // is this really necessary?

    std::cout << "Memory released" << std::endl;
}

void Note::display() {
    std::cout << *this->text << std::endl;
}
