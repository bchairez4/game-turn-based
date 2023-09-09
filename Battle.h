#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"

class Battle {
    private:
        bool playerOneTurn_;
        Player one_;
        Player two_;
    public:
        Battle() : playerOneTurn_(true), one_(), two_() {}

        Battle(const bool& playerOneTurn, const Player& one, const Player& two)
        : playerOneTurn_(playerOneTurn), one_(one), two_(two) {}

        Battle(const Battle& other)
        : playerOneTurn_(other.playerOneTurn_), one_(other.one_), two_(other.two_) {}

        ~Battle() {}

        Battle& operator=(const Battle& other) {
            one_ = other.one_;
            two_ = other.two_;

            return  *this;
        }

        Player getPlayerOne() const {
            return one_;
        }

        Player getPlayerTwo() const {
            return two_;
        }

        void setPlayerOne(const Player& one) {
            one_  = one;
        }

        void setPlayerTwo(const Player& two) {
            two_ = two;
        }

        void showMenu() const {
            std::cout << "What would you like to do?" << '\n';
            std::cout << "1) Fight" << '\n';
            std::cout << "2) Defend" << '\n';
            std::cout << "3) Items" << '\n';
            std::cout << "4) Show Stats" << '\n';
            std::cout << '\n';

        }

        void start() {
            while (!one_.isDead() || !two_.isDead()) {
                if (playerOneTurn_) {
                    mainPhase(one_);
                } else {
                    mainPhase(two_);
                }
                
                playerOneTurn_ = !playerOneTurn_;
            }
        }

        void mainPhase(const Player& currentPlayer) {
            char input = ' ';

            showMenu();

            std::cin.get(input);
            std::cin.ignore();
            std::cout << '\n';
            
            switch(input) {
                case '1':
                    attack();
                    break;
                case '2':
                    defend();
                    break;
                case '3':
                    items();
                    break;
                case '4':
                    showStats();
                    break;
                default:
                    break;
            }
        }

        void attack() {}

        void defend() {}

        void items() {}

        void showStats() {
            if (playerOneTurn_) {
                one_.displayCharacterStats();
            } else {
                two_.displayCharacterStats();
            }
        }

        int damageCalculation() {}

};

#endif
