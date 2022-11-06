#include "../inc/Header.h"

int getIndexOfIsland(char *island, char **arr){
    for (int i = 0; arr[i]; i++) {
        if (mx_strcmp(island, arr[i]) == 0) return i;
    }
    return 0;
}
