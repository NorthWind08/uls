#include "../inc/uls.h"

void mx_free_shell(t_shell *shell) {
    for (int i = 0; i < shell->length; i++) {
        mx_free_ls(&shell->dirs[i]);
    }

    free(shell->flags);
    shell->flags = NULL;
    free(shell->dirs);
    shell->dirs = NULL;
}
