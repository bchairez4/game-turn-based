#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu {
    private:
        Game game_;
    public:
        Menu() {
            std::string selected = "";
            game_.showCharacters();
            
            std::cout << "Enter Player one character: ";
            std::getline(std::cin, selected);
            Player one = game_.chooseCharacter(selected);

            std::cout << "Enter Player two character: ";
            std::getline(std::cin, selected);
            Player two = game_.chooseCharacter(selected);

            game_.startBattle(one, two);
        }

        Menu(const Menu& other) : game_(other.game_) {}

        ~Menu() {}

        Menu& operator =(const Menu& other) {
            game_ = other.game_;

            return *this;
        }
};

#endif
