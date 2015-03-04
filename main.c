/*
** main.c for main in /home/tavukc_k/rendu/PSU_2014_lemipc
**
** Made by kevin tavukciyan
** Login   <tavukc_k@epitech.net>
**
** Started on  Wed Mar  4 11:13:37 2015 kevin tavukciyan
** Last update Wed Mar  4 18:43:10 2015 Jhanzeeb Nayyer
*/

#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lemipc.h"

t_bool		initKey(t_settings *set)
{
  char		path[PATH_SIZE];
  key_t		key;

  if (getcwd(path, sizeof(path)) == NULL)
    {
      printf("Can not find current directory pathname\n");
      return (FALSE);
    }
  if ((key = ftok(path, 0)) != -1)
    printf("Key = [%d]\n", key);
  else
    {
      printf("Error init Key\n");
      return (FALSE);
    }
  set->key = key;
  return (TRUE);
}

t_bool		initMemory(t_settings *set)
{
  if ((set->shm_id = shmget(set->key, getpagesize(), SHM_R | SHM_W)) == -1)
    {
      if ((set->shm_id = shmget(set->key, getpagesize(),
      				IPC_CREAT | SHM_R | SHM_W)) != -1)
	{
	  printf("Creating shm [%d]\n", set->shm_id);
	  if ((set->addr = shmat(set->shm_id, NULL, SHM_R | SHM_W)) == (void *) -1)
	    return (FALSE);
	  printf("%p <- after\n", set->addr);
	  /* sprintf((char *)addr, "Epitech Paris rox"); */
	  return (TRUE);
	}
    }
  printf("Already created [%d]\n", set->shm_id);
  shmctl(set->shm_id, IPC_RMID, NULL); //vérification fonction
  return (FALSE);
}

t_bool		initMap(t_settings *set)
{
  int		map[10][11];

  memset(map, EMPTY, sizeof(map));
  snprintf((char *)set->addr, MAPMAX_SIZE, "%s", (char *)map);
  printf("%d\n", ((char *)set->addr)[100]);
  return (TRUE);
}

t_bool		start()
{
  t_settings	*set;

 if ((set = malloc(sizeof(t_settings))) == NULL)
    return (FALSE);
  if (initKey(set) == FALSE)
    return (FALSE);
  if (initMemory(set) == FALSE)
    return (FALSE);
  if (initMap(set) == FALSE)
    return (FALSE);
  /* if (initSem() == FALSE) */
  /*   return (FALSE); */
  /* if (initMsg() == FALSE) */
  /*   return (FALSE); */
  free(set);
  return (TRUE);
}

int		main(void)
{
  if (start() == FALSE)
    return (-1);
  return (0);
}
