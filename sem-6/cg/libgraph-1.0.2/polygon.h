/* libgraph - TurboC graphics API on GNU/Linux
 * polygon.h: Code for drawing and filling polygons.
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



#include <SDL/SDL.h>
#include <math.h>
#include <stdlib.h>

/* Exported Globals */
extern SDL_Surface *screen;
extern Uint32 _fgcolor, _bgcolor;

/*global to this file*/
typedef struct scln scanpt; 
struct scln 
{
    int x;
    scanpt* next;
};

scanpt** _scanlist; /*Stores the scanlist for a polygon*/



/*User level functions */
void fillpoly(int numpoints, int *polypoints);
void drawpoly(int numpoints, int *polypoints);

/*Special user-level extension -- reads number of vertices into
* argument pointer and returns malloced list of 
* vertices, which can be used for drawpoly or fillpoly. */
int* getpoly(int*);


/*Internal/implementation level functions*/
void _freelist(void);		// frees previous scan-list
void _makelist(int, int*);	//creates new scanlist
void _fillpoly(void);		//actual fill function
void _dda(int, int, int, int);	
void _insertpt(scanpt*, int);  
void getpolysize(int, int*, int*, int*, int*, int*);



#define CHECK_INITIALIZATION \
    if (!getenv("LIBGRAPHICS_ACTIVE")) \
	{ \
		fprintf(stderr, "*** The graphics system has not been initialized!\n"); \
		fprintf(stderr, "*** Call initgraph() before trying to use graphics functions.\n"); \
		exit(-1); \
	}
