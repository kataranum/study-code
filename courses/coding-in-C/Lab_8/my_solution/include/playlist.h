#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS 999

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
    int length;
} Playlist;

/**
 * @brief Create a new empty playlist
 * 
 * @return New empty playlist
 */
Playlist init_playlist(void);

/**
 * @brief Delete all entries of the given playlist
 * 
 * @param p_playlist Given playlist
 */
void delete_playlist(Playlist *p_playlist);

/**
 * @brief Add a new song with the given attributes to the end of `Playlist`
 * 
 * @param p_playlist Playlist to append to
 * @param str_title  Title of new song
 * @param str_artist Artist of new song
 */
void add_song(Playlist *p_playlist, const char *str_title, const char *str_artist);

/**
 * @brief Delete the first song of the given playlist
 * 
 * @param p_playlist Given playlist
 */
void delete_firstSong(Playlist *p_playlist);

/**
 * @brief Print all entries of playlist
 * 
 * @param playlist Playlist to print
 */
void print_playlist(Playlist playlist);

#endif
