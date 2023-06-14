#ifndef Header_h
#define Header_h

#include "../libmx/inc/libmx.h"

#define INT_MAX 2147483647

typedef struct s_ways {
    char *island1;
    char *island2;
    int distance;
}                t_ways;

void check_file(char *filedata, char *filename);
void mx_printerr(const char *s);
int mx_atoi(const char *str);
void check_filedata(char *filedata);
bool chek_island(char *island, char ***arr, int size, int line);
int checkcount(char *filedata, char *is1, char *is2);
char **get_islands_arr(char *filename, int *count_of_islands);
t_ways *get_ways_arr(char *filename, int *ways_size);
void calculate_ways(char *filename);
int getIndexOfIsland(char *island, char **arr);
int getDistanceBetweenbyIndex(int first, int last, char **arr, t_ways *waysArr);
void calculate_way(int start, int finish, char **arr, t_ways *waysArr);
void print_Way(int maxsize, int *result, char **arr, t_ways *waysArr);
void printFromResult(int size, int *resultMatrix, char **arr, t_ways *waysArr);

#endif
