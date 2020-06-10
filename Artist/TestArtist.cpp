//
// Created by Adina Katz on 10/06/2020.
//

#include <iostream>
#include "Artist.h"

int main() {
    Artist pink(555);
    if (pink.getArtistId() == 555) {
        std::cout << "test1: success!" << std::endl;
    }
    if (pink.addSong(56) == SUCCESS) {
        std::cout << "test2: success!" << std::endl;
    }
    if (pink.addSong(50) == SUCCESS) {
        std::cout << "test3: success!" << std::endl;
    }
    if (pink.getArtistBestSong() == 50) {
        std::cout << "test4: success!" << std::endl;
    }
    if (pink.artistAddToSongCount(56, 6) == SUCCESS) {
        std::cout << "test5: success!" << std::endl;
    }
    if (pink.getArtistBestSong() == 56) {
        std::cout << "test6: success!" << std::endl;
    }
    if (!pink.isSong(33)) {
        std::cout << "test7: success!" << std::endl;
    }
    if (pink.isSong(50)) {
        std::cout << "test8: success!" << std::endl;
    }
    if (pink.deleteSong(56) == SUCCESS) {
        std::cout << "test9: success!" << std::endl;
    }
    if (pink.getArtistBestSong() == 50) {
        std::cout << "test10: success!" << std::endl;
    }
    if (!pink.isSong(56)) {
        std::cout << "test11: success!" << std::endl;
    }

    return 0;
}
