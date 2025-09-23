#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "work_with_buffer.h"
#include "bubble_sorts.h"
#include "write_in_files.h"
#include "another_functions.h"
#include "my_functions.h"

#define SORT_ONEGIN "\n\n---------------------SORT ONEGIN---------------------\n\n"
#define SORT_ONEGIN_FROM_END "\n\n---------------------SORT ONEGIN FROM END---------------------\n\n"
#define ORIGINAL_ONEGIN "\n\n---------------------ORIGINAL ONEGIN---------------------\n\n"

size_t get_file_size(const char* file_name) {
    assert(file_name);

    struct stat buf = {};

    stat(file_name, &buf);

    return buf.st_size;
}

int main() {
    FILE* my_file = fopen("test_file.txt", "r");
    assert(my_file);
    //printf("vevre\n");

    size_t file_size = get_file_size("test_file.txt");
    //printf("%d\n", file_size);

    char* buffer = read_in_buffer(my_file, &file_size);
    //printf("rregegegg\n");

    int num_of_strings = count_of_strings(buffer, file_size);
    //printf("%d\n", num_of_strings);

    //file_size -= num_of_strings;

    buffer_without_0(buffer, file_size);
    //printf("rhehieheiuh\n");

    char** string_ptrs = from_buffer_to_massive_ptrs(buffer, num_of_strings, file_size);

    printf("%d\n", num_of_strings);
    for (int i = 0; i < num_of_strings; i++) {
        //printf("%p\n", string_ptrs[i]);
    }
    bubble_sort(string_ptrs, num_of_strings, my_strcmp);

    //printf("zdfdfwgr\n");

    /*for (int i = 0; i < num_of_strings; i++) {
            printf("%s", string_ptrs[i]);
        }
    */

    FILE* write_file = fopen("out_file1.txt", "w");

    fprintf(write_file, SORT_ONEGIN);

    write_in_file_from_massive_ptrs(write_file, string_ptrs, num_of_strings);

    fprintf(write_file, SORT_ONEGIN_FROM_END);

    //bubble_sort_reverse(string_ptrs, num_of_strings);

    //qsort(string_ptrs, num_of_strings, sizeof(char*), &comparator);

    bubble_sort(string_ptrs, num_of_strings, my_reverse_strcmp);

    write_in_file_from_massive_ptrs(write_file, string_ptrs, num_of_strings);

    fprintf(write_file, ORIGINAL_ONEGIN);

    buffer_without_0(buffer, file_size);

    write_in_file(write_file, buffer);

    fclose(write_file);

    fclose(my_file);

    return 0;
}
