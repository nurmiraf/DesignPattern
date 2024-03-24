#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "board.h"
#include "player.h"

class GameManager {
private:
    Board board;
    Player player;

public:
    GameManager(const std::string& playerName);
    void selectDifficulty();
    void play();
    void makeMove();
};

#endif
