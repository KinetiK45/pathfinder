#include "../inc/Header.h"

bool chek_island(char *island, char ***arr, int size, int line){
    if (!mx_strlen(island)){
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(2 + line));
        mx_printerr(" is not valid\n");
        exit(0);
    }
    for (int j = 0; j < mx_strlen(island); j++) {
        if (!mx_isalpha(island[j])) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(2 + line));
            mx_printerr(" is not valid\n");
            exit(0);
        }
    }
    for (int i = 0; i < size; i++) {
        if (mx_strcmp(arr[0][i], island) == 0) return false;
    }
    return true;
}
