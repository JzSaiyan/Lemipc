/*
** init.c for Mario in /home/nayyer_j/rendu/Mario
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Wed Feb  4 18:59:34 2015 Jhanzeeb Nayyer
** Last update Wed Mar  4 10:35:35 2015 Jhanzeeb Nayyer
*/

#include "list.h"

int		initSdl()
{
  SDL_Surface	*screen;
  SDL_Surface	*imageDeFond;
  SDL_Rect	positionFond;

  screen = NULL;
  imageDeFond = NULL;
  if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
    {
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
	      SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetIcon(SDL_LoadBMP("sdl_icon.bmp"), NULL);
  if ((screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE |
				 SDL_DOUBLEBUF)) == NULL)
    {
      fprintf(stderr, "Impossible de charger le mode vidéo : %s\n",
	      SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("LemiPC SDL !", NULL);
  imageDeFond = SDL_LoadBMP("lac_en_montagne.bmp");
  SDL_BlitSurface(imageDeFond, NULL, screen, &positionFond);
  SDL_Flip(screen);
  pause();
  SDL_FreeSurface(imageDeFond);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
