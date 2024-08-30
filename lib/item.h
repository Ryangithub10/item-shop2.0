#ifndef ITEM_H
#define ITEM_H

enum item_category { RESTORE_HP, RESTORE_SP, ARMOR, ACCESSORY, WEAPON };

typedef struct Item {
    enum item_category category;
    unsigned int id;
    char* name;
    unsigned int price;
    union {
        unsigned int hp;
        unsigned int sp;
        unsigned int atk;
        unsigned int def;
    };
    char* desc;
} Item;

#endif
