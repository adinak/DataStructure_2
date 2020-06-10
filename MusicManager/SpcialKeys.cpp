//
// Created by Aviv9 on 10/06/2020.
//

#include "SpcialKeys.h"

bool songKey_t::operator==(const songKey_t song_key)const  {
    return (this->num_of_streams == song_key.num_of_streams)&&
            (this->songid == song_key.songid);
}

bool songKey_t::operator<(const songKey_t song_key)const  {
    if(this->num_of_streams < song_key.num_of_streams) return true;
    else if(this->num_of_streams == song_key.num_of_streams){
        if(this->songid > song_key.songid)
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
    this->songid = new_song_key.songid;
    this->num_of_streams = new_song_key.num_of_streams;
    return *this;
}

bool artistSongKey_t::operator==(const artistSongKey_t artist_song_key) const {
    return (this->num_of_streams == artist_song_key.num_of_streams)&&
            (this->songid == artist_song_key.songid) &&
            (this->artistid == artist_song_key.artistid);

}

bool artistSongKey_t::operator<(const artistSongKey_t artist_song_key) const {
     if(this->num_of_streams < artist_song_key.num_of_streams)
         return true;
    else if(this->num_of_streams == artist_song_key.num_of_streams){
        if(this->artistid > artist_song_key.artistid)
            return true;
        else if(this->artistid == artist_song_key.artistid){
            if (this->songid > artist_song_key.artistid)
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
    this->songid = new_artist_song_key.songid;
    this->num_of_streams = new_artist_song_key.num_of_streams;
    this->artistid = new_artist_song_key.artistid;
    return *this;
}