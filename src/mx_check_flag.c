#include "../inc/uls.h"

bool mx_check_flags(t_shell *shell, char flag) {
    if (shell == NULL || shell->flags == NULL) {
        return false;
    }

    for (int i = 0; shell->flags[i] != '\0'; i++) {
        if (shell->flags[i] == flag) {
            return true;
        }
    }
    return false;
}

bool mx_check_flag(const char *flags, char flag) {
    if (flags == NULL) {
        return false;
    }

    for (int i = 0; i < mx_strlen(flags); i++) {
        if (flags[i] == flag) {
            return true;
        }
    }
    return false;
}
