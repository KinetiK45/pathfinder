#include "../inc/Header.h"

int checkcount(char *filedata, char *is1, char *is2){
    int count;
    char *temp = mx_strjoin("-", is2);
    char *AB = mx_strjoin(is1, temp);
    mx_strdel(&temp);
    temp = mx_strjoin("-", is1);
    char *BA = mx_strjoin(is2, temp);
    mx_strdel(&temp);
    count = mx_count_substr(filedata, AB) + mx_count_substr(filedata, BA);
    if (mx_strcmp(is1, is2) == 0 && count > 0){
        int last = mx_get_substr_index(filedata, AB);
        int count = 0;
        for (int i = 0; i < last; i++) {
            if (filedata[i] == '\n') count++;
        }
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(count + 1));
        mx_printerr(" is not valid\n");
        exit(0);
    }
    mx_strdel(&AB);
    mx_strdel(&BA);
    return count;
}
