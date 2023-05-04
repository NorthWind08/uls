#include "../inc/uls.h"

int mx_get_terminal_width(void) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}
