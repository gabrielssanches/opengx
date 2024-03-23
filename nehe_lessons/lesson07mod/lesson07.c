// normal includes
#include <stdlib.h>
#include <time.h>
#include <gccore.h>
#include <wiiuse/wpad.h> 

// SDL includes
#include <SDL/SDL.h>
//#include <SDL/SDL_.h>

// screen surface, the place where everything will get print onto
SDL_Surface *screen = NULL;

void init(){
	
    // initialize SDL video. If there was an error SDL shows it on the screen
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
    {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError() );
		SDL_Delay( 5000 );
        exit(EXIT_FAILURE);
    }
	
    // button initialization
    WPAD_Init();
 
    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    SDL_ShowCursor(SDL_DISABLE);
 
    // create a new window
    screen = SDL_SetVideoMode(640, 480, 16, SDL_DOUBLEBUF);
    if ( !screen )
    {
        fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
		SDL_Delay( 5000 );
        exit(EXIT_FAILURE);
    }
}

// this will be used in further lessons, not in lesson 1
void apply_surface ( int x, int y, SDL_Surface* source, SDL_Surface* destination ){
     
     // make a temporary rectangle to hold the offsets
     SDL_Rect offset;
     
     // give the offsets to the rectangle
     offset.x = x;
     offset.y = y;
     
     // blit the surface
     SDL_BlitSurface( source, NULL, destination, &offset );
}

void cleanup(){
	
     // we have to quit SDL
     SDL_Quit();
     exit(EXIT_SUCCESS);
}

int main(int argc, char** argv){
	// main function. Always starts first
	
	// to stop the while loop
	bool done = false;
	
	// start init() function
	init();
	
	// this will make the red background
	// the first argument says it must be placed on the screen
	// the third argument gives the color in RGB format. You can change it if you want
	SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 0, 0));
	
	// this is the endless while loop until done = true
	while (!done)
        {
		// scans if a button was pressed
                WPAD_ScanPads();
		u32 held = WPAD_ButtonsHeld(0);
		
		// if the homebutton is pressed it will set done = true and it will fill the screen
		// with a black background
		if(held & WPAD_BUTTON_HOME){
			done=true;
			SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
		}
		
		// SDL_Flip refreshes the screen so it will show the updated screen
		SDL_Flip(screen);
        }
 
	// start cleanup() function
	cleanup();
 
    return 0;
}
