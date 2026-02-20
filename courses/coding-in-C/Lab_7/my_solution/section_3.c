#include <stdio.h>

typedef struct {
    char *p_title;
    char *p_artist;
    struct Song *p_next;
} Song;

typedef struct {
    Song *p_first;
} Playlist;

Playlist init_playlist(void) {
    Playlist playlist;
    playlist.p_first = NULL;

    return playlist;
}

int main(void) {
    return 0;
}
