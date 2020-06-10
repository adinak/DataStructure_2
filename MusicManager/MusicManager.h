//
// Created by aviv on 6/10/2020.
//

#ifndef DATASTRUCTURE_2_MUSICMANAGER_H
#define DATASTRUCTURE_2_MUSICMANAGER_H

#include "SpecialKeys.h"
#include "../RankTree/RankTree.h"
#include "../HashTable/HashTable.h"

typedef enum {MM_SUCSSES, MM_FAIL, MM_INVALID_ARGUMENT} ;

class MusicManager {
private:
    RankTree<ArtistSongKey, int> big_songs_tree;
    HashTable<Artist, int, hashFunction> artists_table;
    int num_of_artists;
    int num_of_songs;
public:
    MusicManager();
    ~MusicManager() = default;

    /**
     * @return total number of songs in music manager
     */
    int getNumberOfSongs() const;

    /**
     * @return total number of artists in music manager
     */
    int getNumberOfArtists() const;

    /**
     * Adds a new artist to the artists tree and adds all the artist songs to
     * the streaming chart
     * @param artistID
     * @param numOfSongs
     */
    void addArtist(int artistID);

    /**
     * Deletes artist from artists tree and deletes all of the artist songs
     * from the streaming chart
     * @param artistID
     */
    void removeArtist(int artistID);

    /**
     * Increases songID streams by:
     * - increasing number of streams in streams[songID]
     * - moving the song from current node in music chart to next node
     * @param artistID
     * @param songID
     */
    void addToSongCount(int artistID, int songID);
};



#endif //DATASTRUCTURE_2_MUSICMANAGER_H
