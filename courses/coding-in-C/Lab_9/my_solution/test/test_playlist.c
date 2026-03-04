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
    assert(p.length == 1);

    add_song(&p, "Amazing\nMulti\nSong\n", "Amazing\nPerson");
    assert(p.length == 2);

    add_song(&p, "", "");
    assert(p.length == 3);

    Song *p_song = p.p_first;
    assert(strcmp(p_song->title, "Song title") == 0);
    assert(strcmp(p_song->artist, "Song artist") == 0);

    p_song = p_song->p_next;
    assert(strcmp(p_song->title, "Amazing\nMulti\nSong\n") == 0);
    assert(strcmp(p_song->artist, "Amazing\nPerson") == 0);

    p_song = p_song->p_next;
    assert(strcmp(p_song->title, "") == 0);
    assert(strcmp(p_song->artist, "") == 0);

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
    assert(strcmp(p_song->title, "1") == 0);
    assert(p.length == 2);

    delete_firstSong(&p);
    p_song = p.p_first;
    assert(strcmp(p_song->title, "2") == 0);
    assert(p.length == 1);

    delete_firstSong(&p);
    p_song = p.p_first;
    assert(p_song == NULL);
    assert(p.length == 0);

    delete_playlist(&p);

    printf("test_delete_firstSong() passed\n");
}

void test_delete_firstSong_empty(void)
{
    Playlist p = init_playlist();

    // "Delete" first song in an empty playlist
    delete_firstSong(&p);

    assert(p.p_first == NULL);
    assert(p.length == 0);

    delete_playlist(&p);

    printf("test_delete_firstSong_empty() passed\n");
}

void test_delete_playlist(void)
{
    Playlist p = init_playlist();

    add_song(&p, "first song", "first artist");
    add_song(&p, "second song", "second artist");

    delete_playlist(&p);
    assert(p.p_first == NULL);
    assert(p.length == 0);

    // Deleting an already "deleted" playlist should do nothing
    delete_playlist(&p);
    assert(p.p_first == NULL);
    assert(p.length == 0);

    printf("test_delete_playlist() passed\n");
}

void test_max_songs_limit() {
    Playlist p = init_playlist();

    // Fill playlist to max
    for (int i = 0; i < MAX_SONGS; i++) {
        char str_title[16];
        char str_artist[16];

        sprintf(str_title, "song %d", i);
        sprintf(str_artist, "artist %d", i);

        add_song(&p, str_title, str_artist);
    }

    // store expected title and artist of last song
    char expected_title[16];
    char expected_artist[16];

    sprintf(expected_title, "song %d", MAX_SONGS - 1);
    sprintf(expected_artist, "artist %d", MAX_SONGS - 1);

    // find last song
    Song *p_last = p.p_first;
    while (p_last->p_next != NULL) {
        p_last = p_last->p_next;
    }

    // do assertions
    assert(strcmp(p_last->title, expected_title) == 0);
    assert(strcmp(p_last->artist, expected_artist) == 0);
    assert(p.length == MAX_SONGS);

    // try adding another song, shouldn't add
    add_song(&p, "unnecessary song", "i really don't want to be here");
    assert(p_last->p_next == NULL);
    assert(p.length == MAX_SONGS);

    delete_playlist(&p);

    printf("test_max_songs_limit() passed\n");
}

void test_access_previous() {
    Playlist p = init_playlist();

    add_song(&p, "first title", "first author");
    add_song(&p, "second title", "second_author");
    add_song(&p, "third song", "third author");

    Song *p_first = p.p_first;
    Song *p_second = p_first->p_next;
    Song *p_third = p_second->p_next;

    assert(access_previous(p, p_third) == p_second);
    assert(access_previous(p, p_second) == p_first);
    assert(access_previous(p, p_first) == NULL);

    delete_playlist(&p);

    printf("test_access_previous() passed\n");
}

/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed
    test_access_previous();

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
