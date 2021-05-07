/* libgraph - TurboC graphics API on GNU/Linux
 * graphics.h: Core initialization and configuration functions
 * 
 * Copyright (C) 2003  Faraz Shahbazker
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 *  MA 02111-1307, USA
 *
 * Author:  Faraz Shahbazker <faraz_ms@rediffmail.com>
 */

/* Graphic functions using SDL */

#ifndef GRAPHICS_H
#define GRAPHICS_H 1


#include <SDL/SDL.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#ifdef __cplusplus
extern "C" 
{

#endif		/* __cplusplus */

	
/* graphic drivers */
enum _driver{DETECT=0, USER, VGA=9};
enum graphics_modes{VGALO=0, VGAMED, VGAHI, VGAMAX, VGA640, VGA800, VGA1024, USERMODE};


/* 16 colors */
enum _color{BLACK=0, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE};



/* global variables */
SDL_Surface *screen;   		//main drawing screen
SDL_Surface *Font_surface;	//font screen 
Uint32 _fgcolor, _bgcolor, _fontcolor;	//global color numbers
pid_t _pid;			//Don't bother with this 



/* function prototypes */
void initgraph(int *graphdriver,int *graphmode,char *pathtodriver);
void closegraph(void);
void setgraphmode(int gmode);
int  getgraphmode(void);
void restorecrtmode(void);
int  getmaxx(void);
int  getmaxy(void);
void putpixel(int x, int y, int color);
int  getpixel(int, int);
void setbkcolor(int color);
int  getbkcolor(void);
void setcolor(int color);
int  getcolor(void);
int getmaxcolor(void);
char* getdrivername(void);
char* getmodename(int mode_number);
int getmaxmode(void);
void detectgraph(int* graphdriver, int* graphmode);
void getmoderange(int graphdriver, int* lomode, int* himode);
int delay(float);
void setfontcolor(int color);
int getfontcolor(void);





/*** library specific functions - not for users ***/
void initialize_settings (void);
void mappixel(int, int);     //marks a pixel without updating screen
void clippixel(int *, int *); /* Clip pixel (x,y) to current
								 screen size*/
void mapword(int,int,int);
void mapvword(int,int,int);
int colorrev(const Uint8);   // maps 0..255 8-bit color to 0..15 TC color
Uint8 colortrans(const int); // maps 0..15 TC color to 0..255 8-bit color
void ctrlbreak(void);	     // To detect user interrupt	
void inthandler(int);	     // clean up on user interrupt
void safe_update(int top, int left, int right, int bottom);
	/* update screen within boundary */

#define CHECK_INITIALIZATION\
    if (!getenv("LIBGRAPHICS_ACTIVE")) \
	{ \
		fprintf(stderr, "*** The graphics system has not been initialized!\n"); \
		fprintf(stderr, "*** Call initgraph() before trying to use graphics functions.\n"); \
		exit(-1); \
	}

struct {int x;int y;}CP;

#include "grtext.h"
#include "shapes.h"
#include "polygon.h"

#ifdef __cplusplus
}
#endif		/* __cplusplus */


#endif		/* LIBGRAPH_H */
