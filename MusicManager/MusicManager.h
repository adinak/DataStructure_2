//
// Created by aviv on 6/10/2020.
//

#ifndef DATASTRUCTURE_2_MUSICMANAGER_H
#define DATASTRUCTURE_2_MUSICMANAGER_H

#include "SpcialKeys.h"
#include "../RankTree/RankTree.h"
#include "../HashTable/HashTable.h"

typedef enum {MM_SUCSSES, MM_FAIL, MM_INVALID_ARGUMENT} ;

class MusicManager {
private:
    RankTree<ArtistSongKey, int> big_songs_tree;
public:

};


#endif //DATASTRUCTURE_2_MUSICMANAGER_H
