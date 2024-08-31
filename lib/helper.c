#include <stddef.h>
#include "helper.h"

int is_enum(char var, char enums[]) {
    size_t i = 0;

    while (enums[i] != '\0') {
        if (var == enums[i])
            return 1;

        i++;
    }

    return 0;
}
