#include "../inc/uls.h"

void mx_init_element(t_element *element, char *path) {
    struct stat filestat;
    char *tmp = mx_strjoin(path, "/");
    char *filepath = mx_strjoin(tmp, element->name);

    element->link_file = NULL;

    int stat_val;

#if __linux__

    stat_val = stat(filepath, &filestat);

#elif __APPLE__

    stat_val = lstat(filepath, &filestat);

#endif

    if (stat_val == -1) {
        free(tmp);
        free(filepath);
        mx_printerr("Init element: error opening file\n");
        exit(-1);
    }

    element->permissions = mx_get_element_permission(&filestat);

    gid_t groupID = filestat.st_gid;
    struct group *grp;

    if ((grp = getgrgid(groupID)) == NULL) {
        mx_printerr("Init element: error getting file group\n");
        exit(-1);
    }

    element->group = mx_strdup(grp->gr_name);

    uid_t userID = filestat.st_uid;
    struct passwd *pwd = getpwuid(userID);

    if (pwd == NULL) {
        mx_printerr("Init element: error getting file user\n");
        exit(-1);
    }

    element->user = mx_strdup(pwd->pw_name);

    element->links= filestat.st_nlink;

    element->date = mx_strdup(ctime(&(filestat.st_mtime)));

    element->size = filestat.st_size;
    
    element->blocks = filestat.st_blocks;

#if __APPLE__

    if (element->permissions[0] == 'l') {
        struct stat link_stat;

        if (lstat(filepath, &link_stat) == -1) {
            mx_printerr("Init element: error reading link content\n");
            exit(-1);
        }

        element->size = link_stat.st_size;

        char *buffer = mx_strnew(256);
        if (readlink(filepath, buffer, 256) < 0) {
            free(buffer);
            mx_printerr("Init element: error reading link content\n");
            exit(-1);
        }



        element->link_file = mx_strdup(buffer);

        free(buffer);
    }

#endif
    
    free(filepath);
    free(tmp);
}
