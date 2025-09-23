#ifndef _BUBBLE_SORTS_H_
#define _BUBBLE_SORTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "my_functions.h"

void bubble_sort(char** massive_ptrs, int num_strings, int (*comparator)(const char*, const char*));
void bubble_sort_reverse(char** massive_ptrs, int num_strings);
int comparator(const void* s0, const void* s1);
#endif
