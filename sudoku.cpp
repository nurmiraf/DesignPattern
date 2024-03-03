#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class SudokuBoard {
private:
    int grid[9][9];
public:
    SudokuBoard() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                grid[i][j] = 0;
            }
        }
    }

    void display() {
        cout << "-----------------------" << endl;
        for (int i = 0; i < 9; ++i) {
            if (i % 3 == 0 && i != 0)
                cout << "|---------------------|" << endl;
            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0 && j != 0)
                    cout << "| ";
                if (grid[i][j] == 0)
                    cout << ". ";
                else
                    cout << grid[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "-----------------------" << endl;
    }

    bool isValid(int row, int col, int num) {
        for (int i = 0; i < 9; ++i)
            if (grid[row][i] == num || grid[i][col] == num)
                return false;

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (grid[i + startRow][j + startCol] == num)
                    return false;

        return true;
    }

    void fillCells() {
        srand(time(0));
        int numInitialCells = rand() % 20 + 20;
        for (int k = 0; k < numInitialCells; ++k) {
            int row = rand() % 9;
            int col = rand() % 9;
            int num = rand() % 9 + 1;
            if (isValid(row, col, num)) {
                grid[row][col] = num;
            }
        }
    }

    bool isFull() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (grid[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    int getValue(int row, int col) {
        return grid[row][col];
    }

    void setValue(int row, int col, int value) {
        grid[row][col] = value;
    }

    void deleteValue(int row, int col) {
        grid[row][col] = 0;
    }
};

class GameManager {
private:
    SudokuBoard sudokuBoard;
public:
    void play() {
        sudokuBoard.fillCells();
        sudokuBoard.display();

        while (!sudokuBoard.isFull()) {
            int row, col, num;
            cout << "Enter row, column, and number (0 to exit): ";
            cin >> row >> col >> num;

            if (row == 0 || col == 0 || num == 0)
                break;

            if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
                cout << "Invalid input! Please enter valid row, column, and number." << endl;
                continue;
            }

            if (sudokuBoard.getValue(row - 1, col - 1) != 0) {
                char choice;
                cout << "Cell already filled! Do you want to delete it? (y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    sudokuBoard.deleteValue(row - 1, col - 1);
                    sudokuBoard.display();
                    continue;
                } else {
                    continue;
                }
            }

            if (!sudokuBoard.isValid(row - 1, col - 1, num)) {
                cout << "Invalid, Number conflicts with existing numbers in the row, column, or subgrid." << endl;
                continue;
            }

            sudokuBoard.setValue(row - 1, col - 1, num);
            sudokuBoard.display();

            if (sudokuBoard.isFull()) {
                cout << "Congratulations! You completed the Sudoku" << endl;
                break;
            }
        }
    }
};

class Player {
private:
    string playerName;
public:
    Player(string name) : playerName(name) {}

    void printPlayerName() {
        cout << "Player: " << playerName << endl;
    }
};

int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName);
    player.printPlayerName();

    GameManager game;
    cout << "To play, enter the row, column, and number you want to place (example : 3 4 5)." << endl;
    cout << "Enter 0 to exit." << endl;
    game.play();
    return 0;
}