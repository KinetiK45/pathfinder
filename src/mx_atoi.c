#include "../inc/Header.h"

int mx_atoi(const char *str){
    long int n = 0;
    int isNegative = 1;
    while (*str != '\0') {
        if (*str == '-' && n == 0 && isNegative == 1) {
            isNegative = - 1;
            str++;
        }
        if (mx_isdigit(*str)) {
            n *= 10;
            n += *str;
            n -= '0';
        }
        else if (!mx_isdigit(*str)){
            return -781437834;
        }
        str++;
    }
    if (n > 2147483647){
        return -781437834;
    }
    int result = (int)n;
    return isNegative * result;
}
