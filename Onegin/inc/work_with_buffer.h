#ifndef _WORK_WITH_BUFFER_H_
#define _WORK_WITH_BUFFER_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* read_in_buffer(FILE* file, size_t *size);
char** from_buffer_to_massive_ptrs(char* buffer, int num_of_strs, int size);
void buffer_without_0(char* buffer, int size);

#endif
