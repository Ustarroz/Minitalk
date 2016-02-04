##
## Makefile for minishell in /home/voyevoda/rendu/systeme_unix/PSU_2015_minishell1
## 
## Made by Voyevoda
## Login   <voyevoda@epitech.net>
## 
## Started on  Fri Jan 15 12:43:37 2016 Voyevoda
## Last update Thu Feb  4 16:30:13 2016 Voyevoda
##

CC	= gcc

SRC	= main_client.c \
	  fct.c		\
	  my_getnbr.c

SRC2	= main_server.c \
	  fct.c		\
	  my_getnbr.c

CFLAGS	= -W -Wall -Wextra -pedantic -ansi

RM	= rm -f

NAME	= client

NAME2	= server

OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)

all	: $(NAME) $(NAME2) 

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

clean	:
	$(RM) $(OBJ) $(OBJ2)

fclean	: clean
	$(RM) $(NAME) $(NAME2)

re	: fclean all

.phony	: all clean fclean re

