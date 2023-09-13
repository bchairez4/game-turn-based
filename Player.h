#ifndef PLAYER_H
#define PLAYER_H

#include <ctime>
#include <iostream>
#include <vector>

#include "Character.h"
#include "Item.h"

class Player {
    private:
        Character current_;
        std::vector<Item> items_;
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

        std::string name() const {
            return current_.getName();
        }

        int totalHealth() const {
            return current_.getHealth();
        }

        int currentHealth() const {
            return current_.getCurrentHealth();
        }

        int attackStat() const {
            return current_.getAttack();
        }

        int defenseStat() const {
            return current_.getDefense();
        }

        int speedStat() const {
            return current_.getDefense();
        }

        // Fatigue mechanic
        int calculateLifeForce() const {
            if (current_.getCurrentHealth() <= 75) {
                if (current_.getCurrentHealth() <= 50) {
                    if (current_.getCurrentHealth() <= 4 && current_.getCurrentHealth() >= 1) {
                        return -10;
                    }

                    return 4;
                }

                return 2;
            }

            return 0;
        }

        int calculateAttackPower() const {
            return current_.getAttack() - calculateLifeForce();
        }
        
        int getDamageMultipler() const {
            int damageMultiplier = 1;

            std::srand(time(0));
            int crit = 1 + (rand() % 10);
            if (crit == 7) {    //Lucky number 7
                std::cout << "Critical!" << '\n';
                damageMultiplier = 2;
            }

            return damageMultiplier;
        }

        int calculateDefense() const {
            return current_.getDefense();
        }

        void attack(Player& opponent) {
            int damageMultiplier = getDamageMultipler();
            int attackDamage = (calculateAttackPower() * damageMultiplier);

            opponent.receiveDamage(attackDamage);
        }

        void receiveDamage(const int& damage) {
            //Evade chance
            std::srand(time(0));
            int evade = 1 + (rand() % 10);
            if ((evade % current_.getSpeed()) == 7) {   //Lucky number 7
                std::cout << "-Evaded!-" << '\n';
                return;
            }

            //Defend
            int damageReceived = damage - current_.getDefense();
            if (damageReceived <= 0) {
                std::cout << "BLOCKED." << '\n';
                return;
            }

            //Update health
            int updatedHealth = current_.getCurrentHealth() - damageReceived;
            current_.setCurrentHealth(updatedHealth);
        }

        void useItem(const std::string& itemName, const Type& type) {
            for (Item& item : items_) {
                if (itemName == item.getName() && item.getQuantity() > 0) {
                    switch(type) {
                        case Type::Health:
                            current_.setCurrentHealth(current_.getCurrentHealth() + item.getEffect());
                            break;
                        case Type::Attack:
                            current_.setAttack(current_.getAttack() + item.getEffect());
                            break;
                        case Type::Defense:
                            current_.setDefense(current_.getDefense() + item.getEffect());
                            break;
                        case Type::Speed:
                            current_.setSpeed(current_.getSpeed() + item.getEffect());
                            break;
                        default:
                            break;
                    }
                }
            }

        }
};

#endif
