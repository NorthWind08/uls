#include "../inc/uls.h"

void mx_print_ls_l(t_ls *ls) {
    int total = 0;
    t_element_max_lens max_lens;
    max_lens.max_group = mx_strlen(ls->elements[0].group);
    max_lens.max_links = mx_intlen(ls->elements[0].links);
    max_lens.max_size = mx_intlen(ls->elements[0].size);
    max_lens.max_user = mx_strlen(ls->elements[0].user);    

    for (int i = 0; i < ls->length; i++) {
        if (mx_intlen(ls->elements[i].size) > max_lens.max_size) {
            max_lens.max_size = mx_intlen(ls->elements[i].size);
        }
        if (mx_intlen(ls->elements[i].links) > max_lens.max_links) {
            max_lens.max_links = mx_intlen(ls->elements[i].links);
        }
        if (mx_strlen(ls->elements[i].group) > max_lens.max_group) {
            max_lens.max_group = mx_strlen(ls->elements[i].group);
        }
        if (mx_strlen(ls->elements[i].user) > max_lens.max_user) {
            max_lens.max_user = mx_strlen(ls->elements[i].user);
        }
        // total += ls->elements[i].size / 1024;
        // if (ls->elements[i].size % 1024 != 0) {
        //     total++;
        // }
        total += ls->elements[i].blocks;
    }
    total = total / 2;
    mx_printstr("total ");
    mx_printint(total);
    mx_printstr("\n");

    for (int i = 0; i < ls->length; i++) {
        mx_print_element_lflag(&ls->elements[i], max_lens);
        mx_printstr("\n");
    }
}
