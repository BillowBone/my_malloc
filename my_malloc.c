/*
** EPITECH PROJECT, 2019
** Memory - malloc
** File description:
** my_malloc
*/

#include "my_malloc.h"

intptr_t around_up(size_t size)
{
    intptr_t power = 1;

    while (power < size)
        power *= 2;
    return (power);
}

int insert_node(section_t *nwNode)
{
    nwNode->free = 0;
    if (list == NULL) {
        list = sbrk(sizeof(list_t));
        if (list == (void *)-1)
            return (1);
        nwNode->prev = NULL;
        nwNode->next = NULL;
        list->first = nwNode;
    } else {
        section_t *first = list->first;
        while (first->next != NULL)
            first = first->next;
        nwNode->prev = first;
        nwNode->next = NULL;
        first->next = nwNode;
    }
    return (0);
}

void *malloc(size_t size)
{
    section_t *nwNode;
    void *addr;

    if (size == 0)
        return (NULL);
    size = around_up(size);
    addr = is_there_place(size);
    if (addr != NULL)
        return (addr);
    nwNode = sbrk(sizeof(section_t));
    if (nwNode == (void *)-1)
        return (NULL);
    nwNode->data = sbrk(size);
    if (nwNode->data == (void *)-1)
        return (NULL);
    nwNode->size = size;
    if (insert_node(nwNode) == 1)
        return (NULL);
    else
        return (nwNode->data);
}

void *calloc(size_t nmemb, size_t size)
{
    return (malloc(nmemb * size));
}