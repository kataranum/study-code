#include "note.hpp"

int main(void) {
    Note note_1 = Note("i am a note");
    Note note_2 = Note(note_1);

    note_1.display();
    note_2.display();

    return 0;
}
