#include "../inc/Header.h"

void check_file(char *filedata, char *filename){
    if (filedata == NULL){
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    else if (mx_strlen(filedata) == 0){
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(0);
    }
    check_filedata(filedata);
}
