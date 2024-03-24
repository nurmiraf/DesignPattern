#include "gamemanager.h"
#include "board.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager(const std::string& playerName) : player(playerName) {}

void GameManager::selectDifficulty() {
    std::cout << "Select difficulty level:" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;
    int choice;
    do {
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;
    } while (choice < 1 || choice > 3);

    std::string folderName;
    switch (choice) {
        case 1:
            folderName = "easy/";
            break;
        case 2:
            folderName = "medium/";
            break;
        case 3:
            folderName = "hard/";
            break;
    }

    std::string filename;
    switch (choice) {
        case 1:
        case 2:
        case 3:
            filename = folderName + "template.txt";
            break;
        }
        board.setFixedCellsFromTxt(filename);
}

void GameManager::play() {
    selectDifficulty();
    board.display();
    
    while (!board.isFull()) {
        makeMove();
        board.display();
    }
    std::cout << "Congratulations, " << player.getName() << "! You solved the puzzle!" << std::endl;
}

void GameManager::makeMove() {
    int row, col, num;
    std::cout << "Enter row, column, and number (0 to exit): ";
    std::cin >> row >> col >> num;

    if (row == 0 || col == 0 || num == 0)
        return;

    if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
        std::cout << "Invalid input! Please enter valid row, column, and number." << std::endl;
        return makeMove();
    }

    if (board.getCell(row - 1, col - 1) != 0) {
        std::cout << "Cell already filled! Please select another cell." << std::endl;
        return makeMove();
    }

    if (!board.isValid(row - 1, col - 1, num)) {
        std::cout << "Invalid move! Number conflicts with existing numbers in the row, column, or subgrid." << std::endl;
        return makeMove();
    }

        board.setCell(row - 1, col - 1, num);
}
