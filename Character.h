#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#define MAX_HEALTH 100
#define MAX_ATTACK 50
#define MAX_DEFENSE 75
#define MAX_SPEED 25

class Character {
    private:
        std::string name_;
        int health_;
        int currentHealth_;
        int attack_;
        int defense_;
        int speed_;
    public:
        Character() 
        : name_("NULL"), health_(0), currentHealth_(0), attack_(0), defense_(0), speed_(0) {}

        Character(const std::string& nm, const int& hp, const int& chp, const int& atk, const int& df, const int& sp)
        : name_(nm), health_(hp), currentHealth_(chp), attack_(atk), defense_(df), speed_(sp) {}

        Character(const Character& other)
        : name_(other.name_), health_(other.health_), currentHealth_(other.currentHealth_), attack_(other.attack_), defense_(other.defense_), speed_(other.speed_) {}

        ~Character() {}

        Character& operator=(const Character& other) {
            name_= other.name_;
            health_ = other.health_;
            currentHealth_ = other.currentHealth_;
            attack_ = other.attack_;
            defense_ = other.defense_;
            speed_ = other.speed_;

            return *this;
        }

        std::string getName() const { 
            return name_; 
        }

        int getHealth() const { 
            return health_; 
        }

        int getCurrentHealth() const {
            return currentHealth_;
        }
    
        int getAttack() const { 
            return attack_; 
        }
    
        int getDefense() const { 
            return defense_; 
        }

        int getSpeed() const {
            return speed_;
        }

        void setName(const std::string& name) {
            name_ = name;
        }

        void setHealth(const int& health) {
            if (health > MAX_HEALTH) {
                health_ = MAX_HEALTH;
                return;
            }

            health_ = health;
        }

        void setCurrentHealth(const int& currentHealth) {
            if (currentHealth > MAX_HEALTH) {
                currentHealth_ = MAX_HEALTH;
                return;
            }

            currentHealth_ = currentHealth;
        }

        void setAttack(const int& attack) { 
            if (attack > MAX_ATTACK) {
                health_ = MAX_ATTACK;
                return;
            }

            attack_ = attack; 
        }

        void setDefense(const int& defense) {
            if (defense > MAX_DEFENSE) {
                health_ = MAX_DEFENSE;
                return;
            }

            defense_ = defense;
        }

        void setSpeed(const int& speed) {
            if (speed > MAX_SPEED) {
                speed_ = MAX_SPEED;
                return;
            }

            speed_ = speed;
        }
};

#endif
