#include "../inc/Header.h"

void printFromResult(int size, int *resultMatrix, char **arr, t_ways *waysArr, int minDist){
    for (int i = 0; i < size; i++) {
        if (resultMatrix[i * size + 0] == -1) return;
        int sum = 0;
        for (int j = 1; resultMatrix[i * size + j] != -1; j++) {
            sum += getDistanceBetweenbyIndex(resultMatrix[i * size + j - 1], resultMatrix[i * size + j], arr, waysArr);
        }
        if (sum == minDist) print_Way(size, &resultMatrix[i * size], arr, waysArr);
    }
}
