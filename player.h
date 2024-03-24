#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;

public:
    Player(const std::string& playerName);
    std::string getName() const;
};

#endif
