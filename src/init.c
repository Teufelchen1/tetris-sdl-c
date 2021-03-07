#include "init.h"

void init() {

    if(TTF_Init() == -1) {
        printSDLErrorAndReboot();
    }

    inputInit();

    init_graphics();

    initTetris();

}

void cleanup() {

    cleanup_graphics();

    TTF_Quit();

    // Shut down SDL
    SDL_Quit();
}
