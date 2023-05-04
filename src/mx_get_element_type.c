#include "../inc/uls.h"

char* mx_get_element_type(struct stat* stat) {
    if (S_ISDIR(stat->st_mode))
        return mx_strdup("d");
    if (S_ISLNK(stat->st_mode))
        return mx_strdup("l");
    if (S_ISBLK(stat->st_mode))
        return mx_strdup("b");
    if (S_ISCHR(stat->st_mode))
        return mx_strdup("c");
    // if (S_ISSOCK(mode))
    //     return mx_strdup("s");
    if (S_ISFIFO(stat->st_mode))
        return mx_strdup("p");
    return mx_strdup("-");
}

