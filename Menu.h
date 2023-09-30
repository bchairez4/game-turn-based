#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu {
    private:
        Game game_;
    public:
        Menu() {
            displayWelcome();
            game_.showCharacters();

            char response = ' ';
            while (response != 'n') {
                std::string selected = getName(1);
                Player one = game_.chooseCharacter(selected);

                selected = getName(2);
                Player two = game_.chooseCharacter(selected);

                game_.startPvPBattle(one, two);

                std::cout << "Return to character select? (y or n): ";
                std::cin >> response;
                std::cin.ignore();
                std::cout << '\n';
            }

            displayFarewell();
        }

        Menu(const Menu& other) : game_(other.game_) {}

        ~Menu() {}

        Menu& operator =(const Menu& other) {
            game_ = other.game_;

            return *this;
        }

        void displayWelcome() const {
            std::cout << "Welcome Fighter!" << '\n';
            std::cout << "Choose your champion wisely:" << '\n';
            std::cout << "-----------------------------------------------------------" << '\n';
        }

        void displayFarewell() const {
            std::cout << "Thank you for playing!" << '\n';
        }

        std::string getName(const int& playerNumber) {
            std::string selected = "";

            std::cout << "Enter Player " << playerNumber <<  " Fighter name: ";
            std::getline(std::cin, selected);
            std::cout << '\n';

            while(!game_.containsCharacter(selected)) {
                std::cout << "Fighter name not found. Try again: ";
                std::getline(std::cin, selected);
                std::cout << '\n';
            }

            return selected;
        }
};

#endif
