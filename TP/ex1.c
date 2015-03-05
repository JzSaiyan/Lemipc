/*
** ex1.c for ex1 in /home/tavukc_k/TP/IPC
**
** Made by kevin tavukciyan
** Login   <tavukc_k@epitech.net>
**
** Started on  Tue Mar  3 13:59:45 2015 kevin tavukciyan
** Last update Wed Mar  4 17:42:42 2015 kevin tavukciyan
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

int	main(int ac, char **av)
{
  key_t key;
  int shm_id;
  void *addr;

  if ((ac != 2))
    {
      return -1;
    }
  key = ftok(av[1], 0);
  shm_id = shmget(key, 42, SHM_W | SHM_R);
  if (shm_id == -1)
    {
      shm_id = shmget(key, 42, IPC_CREAT | SHM_W | SHM_R);
      printf("%d\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_W | SHM_R);
      sprintf((char*)addr, "i love ponies\n");
    }
  else
    {
      addr = shmat(shm_id, NULL, SHM_W | SHM_R);
      printf("%c\n", (char*)addr[1]);
      shmctl(shm_id, IPC_RMID, NULL);
      printf("push caca\n");
    }
  return 0;
}
