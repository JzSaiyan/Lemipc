##
## Makefile for Mario in /home/nayyer_j/rendu/Mario
## 
## Made by Jhanzeeb Nayyer
## Login   <nayyer_j@epitech.net>
## 
## Started on  Tue Feb  3 22:42:17 2015 Jhanzeeb Nayyer
## Last update Fri Mar  6 00:35:37 2015 Jhanzeeb Nayyer
##

CC	= gcc

RM	= rm -f

LDFLAGS	+= -lSDL -lSDL_mixer

NAME	= Mario

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
