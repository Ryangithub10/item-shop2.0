#ifndef INPUT_H
#define INPUT_H

#define LEN_INPUT 6

const char input_values[LEN_INPUT] = { 'i', 'a', 'w', 's', 't', 'q' };

enum input { 
    ITEM      = 'i', 
    ACCESSORY = 'a', 
    WEAPON    = 'w', 
    SELL      = 's', 
    TALK      = 't',
    QUIT      = 'q',
};

#endif
