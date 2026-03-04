#include <playlist.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------
//  PRIVATE FUNCTIONS
// -------------------

/**
 * @brief Allocate a new string on the heap
 * 
 * @param  str Content of new string
 * @return     Pointer to new string
 */
char* alloc_string(const char *str) {
    char *ptr = malloc(strlen(str) + 1);
    if (ptr == NULL) {
        printf("malloc failure\n");
        exit(1);
    }

    strcpy(ptr, str);
    return ptr;
}

/**
 * @brief Free memory of an allocated `Song` struct
 *
 * WARNING: `Song` is supposed to be a part of a linked list, this function does
 * not alter anything of this list, so just calling this function on a list
 * entry will mess up the list.
 * 
 * @param p_song Pointer to `Song` to delete
 */
void delete_song(Song *p_song) {
    free(p_song->title);
    free(p_song->artist);
    free(p_song);
}

// ------------------
//  PUBLIC FUNCTIONS
// ------------------

Playlist init_playlist(void) {
    Playlist playlist;
    playlist.p_first = NULL;
    playlist.length = 0;

    return playlist;
}

void delete_playlist(Playlist *p_playlist) {
    Song *p_song = p_playlist->p_first;

    while (p_song != NULL) {
        Song *p_next = p_song->p_next;
        delete_song(p_song);
        p_song = p_next;
    }

    p_playlist->p_first = NULL;
    p_playlist->length = 0;
}

void add_song(Playlist *p_playlist, const char *str_title, const char *str_artist) {
    if (p_playlist->length >= MAX_SONGS) {
        printf("Cannot add more songs to playlist.\n");
        return;
    }

    char *title = alloc_string(str_title);
    char *artist = alloc_string(str_artist);

    Song *p_new = malloc(sizeof(Song));
    if (p_new == NULL) {
        printf("malloc failure\n");
        exit(1);
    }
    p_new->title = title;
    p_new->artist = artist;
    p_new->p_next = NULL;

    p_playlist->length++;

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

void delete_firstSong(Playlist *p_playlist) {
    if (p_playlist->p_first == NULL) {
        return;
    }

    Song *p_second = p_playlist->p_first->p_next;
    delete_song(p_playlist->p_first);
    p_playlist->p_first = p_second;
    p_playlist->length--;
}

void print_playlist(Playlist playlist) {
    Song *p_song = playlist.p_first;

    while (p_song != NULL) {
        printf("Title: %s, Artist: %s\n", p_song->title, p_song->artist);

        p_song = p_song->p_next;
    }
}

Song* find_song_by_title(Playlist playlist, const char *title) {
    Song *p_song = playlist.p_first;

    while (p_song != NULL) {
        if (strcmp(title, p_song->title) == 0) {
            return p_song;
        }

        p_song = p_song->p_next;
    }

    return NULL;
}

int count_songs_recursive(const Song *current) {
    
}
