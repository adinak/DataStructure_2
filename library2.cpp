//
// Created by Aviv9 on 13/06/2020.
//

#include "library2.h"
#include "MusicManager/MusicManager.h"
using std::bad_alloc;

void *Init() {
    MusicManager *new_manager;
    try {
        new_manager = new MusicManager();
    }
    catch (...) {
        new_manager = nullptr;
    }
    return (void *) new_manager;
}

StatusType AddArtist(void *DS, int artistID) {
    if(DS == nullptr || artistID <= 0) {
        return INVALID_INPUT;
    }
    auto* music_manager = (MusicManager*)DS;
    try {
        if (music_manager->addArtist(artistID) == MM_FAIL) {
            return FAILURE;
        }
    }
    catch (bad_alloc &e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType RemoveArtist(void *DS, int artistID) {
    if(DS == nullptr || artistID <= 0) {
        return INVALID_INPUT;
    }
    auto* music_manager = (MusicManager*)DS;
    try {
        if(music_manager->removeArtist(artistID) == MM_FAIL)
            return FAILURE;
    }
    catch (bad_alloc &e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}


StatusType AddSong(void *DS, int artistID, int songID) {
    if(DS == nullptr || artistID <= 0 || songID <= 0) {
        return INVALID_INPUT;
    }
    auto* music_manager = (MusicManager*)DS;
    try {
        if(music_manager->addSong(artistID,songID) == MM_FAIL)
            return FAILURE;
    }
    catch (bad_alloc &e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType RemoveSong(void *DS, int artistID, int songID) {
    if(DS == nullptr || artistID <= 0 || songID <= 0) {
        return INVALID_INPUT;
    }
    auto* music_manager = (MusicManager*)DS;
    try {
        if(music_manager->removeSong(artistID,songID) == MM_FAIL)
            return FAILURE;
    }
    catch (bad_alloc &e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType AddToSongCount(void *DS, int artistID, int songID, int count) {
    if(DS == nullptr || artistID <= 0 || songID <= 0 || count <= 0) {
        return INVALID_INPUT;
    }
    auto* music_manager = (MusicManager*)DS;
    try {
        if(music_manager->addToSongCount(artistID, songID, count) == MM_FAIL)
            return FAILURE;
    }
    catch (bad_alloc &e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType GetArtistBestSong(void *DS,int artistID, int *songID) {
    if(DS == nullptr || songID == nullptr || artistID <= 0) {
        return INVALID_INPUT;
    }
    auto* music_manager = (MusicManager*)DS;
    try {
        int song_id = music_manager->getArtistBestSong(artistID);
        if(song_id == MM_FAIL)
            return FAILURE;
        *songID = song_id;
    }
    catch (bad_alloc &e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType
GetRecommendedSongInPlace(void *DS, int rank, int *artistId, int *songId){
    if(DS == nullptr || songId == nullptr || artistId == nullptr || rank <= 0) {
        return INVALID_INPUT;
    }
    auto* music_manager = (MusicManager*)DS;
    try {
        ArtistSongKey key = music_manager->getRecommendedSongInPlace(rank);
        if(key.artist_id == -1){
            return FAILURE;
        }
        *artistId = key.artist_id;
        *songId = key.song_id;
    }
    catch (bad_alloc &e) {
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

void Quit(void **DS) {
    auto music_manager = (MusicManager*)*DS;
    delete music_manager;
    *DS = nullptr;
}









