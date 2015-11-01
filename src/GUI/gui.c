#include "gui.h"

int main(void)
{
    SDL_Surface *ecran = NULL, *logo = NULL;
    SDL_Rect  positionlogo;
    positionlogo.x = 0;
    positionlogo.y = 0;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("logo.png"), NULL);
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Facial Recognition", NULL);
    logo = IMG_Load("logo.png");
    SDL_BlitSurface(logo, NULL, ecran, &positionlogo);
    SDL_Flip(ecran);
    pause();
    SDL_FreeSurface(logo);
    SDL_Quit();
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

