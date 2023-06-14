#include "../inc/Header.h"

void calculate_ways(char *filedata){
    int islands_size = 0;
    int ways_size = 0;
    int arr_size = 0;
    char **arr = get_islands_arr(filedata, &islands_size);
    while (arr[arr_size]){
        arr_size++;
    }
    t_ways *waysArr = get_ways_arr(filedata, &ways_size);
    for (int i = 0; i < islands_size - 1; i++) {
        for (int j = i + 1; j < islands_size; j++) {
            calculate_way(i, j, arr, waysArr);
        }
    }
    mx_del_strarr(&arr);
    for (int i = 0; waysArr[i].island1; i++) {
        free(waysArr[i].island1);
        free(waysArr[i].island2);
    }
    free(waysArr);
}
