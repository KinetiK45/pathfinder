#include "../inc/Header.h"

void checkdup(char *filedata, char *is1, char *is2){
    char *temp = mx_strjoin("-", is2);
    char *AB = mx_strjoin(is1, temp);
    mx_strdel(&temp);
    temp = mx_strjoin("-", is1);
    char *BA = mx_strjoin(is2, temp);
    mx_strdel(&temp);
    if (mx_count_substr(filedata, AB) + mx_count_substr(filedata, BA) > 1){
        mx_printerr("error: duplicate bridges\n");
        exit(0);
    }
    mx_strdel(&AB);
    mx_strdel(&BA);
}
