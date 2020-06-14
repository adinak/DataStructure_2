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
    /**
     * RankTree that has songID as keys and num of streams as data
     */
    RankTree<int, int>* songs_id;
    /**
     * RankTree that has SongKey(songId,num of Streams) as keys
     * and songID as data
     */
    RankTree<SongKey , int>* songs_streams;

public:
    /***
     * Constructor for Artist that receives the artists ID
     * best_song_id and best_song_streams initialized to -1
     * and create empty RankTrees
     * @param id - the new artists ID number
     */
    Artist(int id);

    /***
     * default constructor that initialize all int atributes to -1
     * and create empty RankTrees
     */
    Artist();

    /***
     * default Destructor, the two Ranked Trees
     */
    ~Artist();

    /***
     * @return artists ID number
     */
    int getArtistId() const;

    /***
     * @return artists best_song_id
     */
    int getArtistBestSong() const;

    /***
     *
     * @param song_id - song ID to find
     * @return true if the artist has a song with the song ID given as
     * parameter and false otherwise
     */
    bool isSong(int song_id);

    /***
     * @return the number of song the artist has
     */
    int getNumOfSongs();

    /***
     * Add new song to the artist with the given parameters
     * @param song_id
     * @param count - number of streams to initialize the song with,
     * count default value is 0.
     * @return A_SUCCESS if the song added successfully
     *         A_SONG_ALREADY_EXISTS if a song with the ID already exists
     */
    ArtistResult addSong(int song_id, int count = 0);

    /***
     * Delete the song with the given song ID
     * @param song_id
     * @return A_SUCCESS if the song deleted successfully
     *         A_SONG_ALREADY_EXISTS if a song with the ID already exists
     */
    ArtistResult deleteSong(int song_id);

    /***
     * @param song_id
     * @return number of streams of the song with the given song ID.
     *         -1 if the song doesnt exists.
     */
    int getNumOfStreams(int song_id);

    /***
     * Change the number of streams to the song with the given song ID
     * @param song_id
     * @param count - new total number of streams
     * @return A_SUCCESS if the song deleted successfully
     *         A_SONG_ALREADY_EXISTS if a song with the ID already exists
     */
    ArtistResult artistAddToSongCount(int song_id, int count);
};

#endif //DATASTRUCTURE_2_ARTIST_H
