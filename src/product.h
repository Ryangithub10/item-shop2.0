#ifndef PRODUCT_H
#define PRODUCT_H

enum product_type { ITEM_T, ACCESSORY_T, WEAPON_T };

// TODO: Bikin union Props untuk Product sebagai stats suatu item
typedef struct Product {
    enum product_type type;
    char* name;
    unsigned int price;
    union {
        unsigned int hp, sp, atk, def;
    };
    unsigned int id;
    char *desc;
} Product;

#endif
