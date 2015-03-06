/*
** event.c for Mario in /home/nayyer_j/rendu/Mario
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Wed Feb  4 19:09:43 2015 Jhanzeeb Nayyer
** Last update Fri Mar  6 00:28:44 2015 Jhanzeeb Nayyer
*/

#include "list.h"

void		pause()
{
  t_bool	proceed;
  SDL_Event	event;

  proceed = TRUE;
  while (proceed)
    {
      SDL_WaitEvent(&event);
      switch (event.type)
        {
	case SDL_QUIT:
	  proceed = FALSE;
        }
    }
}
