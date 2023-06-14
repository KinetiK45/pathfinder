#include "../inc/Header.h"

int getDistanceBetweenbyIndex(int first, int last, char **arr, t_ways *waysArr){
    if (arr[first] == NULL || arr[last] == NULL) return -1;
    for (int j = 0; waysArr[j].island1; j++) {
        if ((mx_strcmp(waysArr[j].island1, arr[first]) == 0 && mx_strcmp(waysArr[j].island2, arr[last]) == 0)
            || (mx_strcmp(waysArr[j].island2, arr[first]) == 0 && mx_strcmp(waysArr[j].island1, arr[last]) == 0)){
            return waysArr[j].distance;
        }
    }
    return -1;
}
