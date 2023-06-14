#include "../inc/Header.h"

void check_filedata(char *filedata){
    int i = mx_get_char_index(filedata, '\n');
    char *countOfisSTR;
    if (i > 0){
        countOfisSTR = mx_strndup(filedata, i);
    }
    else countOfisSTR = filedata;
    int count_of_islands = mx_atoi(countOfisSTR);
    mx_strdel(&countOfisSTR);
    long sum = 0;
    if (count_of_islands <= 0){
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }
    char **arr = malloc(sizeof(char*) * (count_of_islands + 1));
    int count = 0;
    i++;
    char *delimiters = "-,\n";
    bool invalidNumber = false;
    int j = 1;
    for (; i < mx_strlen(filedata); j++) {
        int start = i;
        while (!mx_strchr(delimiters, filedata[i]) && filedata[i]) {
            i++;
        }
        if (mx_strchr(delimiters, filedata[i+1])){
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(2 + j / 3));
            mx_printerr(" is not valid\n");
            exit(0);
        }
        char *new_island = mx_strndup(&filedata[start], i - start);
        if (j % 3 != 0 && chek_island(new_island, &arr, count, j / 3)) {
            if (count == count_of_islands){
                invalidNumber = true;
            }
            else arr[count++] = mx_strdup(new_island);
        }
        else if (j % 3 == 0 && mx_atoi(new_island) <= 0){
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
    if (j < 4 && j > 1){
        mx_printerr("error: line 2 is not valid\n");
        exit(0);
    }
    bool errorcount = false;
    for (int i = 0; i < count; i++) {
        for (int j = i; j < count; j++) {
            if (checkcount(filedata, arr[i], arr[j]) > 1){
                errorcount = true;
            }
        }
    }
    if (count != count_of_islands || invalidNumber){
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    if (errorcount){
        mx_printerr("error: duplicate bridges\n");
        exit(0);
    }
    if (sum > INT_MAX){
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(0);
    }
    mx_del_strarr(&arr);
}
