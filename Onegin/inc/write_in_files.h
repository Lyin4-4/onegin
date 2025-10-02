#ifndef _WRITE_IN_FILES_H_
#define _WRITE_IN_FILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void write_in_file(const char* file_name, char* buf, const char* type_onegin);
void write_in_file_from_massive_ptrs(const char* file_name, char** massive_ptrs,
                                    int num_strings, const char* type_onegin);

#endif
