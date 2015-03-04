/*
** main.c for main in /home/tavukc_k/rendu/PSU_2014_lemipc
**
** Made by kevin tavukciyan
** Login   <tavukc_k@epitech.net>
**
** Started on  Wed Mar  4 11:13:37 2015 kevin tavukciyan
** Last update Wed Mar  4 15:54:25 2015 Jhanzeeb Nayyer
*/

#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lemipc.h"

# define BUFF_SIZE (1024)

t_bool		initMemory()
{
  /* int		shm_id; */
  char		path[BUFF_SIZE];
  /* void		*addr; */
  key_t		key;

  printf("#1 hello\n");
  if (getcwd(path, sizeof(path)) == NULL)
    return (FALSE);
  printf("#2 hello\n");
  if ((key = ftok(path, 0)) != -1)
    printf("Key = [%d]\n", key);
  else
    {
      printf("Mauvais pathname\n");
      return (FALSE);
    }
  return (TRUE);
}

t_bool		start()
{
  /* if (initMap() == FALSE) */
  /*   return (FALSE); */
  if (initMemory() == FALSE)
    return (FALSE);
  /* if (initSem() == FALSE) */
  /*   return (FALSE); */
  /* if (initMsg() == FALSE) */
  /*   return (FALSE); */
  return (TRUE);
}

int		main(void)
{
  if (start() == FALSE)
    return (-1);
  return (0);
}
