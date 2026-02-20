#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char *p_title;
    char *p_artist;
    struct Song *p_next;
} typedef Song;

typedef struct {
    Song *p_first;
} Playlist;

Playlist init_playlist(void) {
    Playlist playlist;
    playlist.p_first = NULL;

    return playlist;
}

void add_song(Playlist *p_playlist, const char *str_title, const char *str_artist) {
    char *p_title = malloc(strlen(str_title) + 1);
    strncpy(p_title, str_title, strlen(str_title));

    char *p_artist = malloc(strlen(str_artist) + 1);
    strncpy(p_artist, str_artist, strlen(str_artist));

    Song *p_new = malloc(sizeof(Song));
    p_new->p_title = p_title;
    p_new->p_artist = p_artist;
    p_new->p_next = NULL;

    if (!p_title || !p_artist || !p_new) {
        printf("malloc failure\n");
        exit(1);
    }

    if (p_playlist->p_first == NULL) {
        p_playlist->p_first = p_new;
        return;
    }

    Song *p_last = p_playlist->p_first;
    while (p_last->p_next != NULL) {
        p_last = p_last->p_next;
    }

    p_last->p_next = p_new;
}

void print_playlist(Playlist playlist) {
    Song *p_song = playlist.p_first;

    while (p_song != NULL) {
        printf("\"%s\"\n", p_song->p_title);
        printf("from %s\n", p_song->p_artist);
        printf("\n");

        p_song = p_song->p_next;
    }
}

int main(void) {
    return 0;
}
