#ifndef _WORK_WITH_BUFFER_H_
#define _WORK_WITH_BUFFER_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

size_t get_file_size(const char* file_name);
int count_of_strings(char* buffer, int size);
char* read_in_buffer(const char* file_name, size_t *size);
char** from_buffer_to_massive_ptrs(char* buffer, int num_of_strs, int size);
void buffer_without_0(char* buffer, int size);

#endif
