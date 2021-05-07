/* libgraph - TurboC graphics API on GNU/Linux
 * shapes.h: Code for drawing various shapes (except polygons).
 * 
 * Copyright (C) 2003  Faraz Shahbazker.
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

 
/*Standard geometric shapes */
#include <SDL/SDL.h>
#include <math.h>
#include <stdint.h>

#define SWAP(A,B,TYPE) {TYPE temp=A; A=B; B=temp;}
#define MAX(A,B)  (A)>(B)? (A) : (B)
#define ROT(pattern) (((pattern) >> 0x1) | ((pattern) << 0xf))

/* Pre-defined line-styles */
enum line_styles { 
    SOLID_LINE, 
    DOTTED_LINE, 
    CENTER_LINE, 
    DASHED_LINE, 
    USERBIT_LINE 
  };

/* Pre-defined line-widths */
enum line_widths {NORM_WIDTH=1, THICK_WIDTH=3};



extern SDL_Surface *screen;
extern Uint32 _fgcolor, _bgcolor;


struct arccoordstype {
	int x, y;			/* Center point of arc */
	int xstart, ystart; /* Start position */
	int xend, yend;	    /* end position */
};


/* Structure containing information about line-style */
struct linesettingstype {
  int linestyle;
  uint16_t upattern;
  int thickness;
};


void cleardevice(void);

int getx(void);

int gety(void);

void moveto(int x, int y);

void moverel(int dx, int dy);

void line(int x1, int y1, int x2, int y2);

void linerel(int dx, int dy);

void lineto(int x, int y);

void circle(int xc, int yc, int radius);

void arc(int xc, int yc, int stangle, int endangle, int radius);

void pieslice(int xc, int yc, int stangle, int endangle, int radius);

void rectangle(int left, int top, int right, int bottom);

void ellipse(int xc, int yc, int stangle, int endangle, int rx, int ry);

void sector(int xc, int yc, int stangle, int endangle, int rx, int ry);

void floodfill(int x, int y, int color);

void fillellipse(int xc, int yc, int rx, int ry);

void genellipse(int xc, int yc, int rx, int ry, int theta);

void bar(int left, int top, int right, int bottom);

void bar3d(int left, int top, int right, int bottom,
		int depth, int topflag);


void getlinesettings (struct linesettingstype *);

void setlinestyle (int linestyle, int upattern, int thickness);


// Internal function : Do not use
void _boundaryfill(int, int, int);

struct arccoordstype _last_arc;




/* Holds the current set line-style */
struct linesettingstype _internal_linestyle;


#define CHECK_INITIALIZATION \
    if (!getenv("LIBGRAPHICS_ACTIVE")) \
	{ \
		fprintf(stderr, "*** The graphics system has not been initialized!\n"); \
		fprintf(stderr, "*** Call initgraph() before trying to use graphics functions.\n"); \
		exit(-1); \
	}
