##
## makefile for makefile in /home/tavukc_k/rendu/PSU_2014_lemipc
##
## Made by kevin tavukciyan
## Login   <tavukc_k@epitech.net>
##
## Started on  Wed Mar  4 11:12:58 2015 kevin tavukciyan
## Last update Wed Mar  4 11:25:08 2015 kevin tavukciyan
##

CC      =       gcc

RM      =       rm -f

NAME    =       lemipc

CFLAGS  =       -Wall -Wextra -Werror

SRCS    =      	main.c

OBJS    =       $(SRCS:.c=.o)

all     :       $(NAME)

$(NAME) :       $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean   :
		$(RM) $(OBJS)

fclean  :       clean
		$(RM) $(NAME)

re      :       fclean all

.PHONY  :       all clean fclean re
