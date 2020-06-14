cmake_minimum_required(VERSION 3.16)
project(DataStructure_2)

set(CMAKE_CXX_STANDARD 11)
set(ARTIST ./Artist)
set(RANK_TREE ./RankTree)
set(HASH_TABLE ./HashTable)
set(MUSIC_MANAGER ./MusicManager)

include_directories(${ARTIST})
include_directories(${RANK_TREE})
include_directories(${HASH_TABLE})
include_directories(${MUSIC_MANAGER})

add_executable(DataStructure_2
        #${HASH_TABLE}/TestHashTable.cpp # debug
        #${ARTIST}/TestArtist.cpp) # debug
        ${HASH_TABLE}/HashTable.h
        ${HASH_TABLE}/HashTableCell.h
        ${RANK_TREE}/RankTree.h
        ${RANK_TREE}/RankTreeNode.h
        ${ARTIST}/Artist.h
        ${ARTIST}/Artist.cpp
        ${MUSIC_MANAGER}/MusicManager.cpp
        ${MUSIC_MANAGER}/MusicManager.h
        ${MUSIC_MANAGER}/SpecialKeys.cpp
        ${MUSIC_MANAGER}/SpecialKeys.h
        library2.h
        library2.cpp
        main2.cpp)
