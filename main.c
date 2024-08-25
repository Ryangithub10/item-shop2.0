#include <stdio.h>

// TODO: Tambahin member inventory
typedef struct Character {
    char* name;
    int money;
    char** inventory;
} Character;

struct Product {
    char* name;
    unsigned int price;
};

const struct Product mie_goreng = { "Mie Goreng", 3000 };
const struct Product coca_cola = { "Coca Cola", 5000 };

const struct Product *items[] = { &mie_goreng, &coca_cola };

const char input_values[] = { 'i', 'a', 'w', 's', 't', 'q' };
enum input { 
    ITEM      = 'i', 
    ACCESSORY = 'a', 
    WEAPON    = 'w', 
    SELL      = 's', 
    TALK      = 't',
    QUIT      = 'q',
};

int is_enum(char var) {
    for (int i = 0; i < (sizeof(input_values) / sizeof(input_values[0])); i++)
        if (input_values[i] == var) { return 1; }

    return 0;
}

void show_menu(const struct Product **products, size_t len) {
    size_t i;
    
    for (i = 0; i < len; i++)
        printf("%ld. %s\t RP. %d\n", i + 1, products[i]->name, products[i]->price);

    printf("%ld. Back\n", ++i);
}

int main() {
    Character ryan = { "Ryan", 1000000 };
    char user_input;

    while (1) {
        do {
            if (!user_input)
                printf("WELCOME TO MY CONVINIENT STORE %s!\n\n", ryan.name);
            else if (!is_enum(user_input)) {
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
        } while (!is_enum(user_input));

        switch(user_input) {
            case ITEM: 
                while (1) {
                    puts("What do you want?\n");

                    show_menu(items, 2);

                    getchar();
                    getchar();
                    break;
                }
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
