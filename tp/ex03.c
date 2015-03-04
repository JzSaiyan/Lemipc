/*
** ex01.c for examples in /home/nayyer_j/rendu/Lemipc
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Wed Mar  4 11:49:48 2015 Jhanzeeb Nayyer
** Last update Wed Mar  4 15:05:09 2015 Jhanzeeb Nayyer
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>

typedef struct	s_msg
{
  long		type;
  char		str[32];
}		t_msg;

int		main(int argc, char **argv)
{
  int		msg_id;
  void		*addr;
  key_t		key;
  t_msg		mymsg;

  if (argc != 2)
    {
      printf("[USAGE] %s pathname\n", argv[0]);
      return (0);
    }
  if ((key = ftok(argv[1], 0)) != -1)
    printf("Key = [%d]\n", key);
  else
    printf("[USAGE] %s pathname\n", argv[0]);
  msg_id = msgget(key, SHM_R | SHM_W);
  if (msg_id == -1)
    {
      msg_id = msgget(key, SHM_R | SHM_W);
      printf("Create msg\n", msg_id);
      msgrcv(msg_id, &mymsg, sizeof(mymsg), 42, 0);
      printf("Receive : %s (%d)\n", mymsg.str, mymsg.type);
    }
  else
    {
      mymsg.type = 42;
      bzero(mymsg.str, sizeof(mymsg));
      sprintf(mymsg.str, "Hello World\n");
      msgsnd(msg_id, &mymsg, sizeof(mymsg), 0);
      msgctl(msg_id, IPC_RMID, NULL);
    }
  return (0);
}
