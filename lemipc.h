/*
** lemipc.h for lemipc in /home/nayyer_j/rendu/Lemipc
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Wed Mar  4 15:26:42 2015 Jhanzeeb Nayyer
** Last update Thu Mar  5 18:31:35 2015 Jhanzeeb Nayyer
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/types.h>
# include <sys/ipc.h>

# define MAPMAX_SIZE (440)
# define PATH_SIZE (1024)

typedef enum	e_bool
  {
    FALSE,
    TRUE
  }		t_bool;

typedef enum	e_state
  {
    EMPTY,
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    SEP = 42
  }		t_state;

typedef enum	e_move
  {
    MOVE_RIGHT,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_DIG_UP_RIGHT,
    MOVE_DIG_UP_LEFT,
    MOVE_DIG_DOWN_RIGHT,
    MOVE_DIG_DOWN_LEFT
  }		t_move;

typedef struct	s_settings
{
  int		shm_id;
  int		sem_id;
  int		msg_id;
  void		*addr;
  key_t		key;
  struct sembuf	sops;
}		t_settings;

#endif /* !LEMIPC_H_ */
