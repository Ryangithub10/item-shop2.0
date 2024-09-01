#include <stdio.h>
#include "item.h"

void print_items(struct Item *items, size_t len) {
    for (size_t i = 0; i < len; i++) {
        items[i].id = i;
        printf("%ld. %s\t RP. %d\n", i+1, items[i].name, items[i].price);
    }

    puts("0. Back");
}

void show_desc(struct Item item) {
    printf("\n");
    printf("Name: %s\n", item.name);

    switch (item.type) {
        case RESTORE_HP:
            printf("Health: +%d\n", item.stats.hp);
            break;
        case RESTORE_SP:
            printf("Stamina: +%d\n", item.stats.sp);
            break;
        case ACCESSORY:
            printf("Attack: %d\n", item.stats.atk);
            printf("Defense: %d\n", item.stats.def);
            break;
        case ACCESSORY_MAX_HP:
            printf("MAX Health: +%d\n", item.stats.hp);
            break;
        case ACCESSORY_MAX_SP:
            printf("MAX Stamina: +%d\n", item.stats.sp);
            break;
        case ACCESSORY_ATK:
        case WEAPON:
            printf("Attack: %d\n", item.stats.atk);
            break;
        case ACCESSORY_DEF:
        case ARMOR:
            printf("Defense: %d\n", item.stats.def);
            break;
    }

    printf("Price: %d\n", item.price);
    printf("Description: \"%s\"\n", item.desc);
}

void show_items(struct Player *player, struct Item *items, size_t len) {
    int input;
    int con;
    int i;

    while (1) { 
        puts("What do you want?\n");

        printf("Your Money: RP. %d\n", player->money);
        print_items(items, len);

        printf("=> ");
        scanf("%d", &input);

        if (input == 0) {
            getchar();
            break;
        }
        

        do {
            for (i = 0; i < len; i++) {
                if (input - 1 == items[i].id) {
                    show_desc(items[i]);
                    break;
                }
            }

            puts("\nWould you buy it?\n");
            puts("1. Yes\t 0. No");
            printf("=> ");
            scanf("%d", &con);

            if (con == 1) {
                if (player->money < items[i].price)
                    puts("sorry, but you don't have enough money.");
                else {
                    push_item(items[i], player);
                    player->money -= items[i].price;
                    puts("Hehehe, thank you!");
                }
                break;
            }

            else if (con == 0)
                break;

            else
                puts("\n> Please insert valid input!\n");
        } while (con != 1 || con != 0);
    }
}
