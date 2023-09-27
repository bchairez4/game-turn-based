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

        Player(const Character& current, const std::vector<Item>& items)
        : current_(current), items_(items) {}

        Player(const Player& other)
        : current_(other.current_), items_(other.items_) {}

        ~Player() {}

        Player& operator=(const Player& other) {
            current_ = other.current_;
            items_ = other.items_;

            return *this;
        }

        Character getCurrent() const {
            return current_;
        }

        std::vector<Item> getItems() const {
            return items_;
        }

        void setCurrent(const Character& current) {
            current_ = current;
        }

        void setItems(const std::vector<Item>& items) {
            items_ = items;
        }

        void displayCharacterStats() const {
            current_.displayStats();
        }

        void displayItems() const {
            std::cout << "Available Items: " << '\n';
            for (const Item& item : items_) {
                if (item.getQuantity() > 0) {
                    std::cout << "ITEM NAME: " << item.getName() << '\n';
                    std::cout << "ITEM EFFECT: " << item.getEffect() << '\n';
                    std::cout << "ITEM QUANTITY: " << item.getQuantity() << '\n';
                    std::cout << '\n';
                }
            }
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
            return current_.getSpeed();
        }

        bool isDead() const {
            return (current_.getCurrentHealth() <= 0);
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

        int attack(Player& opponent) {
            int damageMultiplier = getDamageMultipler();
            int attackDamage = (calculateAttackPower() * damageMultiplier);

            int damageRecieved = opponent.receiveDamage(attackDamage);

            return damageRecieved;
        }

        void defend() {
            current_.setBlock();
        }

        int receiveDamage(const int& damage) {
            //Evade chance
            std::srand(time(0));
            int evade = 1 + (rand() % 10);
            if ((evade % current_.getSpeed()) == 7) {   //Lucky number 7
                std::cout << "-Evaded!- \n" << '\n';
                return 0;
            }

            //Defend
            bool blocked = current_.isBlocking(); // is the opponent currently blocking
            int damageReceived = damage - (current_.getDefense())/2;
            if (damageReceived <= 0 || blocked) {
                std::cout << "BLOCKED. \n" << '\n';
                current_.setBlock();    // reset blocking
                return 0;
            }

            //Update health
            int updatedHealth = current_.getCurrentHealth() - damageReceived;
            current_.setCurrentHealth(updatedHealth);
            return damageReceived;
        }

        bool containsItem(const std::string& itemName) const {
            for (const Item& item : items_) {
                if (itemName == item.getName() && item.getQuantity() > 0) {
                    return true;
                }
            }
            
            return false;
        }

        void useItem(const std::string& itemName, Player& other) {
            for (Item& item : items_) {
                if (itemName == item.getName() && item.getQuantity() > 0) {
                    if (item.getEffect() >= 0) {
                        useItemOnSelf(item, item.getType());
                    } else {
                        useItemOnOpponent(item, item.getType(), other.current_);
                    }

                    item.setQuantity(item.getQuantity() - 1);
                }
            }
        }

        void useItemOnSelf(Item& item, const Type& type) {
            switch(type) {
                case Type::Health:
                    current_.setCurrentHealth(current_.getCurrentHealth() + item.getEffect());
                    std::cout << "Regained " << item.getEffect() << " health." << '\n';
                    break;
                case Type::Attack:
                    current_.setAttack(current_.getAttack() + item.getEffect());
                    std::cout << "Attack raised by " << item.getEffect() << " points." << '\n';
                    break;
                case Type::Defense:
                    current_.setDefense(current_.getDefense() + item.getEffect());
                    std::cout << "Defense raised by " << item.getEffect() << " points." << '\n';
                    break;
                case Type::Speed:
                    current_.setSpeed(current_.getSpeed() + item.getEffect());
                    std::cout << "Speed raised by " << item.getEffect() << " points." << '\n';
                    break;
                default:
                    break;
            }
        }

        void useItemOnOpponent(Item& item, const Type& type, Character& other) {
            switch(type) {
                case Type::Health:
                    other.setCurrentHealth(current_.getCurrentHealth() + item.getEffect());
                    std::cout << -(item.getEffect()) << " damage dealt to " << other.getName() << "." << '\n';
                    break;
                case Type::Attack:
                    other.setAttack(current_.getAttack() + item.getEffect());
                    std::cout << other.getName() << " attack lowered by " << -(item.getEffect()) << "." << '\n';
                    break;
                case Type::Defense:
                    other.setDefense(current_.getDefense() + item.getEffect());
                    std::cout << other.getName() << " defense lowered by " << -(item.getEffect()) << "." << '\n';
                    break;
                case Type::Speed:
                    other.setSpeed(current_.getSpeed() + item.getEffect());
                    std::cout << other.getName() << " speed lowered by " << -(item.getEffect()) << "." << '\n';
                    break;
                default:
                    break;
            }
        }
};

#endif
