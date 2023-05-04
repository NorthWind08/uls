#include "../inc/uls.h"

void mx_sort_elements(
    t_ls *ls, bool (*comparator)(t_element *el1, t_element *el2)
) {
    for (int i = 0; i < ls->length; i++) {
        for (int j = 0; j < ls->length - i - 1; j++) {
            if ((*comparator)(&ls->elements[j], &ls->elements[j+1])) {
                t_element tmp = ls->elements[j];
                ls->elements[j] = ls->elements[j+1];
                ls->elements[j+1] = tmp;
            }
        }
    }
}
