#include "Scoreboard.h"
#include <iostream>
#include <iomanip>

Scoreboard::Scoreboard() : rollIndex(0), frameIndex(0), totalSum(0) {
    for (auto &r : rolls) r = " ";
    for (auto &t : totals) t = -1; // Initialize with -1 to distinguish from a 0 score
}

void Scoreboard::addStrike() {
    rolls[rollIndex] = " ";   // First box empty
    rolls[rollIndex + 1] = "X"; // Strike in second box
    totalSum += 10;
    totals[frameIndex] = totalSum;
    rollIndex += 2;
    frameIndex++;
}

void Scoreboard::addRoll(int pins) {
    rolls[rollIndex++] = (pins == 0) ? "-" : std::to_string(pins);
}

void Scoreboard::addSpare() {
    rolls[rollIndex++] = "/";
    totalSum += 10;
    totals[frameIndex] = totalSum;
    frameIndex++;
}

void Scoreboard::finishOpenFrame(int frameScore) {
    totalSum += frameScore;
    totals[frameIndex] = totalSum;
    frameIndex++;
}

void Scoreboard::print(const std::string& name) const {
    const int nameWidth = 14;      // Name column width
    const int frameWidth = 5;      // Frames 1-9
    const int tenthWidth = 7;      // 10th frame

    // Header
    std::cout << std::left << std::setw(nameWidth) << "Name" << "|";
    for (int f = 1; f <= 9; f++) std::cout << std::setw(frameWidth) << f << "|";
    std::cout << std::setw(tenthWidth) << 10 << "  | Total\n";

    std::cout << std::string(nameWidth + 9*frameWidth + tenthWidth + 12, '-') << "\n";

    // Row 1: Rolls
    std::cout << std::left << std::setw(nameWidth) << name << "|";
    int rollIdx = 0;
    for (int f = 0; f < 9; f++) {
        std::string r1 = rolls[rollIdx];
        std::string r2 = rolls[rollIdx + 1];
        std::cout << std::setw(frameWidth/2 + 1) << r1 << std::setw(frameWidth/2) << r2 << "|";
        rollIdx += 2;
    }
    // 10th frame
    std::cout << std::setw(tenthWidth/3 + 1) << rolls[rollIdx]
              << std::setw(tenthWidth/3 + 1) << rolls[rollIdx + 1]
              << std::setw(tenthWidth/3 + 1) << rolls[rollIdx + 2]
              << "| ";
    std::cout << totalSum << "\n";

    // Row 2: Totals
    std::cout << std::setw(nameWidth) << " " << "|";
    for (int f = 0; f < 9; f++) {
        if (totals[f] == -1)
            std::cout << std::setw(frameWidth) << " " << "|";
        else
            std::cout << std::setw(frameWidth) << totals[f] << "|";
    }
    // 10th frame
    if (totals[9] == -1)
        std::cout << std::setw(tenthWidth) << " " << "  |";
    else
        std::cout << std::setw(tenthWidth) << totals[9] << "   |";

    std::cout << "\n" << std::string(nameWidth + 9*frameWidth + tenthWidth + 12, '-') << "\n";
}
