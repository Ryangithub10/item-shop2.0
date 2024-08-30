#include <stdio.h>
#include "lib/item.h"

typedef struct Player{
    int money;
    struct Item items[10];
} Player;


enum input {
    BUY = 'b',
    SELL = 's',
    TALK = 't',
    QUIT = 'q',
};
char input_values[] = { BUY, SELL, TALK, QUIT };


struct Item items[] = {
    {
        .category = RESTORE_HP,
        .name = "Mie Goreng",
        .price = 3000,
        .hp = 100,
    },
    {
        .category = RESTORE_HP,
        .name = "Coca Cola",
        .price = 5000,
        .hp = 150,
    },
};
size_t items_length = sizeof(items) / sizeof(items[0]);


int is_enum(char var, char enums[]) {
    size_t i = 0;

    while (enums[i] != '\0') {
        if (var == enums[i])
            return 1;

        i++;
    }

    return 0;
}

void print_items(struct Item *items, size_t len) {
    for (size_t i = 0; i < len; i++) {
        items[i].id = i;
        printf("%ld. %s\t RP. %d\n", i+1, items[i].name, items[i].price);
    }

    puts("0. Back");
}


int main() {
    Player player = { 100000 };
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
                getchar();
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
