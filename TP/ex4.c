/*
** ex1.c for ex1 in /home/tavukc_k/TP/IPC
**
** Made by kevin tavukciyan
** Login   <tavukc_k@epitech.net>
**
** Started on  Tue Mar  3 13:59:45 2015 kevin tavukciyan
** Last update Tue Mar  3 15:14:11 2015 kevin tavukciyan
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <string.h>
typedef struct s_msg
{
  long mtype;
  char str[32];
}	t_msg;

int	main(int ac, char **av)
{
  key_t key;
  int msg_id;
  void *addr;
  struct sembuf sops;
  t_msg msg;

  if ((ac != 2))
    {
      return -1;
    }
  key = ftok(av[1], 0);
  msg_id = msgget(key, SHM_W | SHM_R);
  if (msg_id == -1)
    {
      msg_id = msgget(key, IPC_CREAT | SHM_W | SHM_R);
      printf("Created\n");
      msgrcv(msg_id, &msg, sizeof(msg), 42, 0);
      printf("received message type %d %s \n", msg.mtype, msg.str);
    }
  else
    {
      printf("Using msg queue %d\n", msg_id);
      bzero(&msg, sizeof(msg));
      msg.mtype = 42;
      sprintf(msg.str, "Coucou !");
      msgsnd(msg_id, &msg, sizeof(msg), 0);
      msgctl(msg_id, IPC_RMID, NULL);
    }
  return 0;
}
