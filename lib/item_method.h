#ifndef ITEM_METHOD_H
#define ITEM_METHOD_H

#include "player.h"
void print_items(struct Item *items, size_t len);
void show_desc(struct Item item);
void show_items(struct Player *player, struct Item *items, size_t len);

#endif
