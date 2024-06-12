
#include "config.h"

#include "SDL.h"

#include "video.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( int argc, char *argv[] )
{

	printf("SDL hello\n\n");

	if (SDL_Init(0))
	{
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		return -1;
	}
	init_video();
    printf("Entering main app loop\n");

    for (; ; )
    {
         Uint32 red = SDL_MapRGB(VGAScreen->format, 255, 0, 0);
         SDL_FillRect(VGAScreen, NULL, red);

        JE_showVGA();
        SDL_Delay(1000);
    }

	return 0;
}

