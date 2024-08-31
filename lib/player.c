#include <stdio.h>
#include "player.h"

int top = -1;

void push_item(struct Item item, struct Player *player) {
    if (top == MAX - 1) {
        puts("Exception: Stack Overflow");
        return;
    }

    player->inventory[++top] = item;
}
