#include "../inc/uls.h"

int main(int argc, const char **argv) {
    t_shell *shell = mx_init_shell(argc, argv);
    mx_sort_shell(shell);
    
    if (shell->length == 1) {
        if (mx_check_flags(shell, 'R')) {
            mx_print_ls_R(&shell->dirs[0], shell->flags, true);
        }
        else if (mx_check_flags(shell, 'l')) {
            mx_print_ls_l(&shell->dirs[0]);     
        }
        else {
            mx_print_table(&shell->dirs[0]);
        }
    }
    else {
        for (int i = 0; i < shell->length; i++) {
            if (mx_check_flags(shell, 'R')) {
                mx_exec_R(shell);
            }
            else {
                mx_printstr(shell->dirs[i].dir_name);
                mx_printstr(":\n");
                if (mx_check_flags(shell, 'l')) {
                    mx_print_ls_l(&shell->dirs[i]);
                }
                else {
                    mx_print_table(&shell->dirs[i]);
                }
                if (i != shell->length - 1) {
                    mx_printstr("\n");
                }
            }
        }
    }
    mx_free_shell(shell);
    free(shell);
    return 0;
}
