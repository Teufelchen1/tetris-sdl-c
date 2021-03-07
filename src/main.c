#include <stdio.h>
#include <hal/video.h>
#include <hal/debug.h>
#include <hal/xbox.h>
#include <windows.h>
#include "main.h"


int main() {
    XVideoSetMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, REFRESH_DEFAULT);

    if (SDL_VideoInit(NULL) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL video.\n");
        printSDLErrorAndReboot();
    }

    if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0) {
        printSDLErrorAndReboot();
    }

    atexit(cleanup);
    init();

    bool quit = false;
    while(!quit) {
        preRender();

        getInput();

        updateTetris();

        updateRender();

        // Set to ~60 fps.
        // 1000 ms/ 60 fps = 1/16 s^2/frame
        SDL_Delay(16);
    }


    debugPrint("Prepare for reboot!\n");
    Sleep(5000);
    XReboot();
    return 0;
}
