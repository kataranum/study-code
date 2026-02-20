#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char *p_title;
    char *p_artist;
    struct Song *p_next;
} Song;

typedef struct {
    Song *p_first;
} Playlist;

char* alloc_string(const char *str) {
    char *ptr = malloc(strlen(str) + 1);
    if (ptr == NULL) {
        printf("malloc failure\n");
        exit(1);
    }

    strncpy(ptr, str, strlen(str));
    return ptr;
}

Playlist init_playlist(void) {
    Playlist playlist;
    playlist.p_first = NULL;

    return playlist;
}

void add_song(Playlist *p_playlist, const char *str_title, const char *str_artist) {
    char *p_title = alloc_string(str_title);
    char *p_artist = alloc_string(str_artist);

    Song *p_new = malloc(sizeof(Song));
    if (p_new == NULL) {
        printf("malloc failure\n");
        exit(1);
    }
    p_new->p_title = p_title;
    p_new->p_artist = p_artist;
    p_new->p_next = NULL;

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
        printf("Title: %s, Artist: %s\n", p_song->p_title, p_song->p_artist);

        p_song = p_song->p_next;
    }
}

void delete_song(Song *p_song) {
    free(p_song->p_title);
    free(p_song->p_artist);
    free(p_song);
}

void delete_firstSong(Playlist *p_playlist) {
    if (p_playlist->p_first == NULL) {
        return;
    }

    Song *p_second = p_playlist->p_first->p_next;
    delete_song(p_playlist->p_first);
    p_playlist->p_first = p_second;
}

void delete_playlist(Playlist *p_playlist) {
    Song *p_song = p_playlist->p_first;

    while (p_song != NULL) {
        Song *p_next = p_song->p_next;
        delete_song(p_song);
        p_song = p_next;
    }

    p_playlist->p_first = NULL;
}

int main(void) {
    Playlist playlist = init_playlist();
    add_song(&playlist, "Crawling", "Linkin Park");
    add_song(&playlist, "Layla", "Eric Clapton");
    add_song(&playlist, "Esperanto", "Max Herre");
    print_playlist(playlist);

    printf("After deletion:\n");
    delete_firstSong(&playlist);
    print_playlist(playlist);

    delete_playlist(&playlist);

    return 0;
}
