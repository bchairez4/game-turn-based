#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
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

        void displayCharacterStats() const {
            std::cout << "MAX HEALTH: " << current_.getHealth() << '\n';
            std::cout << "ATTACK: " << current_.getAttack() << '\n';
            std::cout << "DEFENSE: " << current_.getDefense() << '\n';
            std::cout << "SPEED: " << current_.getSpeed() << '\n';
        }

        bool isDead() const {
            return (current_.getCurrentHealth() <= 0);
        }
};

#endif
