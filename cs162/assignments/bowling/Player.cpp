#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Player::Player(const std::string& name) : name(name) {
    srand(time(nullptr));
}

void Player::rollFrame(int frameNumber) { // pass current frame (1-10)
    auto waitForRoll = []() {
        std::cout << "Press Enter to roll...";
        std::cin.get();
    };

    int pins1, pins2, pins3;

    waitForRoll();
    pins1 = rand() % 11;

    if (pins1 == 10) { // Strike
        std::cout << ">> STRIKE! <<\n";
        board.addStrike();
        if (frameNumber == 10) {
            // Two extra rolls for 10th frame
            waitForRoll();
            pins2 = rand() % 11;
            board.addRoll(pins2);

            waitForRoll();
            pins3 = rand() % 11;
            board.addRoll(pins3);
        }
        board.print(name);
        return;
    }

    std::cout << "You knocked down " << pins1 << " pins.\n";
    board.addRoll(pins1);
    board.print(name);

    // Roll 2
    waitForRoll();
    pins2 = rand() % (11 - pins1);

    if (pins1 + pins2 == 10) { // Spare
        std::cout << ">> SPARE! <<\n";
        board.addSpare();
        if (frameNumber == 10) {
            // Extra roll for 10th frame
            waitForRoll();
            pins3 = rand() % 11;
            board.addRoll(pins3);
        }
    } else {
        std::cout << "You knocked down " << pins2 << " more pins.\n";
        board.addRoll(pins2);
        board.finishOpenFrame(pins1 + pins2);
    }

    board.print(name);
}

int Player::getFinalScore() const {
    return board.getTotalSum();
}