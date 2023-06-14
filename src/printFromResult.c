#include "../inc/Header.h"

void printFromResult(int size, int *resultMatrix, char **arr, t_ways *waysArr){
    for (int i = 0; i < size; i++) {
        if (resultMatrix[i * size + 0] == -1) return;
        print_Way(size, &resultMatrix[i * size], arr, waysArr);
    }
}
