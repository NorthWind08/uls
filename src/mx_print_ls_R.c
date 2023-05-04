#include "../inc/uls.h"

void mx_print_ls_R(t_ls *ls, char *flags, bool last) {
    mx_printstr(ls->dir_name);
    mx_printstr(":\n");

    int last_index = -1;

    for (int i = 0; i < ls->length; i++) {
        if (ls->elements[i].permissions[0] == 'd') {
            last_index = i;
        }
    }

    if (mx_check_flag(flags, 'l')) {
        mx_print_ls_l(ls);
    }
    else {
        mx_print_table(ls);
    }
    if (!last || last_index != -1) {
        mx_printstr("\n");
    }

    for (int i = 0; i < ls->length; i++) {
        t_ls *tmp = NULL;
        if (ls->elements[i].permissions[0] != 'd') {
            continue;
        }
        tmp = (t_ls *)malloc(sizeof(t_ls));
        char *temp = mx_strjoin(ls->dir_name, "/");
        tmp->dir_name = mx_strjoin(temp, ls->elements[i].name);
        mx_init_ls(tmp);
        mx_print_ls_R(tmp, flags, (last && (last_index == i)));
        mx_free_ls(tmp);
        free(tmp);
        free(temp);
    }
}
