#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS 999

/**
 * @brief An entry in the `Playlist` linked list
 */
typedef struct Song {
    char *title;
    char *artist;
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
 * @param title  Title of new song
 * @param artist Artist of new song
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

/**
 * @brief Get a pointer to the previous song
 *
 * Returns NULL if the given song is the first in the playlist, or if the
 * playlist doesn't contain the song at all.
 * 
 * @param playlist Given playlist
 * @param song Song to return previous Song of
 * @return Song* Previous song
 */
Song* access_previous(Playlist playlist, const Song *song);

/**
 * @brief Try to find a song with the given title and return a pointer to it
 *
 * Performs a linear search, matching every song with the given title until
 * the correct one is found and returned.
 *
 * Returns NULL in case no match was found
 * 
 * @param playlist Given playlist
 * @param title    Title to search for
 * @return Song*   Pointer to Song with matching title
 */
Song* find_song_by_title(Playlist playlist, const char *title);

/**
 * @brief Recursively count how many songs come after the current
 * 
 * @param current Current song
 * @return int    Amount of following songs, including current
 */
int count_songs_recursive(const Song *current);

/**
 * @brief Use insertion sort to sort the given playlist alphabetically by title
 * 
 * @param playlist Playlist to sort
 */
void sort_playlist_by_title(Playlist *playlist);

#endif
