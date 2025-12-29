#include "Game.h"
#include <iostream>

void Game::run() {
    char playAgain;
    do {
        std::string name;
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);

        Player player(name);

        for (int frame = 0; frame < 10; frame++) {
            std::cout << "\n--- Frame " << frame + 1 << " ---\n";
            player.rollFrame(frame + 1); // Now handles internal pauses per roll
        }

        std::cout << "\nGame Over! Final Score: " << player.getFinalScore() << "\n";
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        std::cin.ignore(); // Clear the newline from the buffer
    } while (playAgain == 'y' || playAgain == 'Y');
}