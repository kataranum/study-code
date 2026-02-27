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

Playlist init_playlist(void);
void delete_playlist(Playlist *p_playlist);

void add_song(Playlist *p_playlist, const char *str_title, const char *str_artist);
void delete_firstSong(Playlist *p_playlist);

void print_playlist(Playlist playlist);

#endif
