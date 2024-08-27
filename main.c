#include <stdio.h>
#include "src/input.h"
#include "src/product.h"
#include "src/character.h"
#include "src/helper.h"

// Decleration
Character ryan = { "Ryan", 1000000 };
const Product mie_goreng = { ITEM_T, "Mie Goreng", 3000 };
const Product coca_cola = { ITEM_T, "Coca Cola", 5000 };
const Product pheonix_down = { ITEM_T, "Pheonix Down", 50000 };
const Product *items[] = { &mie_goreng, &coca_cola, &pheonix_down };
const int items_len = sizeof(items) / sizeof(items[0]);

// Function Definition
void print_product(const Product **products, size_t len);
void show_menu(const Product **products);
void show_desc(const Product **products);

int main() {
    char user_input;

    while (1) {
        do {
            if (!user_input)
                printf("WELCOME TO MY CONVINIENT STORE %s!\n\n", ryan.name);
            else if (!is_enum(user_input, input_values)) {
                puts("\nPlease insert a valid input\n");
                getchar();
            }

            puts("1. (I)tem");
            puts("2. (A)ccessory");
            puts("3. (W)eapon");
            puts("4. (S)ell");
            puts("5. (T)alk");
            puts("6. (Q)uit");

            printf("=> ");
            scanf("%c", &user_input);
        } while (!is_enum(user_input, input_values));

        switch(user_input) {
            case ITEM: 
                show_menu(items);
                break;
            case ACCESSORY:
                puts("This is Accessory section");
                getchar();
                getchar();
                break;
            case WEAPON:
                puts("This is Weapon section");
                getchar();
                getchar();
                break;
            case SELL:
                puts("This is Sell section");
                getchar();
                getchar();
                break;
            case TALK:
                puts("This is Talk section");
                getchar();
                getchar();
                break;
        } 

        if (user_input == QUIT) {
            puts("\nHave a nice time my boy!");
            break;
        }
    }

    return 0;
}

void print_product(const Product **products, size_t len) {
    size_t i;
    
    for (i = 0; i < len; i++)
        printf("%ld. %s\t RP. %d\n", i + 1, products[i]->name, products[i]->price);

    printf("%ld. Back\n", ++i);
}

void show_menu(const Product **products) {
    while (1) {
        puts("What do you want?\n");

        print_product(products, items_len);

        getchar();
        getchar();
        break;
    }
}
