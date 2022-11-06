#include "../inc/Header.h"

t_ways *get_ways_arr(char *filedata, int *ways_size){
    *ways_size = mx_count_words(filedata, '\n') - 1;
    t_ways *arr = (t_ways*)malloc((*ways_size + 1)*sizeof(t_ways));
    int count = 0;
    int i = mx_get_char_index(filedata, '\n') + 1;
    char delimiters[] = "-,\n";
    for (int j = 1; i < mx_strlen(filedata); j++) {
        int start = i;
        while (!mx_strchr(delimiters, filedata[i]) && filedata[i]) {
            i++;
        }
        char *new_island = mx_strndup(&filedata[start], i - start);
        if (j % 3 == 0) {
            arr[count++].distance = mx_atoi(new_island);
        }
        if (j % 3 == 1) {
            arr[count].island1 = mx_strdup(new_island);
        }
        if (j % 3 == 2) {
            arr[count].island2 = mx_strdup(new_island);
        }
        i++;
        mx_strdel(&new_island);
    }
    arr[*ways_size].island1 = NULL;
    return arr;
}
