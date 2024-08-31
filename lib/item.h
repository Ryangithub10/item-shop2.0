#ifndef ITEM_H
#define ITEM_H

#define uint unsigned int

enum item_type { 
    RESTORE_HP, RESTORE_SP, ARMOR, ACCESSORY, ACCESSORY_ATK, 
    ACCESSORY_DEF, ACCESSORY_MAX_HP, ACCESSORY_MAX_SP, WEAPON, 
};

struct Stats {
    union {
        uint hp;
        uint sp;
        uint max_hp;
        uint max_sp;
    };
    uint atk;
    uint def;
};

typedef struct Item {
    enum item_type type;
    char* name;
    char* desc;
    uint price;
    uint id;
    struct Stats stats; 
} Item;

#endif
