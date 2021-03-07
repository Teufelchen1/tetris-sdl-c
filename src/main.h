#include "defs.h"

#include "init.h"
#include "graphics.h"
#include "input.h"
#include "tetris.h"
#include "utility.h"

// extern vars from graphics.h
extern SDL_Window *window;
extern SDL_Renderer *render;
extern SDL_Texture *display;
extern TTF_Font *gFont;

bool render_changed;
