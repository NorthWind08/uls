#include "../inc/uls.h"
#include <stdio.h>

t_shell *mx_init_shell(int argc, const char **argv) {
    t_shell *shell = NULL;
    shell = (t_shell *)malloc(sizeof(t_shell));
    // DIR *dir;
    // struct dirent* direntry;
    shell->length = 0;
    shell->flags = NULL;

    if (argc > 1) {
        if (argv[1][0] == '-') {
            shell->flags = mx_strdup(&argv[1][1]);
        }
    }
    shell->length = argc - 1 - (shell->flags == NULL ? 0 : 1);
    // printf("Shell length: %d\n", shell->length);
    if (shell->length == 0) {
        shell->length = 1;
        shell->dirs = (t_ls *)malloc(sizeof(t_ls));
        shell->dirs[0].dir_name = ".";
        mx_init_ls(&shell->dirs[0]);
        return shell;
    }
    shell->dirs = (t_ls *)malloc(sizeof(t_ls) * shell->length);


    for (int i = 0; i < argc - 1 - (shell->flags == NULL ? 0 : 1) ; i++) {

        shell->dirs[i].dir_name = mx_strdup(argv[i + 1 + (shell->flags == NULL ? 0 : 1)]);
        // printf("%s\n", shell->dirs[i].dir_name);
        mx_init_ls(&shell->dirs[i]);
    }

    

    return shell;
}
