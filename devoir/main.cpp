#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *rectangle = NULL;
    SDL_Rect position;

    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);// Ouverture de la fen�tre
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
    SDL_WM_SetCaption("Jeu de lumiere", NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));

    position.x = 0; //position par rapport � l'axe des abscisses qui part du coin sup�rieure gauche
    position.y = 0;

    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_BlitSurface(rectangle, NULL, ecran, &position); //collage du rectangle sur l'�cran

    SDL_Flip(ecran); /* Mise � jour de l'�cran avec sa nouvelle couleur et le rectangle */

    pause(); // Mise en pause du programme

    SDL_FreeSurface(rectangle);//Lib�ration de la surface
    SDL_Flip(ecran); /* Mise � jour de l'�cran avec sa nouvelle couleur */

    SDL_Quit(); // Arr�t de la SDL

    return EXIT_SUCCESS; // Fermeture du programme
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
