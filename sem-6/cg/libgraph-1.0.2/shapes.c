/* libgraph - TurboC graphics API on GNU/Linux
 * shapes.c: Code for drawing various shapes (except polygons).
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

#include "shapes.h"


extern struct {int x; int y;}CP;  
/* Screen position pointer defined in graphics.h*/


void cleardevice(void)
{
  CHECK_INITIALIZATION	// Check whether libgraph is active
    setbkcolor(getbkcolor());
  CP.x = 0;
  CP.y = 0;
}



int getx(void)
{
  return CP.x;
}


int gety(void)
{
  return CP.y;
}


void moveto(int x, int y)
{
  CP.x = (x>getmaxx())? getmaxx() : x;
  CP.y = (y>getmaxy())? getmaxy() : y;
  CP.x = (x<0)? 0 : x;
  CP.y = (y<0)? 0 : y;
}


void moverel(int dx, int dy)
{
  CP.x += dx;
  CP.y += dy;
  moveto(CP.x, CP.y);
}  


/* simple solid single-pixel line */
void fastline(int x1, int y1, int x2, int y2)
{
  int dx=abs(x1-x2), dy=abs(y1-y2), p;	
  int inc;
  if (!dy)	/* Horizontal line - use mapword */
    x1<x2? mapword(x1, y1, dx) : mapword(x2, y2, dx);
  else
    if (!dx)    /*Vertical line - use mapvword  */  
      y1<y2? mapvword(x1, y1, dy) : mapvword(x2, y2, dy);
    else
      if (dx>=dy)
	{
	  p = 2*dy-dx;
	  if (x1 >= x2)
	    {   
	      SWAP(x1, x2, int)
	    	SWAP(y1, y2, int)
		}
	  mappixel(x1, y1);
	  if (y2>=y1) inc=1;
	  else inc=-1;
    	
	  while(x1 < x2)
	    {	
	      x1++;   	
	      if (p<0) 
		p += 2*dy;
	      else
		{
		  y1+=inc;
		  p += 2*(dy-dx);
		}
	      mappixel(x1,y1);
	    }
	}    
      else
	{
	  p = 2*dx-dy;
	  if (y1 >= y2)
	    {
	      SWAP(x1, x2, int)
		SWAP(y1, y2, int)	
		}
	  mappixel(x1, y1);
    	
	  if (x2>=x1) inc=1;
	  else inc=-1;
    	
	  while(y1 < y2)
	    {	
	      y1++;   	
	      if (p<0) 
		p += 2*dx;
	      else
		{
		  x1 += inc;
		  p += 2*(dx-dy);
		}
	      mappixel(x1,y1);
	    }
	}
} 


/* simple solid thick line */
void thickline(int x1, int y1, int x2, int y2)
{
  int dx=abs(x1-x2), dy=abs(y1-y2), p;	
  int inc, width = _internal_linestyle.thickness;

  if (!dy)	/* Horizontal line - use mapword */
    {
      if (x1 >= x2)
	SWAP (x1, x2, int);
      for (y1 -= (width/2), y2 += (width/2); y1 <= y2; y1++)
	mapword(x1, y1, dx);
    }
  
  else
    if (!dx)    /*Vertical line - use mapvword  */  
      {
	if (y1 >= y2)
	  SWAP (y1, y2, int);
	for (x1 -= (width/2), x2 += (width/2); x1 <= x2; x1++)
	  mapvword(x1, y1, dy);
      }
    else
      if (dx>=dy)
	{
	  width = lrint (width * ((double)dx) / sqrt (dx*dx + dy*dy));
	  p = 2*dy-dx;
	  if (x1 >= x2)
	    {   
	      SWAP(x1, x2, int);
	      SWAP(y1, y2, int);
	    }
	  y1 -= lrint (width/2);
	  y2 -= lrint (width/2);
	  mapvword (x1, y1, width);
      
	  if (y2>=y1) 
	    inc=1;
	  else 
	    inc=-1;
      
	  while(x1 < x2)
	    {	
	      x1++;   	
	      if (p<0) 
		p += 2*dy;
	      else
		{
		  y1+=inc;
		  p += 2*(dy-dx);
		}
	      mapvword (x1, y1, width);
	    }
	}    
      else
	{
	  width = lrint (width * ((double)dy) / sqrt (dx*dx + dy*dy));
	  p = 2*dx-dy;
	  if (y1 >= y2)
	    {
	      SWAP(x1, x2, int);
	      SWAP(y1, y2, int);	
	    }
	  x1 -= lrint (width/2);
	  x2 -= lrint (width/2);
	  mapword (x1, y1, width);
    	
	  if (x2>=x1) inc=1;
	  else inc=-1;
    	
	  while(y1 < y2)
	    {	
	      y1++;   	
	      if (p<0) 
		p += 2*dx;
	      else
		{
		  x1 += inc;
		  p += 2*(dx-dy);
		}
	      mapword (x1, y1, width);
	    }
	}
} 


/* Single-pixel solid line with linestyle */
void fast_linestyle(int x1, int y1, int x2, int y2)
{
  int dx=abs(x1-x2), dy=abs(y1-y2), p;	
  int inc;
  uint16_t pattern = _internal_linestyle.upattern;

  if (!dy)	/* Horizontal line - use mapword */
    {
      if (x1 >= x2)
	SWAP (x1, x2, int);
      for (; x1 <= x2; x1++, pattern = ROT(pattern))
	if (pattern & 0x1) 
	  mappixel(x1, y1);
    }
  
  else
    if (!dx)    /*Vertical line - use mapvword  */  
      {
	if (y1 >= y2)
	  SWAP (y1, y2, int);
	for (; y1 <= y2; y1++, pattern = ROT(pattern))
	  if (pattern & 0x1)
	    mappixel(x1, y1);
      }
    else
      if (dx>=dy)
	{
	  p = 2*dy-dx;
	  if (x1 >= x2)
	    {   
	      SWAP(x1, x2, int);
	      SWAP(y1, y2, int);
	    }
	  mappixel (x1, y1);
      	  inc = (y2>=y1)? 1 : -1;
      
	  while(x1 < x2)
	    {	
	      x1++;   	
	      pattern = ROT (pattern);
	      if (p<0) 
		p += 2*dy;
	      else
		{
		  y1+=inc;
		  p += 2*(dy-dx);
		}
	      if (pattern & 0x1) 
		mappixel (x1, y1);
	    }
	}    
      else
	{
	  p = 2*dx-dy;
	  if (y1 >= y2)
	    {
	      SWAP(x1, x2, int);
	      SWAP(y1, y2, int);	
	    }
	  mappixel (x1, y1);
    	  inc = (x2>=x1)? 1 : -1;
    	
	  while(y1 < y2)
	    {	
	      y1++;   	
	      pattern = ROT (pattern);
	      if (p<0) 
		p += 2*dx;
	      else
		{
		  x1 += inc;
		  p += 2*(dx-dy);
		}
	      if (pattern & 0x1)
		mappixel (x1, y1);
	    }
	}
} 





/* Thick line with linestyle */
void thick_linestyle(int x1, int y1, int x2, int y2)
{
  int dx=abs(x1-x2), dy=abs(y1-y2), p;	
  int inc, width = _internal_linestyle.thickness;
  uint16_t pattern = _internal_linestyle.upattern;

  if (!dy)	/* Horizontal line - use mapword */
    {
      if (x1 >= x2)
	SWAP (x1, x2, int);
      for (y1 -= (width/2); x1 <= x2; x1++, pattern = ROT (pattern))
	(pattern & 0x1)? mapvword(x1, y1, width) : 0;
    }
  
  else
    if (!dx)    /*Vertical line - use mapvword  */  
      {
	if (y1 >= y2)
	  SWAP (y1, y2, int);
	for (x1 -= (width/2); y1 <= y2; y1++, pattern = ROT (pattern))
	  (pattern & 0x1)? mapword(x1, y1, width) : 0;
      }
    else
      if (dx>=dy)
	{
	  width = lrint (width * ((double)dx) / sqrt (dx*dx + dy*dy));
	  p = 2*dy-dx;
	  if (x1 >= x2)
	    {   
	      SWAP(x1, x2, int);
	      SWAP(y1, y2, int);
	    }
	  y1 -= lrint (width/2);
	  y2 -= lrint (width/2);
	  mapvword (x1, y1, width);
      	  inc = (y2>=y1)? 1 : -1;
      
	  while(x1 < x2)
	    {	
	      x1++;   	
	      pattern = ROT (pattern);
	      if (p<0) 
		p += 2*dy;
	      else
		{
		  y1+=inc;
		  p += 2*(dy-dx);
		}
	      (pattern & 0x1)? mapvword (x1, y1, width) : 0;
	    }
	}    
      else
	{
	  width = lrint (width * ((double)dy) / sqrt (dx*dx + dy*dy));
	  p = 2*dx-dy;
	  if (y1 >= y2)
	    {
	      SWAP(x1, x2, int);
	      SWAP(y1, y2, int);	
	    }
	  x1 -= lrint (width/2);
	  x2 -= lrint (width/2);
	  mapword (x1, y1, width);
    	  inc = (x2>=x1)? 1 : -1;
    	
	  while(y1 < y2)
	    {	
	      y1++;   	
	      pattern = ROT (pattern);
	      if (p<0) 
		p += 2*dx;
	      else
		{
		  x1 += inc;
		  p += 2*(dx-dy);
		}
	      (pattern & 0x1)? mapword (x1, y1, width) : 0;
	    }
	}
} 







void line(int x1, int y1, int x2, int y2)
{
  CHECK_INITIALIZATION;	// Check whether libgraph is active
  if (_internal_linestyle.linestyle == SOLID_LINE)
    {
      if (_internal_linestyle.thickness == NORM_WIDTH)
	fastline(x1, y1, x2, y2);
      else 
	thickline (x1, y1, x2, y2);
    }
  else
    {
      if (_internal_linestyle.thickness == NORM_WIDTH)
	fast_linestyle (x1, y1, x2, y2);
      else
	thick_linestyle (x1, y1, x2, y2);
    }
      
  if (x1 > x2) 
    SWAP(x1, x2, int);
  if (y1 > y2) 
    SWAP(y1, y2, int);
  
  safe_update(x1-_internal_linestyle.thickness, y1-_internal_linestyle.thickness, 
	      x2+_internal_linestyle.thickness, y2+_internal_linestyle.thickness);
}


void linerel(int dx, int dy)
{
    
  line(CP.x, CP.y, CP.x+dx, CP.y+dy);
  CP.x += dx;
  CP.y += dy;
}

void lineto(int x, int y)
{
  line(CP.x, CP.y, x, y);
  CP.x = x; 
  CP.y = y;
}


void mapsympixel(int x, int y, int xc, int yc, int symnum)
{
  switch(symnum){
  case 8:		// symmetric in all octents
    mappixel(y+xc, x+yc);
    mappixel(y+xc, -x+yc);
    mappixel(-y+xc, x+yc);
    mappixel(-y+xc, -x+yc);	   
  case 4 :	// symmetric in all quadrants
    mappixel(-x+xc, -y+yc);
    mappixel(-x+xc, y+yc);
  case 2 :	// symmetric about only X-axis
    mappixel(x+xc, -y+yc);
    mappixel(x+xc, y+yc);
    break;
  case 1 :	// symmetric about only Y-axis
    mappixel(-x+xc, y+yc);
    mappixel(x+xc, y+yc);        	   
  }
}   



void circle(int xc, int yc, int radius)
{
  int x, y, p=1-radius;

  CHECK_INITIALIZATION			// Check whether libgraph is active
   
    for(x=0, y=radius, p=1-radius; x<=y; x++)
      {
        mapsympixel(x, y, xc, yc, 8);
        if (p>=0)
	  {
            p += (2*x - 2*y + 1);
            y--;
	  }
        else
	  p += (2*x + 3);
      }
  safe_update(xc-radius, yc-radius, xc+radius+1, yc+radius+1);
}


void arc(int xc, int yc, int stangle, int endangle, int radius)
{
  float xold, yold, xnew, ynew;
  float sintheta, costheta, theta;
  int num;
	 
  CHECK_INITIALIZATION			// Check whether libgraph is active
	
    _last_arc.x = xc;	/* Store values of current*/
  _last_arc.y = yc;	/*  call for getarccoords()*/
	
  theta = MAX((1.0/radius), 0.001) ;
  num = (int)rint(M_PI * abs (endangle-stangle) / 180.0 / theta);
	
  sintheta = sin(theta);
  costheta = cos(theta);
	
  xold = radius * cos(M_PI * stangle / 180.0);
  yold = radius * sin(M_PI * stangle / 180.0);
	
  _last_arc.xstart = xold;	/* Store values of current*/
  _last_arc.ystart = yold;	/*  call for getarccoords()*/

  for(; num; num--)
    {
      xnew = xold * costheta - yold * sintheta;
      ynew = xold * sintheta + yold * costheta;
      mappixel((int)rint(xnew+xc), (int)rint(ynew+yc));
      xold = xnew, yold = ynew;
    }
	
  _last_arc.xstart = xold;	/* Store values of current*/
  _last_arc.ystart = yold;	/*  call for getarccoords()*/
	
  safe_update(xc-radius, yc-radius, xc+radius+1, yc+radius+1);
}


void getarccoords(struct arccoordstype *given_struct)
{
  *given_struct = _last_arc;
}


void pieslice(int xc, int yc, int stangle, int endangle, int radius)
{
  int angle;
  float x, y;
    
  arc(xc, yc, stangle, endangle, radius);
    
  x  = rint(xc + radius * cos((float)stangle*M_PI/180));
  y  = rint(yc + radius * sin((float)stangle*M_PI/180));
  fastline(xc, yc, (int)x, (int)y);
    
  x = rint(xc + radius * cos((float)endangle*M_PI/180));
  y = rint(yc + radius * sin((float)endangle*M_PI/180));
  fastline(xc, yc, (int)x, (int)y);
    
  angle = (stangle + endangle)/2;
  x = rint(xc + radius/2.0 * cos((float)angle*M_PI/180));
  y = rint(yc + radius/2.0 * sin((float)angle*M_PI/180));
    
  _boundaryfill((int)x, (int)y, getcolor()); 
	
  safe_update(xc-radius, yc-radius, xc+radius+1, yc+radius+1);
}



void rectangle(int left, int top, int right, int bottom)
{	
  CHECK_INITIALIZATION;	// Check whether libgraph is active
  
  line(left,top,right,top);
  line(right,top,right,bottom);  
  line(right,bottom,left,bottom);
  line(left,bottom,left,top);
}



void ellipse(int xc, int yc, int stangle, int endangle, int rx, int ry)
{
  float xold, yold, xnew, ynew;
  float sin_rxbyry, sin_rybyrx, costheta, theta;
  int num;
	
  CHECK_INITIALIZATION			// Check whether libgraph is active
	
    theta = MAX(1.00 / (MAX(rx, ry)), 0.001);
  num = (int)rint(M_PI * abs (endangle-stangle) / 180.0 / theta);
	
  sin_rxbyry = (float)rx/ry * sin(theta);
  sin_rybyrx = (float)ry/rx * sin(theta);	
  costheta = cos(theta);
	
  xold = rx * cos(M_PI * stangle / 180.0);
  yold = ry * sin(M_PI * stangle / 180.0);

  for(; num; num--)
    {
      xnew = xold * costheta - yold * sin_rxbyry;
      ynew = xold * sin_rybyrx + yold * costheta;
      mappixel((int)rint(xnew+xc), (int)rint(ynew+yc));
      xold = xnew, yold = ynew;
    }

  safe_update(xc-rx, yc-ry, xc+rx+1, yc+ry+1); 
}


void sector(int xc, int yc, int stangle, int endangle, int rx, int ry)
{
  float xold, yold, xnew, ynew;
  float sin_rxbyry, sin_rybyrx, costheta, theta;
  int num;
		
  CHECK_INITIALIZATION			// Check whether libgraph is active
	
    theta = MAX(1.00 / (MAX(rx, ry)), 0.001);
  num = (int)rint(M_PI * (endangle-stangle) / 180.0 / theta);
	
  sin_rxbyry = (float)rx/ry * sin(theta);
  sin_rybyrx = (float)ry/rx * sin(theta);	
  costheta = cos(theta);
	
  xold = rx * cos(M_PI * stangle / 180.0);
  yold = ry * sin(M_PI * stangle / 180.0);
  line(xc, yc, xold+xc, yold+yc);
  for(; num; num--)
    {
      xnew = xold * costheta - yold * sin_rxbyry;
      ynew = xold * sin_rybyrx + yold * costheta;
      mappixel((int)rint(xnew+xc), (int)rint(ynew+yc));
      xold = xnew, yold = ynew;
    }
  line(xc, yc, xnew+xc, ynew+yc);
  theta = (stangle+endangle)/2.0;
		
  xnew = rint(xc + rx/2.0 * cos(theta*M_PI/180));
  ynew = rint(yc + rx/2.0 * sin(theta*M_PI/180));
    
  _boundaryfill((int)xnew, (int)ynew, getcolor()); 
  safe_update(xc-rx, yc-ry, xc+rx+1, yc+ry+1); 
}



void _boundaryfill(int x, int y, int color)
{
  int curr;
  if (x>screen->w || x<0 || y>screen->h || y<0) 
    return;
  curr = getpixel(x, y);
  if ((curr != getcolor()) && (curr!= color))
    {
      mappixel(x, y);
      _boundaryfill(x+1, y, color);
      _boundaryfill(x-1, y, color);
      _boundaryfill(x, y+1, color);
      _boundaryfill(x, y-1, color);
    }
}


void floodfill(int x, int y, int color)
{
  CHECK_INITIALIZATION			// Check whether libgraph is active
    _boundaryfill(x, y, color);
  SDL_UpdateRect(screen, 0,0,0,0);
}    


void fillellipse(int xc, int yc, int rx, int ry)
{
  int x, y;
  int p1, p2, rx2, ry2;

  CHECK_INITIALIZATION			// Check whether libgraph is active
   
    rx2 = rx*rx;
  ry2 = ry*ry;
  x=0;
  y=ry;
  mapsympixel(x, y, xc, yc, 2); //only topmost and bottom-most points
  p1= ry2-rx2*ry+rx2/4;

  do   
    {
      x++;
      if(p1<0)
	p1+= 2*ry2*x+ry2;
      else  {
	y--;
	p1+= 2*ry2*x-2*rx2*y+1+ry2;
      }
      mapword(-x+xc, y+yc, 2*x);
      mapword(-x+xc, -y+yc, 2*x);
    } while(ry2*x<rx2*y);

  p2 = (ry2*(x+1/2)*(x+1/2) + rx2*(y-1)*(y-1) -rx2*ry2);
  do   
    {
      y--;
      if (p2>0)
	p2+= -2*rx2*y + rx2;
      else	  {
	x++;
	p2+= 2*ry2*x - 2*rx2*y + rx2;
      }
      mapword(-x+xc, y+yc, 2*x);
      mapword(-x+xc, -y+yc, 2*x);
    } while(y>=0);
  safe_update(xc-rx, yc-ry, xc+rx+1, yc+ry+1);
}



void genellipse(int xc, int yc, int rx, int ry, int angle)
{
  int x, y;
  int p1, p2, rx2, ry2;
  double cost, sint;
  double theta = angle * M_PI / 180;
  cost = cos (theta), sint = sin (theta);

  CHECK_INITIALIZATION			// Check whether libgraph is active
  
    if (ry <= 0) ry = 1;
  if (rx <= 0) rx = 1;
  rx2 = rx*rx;
  ry2 = ry*ry;
  x=0;
  y=ry;

  mappixel((int)rint(x*cost - y*sint + xc), 
	   (int)rint(x*sint + y*cost + yc));
  mappixel((int)rint(-x*cost + y*sint + xc), 
	   (int)rint(-x*sint - y*cost + yc));
      
  p1= ry2-rx2*ry+rx2/4;

  do   
    {
      x++;
      if(p1<0)
	p1+= 2*ry2*x+ry2;
      else  {
	y--;
	p1+= 2*ry2*x-2*rx2*y+1+ry2;
      }
      /*only topmost and bottom-most points rotate +ve */
      mappixel((int)rint(x*cost - y*sint + xc), 
	       (int)rint(x*sint + y*cost + yc));
      mappixel((int)rint(-x*cost + y*sint + xc), 
	       (int)rint(-x*sint - y*cost + yc));
      /*diagonally opposite points rotate -ve */
      mappixel((int)rint(x*cost + y*sint + xc), 
	       (int)rint(x*sint - y*cost + yc));
      mappixel((int)rint(-x*cost - y*sint + xc), 
	       (int)rint(-x*sint + y*cost + yc)); 
   
    } while(ry2*x<rx2*y);


  p2 = (ry2*(x+1/2)*(x+1/2) + rx2*(y-1)*(y-1) -rx2*ry2);

  do   
    {
      y--;
      if (p2>0)
	p2+= -2*rx2*y + rx2;
      else	  
	{
	  x++;
	  p2+= 2*ry2*x - 2*rx2*y + rx2;
	}
      /*only topmost and bottom-most points rotate +ve */
      mappixel((int)rint(x*cost - y*sint + xc), 
	       (int)rint(x*sint + y*cost + yc));
      mappixel((int)rint(-x*cost + y*sint + xc), 
	       (int)rint(-x*sint - y*cost + yc));
      /*diagonally opposite points rotate -ve */
      mappixel((int)rint(x*cost + y*sint + xc), 
	       (int)rint(x*sint - y*cost + yc));
      mappixel((int)rint(-x*cost - y*sint + xc), 
	       (int)rint(-x*sint + y*cost + yc)); 

    } while(y>=0);
  rx = MAX (rx, ry);
  safe_update(xc - rx, yc - rx, xc + rx, yc + rx);
}




void bar(int left, int top, int right, int bottom)
{
  int y=top, dx = right-left;
   
  CHECK_INITIALIZATION			// Check whether libgraph is active
	
    while(y <= bottom)
      {
    	mapword(left , y, dx);
	y++;
      }
  safe_update(left, top, right+1, bottom+1);
}


void bar3d(int left, int top, int right, int bottom,
	   int depth, int topflag)
{
  int x, y;
  bar(left, top, right, bottom);
  moveto(right, bottom);
  linerel(depth*cos(M_PI/6), -depth*sin(M_PI/6));
  linerel(0, top-bottom);
  if (topflag)
    {
      linerel(left-right, 0);
      lineto(left, top);
      moveto(right, top);
      linerel(depth*cos(M_PI/6), -depth*sin(M_PI/6));
    }	
}
	

void getlinesettings (struct linesettingstype *dest)
{
  *dest = _internal_linestyle;
}


void setlinestyle (int linestyle, int upattern, int thickness)
{
  _internal_linestyle.linestyle = linestyle;
  
  switch (linestyle) {
  case SOLID_LINE : 
    _internal_linestyle.upattern = 0xffff; break;
  case DOTTED_LINE : 
    _internal_linestyle.upattern = 0x3333; break;
  case CENTER_LINE : 
    _internal_linestyle.upattern = 0x0c3f; break;
  case DASHED_LINE : 
    _internal_linestyle.upattern = 0x1f1f; break;
  case USERBIT_LINE : 
    _internal_linestyle.upattern = (uint16_t)upattern; break;
  default : 
    _internal_linestyle.upattern = 0xffff; break;
  }
  
  _internal_linestyle.thickness =  (thickness <= 0)? 1:thickness;
}
