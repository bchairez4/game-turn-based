#ifndef GAME_H
#define GAME_H

#include <fstream>

#include "Battle.h"

#define CHARACTER_FILE "CharacterData.txt"
#define ITEM_FILE "ItemData.txt"

class Game {
    private:
        Battle battle_;
        std::vector<Character> characterList_;
        std::vector<Item> itemList_;
    public:
        Game() {
            loadCharacters(CHARACTER_FILE);
            loadItems(ITEM_FILE);
        }

        Game(const Game& other) : battle_(other.battle_) {
            for (const Character& c : other.characterList_) {
                characterList_.push_back(c);
            }
        }

        ~Game() {}

        Game& operator=(const Game& other) {
            battle_ = other.battle_;
            for (const Character& c : other.characterList_) {
                characterList_.push_back(c);
            }
        }

        void loadCharacters(const std::string& characterFile) {
            std::ifstream file(characterFile, std::ifstream::in);

            if (!file) {
                return;
            }

            while (!file.eof()) {
                std::string name = "";
                int attack, defense, speed = 0;

                file >> name >> attack >> defense >> speed;

                Character c(name, attack, defense, speed);
                characterList_.push_back(c);
            }

            file.close();
        }

        void loadItems(const std::string& itemFile) {
            std::ifstream file(itemFile, std::ifstream::in);

            if (!file) {
                return;
            }

            while (!file.eof()) {
                std::string type, name = "";
                int effect, quantity = 0;

                file >> type >> name >> effect >> quantity;

                Item item(type, name, effect, quantity);
                itemList_.push_back(item);
            }

            file.close();
        }

        void showCharacters() const {
            for (const Character& character : characterList_) {
                character.displayStats();
                std::cout << '\n';
            }
        }

        Player chooseCharacter(const std::string& selected) {
            for (const Character& character : characterList_) {
                if (selected == character.getName()) {
                    Player player(character, itemList_);
                    return player;
                }
            }
        }

        void start() {}
};

#endif
