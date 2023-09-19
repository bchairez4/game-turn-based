#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"

enum class Action {
    Attack, 
    Defend, 
    UseItem,
    Stats
};

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

        Player getFastest() const {
            return (one_.speedStat() >= two_.speedStat() ? one_ : two_);
        }

        void setPlayerOne(const Player& one) {
            one_  = one;
        }

        void setPlayerTwo(const Player& two) {
            two_ = two;
        }

        void showMenu(const Player& currentPlayer) const {
            std::cout << currentPlayer.name() << " turn: " << '\n';
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
                    mainPhase(one_, two_);
                } else {
                    mainPhase(two_, one_);
                }
                
                playerOneTurn_ = !playerOneTurn_;
            }
        }

        void mainPhase(Player& currentPlayer, Player& otherPlayer) {
            Action action = getAction();
            std::string itemName = (action == Action::UseItem ? getItemName(currentPlayer) : "");

            switch(action) {
                case Action::Attack:
                    attack(currentPlayer, otherPlayer);
                    break;
                case Action::Defend:
                    defend(currentPlayer);
                    break;
                case Action::UseItem:
                    items(currentPlayer, otherPlayer, itemName);
                    break;
                case Action::Stats:
                    showStats(currentPlayer);
                    break;
                default:
                    break;
            }
        }

        Action getAction() const {
            Action action;

            //

            return action;
        }

        std::string getItemName(const Player& currentPlayer) const {
            currentPlayer.displayItems();

            std::string itemName = "";
            std::cout << "Enter the name of the item you want to use: ";
            std::getline(std::cin, itemName);
            std::cout << '\n';

            while(!currentPlayer.containsItem(itemName)) {
                std::cout << "Item name not found. Try again: ";
                std::getline(std::cin, itemName);
                std::cout << '\n';
            }

            return itemName;
        }

        void attack(Player& currentPlayer, Player& otherPlayer) {
            currentPlayer.attack(otherPlayer);
        }

        void defend(Player& currentPlayer) {
            currentPlayer.defend();
        }

        void items(Player& currentPlayer, Player& otherPlayer, const std::string& itemName) {
            currentPlayer.useItem(itemName, otherPlayer);
        }

        void showStats(const Player& currentPlayer) const {
            currentPlayer.displayCharacterStats();
        }
};

#endif
