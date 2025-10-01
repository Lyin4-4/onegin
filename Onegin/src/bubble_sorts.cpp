#include "../inc/bubble_sorts.h"

void bubble_sort(char** massive_ptrs, int num_strings, int (*comparator)(const char*, const char*)) {
    assert(massive_ptrs);

    //printf("zalupa\n");

    int flag = 1;
    char* temp = 0;
    for (int i = 0; i < num_strings - 1; i++) {
        flag = 0;
        for (int j = 0; j < num_strings - i - 1; j++) {
            //printf("zalupa\n");
            if ((int)comparator(massive_ptrs[j], massive_ptrs[j + 1]) > 0) {
                temp = massive_ptrs[j];
                //fprintf(stderr, "%p", massive_ptrs[j]);
                massive_ptrs[j] = massive_ptrs[j + 1];
                //fprintf(stderr, "%p", massive_ptrs[i]);

                massive_ptrs[j + 1] = temp;
                //swap_ptrs(&massive_ptrs[j], &massive_ptrs[j + 1]);
                //printf("pipisunchik\n");
                flag = 1;
            }
        }
        //fprintf(stderr, "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
        if (!flag)
            break;
    }
    //printf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    /*for(int i = 0; i < num_strings; i++) {
        puts(massive_ptrs[i]);
    }*/

}

/*void bubble_sort_reverse(char** massive_ptrs, int num_strings) {
    assert(massive_ptrs);

    int flag = 1;
    char* temp = 0;
    for (int i = 0; i < num_strings - 1; i++) {
        flag = 0;
        for (int j = 0; j < num_strings - i - 1; j++) {
            //printf("zalupa\n");
            if (my_reverse_strcmp(massive_ptrs[j], massive_ptrs[j + 1]) > 0) {
                temp = massive_ptrs[j];

                massive_ptrs[j] = massive_ptrs[j + 1];
                massive_ptrs[j + 1] = temp;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}*/

int comparator(const void* s0, const void* s1) {
    char* str1 = *(char**) s0;
    char* str2 = *(char**) s1;

    return my_reverse_strcmp(str1, str2);
}
