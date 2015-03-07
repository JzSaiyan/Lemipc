##
## makefile for makefile in /home/tavukc_k/rendu/PSU_2014_lemipc
##
## Made by kevin tavukciyan
## Login   <tavukc_k@epitech.net>
##
## Started on  Wed Mar  4 11:12:58 2015 kevin tavukciyan
## Last update Sat Mar  7 17:00:00 2015 Jhanzeeb Nayyer
##

CC      =       gcc

RM      =       rm -f

NAME    =       lemipc

NAMELIB	=	Guilemipc

CFLAGS  +=      -Wall -Wextra -Werror

LDFLAGS	+=	-lSDL -lSDL_mixer

SRCS    =      	main.c

SRCSLIB	=	./Gui/mainGui.c

OBJS    =       $(SRCS:.c=.o)

OBJSLIB	=	$(SRCSLIB:.c=.o)

all     :       $(NAME) $(NAMELIB)

$(NAME) :       $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

$(NAMELIB):	$(OBJSLIB)
		$(CC) -o $(NAMELIB) $(OBJSLIB) $(LDFLAGS)
clean   :
		$(RM) $(OBJS)

fclean  :       clean
		$(RM) $(NAME)

re      :       fclean all

.PHONY  :       all clean fclean re
