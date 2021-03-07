#include "input.h"
#include <hal/debug.h>
#include <hal/xbox.h>
#include <windows.h>


void inputInit() {
    if (SDL_NumJoysticks() < 1) {
        debugPrint("Please connect gamepad\n");
#if defined(NXDK)
        XReboot();
#endif
    }

    if (SDL_GameControllerOpen(0) == NULL) {
        debugPrint("Failed to open gamecontroller 0\n");
#if defined(NXDK)
        XReboot();
#endif
    }
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
}


void getInput() {
    SDL_Event event;

    /* Loop through waiting messages and process them */

    while (SDL_PollEvent(&event)) {
        switch (event.type) {

            /* Closing the Window or pressing Escape will exit the program */
            case SDL_QUIT:
#if defined(NXDK)
                XReboot();
#else
                exit(0);
#endif
            break;

            case SDL_CONTROLLERBUTTONDOWN:
                switch (event.cbutton.button) {
                    case SDL_CONTROLLER_BUTTON_A:
                        TETROMINO_ACTION = ROTATE;
                        break;
                    case SDL_CONTROLLER_BUTTON_B:
                        TETROMINO_ACTION = RIGHT;
                        break;
                    case SDL_CONTROLLER_BUTTON_X:
                        TETROMINO_ACTION = LEFT;
                        break;
                    case SDL_CONTROLLER_BUTTON_Y:
                        TETROMINO_ACTION = DROP;
                        break;
                    case SDL_CONTROLLER_BUTTON_BACK:
                    case SDL_CONTROLLER_BUTTON_START:
                        XReboot();
                        break;
                }
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;

                    case SDLK_s:
                    case SDLK_DOWN:
                        TETROMINO_ACTION = DOWN;
                    break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        TETROMINO_ACTION = RIGHT;
                    break;

                    case SDLK_a:
                    case SDLK_LEFT:
                        TETROMINO_ACTION = LEFT;
                    break;

                    case SDLK_w:
                    case SDLK_UP:
                        TETROMINO_ACTION = ROTATE;
                    break;

                    case SDLK_r:
                        TETROMINO_ACTION = RESTART;
                    break;

                    case SDLK_SPACE:
                        TETROMINO_ACTION = DROP;
                    break;

                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                TETROMINO_ACTION = NONE;
            break;

            case SDL_USEREVENT:
                TETROMINO_ACTION = AUTO_DROP;
            break;

            default:
            break;
        }
    }
}
