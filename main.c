/*
** main.c for main in /home/tavukc_k/rendu/PSU_2014_lemipc
**
** Made by kevin tavukciyan
** Login   <tavukc_k@epitech.net>
**
** Started on  Wed Mar  4 11:13:37 2015 kevin tavukciyan
** Last update Wed Mar  4 17:29:15 2015 Jhanzeeb Nayyer
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
  if ((set->shm_id = shmget(set->key, MAPMAX_SIZE, SHM_R | SHM_W)) == -1)
    {
      if ((set->shm_id = shmget(set->key, MAPMAX_SIZE,
				IPC_CREAT | SHM_R | SHM_W)) == -1)
        return (FALSE);
      printf("Creating shm [%d]\n", set->shm_id);
      if ((set->addr = shmat(set->shm_id, NULL, SHM_R | SHM_W)) == (void *) -1)
	return (FALSE);
      printf("in start -> %p\n", set->addr);
      /* sprintf((char *)addr, "Epitech Paris rox"); */
    }
  else
    {
      printf("Already created [%d]\n", set->shm_id);
      /* addr = shmat(set->shm_id, NULL, SHM_R | SHM_W); //vérification fonction */
      /* printf("--> %s\n", (char *)addr); */
      shmctl(set->shm_id, IPC_RMID, NULL); //vérification fonction
    }
  return (TRUE);
}

t_bool		initMap(t_settings *set)
{
  int		map[10][10];

  memset(map, 0, sizeof(map)); //vérifier fonction
  set->addr = (void *)map;
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
  printf("%d hoho\n", map[0][0]);
  printf("in start -> %p\n", set->addr);
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
