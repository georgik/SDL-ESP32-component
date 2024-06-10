
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

    for (; ; )
    {
         Uint32 red = SDL_MapRGB(VGAScreen->format, 255, 0, 0);

    // Set 100 pixels to red
    for (int i = 0; i < 100; i++) {
        int x = i % VGAScreen->w;  // Ensure the pixel is within screen width
        int y = i / VGAScreen->w;  // Move to next row if needed
        if (y >= VGAScreen->h) break; // Ensure we don't exceed screen height

        Uint32 *pixels = (Uint32 *)VGAScreen->pixels;
        pixels[(y * VGAScreen->pitch / 4) + x] = red;
    }

        JE_showVGA();
    }

	return 0;
}

