#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    private:
        std::string name_;
        int effect_;
    public:
        Item() : name_(""), effect_(0) {}

        Item(const std::string& name, const int& effect) : name_(name), effect_(effect) {}
        
        Item(const Item& other) : name_(other.name_), effect_(other.effect_) {}

        ~Item() {}

        Item& operator=(const Item& other) {
            name_ = other.name_;
            effect_ = other.effect_;
        }

        std::string getName() const {
            return name_;
        }

        int getEffect() const {
            return effect_;
        }
};

#endif
