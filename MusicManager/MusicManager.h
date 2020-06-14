//
// Created by aviv on 6/10/2020.
//

#ifndef DATASTRUCTURE_2_MUSICMANAGER_H
#define DATASTRUCTURE_2_MUSICMANAGER_H

#include "Artist.h"
#include "RankTree.h"
#include "HashTable.h"

typedef enum {MM_SUCCESS = -2, MM_FAIL = -3, MM_INVALID_ARGUMENT = -4}MusicManagerResult ;

class MusicManager {
private:
    RankTree<ArtistSongKey, int> big_songs_tree;
    HashTable<Artist*, int> artists_table;
    int num_of_artists;
    int num_of_songs;
public:
    MusicManager();
    ~MusicManager();

    /**
     * @return total number of songs in music manager
     */
    int getNumberOfSongs() const;
    int getNumberOfSongs(int artist_id);
    /**
     * @return total number of artists in music manager
     */
    int getNumberOfArtists() const;

    /**
     * Adds a new artist to the artists tree and adds all the artist songs to
     * the streaming chart
     * @param artist_id
     * @param numOfSongs
     */
    MusicManagerResult addArtist(int artist_id);


    /**
     * Deletes artist from artists tree and deletes all of the artist songs
     * from the streaming chart
     * @param artist_id
     */
    MusicManagerResult removeArtist(int artist_id);


    MusicManagerResult addSong(int artist_id, int song_id);

    MusicManagerResult removeSong(int artist_id, int song_id);
    /**
     * Increases songID streams by:
     * - increasing number of streams in streams[songID]
     * - moving the song from current node in music chart to next node
     * @param artist_id
     * @param song_id
     */
    MusicManagerResult addToSongCount(int artist_id, int song_id, int count);

    int getArtistBestSong(int artist_id);

    ArtistSongKey getRecommendedSongInPlace(int rank);
};



#endif //DATASTRUCTURE_2_MUSICMANAGER_H
