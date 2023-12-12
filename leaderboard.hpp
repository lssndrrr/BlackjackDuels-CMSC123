#pragma once
#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include "header.hpp"
#include "players.hpp"

class Leaderboard {
private:
    // Attributes
    int length;
    Record *head, *tail;

    // Functions
    void insertHead(Record *);
    void insertTail(Record *);

public:
    // Constructor Destructor
    Leaderboard();
    ~Leaderboard();

    // Functions
    int size();
    void insort(string, int);
    void deleteRecords();
    void readData();
    void writeData();

    Record *operator[](int);
    // void displayData();
};

#endif // !LEADERBOARD_HPP

