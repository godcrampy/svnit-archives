/* libgraph - TurboC graphics API on GNU/Linux
 * text.c: Text input/output functions.
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

#include "grtext.h"

extern struct {int x;int y;}CP;	 /*Screen position pointer
				  *defined in graphics.h
				  *used for outtextxy()*/
				

Uint32 GetPixel(SDL_Surface *Surface, Sint32 X, Sint32 Y)
{

  Uint8  *bits;
  Uint32 Bpp;

  if (X<0) fputs("SFONT ERROR: x too small in GetPixel. Report this to <karlb@gmx.net>", stderr);
  if (X>=Surface->w) fputs("SFONT ERROR: x too big in GetPixel. Report this to <karlb@gmx.net>", stderr);
   
  Bpp = Surface->format->BytesPerPixel;

  bits = ((Uint8 *)Surface->pixels)+Y*Surface->pitch+X*Bpp;

  // Get the pixel
  switch(Bpp) {
  case 1:
    return *((Uint8 *)Surface->pixels + Y * Surface->pitch + X);
    break;
  case 2:
    return *((Uint16 *)Surface->pixels + Y * Surface->pitch/2 + X);
    break;
  case 3: { // Format/endian independent 
    Uint8 r, g, b;
    r = *((bits)+Surface->format->Rshift/8);
    g = *((bits)+Surface->format->Gshift/8);
    b = *((bits)+Surface->format->Bshift/8);
    return SDL_MapRGB(Surface->format, r, g, b);
  }
    break;
  case 4:
    return *((Uint32 *)Surface->pixels + Y * Surface->pitch/4 + X);
    break;
  }

  return -1;
}

void InitFont2(SFont_FontInfo *Font)
{
  int x = 0, i = 0;

  if ( Font->Surface==NULL ) {
    fprintf(stderr, "The font has not been loaded!\n");
    exit(1);
  }

  if (SDL_MUSTLOCK(Font->Surface)) SDL_LockSurface(Font->Surface);

  while ( x < Font->Surface->w ) {
    if(GetPixel(Font->Surface,x,0)==SDL_MapRGB(Font->Surface->format,255,0,255)) { 
      Font->CharPos[i++]=x;
      while (( x < Font->Surface->w-1) && (GetPixel(Font->Surface,x,0)==SDL_MapRGB(Font->Surface->format,255,0,255)))
	x++;
      Font->CharPos[i++]=x;
    }
    x++;
  }
  if (SDL_MUSTLOCK(Font->Surface)) SDL_UnlockSurface(Font->Surface);

  Font->h=Font->Surface->h;
  SDL_SetColorKey(Font->Surface, SDL_SRCCOLORKEY, GetPixel(Font->Surface, 0, Font->Surface->h-1));
}


void InitFont(SDL_Surface *Font)
{
  InternalFont.Surface=Font;
  InitFont2(&InternalFont);
}


void makespace(SFont_FontInfo *Font, char ch)
{
  SDL_Rect dstrect;
  Uint8* bufp;
  int x1,y1=0,ofs;
	
	
  if (ch==' ') {
    TP.x-=Font->CharPos[2]-Font->CharPos[1];
    if (TP.x<0) TP.x=0;
    dstrect.w = Font->CharPos[2]-Font->CharPos[1];              
  }
  else {
    ofs=(ch-33)*2+1;	/*Calculating width of char to erase*/
    dstrect.w = (Font->CharPos[ofs+2]+Font->CharPos[ofs+1])/2-(Font->CharPos[ofs]+Font->CharPos[ofs-1])/2;
    TP.x -= (Font->CharPos[ofs+1]-Font->CharPos[ofs]);
    if (TP.x<0) TP.x = 0;
  }    
  dstrect.h = Font->Surface->h-1;
  for(x1=TP.x; x1<TP.x+dstrect.w; x1++)
    for(y1=TP.y; y1<= TP.y+dstrect.h; y1++)
      {
	bufp = (Uint8 *)screen->pixels + y1*screen->pitch + x1;
	*bufp = _bgcolor;
      }
  SDL_UpdateRect(screen, 0, TP.y, x1, y1);	
  /*For some reason partial update doesn't work here
   *  i am force to do a complete update from the 
   *  beginning of the line till the point of erasure*/
}


void MPutString2(SFont_FontInfo *Font,  char *text)
{
  int ofs;
  int newline=0;
  int i=0;
  SDL_Rect srcrect,dstrect; 

  while (text[i]!='\0') {
    if (text[i]==' ') {
      TP.x+=Font->CharPos[2]-Font->CharPos[1];
      i++;
    }
    else if (text[i]=='\n') {
      SDL_UpdateRect(screen, 0 ,TP.y, TP.x, TP.y+Font->Surface->h-1);/* Update prev line */
      TP.x = 0;				/* Reset x position. */
      TP.y = TP.y+Font->Surface->h-1;	/* inc y position */
      i++;
      newline++;
    }
    else if (text[i]=='\t') {
      TP.x = TP.x + 8*(Font->CharPos[2]-Font->CharPos[1]);
      i++;
    }
    else {			/*Actual printable characters.*/
      ofs=(text[i]-33)*2+1;	
      srcrect.w = dstrect.w = (Font->CharPos[ofs+2]+Font->CharPos[ofs+1])/2\
	-(Font->CharPos[ofs]+Font->CharPos[ofs-1])/2;
      srcrect.h = dstrect.h = Font->Surface->h-1;
      srcrect.x = (Font->CharPos[ofs]+Font->CharPos[ofs-1])/2;
      srcrect.y = 1;
      if ( screen->w - TP.x <= dstrect.w)	/*Reached end of line*/
	{
	  SDL_UpdateRect(screen, 0 , TP.y, TP.x, TP.y+srcrect.y);
	  TP.x = screen->w - TP.x;
	  TP.y = TP.y+dstrect.h;
	  newline++;
	}
      if ( screen->h-TP.y <= srcrect.h) 
	/* Reached end of page.	Wait for space to proceed*/
    	{
	  Uint8* bufp;
	  int x1,y1,c=0;
	  SDL_UpdateRect(screen,0,0,0,0);/*Update previous page*/
	  while(c!=' ') 
	    c=grgetch();	/*wait for space.*/
	  for(x1=0,bufp=(Uint8 *)screen->pixels; x1<=screen->w; x1++)
    	    for(y1=0; y1<=screen->h; y1++,bufp++)
	      *bufp = _bgcolor;
	  SDL_UpdateRect(screen, 0,0,0,0);  /*Update screen after coloring.*/
	  TP.y = screen->h-TP.y;
    	}	
    	    
      dstrect.x = TP.x-(float)(Font->CharPos[ofs]-Font->CharPos[ofs-1])/2;
      dstrect.y = TP.y;

      SDL_BlitSurface( Font->Surface, &srcrect, screen, &dstrect); 
      SDL_UpdateRect(screen,dstrect.x,dstrect.y,dstrect.w,dstrect.h);
      TP.x += Font->CharPos[ofs+1]-Font->CharPos[ofs]; /*inc text pointer by char width*/
      i++;
    }
  }
}

void MPutString(char *text)
{
  MPutString2(&InternalFont, text);
}


void Font_Input(char *input, int num)
{
  SDL_Event event;
  int ch = 0,i=0,count=0;
  int quit=0;
  char *current=input;
  while( !quit )
    if (SDL_PollEvent( &event )) 
      switch( event.type ){
      case SDL_KEYDOWN:
	ch=event.key.keysym.sym;
	if (isprint(ch))
	  {
	    if (!i) 
	      current=input; 
	    else 
	      current++;
	    input[i]=ch;
	    input[++i]='\0';
	    MPutString(current);
	  }
	else if (ch==SDLK_BACKSPACE && i>0)
	  {
	    i--;
	    current--;
	    makespace(&InternalFont, input[i]);
	    input[i]='\0';
	  }
	break;
      case SDL_KEYUP:
	if (event.key.keysym.sym!=SDLK_RETURN) 
	  break;
	else 
	  {
	    count++;
	    TP.x = 0;
	    TP.y += InternalFont.Surface->h;
	    input[i]=' ';
	    input[++i]='\0';
	    current++;
	    if (count<num) 
	      break;
	  } 
      case SDL_QUIT:
	quit = 1;
	break;
      default:
	break;
      }
    else
      SDL_Delay(10);
}


int grgetch(void)
{		
  if (getenv("LIBGRAPHICS_ACTIVE")==0)
    {
      /* getch code is from "$info libc" - Terminal I/O Section.
       *  This block can be used all by itself to provide getch 
       *  functionality by including termios.h and unistd.h  */
      char c;
      struct termios tattr,saved_attributes;
      tcgetattr (STDIN_FILENO, &saved_attributes);   
      tcgetattr (STDIN_FILENO, &tattr);
      tattr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
      tcsetattr (STDIN_FILENO, TCSAFLUSH,  &tattr);
      read(STDIN_FILENO, &c,1);
      tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
      return c;
    }
  else
    {
      int quit=0,c;
      SDL_Event event;
      while( !quit )
	if (SDL_PollEvent( &event )) 
	  switch( event.type ){
	  case SDL_KEYDOWN:
	    c=event.key.keysym.sym;
	    if (isprint(c) || c==SDLK_RETURN)   
	      return c;    
	    break;
	  case SDL_ACTIVEEVENT:
	    if ((event.active.state == SDL_APPINPUTFOCUS)\
		&& event.active.gain)
	      refresh_interrupt(0);
	    break;
	  case SDL_QUIT:
	    quit = 1;
	    break;
	  default:
	    //wSDL_PushEvent(&event);
	    break;
	  }
	else
	  {
	    SDL_WaitEvent(0);
	  }
    }
  return 0;     		/*Never reaches here*/
}                


int grgetche(void)
{
  int c = grgetch();
  grprintf("%c", c);
  return(c);
}


int kbhit(void)
{
  if (getenv("LIBGRAPHICS_ACTIVE")==0)
    {
      int c, oldflags = fcntl(STDIN_FILENO, F_GETFL, 0);
      struct termios tattr,saved_attributes;
      fcntl(STDIN_FILENO, F_SETFL, oldflags|O_NONBLOCK);
      tcgetattr (STDIN_FILENO, &saved_attributes);   
      tcgetattr (STDIN_FILENO, &tattr);
      tattr.c_lflag &= ~(ICANON|ECHO);
      tcsetattr (STDIN_FILENO, TCSANOW,  &tattr);
      if ((read(STDIN_FILENO, &c, 1)) != EOF)
	{
	  fcntl(STDIN_FILENO, F_SETFL, oldflags);
	  tcsetattr (STDIN_FILENO, TCSAFLUSH, &saved_attributes);
	  ungetc(c, stdin);
	  return(c);
	}
      else
	{
	  fcntl(STDIN_FILENO, F_SETFL, oldflags);
	  delay(100);
	  tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
	  return(0);
	}
    }
  else
    {	
      SDL_Event event;
      if(SDL_PollEvent(&event) && (event.type == SDL_KEYDOWN))
	{
	  SDL_PushEvent(&event);
	  return(event.key.keysym.sym);
	}
      {
	if ((event.type == SDL_ACTIVEEVENT) &&(event.active.state == SDL_APPINPUTFOCUS) && event.active.gain)
	  refresh_interrupt(0);
	SDL_Delay(100);
	return(0);
      }
    }
}

int grprintf(const char* text,...)
{
  va_list ap;
  int num=0;
  va_start (ap, text);
	
  if (getenv("LIBGRAPHICS_ACTIVE")==0)
    {
      num = vprintf(text, ap);
    }
  else
    {   
      char *output;  
      num = vasprintf(&output, text, ap);
      /*vasprintf is a GNU extension that allocates a dynamic buffer*/
      MPutString(output);
      free(output);
    }
  va_end(ap);
  return num;
}


int grscanf(const char* text,...)
{
  va_list ap;
  int num=0;
  va_start (ap, text);
	
  if (getenv("LIBGRAPHICS_ACTIVE")==0)
    {
      num = vscanf(text, ap);
    }
  else
    {   
      char input[SCAN_BUF];
      char template[]="1 2 3 4 5 6 7 8 9 10";//Template string to guess 
      //the no of arguments of scanf
      SDL_Event event;
      SDLMod md;
      int ch = 0,i=0;
      int quit=0;
      char *current=input;  
      num = vsscanf(&template,text,ap);    // Guessing no of arguments
      SDL_EnableKeyRepeat( SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
      SDL_EnableUNICODE(1);
      while( !quit )
	if (SDL_PollEvent( &event )) 
	  switch( event.type ){
	  case SDL_KEYDOWN:
	    ch=event.key.keysym.unicode;
	    if (isprint(ch) && i<SCAN_BUF-1) // Check that buffer isn't full
	      {
		if (!i) current=input; else current++;
		input[i]=ch;
		input[++i]='\0';
		MPutString(current);	//draws the last entered char
	      }
	    else
	      if (ch==SDLK_BACKSPACE && i>0)
		{
		  i--;
		  current--;
		  makespace(&InternalFont, input[i]);//clears last entered char
		  input[i]='\0';
		}
	    break;
	  case SDL_KEYUP:
	    md = event.key.keysym.mod;
	    if(  (md & KMOD_RCTRL) || ( md & KMOD_LCTRL ) )
	      {if  (event.key.keysym.sym==SDLK_c)	//Check for CTRL-C
		{
		  MPutString("\nKeyboard Interrupt detected. Qutting...\n");
		  SDL_Delay(200);
		  exit(0);  
		}}    
	    else                    
	      if (event.key.keysym.sym!=SDLK_RETURN) break;
	      else
		{
		  if (i<SCAN_BUF-1 && TP.x!=0)  //Buffer not full
		    {
		      input[i]=' ';
		      input[++i]='\0';
		      current++;
		    }
		  else input[i]='\0'; //Buffer overflow or empty!! Terminate forcefully.
		  TP.x = 0;		// Reset X position.
		  TP.y += InternalFont.Surface->h;  //inc y position.
		  if (vsscanf(&input,text,ap) < num) break;
		  //check number of inputs
		  //if they match, we fall throught to quit.
		} 
	  case SDL_QUIT:
	    quit = 1;
	    break;
	  case SDL_ACTIVEEVENT:
	    if ((event.active.state == SDL_APPINPUTFOCUS)\
		&& event.active.gain)
	      refresh_interrupt(0);
	    break;
	  default:
	    break;
	  }
	else
	  {
	    SDL_Event event;
	    MPutString("_");  	//draw the text-cursor
	    SDL_WaitEvent(&event);
	    SDL_PushEvent(&event);
	    makespace(&InternalFont,'_'); //erase the text-cursor 
	  }
    }
  va_end(ap);
  return num;
}

int grgetchar(void)
{		
  if (getenv("LIBGRAPHICS_ACTIVE")==0)
    {
      return(getc(stdin));
    }
  else
    {
      char c=grgetch();
      grputchar(c);
      return(c);
    }
}

		
int grputchar(int c)
{		
  if (getenv("LIBGRAPHICS_ACTIVE")==0)
    {
      return(putc(c, stdout));
    }
  else
    {
      char c;
      grprintf("%c", c); 
      return(c);
    }
}


void outtext(char* textstring)
{
  int xbak = TP.x, ybak = TP.y;	//save current text position
  CHECK_INITIALIZATION			// Check whether libgraph is active
    TP.x = CP.x, TP.y = CP.y;		//set text position to screen position
  MPutString(textstring);
  TP.x = xbak, TP.y = ybak;		//restore text postition
}

void outtextxy(int x, int y, char* textstring)
{
  int xbak = TP.x, ybak = TP.y;	//save current text position
  CHECK_INITIALIZATION			// Check whether libgraph is active
    TP.x = x, TP.y = y;			//set text position to arguments
  MPutString(textstring);
  TP.x = xbak, TP.y = ybak;		//restore text position
}



int textheight (char *textstring)
{
  CHECK_INITIALIZATION			// Check whether libgraph is active
    return (InternalFont.h);
}


int textwidth (char *text)
{
  int ofs;
  int i = 0;
  int count = 0;

  CHECK_INITIALIZATION			// Check whether libgraph is active
    while (text[i]!='\0') {
      if (text[i]==' ') {
	count += InternalFont.CharPos[2]-InternalFont.CharPos[1];
	i++;
      }
      else if (text[i]=='\n') {
	i++;
      }
      else if (text[i]=='\t') {
	count += + 8*(InternalFont.CharPos[2]-InternalFont.CharPos[1]);
	i++;
      }
      else {			/*Actual printable characters.*/
	ofs=(text[i]-33)*2+1;	
	count += InternalFont.CharPos[ofs+1]-InternalFont.CharPos[ofs]; /*inc text pointer by char width*/
	i++;
      }
    }
  return (count+5);/* Add 5 to actual length to prevent accidental
		      overlap and allow clean fitting onto lines.*/
}

