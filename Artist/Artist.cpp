//
// Created by Adina Katz on 10/06/2020.
//

#include "Artist.h"




Artist::Artist(int id) : artist_id(id) {
    best_song_id = -1;
    best_song_streams = -1;
}

Artist::Artist() {
    artist_id = -1;
    best_song_id = -1;
    best_song_streams = -1;
}

int Artist::getArtistId() const {
    return artist_id;
}

int Artist::getArtistBestSong() const {
    return best_song_id;
}

bool Artist::isSong(int song_id) {
    return songs_id.find(song_id) != nullptr;
}

ArtistResult Artist::addSong(int song_id, int count) {
    if (isSong(song_id)) {
        return A_SONG_ALREADY_EXISTS;
    }
    if (best_song_id < 0 || count > best_song_streams ||
        (count == best_song_streams && song_id < best_song_id)) {
        best_song_id = song_id;
        best_song_streams = count;
    }
    int id = song_id;
    int streams = count;
    songs_id.insert(id, streams);
    SongKey key(id, streams);
    songs_streams.insert(key, id);
    return A_SUCCESS;
}

ArtistResult Artist::deleteSong(int song_id) {
    if (!isSong(song_id)) {
        return A_SONG_DOES_NOT_EXIST;
    }
    int streams = *(songs_id.find(song_id));
    songs_id.remove(song_id);
    SongKey key(song_id, streams);
    songs_streams.remove(key);
    if (best_song_id == song_id) {
        SongKey new_best = songs_streams.select(songs_streams.getSize());
        best_song_id = new_best.song_id;
        best_song_streams = new_best.num_of_streams;
    }
    return A_SUCCESS;
}

ArtistResult Artist::artistAddToSongCount(int song_id, int count) {
    if (deleteSong(song_id) != A_SUCCESS) {
        return A_FAIL;
    }
    if (addSong(song_id, count) != A_SUCCESS) {
        return A_FAIL;
    }
    return A_SUCCESS;
}

int Artist::getNumOfSongs() {
    return this->songs_id.getSize();
}

int Artist::getNumOfStreams(int song_id) {
    int* streams = this->songs_id.find(song_id);
    if(streams == nullptr){
        return -1;
    }
    return *streams;
}








