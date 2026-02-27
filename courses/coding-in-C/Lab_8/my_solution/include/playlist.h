#ifndef PLAYLIST_H
#define PLAYLIST_H

/**
 * @brief An entry in the `Playlist` linked list
 */
typedef struct Song {
    char *p_title;
    char *p_artist;
    struct Song *p_next;
} Song;

/**
 * @brief A linked list of multiple `Song` structs
 */
typedef struct {
    Song *p_first;
} Playlist;

#endif
