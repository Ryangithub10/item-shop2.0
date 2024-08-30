#include <stdio.h>
#define uint unsigned int


enum input {
    BUY = 'b',
    SELL = 's',
    TALK = 't',
    QUIT = 'q',
};
char input_values[] = { BUY, SELL, TALK, QUIT };

enum item_category { RESTORE_HP, RESTORE_SP, ARMOR, ACCESSORY, WEAPON };


typedef struct Item {
    enum item_category category;
    char* name;
    uint price;
    union {
        uint hp;
        uint sp;
        uint atk;
        uint def;
    };
    char* desc;
} Item;

typedef struct Player{
    int money;
    struct Item items[10];
} Player;


int is_enum(char var, char enums[]) {
    size_t i = 0;

    while (enums[i] != '\0') {
        if (var == enums[i])
            return 1;

        i++;
    }

    return 0;
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
                puts("this is buy section");
                getchar();
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
