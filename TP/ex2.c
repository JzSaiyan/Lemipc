/*
** ex1.c for ex1 in /home/tavukc_k/TP/IPC
**
** Made by kevin tavukciyan
** Login   <tavukc_k@epitech.net>
**
** Started on  Tue Mar  3 13:59:45 2015 kevin tavukciyan
** Last update Tue Mar  3 14:36:05 2015 kevin tavukciyan
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>

int	main(int ac, char **av)
{
  key_t key;
  int sem_id;
  void *addr;
  struct sembuf sops;

  if ((ac != 2))
    {
      return -1;
    }
  key = ftok(av[1], 0);
  sem_id = semget(key, 1, SHM_W | SHM_R);
  if (sem_id == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_W | SHM_R);
      printf("created \n");
      semctl(sem_id, 0, SETVAL, 4);
    }
  else
    {
      printf("%d\n", sem_id);
      sops.sem_flg = 0;
      sops.sem_num = 0;
      sops.sem_op = -1;
      printf("Before %d\n", semctl(sem_id, 0, GETVAL));
      semop(sem_id, &sops, 1);
      printf("after %d\n", semctl(sem_id, 0, GETVAL));
    }
  return 0;
}
