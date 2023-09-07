#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
    private:
        Character current_;
    public:
        Player() : current_() {}

        Player(const Character& current)
        : current_(current) {}

        Player(const Player& other)
        : current_(other.current_) {}

        ~Player() {}

        Player& operator=(const Player other) {
            current_ = other.current_;

            return *this;
        }
};

#endif
