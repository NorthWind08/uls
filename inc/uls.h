#pragma once

#include "../libmx/inc/libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/sysmacros.h>

typedef struct s_element {
    char *name;
    char *permissions;
    char *date;
    char *user;
    char *group;
    int links;
    long size;
    int blocks;
    char *link_file;
}               t_element;

typedef struct s_element_max_lens {
    int max_name;
    int max_user;
    int max_group;
    int max_links;
    int max_size;
}               t_element_max_lens;

typedef struct s_ls {
    char *dir_name;
    t_element *elements;
    int length;
}               t_ls;

typedef struct s_shell {
    t_ls *dirs;
    int length;
    char *flags;
}               t_shell;

t_shell *mx_init_shell(int argc, const char **argv);
void mx_init_ls(t_ls *ls);
void mx_init_element(t_element *element, char *path);
bool mx_check_flags(t_shell *shell, char flag);
void mx_print_element_lflag(t_element *element, t_element_max_lens max_lens);
void mx_print_sdate(char *date);
void mx_print_ls_l(t_ls *ls);
int mx_get_terminal_width(void);
void mx_print_table(t_ls *ls);
void mx_sort_shell(t_shell *shell);
void mx_sort_elements(t_ls *ls, bool (*comparator)(t_element *el1, t_element *el2));
bool mx_std_comparator(t_element *el1, t_element *el2);
void mx_free_element(t_element *element);
void mx_free_ls(t_ls *ls);
void mx_free_shell(t_shell *shell);
char* mx_get_element_permission(struct stat* stat);
char* mx_get_element_type(struct stat* stat);
bool mx_get_element_acl(char* path);
void mx_exec_R(t_shell *shell);
void mx_print_ls_R(t_ls *ls, char *flags, bool last);
bool mx_check_flag(const char *flags, char flag);

