#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#define MIN_ 0
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
        bool blocking_;
    public:
        Character() 
        : name_("NULL"), health_(MIN_), currentHealth_(MIN_), attack_(MIN_), defense_(MIN_), speed_(MIN_), blocking_(false) {}

        Character(const std::string& nm, const int& atk, const int& def, const int& sp)
        : name_(nm), health_(MAX_HEALTH), currentHealth_(MAX_HEALTH), attack_(atk), defense_(def), speed_(sp), blocking_(false) {}

        Character(const std::string& nm, const int& hp, const int& chp, const int& atk, const int& def, const int& sp)
        : name_(nm), health_(hp), currentHealth_(chp), attack_(atk), defense_(def), speed_(sp), blocking_(false) {}

        Character(const Character& other)
        : name_(other.name_), health_(other.health_), currentHealth_(other.currentHealth_), 
        attack_(other.attack_), defense_(other.defense_), speed_(other.speed_), blocking_(other.blocking_)  {}

        ~Character() {}

        Character& operator=(const Character& other) {
            name_= other.name_;
            health_ = other.health_;
            currentHealth_ = other.currentHealth_;
            attack_ = other.attack_;
            defense_ = other.defense_;
            speed_ = other.speed_;
            blocking_ = other.blocking_;

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

        bool isBlocking() const {
            return blocking_;
        }

        void setName(const std::string& name) {
            name_ = name;
        }

        void setHealth(const int& health) {
            if (health <= MIN_) {
                health_ = MIN_;
                return;
            }

            if (health > MAX_HEALTH) {
                health_ = MAX_HEALTH;
                return;
            }

            health_ = health;
        }

        void setCurrentHealth(const int& currentHealth) {
            if (currentHealth <= MIN_) {
                currentHealth_ = MIN_;
                return;
            }
            
            if (currentHealth > MAX_HEALTH) {
                currentHealth_ = MAX_HEALTH;
                return;
            }

            currentHealth_ = currentHealth;
        }

        void setAttack(const int& attack) { 
            if (attack <= MIN_) {
                attack_ = MIN_;
                return;
            }

            if (attack > MAX_ATTACK) {
                attack_ = MAX_ATTACK;
                return;
            }

            attack_ = attack; 
        }

        void setDefense(const int& defense) {
            if (defense <= MIN_) {
                defense_ = MIN_;
                return;
            }
            
            if (defense > MAX_DEFENSE) {
                defense_ = MAX_DEFENSE;
                return;
            }

            defense_ = defense;
        }

        void setSpeed(const int& speed) {
            if (speed <= MIN_) {
                speed_ = MIN_;
                return;
            }

            if (speed > MAX_SPEED) {
                speed_ = MAX_SPEED;
                return;
            }

            speed_ = speed;
        }

        void setBlock() {
            blocking_ = !blocking_;
        }

        void displayStats() const {
            std::cout << "NAME: " << name_ << '\n';
            std::cout << "CURRENT HEALTH: " << currentHealth_ << '\n';
            std::cout << "MAX HEALTH: " << health_ << '\n';
            std::cout << "ATTACK: " << attack_ << '\n';
            std::cout << "DEFENSE: " << defense_ << '\n';
            std::cout << "SPEED: " << speed_ << '\n';
        }
};

#endif
