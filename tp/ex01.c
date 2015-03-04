/*
** ex01.c for examples in /home/nayyer_j/rendu/Lemipc
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Wed Mar  4 11:49:48 2015 Jhanzeeb Nayyer
** Last update Wed Mar  4 12:21:26 2015 Jhanzeeb Nayyer
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int		main(int argc, char **argv)
{
  int		shm_id;
  void		*addr;
  key_t		key;

  if (argc != 2)
    {
      printf("[USAGE] %s pathname\n", argv[0]);
      return (0);
    }
  if ((key = ftok(argv[1], 0)) != -1)
    printf("Key = [%d]\n", key);
  else
    printf("[USAGE] %s pathname\n", argv[0]);
  if ((shm_id = shmget(key, 42, SHM_R | SHM_W)) == -1)
    {
      if ((shm_id = shmget(key, 42, IPC_CREAT | SHM_R | SHM_W)) == -1)
	return (-1);
      printf("Creating shm [%d]\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      sprintf((char *)addr, "Epitech Paris rox");
    }
  else
    {
      printf("Already created [%d]\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      printf("--> %s\n", (char *)addr);
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
