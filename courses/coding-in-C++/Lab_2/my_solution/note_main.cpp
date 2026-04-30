#include "note.hpp"

int main(void) {
    Note note_1 = Note("i am a note");
    Note note_2 = Note(note_1);
    
    // Leaving the copy constructor undefined causes a SegFault
    // probably because all fields are just copied from the passed object, so
    // the pointer *text points to the same place in both objects.
    // This then causes a double free

    note_1.display();
    note_2.display();

    return 0;
}
