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

MusicManagerResult MusicManager::addArtist(int artistID) {
    Artist a(artistID);
    this->artists_table.insertNewMember(artistID, a);
    this->num_of_artists++;
}

MusicManagerResult MusicManager::removeArtist(int artistID) {
   int artist_num_of_songs = this->getNumberOfSongs(artistID);
   if(artist_num_of_songs != 0) return;
   this->artists_table.deleteMember(artistID);
   this->num_of_artists--;
}

int MusicManager::getNumberOfSongs(int artistID) {
    Artist a = this->artists_table.findMember(artistID);
    return a.getNumOfSongs();
}

MusicManagerResult MusicManager::addSong(int artist_id, int song_id) {
    Artist a = this->artists_table.findMember(artist_id);
    a.addSong(song_id);
    ArtistSongKey tmp_key(artist_id,song_id,0);
    this->big_songs_tree.insert(tmp_key,song_id);
    this->num_of_songs++;
}

MusicManagerResult MusicManager::removeSong(int artist_id, int song_id) {
    Artist a = this->artists_table.findMember(artist_id);
    int streams = a.getNumOfStreams(song_id);
    a.deleteSong(song_id);
    ArtistSongKey tmp_key(artist_id,song_id, streams);
    this->num_of_songs--;
}

MusicManagerResult MusicManager::addToSongCount(int artist_id, int song_id) {
    Artist a = this->artists_table.findMember(artist_id);
    int streams = a.getNumOfStreams(song_id);
    a.artistAddToSongCount(song_id, streams+1);
    ArtistSongKey tmp_key(artist_id,song_id,streams);
    this->big_songs_tree.remove(tmp_key);
    tmp_key = ArtistSongKey(artist_id,song_id,streams+1);
    this->big_songs_tree.insert(tmp_key, song_id);
}

int MusicManager::getArtistBestSong(int artist_id) {
    Artist a = this->artists_table.findMember(artist_id);
    return a.getArtistBestSong();
}

ArtistSongKey MusicManager::getRecommendedSongInPlace(int rank) {
    int num_of_songs = this->big_songs_tree.getSize();
    return this->big_songs_tree.select(num_of_songs-rank+1);
}








