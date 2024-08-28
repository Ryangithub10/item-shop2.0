#include "helper.h"

int is_char_enum(char var, char enums[]) {
    int i = 0;

    while (enums[i]) {
        if (enums[i] == var)
            return 1;
        i++;
    }

    return 0;
}

int is_enum(int var, int enums[]) {
    int i = 0;

    while (enums[i]) {
        if (enums[i] == var)
            return 1;
        i++;
    }

    return 0;
}
