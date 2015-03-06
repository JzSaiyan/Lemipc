/*
** main.c for Mario in /home/nayyer_j/rendu/Mario
** 
** Made by Jhanzeeb Nayyer
** Login   <nayyer_j@epitech.net>
** 
** Started on  Tue Feb  3 22:42:29 2015 Jhanzeeb Nayyer
** Last update Fri Mar  6 00:38:20 2015 Jhanzeeb Nayyer
*/

#include "list.h"

int		main(void)
{
  SDL_Surface *ecran = NULL, *zozor = NULL;
  SDL_Rect positionZozor;
  SDL_Event event;
  int continuer = 1;

  SDL_Init(SDL_INIT_VIDEO);

  ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /* Double Buffering */
  SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);

  zozor = SDL_LoadBMP("zozor.bmp");
  SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));

  positionZozor.x = ecran->w / 2 - zozor->w / 2;
  positionZozor.y = ecran->h / 2 - zozor->h / 2;

  SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */

  while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  continuer = 0;
	  break;
	case SDL_KEYDOWN:
	  switch(event.key.keysym.sym)
	    {
	    case SDLK_UP:
	      positionZozor.y--;
	      break;
	    case SDLK_DOWN:
	      positionZozor.y++;
	      break;
	    case SDLK_RIGHT:
	      positionZozor.x++;
	      break;
	    case SDLK_LEFT:
	      positionZozor.x--;
	      break;
	    }
	  break;
	}

      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
      SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
      SDL_Flip(ecran);
    }
  SDL_FreeSurface(zozor);
  SDL_Quit();
  return EXIT_SUCCESS;
}
