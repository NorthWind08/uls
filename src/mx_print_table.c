#include "../inc/uls.h"
#include <unistd.h>

static void mx_print_tabs(int max_len, char *name) {
    int tabs = 0;
    int diff = max_len - mx_strlen(name);
    tabs = diff / 8;
    if (diff != tabs * 8) {
        tabs++;
    }

    // if (tabs == 0) {
    //     mx_printchar(' ');
    //     return;
    // }

    mx_printchar(' ');
    for (int i = 0; i < tabs; i++) {
        mx_printchar('\t');
    }
}

void mx_print_table(t_ls *shell) {

    int zhopa = isatty(STDOUT_FILENO);

    if (!zhopa) {
        for (int i = 0; i < shell->length; i++) {
            mx_printstr(shell->elements[i].name);
            mx_printstr("\n");
        }
        return;
    }
    

    if (shell->elements == NULL || shell->length == 0) {
        return;
    }

    int max_len;
    int tabs;
    tabs = 2;
    max_len = mx_strlen(shell->elements[0].name);

    for (int i = 1; i < shell->length; i++) {
        int len = mx_strlen(shell->elements[i].name);
        if (len > max_len) {
            max_len = len;
        }
    }

    if (max_len >= tabs * 4) {
        tabs = max_len / 4 + 1;
        if (max_len > tabs * 4) {
            tabs++;
        }
    }


    int rows = 1;
    int width = mx_get_terminal_width();


    while (true) {
        if (tabs * 4 * (shell->length + 1) / rows >= width) {
            rows++;
            continue;
        }
        break;
    }
    int cols = shell->length / rows;

    if (shell->length > cols * rows) {
        rows++;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j * rows + i >= shell->length) {
                break;
            }

            mx_printstr(shell->elements[j * rows + i].name);

            // for (int k = 0; k < tabs - (mx_strlen(shell->elements[j * rows + i].name)) / 4; k++) {
            //     // mx_printstr(" ");
            //     mx_printchar('\t');
            // }
            if (mx_strlen(shell->elements[j * rows + i].name) < tabs * 4) {
                mx_print_tabs(tabs * 4, shell->elements[j * rows + i].name);
            }
            // else {
            //     mx_printchar(' ');
            // }

            // for (int i = 0; i < tabs * 4 - mx_strlen(shell->elements[j * rows + i].name); i++) {
            //     mx_printchar(' ');
            // }

        }
        mx_printstr("\n");
    }
}
