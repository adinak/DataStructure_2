//
// Created by aviv on 6/10/2020.
//

#include "MusicManager.h"


MusicManager::MusicManager() {
    this->num_of_songs = 0;
    this->num_of_artists = 0;

}

int MusicManager::getNumberOfSongs() const {
    return this->num_of_songs;
}

int MusicManager::getNumberOfArtists() const {
    return this->num_of_artists;
}

void MusicManager::addArtist(int artistID) {
    Artist a();
    this->artists_table.insertNewMember(artistID, a);
}


