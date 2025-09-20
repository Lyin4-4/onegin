#include "my_functions.h"

int my_puts(const char* str) {
    assert(str);

    while (*str != '\0') {
        printf("%c", *str++);
    }

    putchar('\n');

    return ferror(stdout) ? EOF : 0;
}

const char* my_strchr(const char* str, int find_ch) {
    assert(str);

    while (*str != '\0' && *str != find_ch) {
        str++;

        if (*str == find_ch) {

            return str;
        }
    }

    return NULL;
}

size_t my_strlen(const char* str) {
    assert(str);

    int cnt = 0;
    while (*str != '\0') {
        str++;
        ++cnt;
    }

    return cnt;
}

char* my_strcpy(char* to_str, const char* from_str) {
    assert(to_str);
    assert(from_str);

    char* var = to_str;

    while ((*to_str = *from_str) != '\0') {
        to_str++;
        from_str++;
    }

    return var;
}

char* my_strncpy(char* to_str, const char* from_str, int n) {
    assert(to_str);
    assert(from_str);

    int cnt = 0;

    char* var = to_str;

    *to_str = *from_str;
    cnt++;

    while ((*to_str != '\0') && (cnt++ < n)) {
        to_str++;
        from_str++;
        *to_str = *from_str;
    }

    return var;
}

char* my_strcat(const char* str, char* in_str) {
    assert(str);
    assert(in_str);

    char* var = in_str;

    while (*in_str != '\0')
        in_str++;

    in_str--;

    while (*str != '\0') {
        *in_str = *str;
        str++;
        in_str++;
    }
    *in_str = '\0';

    return var;
}

char* my_strncat(const char* str, char* in_str, int n) {
    assert(str);
    assert(in_str);

    char* var = in_str;

    while (*in_str++ != '\0');
    in_str--;

    int cnt = 0;

    while ((*str != '\0') && cnt < n){
        cnt++;
        *in_str = *str;
        str++;
        in_str++;
    }
    *in_str = '\0';

    return var;
}

int my_atoi(const char* str) {
    assert(str);

    int n = 0;

    while (*str >= '0' && *str <= '9') {
        n = n * 10 + (*str - '0');
        str++;
    }

    return n;
}

char* my_fgets(char *s, int n, FILE *file_ptr) {
    assert(s);
    assert(file_ptr);

    int cnt = 0;
    int c = 0;
    char* cs = 0;

    cs = s;
    c = getc(file_ptr);
    cnt++;

    while((cnt < n) && (c != EOF)) {
        cnt++;
        *cs = c;
        if (*cs == '\n') {
            cs++;
            break;
        }
        cs++;
        c = getc(file_ptr);
    }
    *cs = '\0';

    return (c == EOF && cs == s) ? NULL : s;
}

char* my_strdup(const char* s) {
    assert(s);

    char* p = NULL;

    p = (char*) calloc(sizeof(s), sizeof(*s));
    assert(p);

    if (p != NULL) {
        my_strcpy(p, s);
    }

    return p;
}

int my_getline(char** str, size_t* n, FILE* file_ptr) {
    assert(str);
    assert(*str);
    assert(n);
    assert(file_ptr);

    *str = (char*)calloc(*n, sizeof(char));
    assert(*str);

    int cnt = 0;
    char c = 0;

    while (cnt < *n && (c = getc(file_ptr)) != EOF) {
        if (cnt + 1 == *n) {
            *str = (char*)realloc(*str - cnt, *n + 100); // uvelichivat v 1,2 raza
            *n += 100;
            assert(*str);
            *str = *str + cnt;
        }
        if (c == '\n') {
            **str = c;
            cnt++;
            (*str)++;
            break;
        }

        **str = c;
        (*str)++;
        cnt++;
    }

    if (c == EOF) {
        return -1;
    }

    **str = '\0';
    if (cnt < *n) {
        *str = (char*)realloc(*str - cnt, strlen(*str - cnt));
        assert(*str);
    }
    else {
        *str -= cnt;
    }

    *n = cnt;

    return cnt;
}

/*int strcmp(const char* s1, const char* s2) {
    int flag = 1;
    int flag1 = 1;
    int cnt1 = 0;
    int cnt2 = 0;
    while (flag) {
        if (tolower(s1[cnt1])) {
            while (flag1) {
                if (tolower(s2[cnt2])) {
                    flag1 = 0;
                    break;
                }
                else if (s2[cnt2] == '\0')
                    break;
                ++cnt2;
            }
            if (flag1 == 0) {

            }
        }
            return 0;
    }
}*/

int my_strcmp(const char *s0, const char *s1 ){

    while( *s0 != '\0' && *s1 != '\0'){
        if (isalpha(*s0) == 0)
            s0++;
        else if (isalpha(*s1) == 0)
            s1++;
        else if (tolower(*s0) == tolower(*s1)){
            s0++;
            s1++;
        }
        else
            break;
    }
    return tolower(*s0) - tolower(*s1);
}

int my_reverse_strcmp(const char* s0, const char* s1) {
    int flag0 = 1;
    int flag1 = 1;
    int cnt0 = 0;
    int cnt1 = 0;

    while((flag0 + flag1) != 0) {
        if (*s0 != '\0') {
            ++cnt0;
            ++s0;
        } else flag0 = 0;
        if (*s1 != '\0') {
            ++cnt1;
            ++s1;
        } else flag1 = 0;
    }

    int chet0 = 0;
    int chet1 = 0;

    while(chet0 < cnt0 && chet1 < cnt1){
        if (isalpha(*s0) == 0){
            s0--;
            chet0++;
        }
        else if (isalpha(*s1) == 0) {
            s1--;
            chet1++;
        }
        else if (tolower(*s0) == tolower(*s1)){
            s0--;
            chet1++;
            chet0++;
            s1--;
        }
        else
            break;
    }
    return tolower(*s0) - tolower(*s1);

}



