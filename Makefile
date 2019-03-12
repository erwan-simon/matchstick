##
## Makefile for allum1 in /home/simon_w/Prog_Elem/alum1/CPE_2015_Allum1
## 
## Made by Erwan Simon
## Login   <simon_w@epitech.net>
## 
## Started on  Wed Feb 10 16:26:13 2016 Erwan Simon
## Last update Thu Feb 25 16:05:05 2016 Erwan Simon
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.

NAME	= allum1

SRCS	= allum1.c \
	  allum1_2.c \
	  allum1_3.c \
	  allum1_4.c \
	  sources.c \
	  get_next_line.c \
	  my_printf.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
