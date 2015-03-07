/*
** mainGui.c for lemipc in /home/nayyer_j/rendu/Lemipc/Gui
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Fri Mar  6 14:10:04 2015 Jhanzeeb Nayyer
** Last update Sat Mar  7 17:55:30 2015 Jhanzeeb Nayyer
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include "Gui.h"

int		initSdl(t_sdl *init)
{
  init->screen = NULL;
  init->image = NULL;
  init->position.x = 0;
  init->position.y = 0;
  if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
    {
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
	      SDL_GetError());
      return (-1);
    }
  if ((init->screen = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE |
				       SDL_DOUBLEBUF)) == NULL)
    {
      fprintf(stderr, "Impossible de charger le mode vidéo : %s\n",
	      SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("LemiPC SDL !", NULL);
  return (0);
}

void		pauseSdl()
{
  int		cont;
  SDL_Event	event;

  cont = 1;
  while (cont)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	cont = 0;
      else if (event.key.keysym.sym == SDLK_ESCAPE)
	cont = 0;
    }
}

void		readMap(t_sdl *init)
{
  char		*imageName;

  imageName = "./Gui/lemipc.bmp";
  init->image = SDL_LoadBMP(imageName);
  while (init->position.y < 1000)
    {
      while (init->position.x < 1000)
	{
	  SDL_BlitSurface(init->image, NULL, init->screen, &init->position);
	  init->position.x += 100;
	}
      imageName = "./Gui/img1.bmp";
      init->image = SDL_LoadBMP(imageName);
      init->position.x = 0;
      init->position.y += 100;
    }
}

int		startSdl()
{
  t_sdl		init;

  if (initSdl(&init) == -1)
    return (-1);
  readMap(&init);
  SDL_Flip(init.screen);
  pauseSdl();
  SDL_FreeSurface(init.image);
  SDL_Quit();
  return (0);
}

int		main(void)
{
  if (startSdl() == -1)
    return (-1);
  return (0);
}
