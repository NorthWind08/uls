#include "../inc/uls.h"

void mx_print_sdate(char *date) {
    mx_printstr(mx_strndup(&date[4], 12));
}
