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

void test_find_by_title() {
    Playlist p = init_playlist();

    add_song(&p, "first", "a");
    add_song(&p, "second", "b");
    add_song(&p, "third", "c");

    Song *p_first = p.p_first;
    Song *p_second = p_first->p_next;
    Song *p_third = p_second->p_next;

    assert(find_song_by_title(p, "first") == p_first);
    assert(find_song_by_title(p, "second") == p_second);
    assert(find_song_by_title(p, "third") == p_third);
    assert(find_song_by_title(p, "something else") == NULL);

    delete_playlist(&p);

    printf("test_find_by_title() passed\n");
}

void test_recursive_count() {
    Playlist p = init_playlist();

    assert(count_songs_recursive(p.p_first) == 0);

    add_song(&p, "a", "a");
    assert(count_songs_recursive(p.p_first) == 1);

    add_song(&p, "a", "a");
    assert(count_songs_recursive(p.p_first) == 2);

    add_song(&p, "a", "a");
    assert(count_songs_recursive(p.p_first) == 3);
    assert(count_songs_recursive(p.p_first->p_next) == 2);

    delete_playlist(&p);

    printf("test_recursive_count() passed\n");
}

void test_swap_songs_easy() {
    Playlist p = init_playlist();

    add_song(&p, "dummy", "dummy");
    add_song(&p, "first", "first");
    add_song(&p, "second", "second");
    add_song(&p, "last", "last");

    Song *p_first = p.p_first->p_next;
    Song *p_second = p_first->p_next;
    Song *p_third = p_second->p_next;

    swap_songs(&p, p_first, p_third);

    p_first = p.p_first->p_next;
    p_second = p_first->p_next;
    p_third = p_second->p_next;

    assert(strcmp(p.p_first->title, "dummy") == 0);
    assert(strcmp(p_first->title, "last") == 0);
    assert(strcmp(p_second->title, "second") == 0);
    assert(strcmp(p_third->title, "first") == 0);

    delete_playlist(&p);

    printf("test_swap_songs_easy() passed\n");
}

void test_swap_songs_first() {
    Playlist p = init_playlist();

    add_song(&p, "first", "first");
    add_song(&p, "second", "second");
    add_song(&p, "third", "third");
    add_song(&p, "last", "last");

    Song *p_first = p.p_first;
    Song *p_second = p_first->p_next;
    Song *p_third = p_second->p_next;
    Song *p_last = p_third->p_next;

    swap_songs(&p, p_first, p_third);

    p_first = p.p_first;
    p_second = p_first->p_next;
    p_third = p_second->p_next;
    p_last = p_third->p_next;

    assert(strcmp(p_first->title, "third") == 0);
    assert(strcmp(p_second->title, "second") == 0);
    assert(strcmp(p_third->title, "first") == 0);
    assert(strcmp(p_last->title, "last") == 0);

    delete_playlist(&p);

    printf("test_swap_songs_first() passed\n");
}

void test_swap_songs_neighbouring() {
    Playlist p = init_playlist();

    add_song(&p, "dummy", "dummy");
    add_song(&p, "first", "first");
    add_song(&p, "second", "second");

    Song *p_dummy = p.p_first;
    Song *p_first = p_dummy->p_next;
    Song *p_second = p_first->p_next;

    swap_songs(&p, p_first, p_second);

    p_dummy = p.p_first;
    p_first = p_dummy->p_next;
    p_second = p_first->p_next;

    assert(strcmp(p_dummy->title, "dummy") == 0);
    assert(strcmp(p_first->title, "second") == 0);
    assert(strcmp(p_second->title, "first") == 0);

    delete_playlist(&p);

    printf("test_swap_songs_neighbouring() passed\n");
}

void test_swap_songs_first_neighbouring() {
    Playlist p = init_playlist();

    add_song(&p, "first", "first");
    add_song(&p, "second", "second");
    add_song(&p, "last", "last");

    Song *p_first = p.p_first;
    Song *p_second = p_first->p_next;
    Song *p_third = p_second->p_next;

    swap_songs(&p, p_first, p_second);

    p_first = p.p_first;
    p_second = p_first->p_next;
    p_third = p_second->p_next;

    assert(strcmp(p_first->title, "second") == 0);
    assert(strcmp(p_second->title, "first") == 0);
    assert(strcmp(p_third->title, "last") == 0);

    delete_playlist(&p);

    printf("test_swap_songs_first_neighbouring() passed\n");
}

void test_sort_by_title() {
    Playlist p = init_playlist();

    add_song(&p, "aba", "b");
    add_song(&p, "aaa", "a");
    add_song(&p, "aea", "e");
    add_song(&p, "aca", "c");
    add_song(&p, "ada", "d");

    sort_playlist_by_title(&p);

    char *expected_titles[] = {
        "aaa",
        "aba",
        "aca",
        "ada",
        "aea",
    };
    int expected_titles_len = sizeof(expected_titles) / sizeof(expected_titles[0]);

    Song *p_song = p.p_first;
    char **pp_titles = expected_titles;

    while (p_song->p_next != NULL) {
        assert(strcmp(p_song->title, *(pp_titles++)) == 0);
        p_song = p_song->p_next;
    }

    delete_playlist(&p);

    printf("test_sort_by_title() passed\n");
}

void test_sort_stability() {
    Playlist p = init_playlist();

    add_song(&p, "b", "3");
    add_song(&p, "b", "4");
    add_song(&p, "a", "1");
    add_song(&p, "b", "5");
    add_song(&p, "a", "2");

    sort_playlist_by_title(&p);

    char *expected_titles[] = {
        "a",
        "a",
        "b",
        "b",
        "b",
    };
    char *expected_authors[] = {
        "1",
        "2",
        "3",
        "4",
        "5",
    };

    Song *p_song = p.p_first;
    char **pp_titles = expected_titles;
    char **pp_authors = expected_authors;

    while (p_song->p_next != NULL) {
        assert(strcmp(p_song->title, *(pp_titles++)) == 0);
        assert(strcmp(p_song->artist, *(pp_authors++)) == 0);
        p_song = p_song->p_next;
    }

    delete_playlist(&p);

    printf("test_sort_stability() passed\n");
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
    test_find_by_title();
    test_recursive_count();

    test_swap_songs_easy();
    test_swap_songs_first();
    test_swap_songs_neighbouring();
    test_swap_songs_first_neighbouring();

    test_sort_by_title();
    test_sort_stability();

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
