#ifndef NPC_H
#define NPC_H

#include "Player.h"

class NPC : public Player {
    private:
        //
    public:
        NPC() {}

        NPC(const Character& character, const std::vector<Item>& itemList) {
            setCurrent(character);
            setItems(itemList);
        }

        NPC(const NPC& other) {
            setCurrent(other.getCurrent());
            setItems(other.getItems());
        }

        ~NPC() {}

        NPC& operator=(const NPC& other) {
            setCurrent(other.getCurrent());
            setItems(other.getItems());

            return *this;
        }
};

#endif
