#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class Type {
    Health,
    Attack,
    Defense,
    Speed
};

class Item {
    private:
        Type type_;
        std::string name_;
        int effect_;
        int quantity_;
    public:
        Item() : type_(Type::Health), name_(""), effect_(0), quantity_(0) {}

        Item(const std::string& type, const std::string& name, const int& effect, const int& quantity) 
        : name_(name), effect_(effect), quantity_(quantity) {
            if (type == "Health") {
                type_ = Type::Health;
            } else if (type == "Attack") {
                type_ = Type::Attack;
            } else if (type == "Defense") {
                type_ = Type::Defense;
            } else if (type == "Speed") {
                type_ = Type::Speed;
            }
        }

        Item(const Type& type, const std::string& name, const int& effect, const int& quantity)
        : type_(type), name_(name), effect_(effect), quantity_(quantity) {}
        
        Item(const Item& other) 
        : type_(other.type_), name_(other.name_), effect_(other.effect_), quantity_(other.quantity_) {}

        ~Item() {}

        Item& operator=(const Item& other) {
            type_ = other.type_;
            name_ = other.name_;
            effect_ = other.effect_;
            quantity_ = other.quantity_;

            return *this;
        }

        Type getType() const {
            return type_;
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

        void setEffect(const int& effect) {
            effect_ = effect;
        }

        void setQuantity(const int& quantity) {
            if (quantity < 0) {
                quantity_ = 0;
                return;
            }

            quantity_ = quantity;
        }
};

#endif
