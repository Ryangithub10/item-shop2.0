#include <stdio.h>
#include "bundle.h"

struct Item items[] = {
    {
        .type = RESTORE_HP,
        .name = "Mie Goreng",
        .price = 3000,
        .stats = {
            .hp = 100,
        },
        .desc = "Just Mie Goreng",
    },
    {
        .type = RESTORE_HP,
        .name = "Coca Cola",
        .price = 5000,
        .stats = {
            .hp = 150,
        },
        .desc = "Just Coca Cola",
    },
    {
        .type = ACCESSORY_DEF,
        .name = "Ring",
        .price = 100000,
        .stats = {
            .def = 300,
        },
        .desc = "Just Ring",
    },
    {
        .type = ACCESSORY_MAX_SP,
        .name = "Capsule Pouch",
        .price = 100000,
        .stats = {
            .sp = 100,
        },
        .desc = "Increse capacity of SP",
    }
};
size_t items_length = sizeof(items) / sizeof(items[0]);


enum input { BUY = 'b', SELL = 's', TALK = 't', QUIT = 'q', };
char input_values[] = { BUY, SELL, TALK, QUIT };


int main() {
    struct Player player = { 100000, {} };
    char user_input;

    while (1) {
        do {
            if (!user_input) 
                puts("Welcome to my store!");

            else if (!is_enum(user_input, input_values)) {
                puts("\n> Please insert valid input!");
                getchar();
            }

            puts("What do you want\n");

            puts("1. (B)uy");
            puts("2. (S)ell");
            puts("3. (T)alk");
            puts("4. (Q)uit");

            printf("=> ");
            scanf("%c", &user_input);
        } while (!is_enum(user_input, input_values));

        switch (user_input) {
            case BUY:
                show_items(&player, items, items_length);
                break;
            case SELL:
                puts("this is sell section");
                getchar();
                getchar();
                break;
            case TALK:
                puts("this is talk section");
                getchar();
                getchar();
                break;
        }

        if (user_input == QUIT) {
            puts("See you later...");
            break;
        }
    }
}
