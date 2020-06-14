//
// Created by Aviv9 on 10/06/2020.
//

#ifndef DATASTRUCTURE_2_SPECIALKEYS_H
#define DATASTRUCTURE_2_SPECIALKEYS_H

/**
 * Song key that used to sort song according to num of streams
 * and then according to their songID
 */
typedef struct songKey_t{
    int song_id;
    int num_of_streams;
    songKey_t (int songid, int num_of_streams): song_id(songid), num_of_streams(num_of_streams){};
    songKey_t(): song_id(-1), num_of_streams(-1){};
    ~songKey_t() = default;
    songKey_t& operator= (songKey_t new_song_key);
    bool operator==(songKey_t song_key)const ;
    bool operator<(songKey_t song_key)const ;
    bool operator<=(songKey_t song_key)const ;
    bool operator>(songKey_t song_key)const ;
    bool operator>=(songKey_t song_key)const ;
    bool operator!=(songKey_t song_key)const ;
} SongKey;

/**
 * Artist Song key that used to sort song according to num of streams
 * and then according to their artistID and then according to their
 * songID
 */
typedef struct artistSongKey_t{
    int artist_id;
    int song_id;
    int num_of_streams;
    artistSongKey_t(int artistid, int songid, int num_of_streams) : artist_id(artistid), song_id(songid),
                                                                    num_of_streams(num_of_streams){};

    ~artistSongKey_t() = default;
    artistSongKey_t(): artist_id(-1), song_id(-1), num_of_streams(-1){};
    artistSongKey_t& operator= (artistSongKey_t new_artist_song_key);
    bool operator==(artistSongKey_t artist_song_key) const;
    bool operator<(artistSongKey_t artist_song_key) const;
    bool operator<=(artistSongKey_t artist_song_key) const;
    bool operator>(artistSongKey_t artist_song_key) const;
    bool operator>=(artistSongKey_t artist_song_key) const;
    bool operator!=(artistSongKey_t artist_song_key) const;
} ArtistSongKey;


#endif //DATASTRUCTURE_2_SPECIALKEYS_H
