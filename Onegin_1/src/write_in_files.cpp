#include "../inc/write_in_files.h"

void write_in_file(const char* file_name, char* buf, const char* type_onegin) {
    assert(buf);

    FILE* write_file = fopen(file_name, "a");
    assert(write_file);

    fprintf(write_file, type_onegin);
    fprintf(write_file, "%s", buf);

    fclose(write_file);
}

void write_in_file_from_massive_ptrs(const char* file_name, char** massive_ptrs,
                                    int num_strings, const char* type_onegin) {
    assert(massive_ptrs);

    FILE* write_file = fopen(file_name, "a");
    assert(write_file);

    fprintf(write_file, type_onegin);

    for (int i = 0; i < num_strings; i++) {
        fprintf(write_file, "%s\n", massive_ptrs[i]);
    }

    fclose(write_file);
}
