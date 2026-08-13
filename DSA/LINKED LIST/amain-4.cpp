#include <iostream>
#include <string>
#include "applemusic_ll.h"

// prints a section header so each step of the demo stands out
void printHeader(const std::string& title) {
    std::string border(title.length() + 4, '=');
    std::cout << "\n" << border << "\n";
    std::cout << "  " << title << "\n";
    std::cout << border << "\n";
}

int main() {
    // create queue
    printHeader("CREATE QUEUE");
    CircularList<Song>* queue = nullptr;
    addSong(Song{"Summer Crush", "HELLMERRY"}, &queue);
    addSong(Song{"Halik Sobrang Diin Pt. 2", "Gat Putch"}, &queue);
    addSong(Song{"Origimal", "Uncle Dags"}, &queue);
    addSong(Song{"Chinay", "La Mave"}, &queue);
    std::cout << "Queue created. Playing all songs:\n";
    playAllSongs(queue);

    // add song
    printHeader("ADD SONG");
    std::cout << "Adding 'MYSB (Miss You So Bad)' by Skusta Clee...\n";
    addSong(Song{"MYSB (Miss You So Bad)", "Skusta Clee"}, &queue);
    playAllSongs(queue);

    // remove song
    printHeader("REMOVE SONG");
    std::cout << "Removing 'Chinay' by La Mave...\n";
    removeSong(Song{"Chinay", "La Mave"}, &queue);
    playAllSongs(queue);

    // loop
    printHeader("PLAY ALL (LOOP)");
    playAllSongs(queue);

    // next / previous
    printHeader("NEXT / PREVIOUS");
    CircularList<Song>* nowPlaying = queue;
    std::cout << "Now playing : " << nowPlaying->data << std::endl;
    nextSong(&nowPlaying);
    std::cout << "Next        : " << nowPlaying->data << std::endl;
    nextSong(&nowPlaying);
    std::cout << "Next        : " << nowPlaying->data << std::endl;
    previousSong(&nowPlaying);
    std::cout << "Previous    : " << nowPlaying->data << std::endl;

    // remove non-existent song
    printHeader("REMOVE NON-EXISTENT SONG");
    std::cout << "Attempting to remove 'Paano Ka Ba?' by Hev Abi...\n";
    removeSong(Song{"Paano Ka Ba?", "Hev Abi"}, &queue);

    // confirm the queue loops back to the start after a full cycle
    printHeader("CONFIRM LOOPING");
    CircularList<Song>* cursor = queue;
    int songCount = 0;
    CircularList<Song>* counter = queue;
    do {
        songCount++;
        counter = counter->next;
    } while (counter != queue);

    for (int played = 0; played < songCount * 2; played++) {
        std::cout << "  [" << (played % songCount) + 1 << "/" << songCount << "] "
                   << cursor->data << std::endl;
        nextSong(&cursor);
    }
    std::cout << std::endl;

    return 0;
}