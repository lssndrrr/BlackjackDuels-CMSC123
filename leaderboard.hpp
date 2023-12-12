#pragma once
#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include "header.hpp"
#include "players.hpp"

// Record for each player (node)
class Record {
public:
    // Attributes
    string username;
    int points;
    Record *next;

    // Constructor
    Record();
    Record(string, int);
    string getUsername();
    string getPoints();
};

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

