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

        Battle(const Player& one, const Player& two)
        : playerOneTurn_(false), one_(one), two_(two) {
            playerOneTurn_ = OneIsFaster();
        }

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

        bool OneIsFaster() const {
            return (one_.speedStat() >= two_.speedStat() ? true : false);
        }

        void setPlayerOne(const Player& one) {
            one_  = one;
        }

        void setPlayerTwo(const Player& two) {
            two_ = two;
        }

        void showMenu(const Player& currentPlayer) const {
            std::cout << currentPlayer.name() << " turn: " << '\n';
            std::cout << "- Attack" << '\n';
            std::cout << "- Defend" << '\n';
            std::cout << "- UseItem" << '\n';
            std::cout << "- Stats" << '\n';
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

            displayResults();
        }

        void mainPhase(Player& currentPlayer, Player& otherPlayer) {
            showMenu(currentPlayer);
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
            std::string input = "";

            std::cout << "Enter an action: ";
            std::getline(std::cin, input);
            std::cout << '\n';

            if (input == "Attack") {
                action = Action::Attack;
            } else if (input == "Defend") {
                action = Action::Defend;
            } else if (input == "UseItem") {
                action = Action::UseItem;
            } else if (input == "Stats") {
                action = Action::Stats;
            }

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
            std::cout << currentPlayer.name() << " attacks " << otherPlayer.name() << "!\n";
            int damage = currentPlayer.attack(otherPlayer);
            
            if (damage > 0) {
                std::cout << damage << " damage! \n" << '\n';
            }
        }

        void defend(Player& currentPlayer) {
            std::cout << currentPlayer.name() << " blocks." << '\n';
            currentPlayer.defend();
            std::cout << '\n';
        }

        void items(Player& currentPlayer, Player& otherPlayer, const std::string& itemName) {
            std::cout <<  currentPlayer.name() << " uses " << itemName << "!\n";
            currentPlayer.useItem(itemName, otherPlayer);
            std::cout << '\n';
        }

        void showStats(const Player& currentPlayer) const {
            std::cout << "Displaying stats: " << '\n'; 
            currentPlayer.displayCharacterStats();
            std::cout << '\n';
        }

        void displayResults() const {
            Player winner = (one_.isDead() ? two_ : one_);

            std::cout << "WINNER! " << winner.name() << '\n';
        }
};

#endif
