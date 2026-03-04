#include <stdio.h>
#include <playlist.h>

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
