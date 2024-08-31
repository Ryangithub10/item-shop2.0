#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"

#define MAX 20

struct Player {
    int money;
    struct Item inventory[MAX];
};

void push_item(struct Item item, struct Player *player);

#endif
