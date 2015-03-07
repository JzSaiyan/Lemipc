##
## Makefile for Mario in /home/nayyer_j/rendu/Mario
## 
## Made by Jhanzeeb Nayyer
## Login   <nayyer_j@epitech.net>
## 
## Started on  Tue Feb  3 22:42:17 2015 Jhanzeeb Nayyer
## Last update Sat Mar  7 16:38:43 2015 Jhanzeeb Nayyer
##

CC	= gcc

RM	= rm -f

LDFLAGS	+= -lSDL -lSDL_mixer

NAME	= Mario

SRCS	= mainGui.c

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
