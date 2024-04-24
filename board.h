#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <vector>

class Board {
private:
    int grid[9][9];

public:
    Board();
    void display();
    bool isValid(int row, int col, int num);
    void setCell(int row, int col, int num);
    int getCell(int row, int col);
    bool isFull();
    void setFixedCellsFromTxt(const std::string& filename);
};

#endif
