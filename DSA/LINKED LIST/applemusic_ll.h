#ifndef APPLEMUSIC_LL_H
#define APPLEMUSIC_LL_H

#include <iostream>
#include <string>

// A song stored in the Apple Music queue
struct Song {
    std::string title;
    std::string artist;

    bool operator==(const Song& other) const {
        return title == other.title && artist == other.artist;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << s.title << " - " << s.artist;
    return os;
}

// node creation
template <typename S>
class CircularList {
public:
    S data;
    CircularList<S>* next = nullptr;
    CircularList<S>* prev = nullptr;
};

// add song at the end of the Apple Music queue
template <typename S>
void addSong(S newSong, CircularList<S>** head) {
    CircularList<S>* newNode = new CircularList<S>;
    newNode->data = newSong;

    // empty queue
    if (*head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }

    // linking
    CircularList<S>* tail = (*head)->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// remove a song
template <typename S>
void removeSong(S findSong, CircularList<S>** head) {
    if (*head == nullptr) return;

    CircularList<S>* currNode = *head;

    do {
        if (currNode->data == findSong) {
            if (currNode->next == currNode) {
                *head = nullptr;
            } else {
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;
                if (currNode == *head) {
                    *head = currNode->next;
                }
            }
            delete currNode;
            return;
        }
        currNode = currNode->next;
    } while (currNode != *head);

    std::cout << "\"" << findSong << "\" was not found in the queue\n";
}

// play every song once
template <typename S>
void playAllSongs(CircularList<S>* head) {
    if (head == nullptr) {
        std::cout << "the queue was empty\n";
        return;
    }

    CircularList<S>* currNode = head;
    do {
        std::cout << currNode->data;
        currNode = currNode->next;
        if (currNode != head) std::cout << " -> ";
    } while (currNode != head);
    std::cout << std::endl;
}

template <typename S>
void nextSong(CircularList<S>** current) {
    if (*current == nullptr) return;
    *current = (*current)->next;
}

template <typename S>
void previousSong(CircularList<S>** current) {
    if (*current == nullptr) return;
    *current = (*current)->prev;
}
#endif
