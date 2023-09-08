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

        Character getCurrent() const {
            return current_;
        }

        void setCurrent(const Character& current) {
            current_ = current;
        }
};

#endif
