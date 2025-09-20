#ifndef _WRITE_IN_FILES_H_
#define _WRITE_IN_FILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void write_in_file(FILE* write_file, char* buf);
void write_in_file_from_massive_ptrs(FILE* write_file, char** massive_ptrs, int num_strings);

#endif
