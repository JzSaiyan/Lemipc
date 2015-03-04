/*
** ex01.c for examples in /home/nayyer_j/rendu/Lemipc
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Wed Mar  4 11:49:48 2015 Jhanzeeb Nayyer
** Last update Wed Mar  4 14:45:08 2015 Jhanzeeb Nayyer
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int		main(int argc, char **argv)
{
  int		sem_id;
  void		*addr;
  key_t		key;
  struct sembuf	sops;

  if (argc != 2)
    {
      printf("[USAGE] %s pathname\n", argv[0]);
      return (0);
    }
  if ((key = ftok(argv[1], 0)) != -1)
    printf("Key = [%d]\n", key);
  else
    printf("[USAGE] %s pathname\n", argv[0]);
  if ((sem_id = semget(key, 1, SHM_R | SHM_W)) == -1)
    {
      if ((sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W)) -1)
	return (-1);
      printf("sem_id = [%d]\n", sem_id);
      semctl(sem_id, 0, SETVAL, 4);
    }
  else
    {
      printf("#1 value = %d\n", semctl(sem_id, 0, GETVAL));
      sops.sem_num = 0;
      sops.sem_op = -1;
      sops.sem_flg = 0;
      semop(sem_id, &sops, 1);
      printf("#2 value = %d\n", semctl(sem_id, 0, GETVAL));
    }
    return (0);
}
