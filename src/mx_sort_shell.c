#include "../inc/uls.h"

void mx_sort_shell(t_shell *shell) {
    if (mx_check_flags(shell, '?')) {

    }
    else {
        for (int i = 0; i < shell->length; i++) {
            for (int j = 0; j < shell->length - i - 1; j++) {
                if (mx_strcmp(shell->dirs[j].dir_name, shell->dirs[j+1].dir_name) > 0) {
                    t_ls tmp = shell->dirs[j];
                    shell->dirs[j] = shell->dirs[j+1];
                    shell->dirs[j+1] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < shell->length; i++) {
        mx_sort_elements(&shell->dirs[i], mx_std_comparator);
    }
}
