/* libgraph - TurboC graphics API on GNU/Linux
 * grtext.h: Text input/output functions.
 * 
 * Copyright (C) 2003   Faraz Shahbazker.
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


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define getch grgetch 		//Mapping regular C functions    
#define getche grgetche 	// to graphics mode functions    
#define printf grprintf	
#define scanf grscanf
#define putchar grputchar
#define getchar grgetchar
#define SCAN_BUF 256   /* Increase this if you want a bigger buffer for scanf*/



			/*These are regular TC functions*/
void outtext(char* textstring);
void outtextxy(int x, int y, char* textstring);
int textheight (char *textstring);
int textwidth (char *textstring);

			/*The gr... functions provide corresponding facilities in graphics mode.
			You can use getch(),printf(),scanf() directly without bothering about these
			declarations*/ 
int grgetch(void);
int grgetche(void);
int grprintf(const char* text,...);
int grscanf(const char* text,...);
int grputchar(int);
int grgetchar(void);

/*******Following declarations are internal i.e. not for users. Developers read on...***************/


// Delcare one variable of this type for each font you are using.
// To load the fonts, load the font image into YourFont->Surface
// and call InitFont( YourFont );
typedef struct {
	SDL_Surface *Surface;	
	int CharPos[512];
	int h;
} SFont_FontInfo;


SFont_FontInfo InternalFont;  //The default internal font.



			/*Global variables	*/   
extern SDL_Surface *screen;	  /* The main drawing screen */
extern Uint32 _fgcolor, _bgcolor; /*to tell makespace what color to fill in while backspacing*/ 


			/*Internal Global variable */
struct {int x; int y;}TP;			/*The text pointer manipulated by printf/scanf */


// Initializes the font
// Font: this contains the suface with the font.
//       The font must be loaded before using this function.
//Font must be loaded by Font = IMG_Load("fontfile.png");

void InitFont (SDL_Surface *Font);
void InitFont2(SFont_FontInfo *Font);
Uint32 GetPixel(SDL_Surface *Surface, Sint32 X, Sint32 Y);


// Blits a string to a surface
// text: a string containing the text you want to blit.

void MPutString (char *text);
void MPutString2(SFont_FontInfo *Font, char *text);


// Allows the user to enter text
// num : number of arguments passed to scanf 
// input : string containing user input that is read by Font_Input 

void Font_Input(char *input, int num);


//Used to backspace. ch is char to be erased

void makespace(SFont_FontInfo *Font, char ch); 


#define CHECK_INITIALIZATION \
    if (!getenv("LIBGRAPHICS_ACTIVE"))\
	{\
		fprintf(stderr, "*** The graphics system has not been initialized!\n"); \
		fprintf(stderr, "*** Call initgraph() before trying to use graphics functions.\n"); \
		exit(-1); \
	}
