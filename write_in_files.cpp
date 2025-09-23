#include "write_in_files.h"

void write_in_file(FILE* write_file, char* buf) {
    assert(write_file);
    assert(buf);

    fprintf(write_file, "%s", buf);

    return ;
}

void write_in_file_from_massive_ptrs(FILE* write_file, char** massive_ptrs, int num_strings) {
    assert(write_file);
    assert(massive_ptrs);

    for (int i = 0; i < num_strings; i++) {
        fprintf(write_file, "%s\n", massive_ptrs[i]);
    }

    return ;
}
