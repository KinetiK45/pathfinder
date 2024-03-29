#include "../inc/Header.h"

void fillResult(int size , int *result, int index){
    for (int i = 0; i < size; i++) {
        if (result[i] == -1){
            result[i] = index;
            return;
        }
    }
}

void delWhileIndex(int size , int *result, int index){
    for (int i = size - 1; i >= 0; i--) {
        if (result[i] == index){
            result[i] = -1;
            return;
        }
        result[i] = -1;
    }
}

bool check_in_result(int size , int *result, int index){
    for (int i = 0; i < size; i++) {
        if (result[i] == index){
            return true;
        }
    }
    return false;
}

void clearResultMatrix(int size, int *resultMatrix){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[i * size + j] = -1;
        }
    }
}

void swapLines(int size, int resultMatrix[size][size], int line1, int line2){
    for (int i = 0; i < size; i++) {
        int temp = resultMatrix[line1][i];
        resultMatrix[line1][i] = resultMatrix[line2][i];
        resultMatrix[line2][i] = temp;
    }
}

void sortResults(int size, int resultMatrix[size][size], int finish){
    for (int i = 0; i < size; i++) {
        if (resultMatrix[i][1] == finish){
            while (resultMatrix[i-1][1] > finish && i > 0) {
                swapLines(size, resultMatrix, i-1, i);
                i--;
            }
            return;
        }
    }
}

void writeInResult(int size, int *currentResult, int *resultMatrix, int matrix[size][size]){
    int currentDist = 0;
    int lastMin = 0;
    if (resultMatrix[0] != -1){
        for (int i = 1; currentResult[i] != -1 && i < size; i++) {
            currentDist += matrix[currentResult[i-1]][currentResult[i]];
        }
        for (int i = 1; resultMatrix[i] != -1 && i < size; i++) {
            lastMin += matrix[resultMatrix[i-1]][resultMatrix[i]];
        }
    }
    if (currentDist < lastMin){
        clearResultMatrix(size, resultMatrix);
    }
    if (currentDist <= lastMin){
        for (int i = 0; i < size; i++) {
            if (resultMatrix[i * size + 0] != -1) continue;
            for (int j = 0; j < size; j++) {
                resultMatrix[i * size + j] = currentResult[j];
            }
            return;
        }
    }
}

int calculate(int size, int matrix[size][size], int *currentResult, int *resultMatrix, int current, int finish){
    fillResult(size, currentResult, current);
    int result = -1;
    for (int i = 0; i < size; i++) {
        if (check_in_result(size, currentResult, i) && i != current) continue;
        delWhileIndex(size, currentResult, current);
        fillResult(size, currentResult, current);
        if (matrix[current][i] > 0 && i != finish){
            int next = calculate(size, matrix, currentResult, resultMatrix, i, finish);
            if (next != -1){
                int current_dist = matrix[current][i] + next;
                if (result == -1 || current_dist < result){
                    result = current_dist;
                }
            }
        }
    }
    delWhileIndex(size, currentResult, current);
    fillResult(size, currentResult, current);
    if (matrix[current][finish] > 0){
        fillResult(size, currentResult, finish);
        writeInResult(size, currentResult, resultMatrix, matrix);
        delWhileIndex(size, currentResult, current);
        return matrix[current][finish];
    }
    return result;
}

void calculate_way(int start, int finish, char **arr, t_ways *waysArr){
    int arr_size = 0;
    while (arr[arr_size]) arr_size++;
    int matrix[arr_size][arr_size];
    int tempresult[arr_size];
    int resultMatrix[arr_size][arr_size];
    for (int i = 0; i < arr_size; i++) {
        tempresult[i] = -1;
        for (int j = 0; j < arr_size; j++) {
            matrix[i][j] = 0;
            resultMatrix[i][j] = -1;
        }
    }
    int ways_size = 0;
    while (waysArr[ways_size].island1) ways_size++;
    for (int i = 0; i < ways_size; i++) {
        int x = getIndexOfIsland(waysArr[i].island1, arr);
        int y = getIndexOfIsland(waysArr[i].island2, arr);
        int distance = getDistanceBetweenbyIndex(x, y, arr, waysArr);
        matrix[x][y] = distance;
        matrix[y][x] = distance;
    }
    calculate(arr_size, matrix, &tempresult[0], &resultMatrix[0][0], start, finish);
    sortResults(arr_size, resultMatrix, finish);
    printFromResult(arr_size, &resultMatrix[0][0], arr, waysArr);
}
