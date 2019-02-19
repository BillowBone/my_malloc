/*
** EPITECH PROJECT, 2019
** Memory - malloc
** File description:
** show_alloc_mem
*/

#include "my_malloc.h"

void show_alloc_mem(void)
{
    section_t *tmp;

    printf("break : %p\n", sbrk(0));
    if (list == NULL)
        return;
    tmp = list->first;
    while (tmp != NULL) {
        if (tmp->free == 0)
            printf("%p - %p : %zu octets\n", tmp, tmp + tmp->size, tmp->size);
        tmp = tmp->next;
    }
}

void *is_there_place(size_t size)
{
    if (list != NULL) {
        section_t *current = list->first;
        while (current->next != NULL) {
            if (current->free == 1 && current->size >= size) {
                current->free = 0;
                return (current->data);
            }
            current = current->next;
        }
    }
    return (NULL);
}
