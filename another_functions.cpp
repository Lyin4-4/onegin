#include "another_functions.h"

int count_of_strings(char* buffer, int size) {
    assert(buffer);

    int iter = 0;
    int counter = 0;

    while (iter < size) {
        if (buffer[iter] == '\n')
            ++counter;
        ++iter;
    }

    if (counter == 0 && size != 0)
        return 1;

    return counter;
}

void swap_ptrs(char** ptr1, char** ptr2) {
    assert(ptr1);
    assert(ptr2);

    char* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    return ;
}

