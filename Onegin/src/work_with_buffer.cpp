#include "../inc/work_with_buffer.h"

size_t get_file_size(const char* file_name) {
    assert(file_name);

    struct stat buf = {};

    stat(file_name, &buf);

    return buf.st_size;
}

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

char* read_in_buffer(const char* file_name, size_t *size) {
    assert(size);

    FILE* file = fopen(file_name, "r");
    assert(file);

    char* buffer = (char*) calloc(*size + 1, sizeof(char));

    //printf("7\n");

    assert(buffer);

    //printf("6\n");

    int size_read = fread(buffer, sizeof(char), *size, file);

    //printf("new size %d\n", size_read);

    *size = size_read;

    buffer = (char*)realloc(buffer, size_read + 1);

    fclose(file);

    return buffer;
}

char** from_buffer_to_massive_ptrs(char* buffer, int num_of_strs, int size) {
    //printf("num_of_strs: %d\n", num_of_strs);
    assert(buffer);

    //printf("pipipipipi\n");

    char* temp = buffer;

    //printf("num_of_strs: %d", num_of_strs);

    char** massive_ptrs = (char**) calloc(num_of_strs, sizeof(char*));
    //printf("%d", num_of_strs);

    int counter = 0;

    massive_ptrs[0] = buffer;
    //printf("%p\n", *massive_ptrs);

    int size_counter = 0;

    while(size_counter < size) {
        //printf("%d\n", counter);
        if (buffer[size_counter] == '\n') {
            ++counter;
            //printf("%d\n", counter);
            //fprintf(stderr, "\n%d\n", counter);
            buffer[size_counter] = '\0';
            //fprintf(stderr, "%c\n", buffer[size_counter]);
            massive_ptrs[counter] = (buffer + size_counter + 1);
            //fprintf(stderr, "%p %c\n", massive_ptrs[counter], *massive_ptrs[counter]);
            //printf("%p\n", (*massive_ptrs + counter));
        }
        size_counter++;
    }
    /*
    for(int i = 0; i < num_of_strs; i++) {
        puts(massive_ptrs[i]);
    }
    */

    return massive_ptrs;
}

void buffer_without_0(char* buffer, int size) {
    assert(buffer);

    for (int i = 0; i < size - 1; i++) {
        //fprintf(stderr, "[%d] %c\n", i, buffer[i]);
        if (buffer[i] == '\0')
            buffer[i] = '\n';
    }
}
