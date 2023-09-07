#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"

class Battle {
    private:
        Player one_;
        Player two_;
    public:
        Battle() : one_(), two_() {}

        Battle(const Player& one, const Player& two)
        : one_(one), two_(two) {}

        Battle(const Battle& other)
        : one_(other.one_), two_(other.two_) {}

        ~Battle() {}

        Battle& operator=(const Battle& other) {
            one_ = other.one_;
            two_ = other.two_;

            return  *this;
        }
};

#endif
