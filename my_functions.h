#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int           my_puts(const char* str);
const char*   my_strchr(const char* str, int find_ch);
size_t        my_strlen(const char* str);
char*         my_strcpy(char* to_str, const char* from_str);
char*         my_strncpy(char* to_str, const char* from_str, int n);
char*         my_strcat(const char* str, char* in_str);
char*         my_strncat(const char* str, char* in_str, int n);
int           my_atoi(const char* str);
char*         my_fgets(char *s, int n, FILE *file_ptr);
char*         my_strdup(const char* s);
int           my_getline(char** str, size_t* n, FILE* file_ptr);
int           my_strcmp( const char *s0, const char *s1 );
int           my_reverse_strcmp(const char* s0, const char* s1);

#endif
