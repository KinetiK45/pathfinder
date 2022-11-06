#include "../inc/Header.h"

int main(int argc, char * argv[]) {
    if (argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    char *filedata = mx_file_to_str(argv[1]);
    check_file(filedata, argv[1]);
    calculate_ways(filedata);
    mx_strdel(&filedata);
    return 0;
}
