#include <stdio.h>
#include "lib/input.h"
#include "lib/product.h"
#include "lib/character.h"
#include "lib/helper.h"

// Decleration
Character ryan = { "Ryan", 100000 };
char enum_inputs[] = { ITEM, ACCESSORY, WEAPON, SELL, TALK, QUIT };

// Product items
Product mie_goreng = { 
    .type = ITEM_T, 
    .name = "Mie Goreng", 
    .price = 3000,
    .hp = 50,
};

Product coca_cola = { 
    .type = ITEM_T, 
    .name = "Coca Cola", 
    .price = 5000, 
    .hp = 30
};

Product *items[] = { &mie_goreng, &coca_cola };
const int items_len = sizeof(items) / sizeof(items[0]);
// Product items end

// TODO: Bikin Fungsi talk
// Function Definition
void print_product(Product **products, size_t len);
void show_menu(Product **products, size_t len);
void show_desc(Product *product);

int main() {
    char user_input;

    while (1) {
        do {
            if (!user_input)
                puts("WELCOME TO MY CONVINIENT STORE!");
            else if (!is_char_enum(user_input, enum_inputs)) {
                puts("\n> Please insert a valid input");
                getchar();
            } 

            puts("What do you want?\n");

            puts("1. (I)tem");
            puts("2. (A)ccessory");
            puts("3. (W)eapon");
            puts("4. (S)ell");
            puts("5. (T)alk");
            puts("6. (Q)uit");

            printf("=> ");
            scanf("%c", &user_input);
        } while (!is_char_enum(user_input, enum_inputs));

        switch(user_input) {
            case ITEM: 
                show_menu(items, items_len);
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
            puts("\nSee you later...");
            break;
        }
    }

    return 0;
}

void print_product(Product **products, size_t len) {
    size_t i;
    
    for (i = 0; i < len; i++) {
        products[i]->id = i;
        printf("%ld. %s\t RP. %d\n", i + 1, products[i]->name, products[i]->price);
    }

    printf("0. Back\n");
}

void show_desc(Product *product) {
    printf("\n");
    switch (product->type) {
        // TODO: Make case statement for WEAPON_T and ACCESSORY_T
        case ITEM_T:
            printf("Name: %s\n", product->name);
            printf("Health: +%d\n", product->hp);
            printf("Price: %d\n", product->price);
            break;
    }
}

void show_menu(Product **products, size_t products_len) {
    int input;
    int con;
    int i;

    while (1) { 
        puts("What do you want?\n");

        print_product(products, products_len);

        printf("=> ");
        scanf("%d", &input);

        if (input == 0) {
            getchar();
            break;
        }
        
        for (i = 0; i < items_len; i++) {
            if (input - 1 == products[i]->id) {
                show_desc(products[i]);
                break;
            }
        }

        puts("\nWould you buy it?\n");
        puts("1. Yes\t 0. No");
        printf("=> ");
        scanf("%d", &con);

        if (con == 1) {
            if (ryan.money < products[i]->price)
                puts("sorry, but you don't have enough money.");
            else {
                puts("Hehehe, thank you!");
                ryan.money -= products[i]->price;
            }
        }   
    }
}
