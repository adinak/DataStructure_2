//
// Created by Adina Katz on 10/06/2020.
//

#ifndef DATASTRUCTURE_2_ARTIST_H
#define DATASTRUCTURE_2_ARTIST_H

#include <cmath>
#include "RankTree.h"
#include "SpecialKeys.h"

typedef enum {A_SUCCESS , A_FAIL, A_SONG_ALREADY_EXISTS, A_SONG_DOES_NOT_EXIST}
ArtistResult;

class Artist{
private:
    int artist_id;
    int best_song_id;
    int best_song_streams;
    RankTree<int, int>* songs_id;
    RankTree<SongKey , int>* songs_streams;

public:
    Artist(int id);
    Artist();
    ~Artist();
    int getArtistId() const;
    int getArtistBestSong() const;
    bool isSong(int song_id);
    int getNumOfSongs();
    ArtistResult addSong(int song_id, int count = 0);
    ArtistResult deleteSong(int song_id);
    int getNumOfStreams(int song_id);
    ArtistResult artistAddToSongCount(int song_id, int count);
};

#endif //DATASTRUCTURE_2_ARTIST_H
