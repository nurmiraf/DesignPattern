#include "gamemanager.h"
#include <iostream>

int main() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    GameManager game(playerName);
    std::cout << "Welcome to Sudoku, " << playerName << "!" << std::endl;
    game.play();
    return 0;
}
