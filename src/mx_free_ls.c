#include "../inc/uls.h"

void mx_free_ls(t_ls *ls) {
    for (int i = 0; i < ls->length; i++) {
        mx_free_element(&ls->elements[i]);
    }   

    // free(ls->dir_name);
    free(ls->elements);
    ls->dir_name = NULL;
    ls->elements = NULL;
}
