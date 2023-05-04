#include "../inc/uls.h"

bool mx_std_comparator(t_element *el1, t_element *el2) {
    if (mx_strcmp(el1->name, el2->name) > 0) 
        return true;
    return false;
}
