/*
** moveDig.c for lemipc in /home/nayyer_j/rendu/Lemipc
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Thu Mar  5 19:10:06 2015 Jhanzeeb Nayyer
** Last update Thu Mar  5 19:10:46 2015 Jhanzeeb Nayyer
*/

#include "lemipc.h"

void		moveDigUpRight(t_settings *set, int pos)
{
  if ((pos - 10 >= 1) && ((char *)set->addr)[pos - 10] == EMPTY)
    {
      ((char *)set->addr)[pos - 10] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}

void		moveDigUpLeft(t_settings *set, int pos)
{
  if ((pos - 12 <= 100) && ((char *)set->addr)[pos - 12] == EMPTY)
    {
      ((char *)set->addr)[pos - 12] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}

void		moveDigDownRight(t_settings *set, int pos)
{
  if ((pos + 12 <= 100) && ((char *)set->addr)[pos + 12] == EMPTY)
    {
      ((char *)set->addr)[pos + 12] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}

void		moveDigDownLeft(t_settings *set, int pos)
{
  if ((pos + 10 <= 100) && ((char *)set->addr)[pos + 10] == EMPTY)
    {
      ((char *)set->addr)[pos + 10] = ((char *)set->addr)[pos];
      ((char *)set->addr)[pos] = EMPTY;
    }
}
