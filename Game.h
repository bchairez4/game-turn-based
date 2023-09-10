#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Battle.h"

class Game {
    private:
        //
    public:
        Game() {}
        Game(const Game& other) {}
        ~Game() {}
        Game& operator=(const Game& other) {}
        void characterSelection();
        void start();
        void results();
};

#endif
