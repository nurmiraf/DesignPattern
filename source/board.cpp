#include "board.h"
#include <iostream>
#include <fstream>

Board::Board() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            grid[i][j] = 0;
        }
    }
}

void Board::display() {
    std::cout << "-----------------------" << std::endl;
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0)
            std::cout << "|---------------------|" << std::endl;
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0)
                std::cout << "| ";
            if (grid[i][j] == 0)
                std::cout << ". ";
            else
                std::cout << grid[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}

bool Board::isValid(int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < 9; ++i)
        if (grid[row][i] == num || grid[i][col] == num)
            return false;

    // Check subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

void Board::setCell(int row, int col, int num) {
    grid[row][col] = num;
}

int Board::getCell(int row, int col) {
    return grid[row][col];
}

bool Board::isFull() {
    // Check if the grid is full (no empty cells)
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (grid[i][j] == 0)
                return false;
        }
    }
    return true;
}

void Board::setFixedCellsFromTxt(const std::string& filename) {
    // Read from text file and set fixed cells
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening text file." << std::endl;
        return;
    }

    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < 9) {
        for (int col = 0; col < 9 && col < line.length(); ++col) {
            if (isdigit(line[col])) {
                grid[row][col] = line[col] - '0';
            } else {
                // Handle invalid characters in the file
                std::cerr << "Invalid character in text file at row " << row + 1 << ", column " << col + 1 << std::endl;
                grid[row][col] = 0; // Set to default value
            }
        }
        ++row;
    }
}
