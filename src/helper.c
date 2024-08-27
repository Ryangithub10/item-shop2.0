#include "helper.h"

int is_enum(char var, char enums[]) {
    int i = 0;

    while (enums[i] != '\0') {
        if (enums[i] == var)
            return 1;
        i++;
    }

    return 0;
}
