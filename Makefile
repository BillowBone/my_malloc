##
## EPITECH PROJECT, 2018
## PSU - my_printf
## File description:
## Makefile
##

GCC	= 		gcc

RM	= 		rm -rf

NAME	= 	libmy_malloc.so

SRCS	= 	my_malloc.c	\
			my_free.c	\
			my_realloc.c	\
			fct.c		\

OBJS	= 	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	$(GCC) -c -fPIC $(SRCS)
	$(GCC) my_malloc.o my_free.o my_realloc.o fct.o -shared -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
