#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    private:
        std::string name_;
        int effect_;
        int quantity_;
    public:
        Item() : name_(""), effect_(0), quantity_(0) {}

        Item(const std::string& name, const int& effect, const int& quantity)
        : name_(name), effect_(effect), quantity_(quantity) {}
        
        Item(const Item& other) 
        : name_(other.name_), effect_(other.effect_), quantity_(other.quantity_) {}

        ~Item() {}

        Item& operator=(const Item& other) {
            name_ = other.name_;
            effect_ = other.effect_;
            quantity_ = other.quantity_;

            return *this;
        }

        std::string getName() const {
            return name_;
        }

        int getEffect() const {
            return effect_;
        }

        int getQuantity() const {
            return quantity_;
        }

        void setQuantity(const int& quantity) {
            quantity_ = quantity;
        }
};

#endif
