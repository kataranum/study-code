#include <stdio.h>

void print_ascii_art();

int main(void) {
    print_ascii_art();

    return 0;
}

void print_ascii_art() {
    printf("\
   X         X      XXXXXXXXXX                 X                   XXXXXXX   \n \
   X         X      X              X           X                  XX      X  \n \
   XX        X      X              X           X                 XX       XX \n \
    XXXXXXXXXXX     XXXXXXXX       X           X                 X         X \n \
    X         X     X              X           X                 XX        XX\n \
    XX        X     X              X           X                  XXX    XXX \n \
    XX       XX     X          X    X   XXXXX  XXX                   XXXXX   \n \
    X        X      XXXXXXXXXXXX    XXX            XX XXXXXX                 \n \
    X                                                                        \n \
                                                       XXXXX        XX       \n \
X   XX    X   XXXXXXXXX      XXXXX      X              X   XXX       X       \n \
X   XX   XX  X        X      X   X       X             X      X      X       \n \
X   XX  XX   X         X     XXXX        XX            X      XX     X       \n \
 X  XXX X    X         X     XXX          X            X      X      X       \n \
  X   X X    XX        X     X X X        X            X    XX       X       \n \
  X   XX      XXX    XXX     X   XX       X  XXXXX     XXXXX                 \n \
   X              XXXX            XXX     XXX                      XXXX      \n \
                                     XX                             XXXX     \n");
}
