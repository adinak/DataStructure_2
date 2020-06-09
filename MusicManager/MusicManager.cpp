//
// Created by aviv on 6/10/2020.
//

#include "MusicManager.h"


bool songKey_t::operator==(songKey_t song_key) {
    return (this->num_of_streams == song_key.num_of_streams)&&
            (this->songid == song_key.songid);
}

bool songKey_t::operator<(songKey_t song_key) {
    if(this->num_of_streams < song_key.num_of_streams) return true;
    else if(this->num_of_streams == song_key.num_of_streams){
        if(this->songid<song_key.songid)
            return true;
    }
    return false;
}

bool songKey_t::operator<=(songKey_t song_key) {
    if(*this < song_key || *this == song_key)
        return true;
}
