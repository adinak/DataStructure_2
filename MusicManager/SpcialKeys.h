//
// Created by Aviv9 on 10/06/2020.
//

#ifndef DATASTRUCTURE_2_SPCIALKEYS_H
#define DATASTRUCTURE_2_SPCIALKEYS_H


typedef struct songKey_t{
    int songid;
    int num_of_streams;
    songKey_t (int songid, int num_of_streams):songid(songid), num_of_streams(num_of_streams){};
    songKey_t():songid(-1), num_of_streams(-1){};
    ~songKey_t() = default;
    songKey_t& operator= (songKey_t new_song_key);
    bool operator==(songKey_t song_key)const ;
    bool operator<(songKey_t song_key)const ;
    bool operator<=(songKey_t song_key)const ;
    bool operator>(songKey_t song_key)const ;
    bool operator>=(songKey_t song_key)const ;
    bool operator!=(songKey_t song_key)const ;
} SongKey;

typedef struct artistSongKey_t{
    int artistid;
    int songid;
    int num_of_streams;
    artistSongKey_t(int artistid, int songid, int num_of_streams) : artistid(artistid), songid(songid),
                                                                    num_of_streams(num_of_streams){};

    ~artistSongKey_t() = default;
    artistSongKey_t():artistid(-1),songid(-1), num_of_streams(-1){};
    artistSongKey_t& operator= (artistSongKey_t new_artist_song_key);
    bool operator==(artistSongKey_t artist_song_key) const;
    bool operator<(artistSongKey_t artist_song_key) const;
    bool operator<=(artistSongKey_t artist_song_key) const;
    bool operator>(artistSongKey_t artist_song_key) const;
    bool operator>=(artistSongKey_t artist_song_key) const;
    bool operator!=(artistSongKey_t artist_song_key) const;
} ArtistSongKey;


#endif //DATASTRUCTURE_2_SPCIALKEYS_H
