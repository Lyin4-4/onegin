#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../inc/work_with_buffer.h"
#include "../inc/bubble_sorts.h"
#include "../inc/write_in_files.h"
#include "../inc/my_functions.h"

#define SORT_ONEGIN "\n\n---------------------SORT ONEGIN---------------------\n\n"
#define SORT_ONEGIN_FROM_END "\n\n---------------------SORT ONEGIN FROM END---------------------\n\n"
#define ORIGINAL_ONEGIN "\n\n---------------------ORIGINAL ONEGIN---------------------\n\n"
#define FILE_NAME_OUTPUT "../out_file1.txt"
#define FILE_NAME_INPUT "../test_file.txt"

int main() {
    size_t file_size = get_file_size(FILE_NAME_INPUT);

    char* buffer = read_in_buffer(FILE_NAME_INPUT, &file_size);

    int num_of_strings = count_of_strings(buffer, file_size);

    buffer_without_0(buffer, file_size);

    char** string_ptrs = from_buffer_to_massive_ptrs(buffer, num_of_strings, file_size);

    printf("%d\n", num_of_strings);

    bubble_sort(string_ptrs, num_of_strings, my_strcmp);

    FILE* write_file = fopen(FILE_NAME_OUTPUT, "w");
    fclose(write_file);

    //fprintf(write_file, SORT_ONEGIN);

    write_in_file_from_massive_ptrs(FILE_NAME_OUTPUT, string_ptrs, num_of_strings, SORT_ONEGIN);

    //fprintf(write_file, SORT_ONEGIN_FROM_END);

    //bubble_sort_reverse(string_ptrs, num_of_strings);

    //qsort(string_ptrs, num_of_strings, sizeof(char*), &comparator);

    bubble_sort(string_ptrs, num_of_strings, my_reverse_strcmp);

    write_in_file_from_massive_ptrs(FILE_NAME_OUTPUT, string_ptrs, num_of_strings,
                                                        SORT_ONEGIN_FROM_END);

    //fprintf(write_file, ORIGINAL_ONEGIN);

    buffer_without_0(buffer, file_size);

    write_in_file(FILE_NAME_OUTPUT, buffer, ORIGINAL_ONEGIN);

    return 0;
}
