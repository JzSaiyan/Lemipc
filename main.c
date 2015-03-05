/*
** main.c for main in /home/tavukc_k/rendu/PSU_2014_lemipc
**
** Made by kevin tavukciyan
** Login   <tavukc_k@epitech.net>
**
** Started on  Wed Mar  4 11:13:37 2015 kevin tavukciyan
** Last update Thu Mar  5 15:45:59 2015 kevin tavukciyan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
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
      				IPC_CREAT | SHM_R | SHM_W)) != -1)
	{
	  printf("Creating shm [%d]\n", set->shm_id);
	  if ((set->addr = shmat(set->shm_id, NULL, SHM_R | SHM_W)) == (void *) -1)
	    return (FALSE);
	  return (TRUE);
	}
      else
	printf("Already created [%d]\n", set->shm_id);
    }
  /* shmctl(set->shm_id, IPC_RMID, NULL); */
  return (FALSE);
}

t_bool		initMap(t_settings *set)
{
  int		i;
  int		map[10][10];

  i = 0;
  memset(map, EMPTY, sizeof(map));
  snprintf((char *)set->addr, MAPMAX_SIZE, "%s", (char *)map);
  while (i < MAPMAX_SIZE)
    {
      if (i % 11 == 0)
	((char *)set->addr)[i] = SEP;
      ++i;
      //    printf("%d\n", ((char*)set->addr)[100]);
    }
  return (TRUE);
}

t_bool		setMap(t_settings *set)
{
  int		i;
  int		j;

  i = 1;
  j = 0;
  while (i < MAPMAX_SIZE)
    {
      if (i % 10 == 0)
	++j;
      if (j > 4 && j < 7 && i % 10 == 0 && ((char *)set->addr)[i] == EMPTY)
      	((char *)set->addr)[i] = FIRST;
      //      printf("%d\n", ((char *)set->addr)[i]);
      ++i;
    }
  return (TRUE);
}

t_bool		initSem(t_settings *set)
{
  if ((set->sem_id = semget(set->key, 1, SHM_R | SHM_W)) == -1)
    {
      if ((set->sem_id = semget(set->key, 1, IPC_CREAT | SHM_R | SHM_W)) == -1)
	return (FALSE);
      printf("sem_id = [%d]\n", set->sem_id);
      semctl(set->sem_id, 0, SETVAL, 4);
    }
  else
    {
      printf("#1 value = %d\n", semctl(set->sem_id, 0, GETVAL));
      set->sops.sem_num = 0;
      set->sops.sem_op = -1;
      set->sops.sem_flg = 0;
      semop(set->sem_id, &(set)->sops, 1);
      printf("#2 value = %d\n", semctl(set->sem_id, 0, GETVAL));
    }
  return (TRUE);
}

/*
** Catcher sigkill, sigterm
*/

t_bool		readMap(t_settings *set)
{
  if ((set->addr = shmat(set->shm_id, NULL, SHM_R | SHM_W)) == (void *) -1)
    return (FALSE);
  printf("%d\n",((char*)set->addr)[0]);
  return (TRUE);
}

t_bool		start()
{
  t_settings	*set;

 if ((set = malloc(sizeof(t_settings))) == NULL)
    return (FALSE);
  if (initKey(set) == FALSE)
    return (FALSE);
  if ((set->shm_id = shmget(set->key, MAPMAX_SIZE, SHM_R | SHM_W)) == -1)
    {
      if (initMemory(set) == FALSE)
  	return (FALSE);
      if (initMap(set) == FALSE)
	return (FALSE);
    }
  if (initSem(set) == FALSE)
    return (FALSE);
  if (readMap(set) == FALSE)
    return (FALSE);
  printf("%d\n", 1);
  setMap(set);
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
