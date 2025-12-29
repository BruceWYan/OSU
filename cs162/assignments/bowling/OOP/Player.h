#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Scoreboard.h"

class Player {
private:
    std::string name;
    Scoreboard board;

public:
    Player(const std::string& name);
    void rollFrame(int frame);
    void printBoard() const;
    int getFinalScore() const;
};

#endif