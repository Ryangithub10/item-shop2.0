#include <stdio.h>
#include "lib/input.h"
#include "lib/product.h"
#include "lib/character.h"
#include "lib/helper.h"

// Decleration
Character ryan = { "Ryan", 1000000 };
char enum_inputs[] = { ITEM, ACCESSORY, WEAPON, SELL, TALK, QUIT };

// Product items
Product mie_goreng = { 
    .type = ITEM_T, 
    .name = "Mie Goreng", 
    .price = 3000,
};

Product coca_cola = { 
    .type = ITEM_T, 
    .name = "Coca Cola", 
    .price = 5000, 
};

Product pheonix_down = { 
    .type = ITEM_T, 
    .name = "Pheonix Down", 
    .price = 50000,
};

Product *items[] = { &mie_goreng, &coca_cola, &pheonix_down };
const int items_len = sizeof(items) / sizeof(items[0]);
// Product items end

// Function Definition
void print_product(Product **products, size_t len);
void show_menu(Product **products);
void show_desc(Product *product);

int main() {
    char user_input;

    while (1) {
        do {
            if (!user_input)
                printf("WELCOME TO MY CONVINIENT STORE %s!\n\n", ryan.name);
            // TODO: Don't print this when user back
            else if (!is_char_enum(user_input, enum_inputs)) {
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
        } while (!is_char_enum(user_input, enum_inputs));

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
            printf("Health: %d\n", product->hp);
            printf("Price: %d\n", product->price);
            break;
    }
}

void show_menu(Product **products) {
    int input;
    int con;
    int i;

    while (1) { 
        puts("What do you want?\n");

        print_product(products, items_len);

        printf("=> ");
        scanf("%d", &input);

        if (input == 0) {
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
