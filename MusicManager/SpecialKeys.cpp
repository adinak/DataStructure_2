//
// Created by Aviv9 on 10/06/2020.
//

#include "SpecialKeys.h"

bool songKey_t::operator==(const songKey_t song_key)const  {
    return (this->num_of_streams == song_key.num_of_streams)&&
            (this->song_id == song_key.song_id);
}

bool songKey_t::operator<(const songKey_t song_key)const  {
    if(this->num_of_streams < song_key.num_of_streams) return true;
    else if(this->num_of_streams == song_key.num_of_streams){
        if(this->song_id > song_key.song_id)
            return true;
    }
    return false;
}

bool songKey_t::operator<=(const songKey_t song_key)const  {
    return (*this < song_key || *this == song_key);
}

bool songKey_t::operator>(const songKey_t song_key)const  {
    return !(*this<=song_key);
}

bool songKey_t::operator>=(const songKey_t song_key)const  {
    return (*this > song_key || *this == song_key);
}

bool songKey_t::operator!=(const songKey_t song_key)const  {
    return !(*this == song_key);
}

songKey_t& songKey_t::operator=(const songKey_t new_song_key)  {
    this->song_id = new_song_key.song_id;
    this->num_of_streams = new_song_key.num_of_streams;
    return *this;
}

bool artistSongKey_t::operator==(const artistSongKey_t artist_song_key) const {
    return (this->num_of_streams == artist_song_key.num_of_streams) &&
           (this->song_id == artist_song_key.song_id) &&
           (this->artist_id == artist_song_key.artist_id);

}

bool artistSongKey_t::operator<(const artistSongKey_t artist_song_key) const {
     if(this->num_of_streams < artist_song_key.num_of_streams)
         return true;
    else if(this->num_of_streams == artist_song_key.num_of_streams){
        if(this->artist_id > artist_song_key.artist_id)
            return true;
        else if(this->artist_id == artist_song_key.artist_id){
            if (this->song_id > artist_song_key.artist_id)
                return true;
        }
    }
    return false;
}

bool artistSongKey_t::operator<=(const artistSongKey_t artist_song_key) const {
    return (*this < artist_song_key || *this == artist_song_key);
}

bool artistSongKey_t::operator>(const artistSongKey_t artist_song_key) const {
    return !(*this <= artist_song_key);
}

bool artistSongKey_t::operator>=(const artistSongKey_t artist_song_key) const  {
    return (*this > artist_song_key || *this == artist_song_key);
}

bool artistSongKey_t::operator!=(const artistSongKey_t artist_song_key) const {
    return !(*this == artist_song_key);
}

artistSongKey_t &artistSongKey_t::operator=(const artistSongKey_t new_artist_song_key) {
    this->song_id = new_artist_song_key.song_id;
    this->num_of_streams = new_artist_song_key.num_of_streams;
    this->artist_id = new_artist_song_key.artist_id;
    return *this;
}