/*
** lemipc.h for lemipc in /home/nayyer_j/rendu/Lemipc
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Wed Mar  4 15:26:42 2015 Jhanzeeb Nayyer
** Last update Wed Mar  4 17:07:13 2015 Jhanzeeb Nayyer
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/types.h>
# include <sys/ipc.h>

# define MAPMAX_SIZE (400)
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
    THIRD
  }		t_state;

typedef struct	s_settings
{
  int		shm_id;
  int		sem_id;
  int		msg_id;
  void		*addr;
  key_t		key;
}		t_settings;

#endif /* !LEMIPC_H_ */
