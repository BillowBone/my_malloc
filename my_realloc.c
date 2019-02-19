/*
** EPITECH PROJECT, 2019
** Memory _ malloc
** File description:
** my_realloc
*/

#include "my_malloc.h"

void *realloc_new_node(void *ptr, size_t size, section_t *listNode)
{
    void *tmp;

    if (size > listNode->size) {
        tmp = malloc(size);
        memcpy(tmp, ptr, listNode->size);
        free(ptr);
        return (tmp);
    }
    return (ptr);
}

void *realloc(void *ptr, size_t size)
{
    section_t *listNode = list->first;
    void *tmp;

    if (size == 0) {
        free(ptr);
        return (NULL);
    } else if (ptr == NULL) {
        return (malloc(size));
    }
    tmp = is_there_place(size);
    if (tmp != NULL)
        return (tmp);
    for (; listNode != NULL && (void *)(listNode) +
            sizeof(*listNode) != ptr; listNode = listNode->next);
    if (listNode == NULL)
        return (NULL);
    else
        return (realloc_new_node(ptr, size, listNode));
}
