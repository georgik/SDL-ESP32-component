
#include "config.h"

#include "SDL.h"

#include "video.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random_in_range(int max) {
    return  rand() % max;
}

void draw_random_rectangle(SDL_Surface *surface) {
    int x = random_in_range(vga_width);   // Random x within screen width
    int y = random_in_range(vga_height);  // Random y within screen height

    // Random width and height constrained to fit within the screen
    int max_w = vga_width - x;
    int max_h = vga_height - y;
    int w = random_in_range(max_w);
    int h = random_in_range(max_h);

    Uint32 color = random_in_range(256); // Random color index from the palette
    SDL_Rect rect = {x, y, w, h};
    printf("Drawing rectangle at x=%d, y=%d, w=%d, h=%d, color=%ld\n", x, y, w, h, color);
    SDL_FillRect(surface, &rect, color);
    
}

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

    SDL_FillRect(VGAScreen, NULL, 0x02);
    for (; ; )
    {
        printf("Drawing red screen\n");
        
        // Draw random size rectangle with random color
        draw_random_rectangle(VGAScreen);

        //  Uint32 red = SDL_MapRGB(VGAScreen->format, 255, 0, 0);
        //  SDL_FillRect(VGAScreen, NULL, red);

        JE_showVGA();
        SDL_Delay(1000);
    }

	return 0;
}

