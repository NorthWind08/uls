#include "../inc/uls.h"

void mx_free_element(t_element *element) {
    free(element->name);
    // free(element->date);
    free(element->permissions);
    free(element->user);
    free(element->group);
    free(element->link_file);

    element->name = NULL;
    element->date = NULL;
    element->permissions = NULL;
    element->user = NULL;
    element->group = NULL;
    element->link_file = NULL;
}
