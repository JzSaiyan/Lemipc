/*
** move.c for lemipc in /home/nayyer_j/rendu/Lemipc
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Thu Mar  5 18:35:24 2015 Jhanzeeb Nayyer
** Last update Thu Mar  5 19:10:56 2015 Jhanzeeb Nayyer
*/

#include "lemipc.h"

void		moveRight(t_settings *set, int pos)
{
  if ((pos + 1 <= 100) && ((char *)set->addr)[pos + 1] == EMPTY)
    {
      ((char *)set->addr)[pos + 1] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}

void		moveLeft(t_settings *set, int pos)
{
  if ((pos - 1 >= 1) && ((char *)set->addr)[pos - 1] == EMPTY)
    {
      ((char *)set->addr)[pos - 1] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}

void		moveUp(t_settings *set, int pos)
{
  if ((pos - 11 >= 1) && ((char *)set->addr)[pos - 11] == EMPTY)
    {
      ((char *)set->addr)[pos - 11] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}

void		moveDown(t_settings *set, int pos)
{
  if ((pos + 11 <= 100) && ((char *)set->addr)[pos + 11] == EMPTY)
    {
      ((char *)set->addr)[pos + 11] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}
