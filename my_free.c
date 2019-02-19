/*
** EPITECH PROJECT, 2019
** Memory - malloc
** File description:
** my_free.c
*/

#include "my_malloc.h"

void replace_segment(void)
{
    section_t *current = list->first;
    section_t *tmp = NULL;

    for (; current->next != NULL; current = current->next);
    for (; current->prev != NULL && current->free == 1; current = current->prev);
    if (current->free == 0) {
        brk(current->next);
        current->next = NULL;
    } else {
        brk(list);
        list = NULL;
    }
}

void free(void *ptr)
{
    section_t *current = list->first;

    if (ptr == NULL)
        return;
    while (current != NULL) {
        if ((void *)(current) + sizeof(*current) == (void *)ptr) {
            current->free = 1;
            break;
        }
        current = current->next;
    }
    replace_segment();
}
