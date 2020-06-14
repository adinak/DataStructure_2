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
    //RankTree of all the songs ordered according to ArtistSongKey
    RankTree<ArtistSongKey, int> big_songs_tree;
    //HashTable that store all the artists in the structure
    HashTable<Artist*, int> artists_table;
    int num_of_artists;
    int num_of_songs;
public:
    /**
     * default constructor initialize all the attributes to 0.
     */
    MusicManager();

    /**
     * default destructor, deallocate all the Artists in the structure
     */
    ~MusicManager();

    /**
     * @return total number of songs in music manager
     */
    int getNumberOfSongs() const;

    /**
     * @param artist_id
     * @return total number of songs of the specific artist in music manager
     *         -1 if the artist not found
     */
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
     * @return MM_SUCCESS if the artist added successfully
     *         MM_FAIL if the artist already exists in the structure
     */
    MusicManagerResult addArtist(int artist_id);


    /**
     * Deletes artist from artists tree and deletes all of the artist songs
     * from the streaming chart
     * @param artist_id
     * @return MM_SUCCESS if the artist removed successfully
     *         MM_FAIL if the artist not exists in the structure
     */
    MusicManagerResult removeArtist(int artist_id);

    /**
     * Add new song to the structure
     * @param artist_id
     * @param song_id
     * @return MM_SUCCESS if the song added successfully
     *         MM_FAIL if the song already exists in the structure
     */
    MusicManagerResult addSong(int artist_id, int song_id);

    /**
      * Remove the song from the structure
      * @param artist_id
      * @param song_id
      * @return MM_SUCCESS if the song removed successfully
      *         MM_FAIL if the song not exists in the structure
      */
    MusicManagerResult removeSong(int artist_id, int song_id);

    /**
     * Increases songID number of streams by count
     * @param artist_id
     * @param song_id
     * @param count
     * @return MM_SUCCESS if the steams changed successfully
     *         MM_FAIL if the artist or song not exists in the structure
     */
    MusicManagerResult addToSongCount(int artist_id, int song_id, int count);
    /**
     * @param artist_id
     * @return the artists best song ID
     *         -1 if the artist not exists in the structures
     */
    int getArtistBestSong(int artist_id);

    /**
     * find the song in the rank place in the ordered series of all the song
     * in the structure, rank = 1 gives the biggest element
     * @param rank, 0<rank<=size
     * @return the key of the specific song
     */
    ArtistSongKey getRecommendedSongInPlace(int rank);
};



#endif //DATASTRUCTURE_2_MUSICMANAGER_H
