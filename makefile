XBE_TITLE = tetris
GEN_XISO = $(XBE_TITLE).iso

NXDK_DIR = /Users/$(USER)/Programming/nxdk-teufelchen
NXDK_SDL = y

SRCS += src/init.c\
	src/input.c\
	src/graphics.c\
	src/tetris.c\
	src/shuffle.c\
	src/sds.c\
	src/utility.c\
	src/main.c

include $(NXDK_DIR)/Makefile


#macOS:
#	$(CC) -o tetris.bin $(SRCS) `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_ttf -lm

#include $(NXDK_DIR)/Makefile

#src/SDL2_gfxBlitFunc.c\

#CFLAGS   = -g `sdl2-config --cflags`
#LDFLAGS  = `sdl2-config --libs` -lSDL2_gfx -lSDL2_ttf -lm
#PROG = tetris_toy
#CXX = gcc

#OBJS   = init.o input.o graphics.o tetris.o shuffle.o sds.o utility.o main.o

# top-level rule to create the program.
#all: $(PROG)

# compiling other source files.
#%.o: src/%.c src/%.h src/defs.h
#	$(CXX) $(CFLAGS) -c $<

# linking the program
#$(PROG): $(OBJS)
#	$(CXX) $(OBJS) -o $(PROG) $(LDFLAGS)

# cleaning everything that can be automatically recreated with "make"
#clean:
#	rm $(PROG) *.o
