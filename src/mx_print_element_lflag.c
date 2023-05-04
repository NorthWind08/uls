#include "../inc/uls.h"

void mx_print_element_lflag(t_element *element, t_element_max_lens max_lens) {
    mx_printstr(element->permissions);
    mx_printstr(" ");
    for (int i = 0; i < (max_lens.max_links - mx_intlen(element->links)); i++) {
        mx_printstr(" ");
    }
    mx_printint(element->links);
    mx_printstr(" ");
    for (int i = 0; i < (max_lens.max_user - mx_strlen(element->user)); i++) {
        mx_printstr(" ");
    }
    mx_printstr(element->user);
    mx_printstr(" ");
    for (int i = 0; i < (max_lens.max_group - mx_strlen(element->group)); i++) {
        mx_printstr(" ");
    }
    mx_printstr(element->group);
    mx_printstr(" ");
    for (int i = 0; i < (max_lens.max_size - mx_intlen(element->size)); i++) {
        mx_printstr(" ");
    }
    mx_printint(element->size);
    mx_printstr(" ");
    
    mx_print_sdate(element->date);
    mx_printstr(" ");
    mx_printstr(element->name);

    if (element->link_file != NULL) {
        mx_printstr(" -> ");
        mx_printstr(element->link_file);
    }
}
