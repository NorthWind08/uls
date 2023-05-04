#include "../inc/uls.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

void mx_init_ls(t_ls *ls) {
    DIR *dir;
    struct dirent* entry;
    ls->length = 0;

    if ((dir = opendir(ls->dir_name)) == NULL) {
        mx_printerr("Init ls: error opening folder\n");
        exit(-1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        ls->length++;
        // printf("Cock1\n");
    }

    closedir(dir);
    ls->elements = (t_element *)malloc(sizeof(t_element) * ls->length);

    dir = opendir(ls->dir_name);
    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        ls->elements[i].name = mx_strdup(entry->d_name);
        mx_init_element(&ls->elements[i], ls->dir_name);
        i++;
        // printf("Cock2\n");
    }

    closedir(dir);
}
