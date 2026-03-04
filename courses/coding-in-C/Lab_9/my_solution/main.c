#include "include/playlist.h"
#include <stdio.h>
#include <playlist.h>

int main(void) {
    Playlist playlist = init_playlist();
    
    add_song(&playlist, "Crawling", "Linkin Park");
    add_song(&playlist, "Layla", "Eric Clapton");
    add_song(&playlist, "Esperanto", "Max Herre");
    add_song(&playlist, "Despacito", "despacito author");
    print_playlist(playlist);

    Song *p_find = find_song_by_title(playlist, "Esperanto");
    printf("Found song \"%s\" by %s\n", p_find->title, p_find->artist);

    int song_length = count_songs_recursive(playlist.p_first);
    printf("Song length (counted recursively): %d\n", song_length);

    sort_playlist_by_title(&playlist);
    printf("Playlist sorted:\n");
    print_playlist(playlist);

    delete_playlist(&playlist);

    return 0;
}
