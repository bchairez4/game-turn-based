#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
    private:
        std::string name_;
        int health_;
        int attack_;
        int defense_;
        int speed_;
    public:
        Character() 
        : name_("NULL"), health_(100), attack_(0), defense_(0), speed_(0) {}

        Character(const std::string& nm, const int& hp, const int& atk, const int& df, const int& sp)
        : name_(nm), health_(hp), attack_(atk), defense_(df), speed_(sp) {}

        Character(const Character& other)
        : name_(other.name_), health_(other.health_), attack_(other.attack_), defense_(other.defense_), speed_(other.speed_) {}

        ~Character() {}

        Character& operator=(const Character& other) {
            name_= other.name_;
            health_ = other.health_;
            attack_ = other.attack_;
            defense_ = other.defense_;
            speed_ = other.speed_;

            return *this;
        }
};

#endif
