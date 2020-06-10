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

MusicManagerResult MusicManager::addArtist(int artist_id) {
    Artist a(artist_id);
    if(this->artists_table.insertNewMember(artist_id, a) == -1){
        return MM_FAIL;
    }
    this->num_of_artists++;
    return MM_SUCSSES;
}

MusicManagerResult MusicManager::removeArtist(int artist_id) {
   int artist_num_of_songs = this->getNumberOfSongs(artist_id);
   if(artist_num_of_songs != 0) return MM_FAIL;
   if(!this->artists_table.isMember(artist_id))
       return MM_FAIL;
   Artist a = this->artists_table.deleteMember(artist_id);
   this->num_of_artists--;
   return MM_SUCSSES;
}

int MusicManager::getNumberOfSongs(int artist_id) {
    Artist a = this->artists_table.findMember(artist_id);
    return a.getNumOfSongs();
}

MusicManagerResult MusicManager::addSong(int artist_id, int song_id) {
    Artist a = this->artists_table.findMember(artist_id);
    if(!this->artists_table.isMember(artist_id))
        return MM_FAIL;
    if(a.addSong(song_id)== SONG_ALREADY_EXISTS)
        return MM_FAIL;
    ArtistSongKey tmp_key(artist_id,song_id,0);
    this->big_songs_tree.insert(tmp_key,song_id);
    this->num_of_songs++;
    return MM_SUCSSES;
}

MusicManagerResult MusicManager::removeSong(int artist_id, int song_id) {
    if(!this->artists_table.isMember(artist_id))
        return MM_FAIL;
    Artist a = this->artists_table.findMember(artist_id);
    int streams = a.getNumOfStreams(song_id);
    if(a.deleteSong(song_id)== SONG_DOES_NOT_EXIST)
        return MM_FAIL;
    ArtistSongKey tmp_key(artist_id,song_id, streams);
    this->num_of_songs--;
    return MM_SUCSSES;
}

MusicManagerResult MusicManager::addToSongCount(int artist_id, int song_id, int count) {
    if(!this->artists_table.isMember(artist_id))//Artist doesnt exists
        return MM_FAIL;
    Artist a = this->artists_table.findMember(artist_id);
    int streams = a.getNumOfStreams(song_id);
    if(streams == -1)//Song doesnt exists
        return MM_FAIL;
    a.artistAddToSongCount(song_id, streams+count);
    ArtistSongKey tmp_key(artist_id,song_id,streams);
    this->big_songs_tree.remove(tmp_key);
    tmp_key = ArtistSongKey(artist_id,song_id,streams+count);
    this->big_songs_tree.insert(tmp_key, song_id);
    return MM_SUCSSES;
}

int MusicManager::getArtistBestSong(int artist_id) {
    if(!this->artists_table.isMember(artist_id))//Artist doesnt exists
        return MM_FAIL;
    Artist a = this->artists_table.findMember(artist_id);
    if(a.getNumOfSongs() == 0)
        return MM_FAIL;
    return a.getArtistBestSong();
}

ArtistSongKey MusicManager::getRecommendedSongInPlace(int rank) {
    int total_num_of_songs = this->big_songs_tree.getSize();
    int new_rank = total_num_of_songs-rank+1;
    return this->big_songs_tree.select(new_rank);
}








