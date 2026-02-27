#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <playlist.h>

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist p = init_playlist();

    assert(p.p_first == NULL);
    assert(p.length == 0);

    delete_playlist(&p);

    printf("test_init_playlist() passed\n");
}

void test_add_song(void)
{
    Playlist p = init_playlist();

    add_song(&p, "Song title", "Song artist");
    add_song(&p, "Amazing\nMulti\nSong\n", "Amazing\nPerson");
    add_song(&p, "", "");

    Song *p_song = p.p_first;
    assert(strcmp(p_song->p_title, "Song title") == 0);
    assert(strcmp(p_song->p_artist, "Song artist") == 0);

    p_song = p_song->p_next;
    assert(strcmp(p_song->p_title, "Amazing\nMulti\nSong\n") == 0);
    assert(strcmp(p_song->p_artist, "Amazing\nPerson") == 0);

    p_song = p_song->p_next;
    assert(strcmp(p_song->p_title, "") == 0);
    assert(strcmp(p_song->p_artist, "") == 0);

    assert(p_song->p_next == NULL);

    delete_playlist(&p);

    printf("test_add_song() passed\n");
}

void test_delete_firstSong(void)
{
    Playlist p = init_playlist();

    add_song(&p, "1", "artist1");
    add_song(&p, "2", "artist2");

    Song *p_song = p.p_first;
    printf("p_song title: '%s'\n", p_song->p_title);
    assert(strcmp(p_song->p_title, "1") == 0);

    delete_firstSong(&p);
    p_song = p.p_first;
    assert(strcmp(p_song->p_title, "2") == 0);

    delete_firstSong(&p);
    p_song = p.p_first;
    assert(p_song == NULL);

    delete_playlist(&p);

    printf("test_delete_firstSong() passed\n");
}

/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    //test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    //test_delete_playlist();
    //test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
