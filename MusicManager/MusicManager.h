//
// Created by aviv on 6/10/2020.
//

#ifndef DATASTRUCTURE_2_MUSICMANAGER_H
#define DATASTRUCTURE_2_MUSICMANAGER_H

#include "../RankTree/RankTree.h"
#include "../HashTable/HashTable.h"
typedef struct songKey_t{
    int songid;
    int num_of_streams;
    songKey_t (int songid, int num_of_streams):songid(songid), num_of_streams(num_of_streams){}
    ~songKey_t() = default;
    bool operator==(songKey_t song_key);
    bool operator<(songKey_t song_key);
    bool operator<=(songKey_t song_key);
    bool operator>(songKey_t song_key);
    bool operator>=(songKey_t song_key);
    bool operator!=(songKey_t song_key);
} SongKey;

typedef struct artistSongKey_t{
    int artistid;
    int songid;
    int num_of_streams;
    artistSongKey_t (int songid, int num_of_streams):artistid(artistid),songid(songid),
                                                        num_of_streams(num_of_streams){}
    ~artistSongKey_t() = default;
    bool operator==(artistSongKey_t artist_song_key);
    bool operator<(artistSongKey_t artist_song_key);
    bool operator<=(artistSongKey_t artist_song_key);
    bool operator>(artistSongKey_t artist_song_key);
    bool operator>=(artistSongKey_t artist_song_key);
    bool operator!=(artistSongKey_t artist_song_key);
} ArtistSongKey;

class MusicManager {
private:

};


#endif //DATASTRUCTURE_2_MUSICMANAGER_H
