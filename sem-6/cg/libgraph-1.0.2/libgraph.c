/* libgraph - TurboC graphics API on GNU/Linux
 * libgraph.c: Core initialization and configuration functions
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


#include "graphics.h"


void ctrlbreak(void)
{
  int quit=0;	
  SDL_Event event;
  SDLMod md;
  sleep(1);
  while( !quit ){
    if (getppid()==1) exit(0);
    if (SDL_PollEvent (&event))
      { 
	switch (event.type){
	case SDL_KEYUP:
	  md = event.key.keysym.mod;	
	  if((md && KMOD_RCTRL) || (md && KMOD_LCTRL) )
	    if  (event.key.keysym.sym==SDLK_c)
	      {
		fprintf(stderr,"Keyboard Interrupt detected. Quitting...\n");
		kill(getppid(),SIGUSR1);  //Signal parent to quit
		exit(0);  
	      }    
	  break;  
	case SDL_ACTIVEEVENT:
	  if ((event.active.state == SDL_APPINPUTFOCUS) &&\
	      event.active.gain)
	    kill(getppid(), SIGUSR2);
	  break;
	case SDL_QUIT:
	  quit = 1;
	  break;
	default:
	  break;
	}
      }
    else 
      {
	sleep(1);/* X requires time between 2 successive
		  * event polls. */
      }
  }
}
    
                                                                                
void inthandler(int x)
{
  closegraph();
  exit(0);
}



void refresh_interrupt (int x)
{
  SDL_UpdateRect (screen, 0, 0, 0, 0);
}



void initgraph(int *graphdriver,int *graphmode,char *pathtodriver)
{
  int x=640, y;  
  int _initflag=SDL_SWSURFACE;

  if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
    {
      fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
      exit(-1);
    } 
  atexit(closegraph);  /* Register closegraph() as the default 
			  exit function in case user forgets to call it. */			
    
  _pid = fork();	// Don't bother with this. 
  if 			//The process forks a child to check for Ctrl-C.
    (!_pid) ctrlbreak();
  else
    {
      signal(SIGUSR1, inthandler);
      signal (SIGUSR2, refresh_interrupt);
    }
   
  if (*graphdriver == DETECT) 
    *graphmode = VGAHI;    	//Default mode 640*480*8
  if (*graphdriver == USER)	
    {
      y = *graphmode % 1000;
      x = (*graphmode / 1000) % 1000;
      *graphmode = USERMODE;
    }
  else
    switch(*graphmode){
    case VGALO : 
      y = 200;
      break;
    case VGAMED : 
      y = 350;
      break;
    case VGAMAX :
      x = 800,y = 600;  /*Special extension 800*600*8  windowed*/
      break;
    case VGA640 :		/* Special extension 640x480x8 fullscreen	*/
      y = 480;		/* WARNING : may cause virtual screen */
      _initflag |= SDL_FULLSCREEN;
      break;
    case VGA800 :			/* Special extension 800x600x8  fullscreen	*/
      x = 800, y = 600;	/* WARNING : may cause virtual screen */
      _initflag |= SDL_FULLSCREEN;
      break;
    case VGA1024 :			/* Special extension 1024x768x8 fullscreen	*/
      x = 1024, y = 768;	/* WARNING : may cause virtual screen */
      _initflag |= SDL_FULLSCREEN;
      break;
    case VGAHI : 
    default    : 
      y = 480;
      break;
    }


  {	/* Setup the custom libgraph icon */
    char *iconpath;
    asprintf (&iconpath, "%s%s", FONTDIR, "icon.bmp");
    SDL_WM_SetIcon (SDL_LoadBMP	(iconpath), NULL);
    free (iconpath);
  }
	
	
  SDL_WM_SetCaption("SDL-libgraph -- Graphics on GNU/Linux", 0); 
  /* Set the default libgraph window caption */

	
  screen = SDL_SetVideoMode(x, y, 8, _initflag);
  if ( screen == NULL ) {
    fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
    exit(-1);
  }

  initialize_settings (); /* Initialize global variables */
}



void closegraph(void)
{
  kill(_pid, SIGKILL);		//Kill child if it is alive.
  SDL_Quit();
  unsetenv("LIBGRAPHICS_ACTIVE");     //Unset the env variable
}            	 


void initialize_settings (void)
{
  _fgcolor = colortrans(WHITE);	//Default drawing color = white
  _bgcolor = colortrans(BLACK);	//default background = black
  _fontcolor = WHITE;				/* Default font color */
  putenv("LIBGRAPHICS_ACTIVE=1");  /*This is used by text funtions to 
				     determine whether to use stdout or 
				     drawing screen */
  setfontcolor(_fontcolor); //Loads the default font -- white
  _internal_linestyle.linestyle = SOLID_LINE;
  _internal_linestyle.thickness = NORM_WIDTH;
  _internal_linestyle.upattern = 0xffff;
}

void setgraphmode(int gmode)
{
  int gdriver = VGA;
  initgraph(&gdriver,&gmode,0);
}


int getgraphmode(void)
{
  CHECK_INITIALIZATION
    switch (getmaxy()){
    case 199 :  return VGALO;
    case 349 : return VGAMED;
    case 479 : return VGAHI;
    case 599 : return VGAMAX;
    case 767 : return VGA1024;
    default : return USERMODE;
    }
}    

void restorecrtmode(void)
{
  closegraph();
}

int getmaxx(void)
{
  CHECK_INITIALIZATION
    return (screen->w - 1);
}

int getmaxy(void)
{
  CHECK_INITIALIZATION
    return (screen->h - 1);
}
           		  
           		             		             		  
void mappixel(int x, int y)
{
  Uint8* bufp;
  if (x > screen->w || y > screen->h || x < 0 || y < 0) 
    {
      fprintf(stderr, "Pixel request out of range!!\t(%d,%d)\n", x, y);	
      return;  
    }
  bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
  *bufp = _fgcolor;
}


void clippixel(int *x, int *y)
{
  if (*x < 0) 
    *x = 0;
  else if (*x > screen->w)
    *x = screen->w;
  if (*y < 0)
    *y = 0;
  else if (*y > screen->h)
    *y = screen->h;
}


void mapword(int x, int y, int word)
{
  Uint8* bufp;
  if (x+word < 0)
    {
      x -= word;
      word -= 0;
    }
  if (x > screen->w || y > screen->h || x < 0 || y < 0) 
    {	/* Check for range */
      fprintf(stderr, "Pixel request out of range!!\t(%d,%d)\n", x, y);	
      return;  
    }
  if (x+word > screen->w)  /* Check for range and clip */ 
    word = screen->w - x;
  bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
    
  /* BUGFIX : condition word changed to word >= 0
     one less pixel was getting plotted */
  for (; word >= 0; word--)
    {
      *bufp = _fgcolor;
      bufp++;
    }
}  
 
void mapvword(int x, int y, int word)
{
  Uint8* bufp;
  if (word<0) 
    {
      y -= word;
      word -= 0;
    }	

  if (x > screen->w || y >  screen->h || x < 0 || y < 0) 
    {	/* Check for range */
      fprintf(stderr, "Pixel request out of range!!\t(%d,%d)\n", x, y);	
      return;  
    }

  if (y+word > screen->h)		/*Check for range and clip */
    word = screen->h - y;
  bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;

  /* BUGFIX : condition word changed to word >= 0
     one less pixel was getting plotted */
  for (; word >= 0; word--)
    {
      *bufp = _fgcolor;
      bufp += screen->pitch;
    }
}  
                                                                                                                      
void putpixel(int x, int y, int color)
{  
  int orig_color;
  CHECK_INITIALIZATION
    orig_color = getcolor();
  setcolor(color);
  mappixel(x,y); 
  setcolor(orig_color);
  SDL_UpdateRect(screen, x, y, 1, 1);
}                          		      


int getpixel(int x, int y)
{
  Uint8* bufp;
  Uint8 color;
  CHECK_INITIALIZATION
    if (x > screen->w || y > screen->h || x < 0 || y < 0) 
      {
	fprintf(stderr, "getpixel() request out of range!!\t(%d,%d)\n", x, y);	
	return colorrev(_fgcolor);  
      }
  bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
  color = *bufp;
  return colorrev(color);
}       		             		  
 		             		         		             

Uint8 colortrans(const int color)
{
  Uint8 trans;
  switch(color){
  case 0 : trans = 0; break;
  case 1 : trans = 3; break;
  case 2 : trans = 28; break;
  case 3 : trans = 31; break;
  case 4 : trans = 224; break;
  case 5 : trans = 227; break;
  case 6 : trans = 136; break;
  case 7 : trans = 219; break;
  case 8 : trans = 73; break;
  case 9 : trans = 143; break;
  case 10 : trans = 158; break;
  case 11 : trans = 191; break;
  case 12 : trans = 237; break;
  case 13 : trans = 247; break;
  case 14 : trans = 252; break;
  case 15 :
  default : trans = 255; break;
  }
  return trans;
}


int colorrev(const Uint8 color)
{
  int rev;
  switch(color){
  case 0 : rev = 0; break;
  case 3 : rev = 1; break;
  case 28 : rev = 2; break;
  case 31 : rev = 3; break;
  case 224 : rev = 4; break;
  case 227 : rev = 5; break;
  case 136 : rev = 6; break;
  case 219 : rev = 7; break;
  case 73 : rev = 8; break;
  case 143 : rev = 9; break;
  case 158 : rev = 10; break;
  case 191 : rev = 11; break;
  case 237 : rev = 12; break;
  case 247 : rev = 13; break;
  case 252 : rev = 14; break;
  case 255 :
  default : rev = 15; break;
  }
  return rev;
}


void setbkcolor(int color)
{   
  SDL_Rect* dstrect;
  Uint8* bufp;
  CHECK_INITIALIZATION
    dstrect=0;
  _bgcolor = colortrans(color);
  SDL_FillRect(screen, dstrect, _bgcolor);
  SDL_UpdateRect(screen, 0,0,0,0);
}    


int getbkcolor(void)
{
  return colorrev(_bgcolor);
}


void setcolor(int color)
{
  _fgcolor = colortrans(color);
}


int getcolor(void)
{
  return colorrev(_fgcolor);
}


int getmaxcolor(void)
{
  return 15;
}


char* getdrivername(void)
{
  return strdup ("EGAVGA");
}


char* getmodename(int mode_number)
{
  char* modename;
  switch(mode_number)
    {
    case VGALO : modename = strdup ("640 x 200 VGA");break;
    case VGAMED : modename = strdup ("640 x 350 VGA");break;
    case VGAHI : modename = strdup ("640 x 480 VGA");break;
    case VGAMAX : modename = strdup ("800 x 600 VGA");break;
    case VGA640 : modename = strdup ("640 x 480 VGA - fullscreen");break;
    case VGA800 : modename = strdup ("800 x 600 VGA - fullscreen");break;
    case VGA1024 : modename = strdup ("1024 x 800 VGA - fullscreeen");break;
    default : modename = strdup ("User specified");
    }
  return modename;
}

int getmaxmode(void)
{
  return VGA1024;
}


void detectgraph(int* graphdriver, int* graphmode)
{
  int driver = VGA;
  *graphmode = VGAMAX;
  if (getenv("LIBGRAPHICS_ACTIVE"))
    closegraph();
  initgraph(&driver, graphmode, "");
}


void getmoderange(int graphdriver, int* lomode, int* himode)
{
  if ((graphdriver == VGA) || (graphdriver == -1))
    {
      *lomode = VGALO;
      *himode = VGA1024;
    }
  else
    {
      *lomode = -1;
      *himode = -1;
    }
}


void safe_update(int left, int top, int right, int bottom)
{
  clippixel(&left, &top);
  clippixel(&right, &bottom);
  SDL_UpdateRect(screen, left, top, abs(right-left), abs(bottom-top));
}


int delay(float milisec)
{
  struct timespec wait;
  if(milisec>=1000)
    {
      wait.tv_sec=milisec/1000;
      milisec-=(wait.tv_sec*1000);
    }
  else
    wait.tv_sec=0;
  wait.tv_nsec=milisec*1000000;
  nanosleep(&wait,0);
  return 0;
}



void setfontcolor(int color)
{
  char *fontpath;
  CHECK_INITIALIZATION
    switch(color)
      {
      case WHITE :
	asprintf(&fontpath, "%s%s", FONTDIR, "white.png");
	break;
      case BLACK :
	asprintf(&fontpath, "%s%s", FONTDIR, "black.png");
	break;
      case RED :
	asprintf(&fontpath, "%s%s", FONTDIR, "red.png");
	break;
      case BLUE :
	asprintf(&fontpath, "%s%s", FONTDIR, "blue.png");
	break;
      case GREEN :
	asprintf(&fontpath, "%s%s", FONTDIR, "green.png");
	break;
      case CYAN :
	asprintf(&fontpath, "%s%s", FONTDIR, "cyan.png");
	break;
      case MAGENTA :
	asprintf(&fontpath, "%s%s", FONTDIR, "magenta.png");
	break;
      case YELLOW :
	asprintf(&fontpath, "%s%s", FONTDIR, "yellow.png");
	break;
      case LIGHTGREEN :
	asprintf(&fontpath, "%s%s", FONTDIR, "lightgreen.png");
	break;
      case LIGHTBLUE :
	asprintf(&fontpath, "%s%s", FONTDIR, "lightblue.png");
	break;
      case LIGHTMAGENTA :
	asprintf(&fontpath, "%s%s", FONTDIR, "lightmagenta.png");
	break;
      case LIGHTRED :
	asprintf(&fontpath, "%s%s", FONTDIR, "lightred.png");
	break;
      case BROWN :
	asprintf(&fontpath, "%s%s", FONTDIR, "brown.png");
	break;
      case LIGHTGRAY :
	asprintf(&fontpath, "%s%s", FONTDIR, "lightgray.png");
	break;
      case DARKGRAY :
	asprintf(&fontpath, "%s%s", FONTDIR, "darkgray.png");
	break;
      default :
	fprintf(stderr, "Font color requested is unavailable -- %d\n", color);
	return;
      }	
  SDL_FreeSurface(Font_surface);
  Font_surface = IMG_Load(fontpath);
  InitFont(Font_surface);
  free(fontpath);
}
	

int getfontcolor(void)
{
  return(_fontcolor);
}
