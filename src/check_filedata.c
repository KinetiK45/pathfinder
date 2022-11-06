#include "../inc/Header.h"

void check_filedata(char *filedata){
    char *countOfisSTR = mx_strndup(filedata, mx_get_char_index(filedata, '\n'));
    int count_of_islands = mx_atoi(countOfisSTR);
    mx_strdel(&countOfisSTR);
    long sum = 0;
    if (count_of_islands <= 0){
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    char **arr = malloc(sizeof(char*) * (count_of_islands + 1));
    int count = 0;
    int i = mx_get_char_index(filedata, '\n') + 1;
    char *delimiters = "-,\n";
    bool invalidNumber = false;
    for (int j = 1; i < mx_strlen(filedata); j++) {
        int start = i;
        while (!mx_strchr(delimiters, filedata[i]) && filedata[i]) {
            i++;
        }
        char *new_island = mx_strndup(&filedata[start], i - start);
        if (j % 3 != 0 && chek_island(new_island, &arr, count, j / 3)) {
            if (count == count_of_islands){
                invalidNumber = true;
            }
            else arr[count++] = mx_strdup(new_island);
        }
        else if (j % 3 == 0 && mx_atoi(new_island) < 0){
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(1 + j / 3));
            mx_printerr(" is not valid\n");
            exit(0);
        }
        else if (j % 3 == 0){
            sum += mx_atoi(new_island);
        }
        mx_strdel(&new_island);
        i++;
    }
    if (count != count_of_islands || invalidNumber){
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    for (int i = 0; i < count_of_islands; i++) {
        for (int j = i; j < count_of_islands; j++) {
            checkdup(filedata, arr[i], arr[j]);
        }
    }
    if (sum > INT_MAX){
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
    mx_del_strarr(&arr);
}
