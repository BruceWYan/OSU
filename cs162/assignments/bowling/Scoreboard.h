#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Scoreboard {
private:
    std::string rolls[21]; // 2 rolls per frame + 1 extra for 10th frame
    int totals[10];        // Cumulative score for each frame
    int rollIndex;
    int frameIndex;
    int totalSum;

public:
    Scoreboard();
    
    // Logic updates
    void addRoll(int pins);
    void addStrike();
    void addSpare();
    void finishOpenFrame(int frameScore);
    
    // Display and Data
    void print(const std::string& name) const;
    int getTotalSum() const { return totalSum; }
};

#endif