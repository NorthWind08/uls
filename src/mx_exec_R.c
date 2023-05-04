#include "../inc/uls.h"

void mx_exec_R(t_shell *shell) {
    for (int i = 0; i < shell->length; i++) {
        mx_print_ls_R(&shell->dirs[i], shell->flags, i == shell->length - 1);
    }
}
