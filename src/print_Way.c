#include "../inc/Header.h"

void print_Way(int maxsize, int *result, char **arr, t_ways *waysArr){
    int size = maxsize;
    for (int i = 0; i < maxsize; i++) {
        if (result[i] == -1){
            size = i;
            break;
        }
    }
    mx_printstr("========================================\nPath: ");
    mx_printstr(arr[result[0]]);
    mx_printstr(" -> ");
    mx_printstr(arr[result[size - 1]]);
    mx_printstr("\nRoute: ");
    mx_printstr(arr[result[0]]);
    for (int k = 1; k < size; k++) {
        if (result[k] != -1){
            mx_printstr(" -> ");
            mx_printstr(arr[result[k]]);
        }
    }
    if (size > 2){
        mx_printstr("\nDistance: ");
        int sum = getDistanceBetweenbyIndex(result[0], result[1], arr, waysArr);
        mx_printint(sum);
        for (int k = 1; k < size - 1; k++) {
            mx_printstr(" + ");
            int dist = getDistanceBetweenbyIndex(result[k], result[k+1], arr, waysArr);
            sum += dist;
            mx_printint(dist);
        }
        mx_printstr(" = ");
        mx_printint(sum);
        mx_printstr("\n========================================\n");
    }
    else{
        mx_printstr("\nDistance: ");
        int dist = getDistanceBetweenbyIndex(result[0], result[1], arr, waysArr);
        if (dist == -1) dist = 0;
        mx_printint(dist);
        mx_printstr("\n========================================\n");
    }
}
