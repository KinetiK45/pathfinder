#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim){
    if (arr == NULL || delim == NULL) return;
    int i = 1;
    mx_printstr(arr[0]);
    while (arr[i] != NULL) {
        mx_printstr(delim);
        mx_printstr(arr[i]);
        i++;
    }
    mx_printchar('\n');
}
