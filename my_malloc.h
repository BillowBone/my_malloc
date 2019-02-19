/*
** EPITECH PROJECT, 2019
** Memory - malloc
** File description:
** my_malloc.h
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>

void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void show_alloc_mem();
void *is_there_place(size_t size);

typedef struct section_s {
    struct section_s *next;
    struct section_s *prev;
    void *data;
    size_t size;
    char free;
} section_t;

typedef struct list_s {
    section_t *first;
} list_t;

list_t *list;

#endif /* !MY_MALLOC_H_ */
