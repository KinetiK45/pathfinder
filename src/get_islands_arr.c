#include "../inc/Header.h"

char **get_islands_arr(char *filedata, int *count_of_islands){
    char *countOfisSTR = mx_strndup(filedata, mx_get_char_index(filedata, '\n'));
    *count_of_islands = mx_atoi(countOfisSTR);
    mx_strdel(&countOfisSTR);
    char **arr = (char**)malloc((*count_of_islands + 1)*sizeof(char*));
    int count = 0;
    int i = mx_get_char_index(filedata, '\n') + 1;
    char delimiters[] = "-,\n";
    for (int j = 1; i < mx_strlen(filedata); j++) {
        int start = i;
        while (!mx_strchr(delimiters, filedata[i]) && filedata[i]) {
            i++;
        }
        char *new_island = mx_strndup(&filedata[start], i - start);
        if (j % 3 != 0 && chek_island(new_island, &arr, count, j / 3)) {
            arr[count++] = mx_strdup(new_island);
        }
        i++;
        mx_strdel(&new_island);
    }
    arr[*count_of_islands] = NULL;
    return arr;
}
