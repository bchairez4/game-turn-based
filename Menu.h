#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu {
    private:
        Game game_;
    public:
        Menu() {
            displayWelcome();

            displayMenu();

            char repsonse = ' ';
            std::cin >> repsonse;
            std::cin.ignore();
            std::cout << '\n';
            
            switch(repsonse) {
                case '1':
                    PvE();
                    break;
                case '2':
                    PvP();
                    break;
                default:
                    break;
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
            std::cout << "Turn Based Combat Game" << '\n' << '\n';
        }

        void displayMenu() const {
            std::cout << "Battle Modes:" << '\n';
            std::cout << "-----------------------------------------------------------" << '\n';
            std::cout << "1) Player vs Enemy (PvE)" << '\n';
            std::cout << "2) Player vs Player (PvP)" << '\n';

            std::cout << "Enter a battle mode number: ";
        }

        void displayCharacterSelectWelcome() const {
            std::cout << "Welcome Fighter!" << '\n';
            std::cout << "Choose your champion wisely:" << '\n';
            std::cout << "-----------------------------------------------------------" << '\n';
        }

        void PvE() {
            char response = ' ';
            while (response != 'n') {
                displayCharacterSelectWelcome();
                game_.showCharacters();
                
                std::string selected = getName(1);
                Player one = game_.chooseCharacter(selected);

                game_.startPvEBAttle(one);

                std::cout << "Return to character select? (y or n): ";
                std::cin >> response;
                std::cin.ignore();
                std::cout << '\n';
            }
        }

        void PvP() {
            char response = ' ';
            while (response != 'n') {
                displayCharacterSelectWelcome();
                game_.showCharacters();
                
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
