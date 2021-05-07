/* libgraph - TurboC graphics API on GNU/Linux
 * polygon.c: Code for drawing and filling polygons.
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

#include "graphics.h"
#include "polygon.h"


void drawpoly(int numpoints, int *polypoints)
{
  int i, x1, y1, x2, y2;
	
  CHECK_INITIALIZATION			// Check whether libgraph is active
    
    for(i=0; i<numpoints-1; i++)
      {
        x1 = polypoints[2*i];
        y1 = polypoints[2*i+1];
        x2 = polypoints[2*i+2];
        y2 = polypoints[2*i+3];
        line(x1, y1, x2, y2);
      }

}


void fillpoly(int numpoints, int* polypoints)
{
  int i;
	
  CHECK_INITIALIZATION			// Check whether libgraph is active
	
    _scanlist = calloc(screen->h, sizeof(scanpt));
  _freelist();
  for(i=0; i<screen->h; i++)
    _scanlist[i]=0;
  _makelist(numpoints, polypoints);
  _fillpoly();
  SDL_UpdateRect(screen, 0,0,0,0);
  _freelist();
  free(_scanlist);
}	


void _freelist(void)
{
  int i;
  scanpt* curr,*prev;
  for(i=0; i<screen->h; i++)
    if (_scanlist[i])
      {
	curr=_scanlist[i];
	while(curr->next)
	  {
	    prev=curr;
	    curr = curr->next;
	    free(prev);
	  }
	free(curr);
      }
}	


void _fillpoly(void)
{
  int i;
  for(i=0; i<screen->h; i++)
    if (_scanlist[i])
      {
	scanpt* curr=_scanlist[i];
	while(curr!=0)
	  {
	    if (curr->next==0)
	      {
		mappixel(curr->x,i);
		curr = curr->next;
	      }
	    else
	      {
		scanpt* p2;
		p2=curr->next;
		mapword(curr->x,i,p2->x-curr->x);
		curr = p2->next;
	      }
	  }
      }
}	



int* getpoly(int* num)
{
  int i;
  int* list;
  printf("Enter the number of vertices : ");
  scanf("%d",num);
  list=(int *)calloc(2*(*num+1), sizeof(int));
  for(i=0; i<*num; i++)
    {
      printf("Vertex %d => ",i);
      scanf("%d %d",&list[2*i],&list[2*i+1]);
    }
  list[2*(*num)] = list[0];
  list[2*(*num)+1] = list[1];
  (*num)++;
  return list;
}

	
void _makelist(int numpoints, int *polypoints)
{
  int i, x1, y1, x2, y2;
  for(i=0; i<numpoints-1; i++)
    {
      x1 = polypoints[2*i];
      y1 = polypoints[2*i+1];
      x2 = polypoints[2*i+2];
      y2 = polypoints[2*i+3];
      if (y1 != y2) 
	_dda(x1, y1, x2, y2);
      if (i<numpoints-2)
	if((y2>y1 && y2<polypoints[2*i+5])\
	   || (y2<y1 && y2>polypoints[2*i+5]))
	  {
	    scanpt* extra = (scanpt*)malloc(sizeof(scanpt));
	    extra->x = x2;
	    _insertpt(extra, y2);
	  }
    }
}

		
void _dda(int x1, int y1, int x2, int y2)
{
  int dx=x2-x1, dy=y2-y1, steps, yold;
  float xinc, yinc, x, y;
  scanpt* new;
  steps = abs(dx)>=abs(dy)? abs(dx):abs(dy);
  xinc = (float)dx/steps;
  yinc = (float)dy/steps;
  yold = (y1<y2)? (int)rint(y1-1):(int)rint(y1+1);
  for(x=x1, y=y1; steps ;x+=xinc, y+=yinc, steps--)
    {
      if ((int)rint(y)!= yold)
	{
	  new=(scanpt*)malloc(sizeof(scanpt));
	  new->x=(int)rint(x);
	  _insertpt(new,(int)rint(y));
	  yold=(int)rint(y);
	}
    }
  if (y2!=yold)
    {
      new = (scanpt*)malloc(sizeof(scanpt));
      new->x = x2;
      _insertpt(new, y2);
    }
}   



void _insertpt(scanpt* new, int row)
{
  scanpt *curr,*prev;
  if (_scanlist[row]==0)
    {
      _scanlist[row] = new;
      _scanlist[row]->next = 0;
      return;
    }
  prev = _scanlist[row];
  if (prev->x > new->x)
    {
      new->next=prev;
      _scanlist[row]=new;
      return;
    }
  curr = prev->next;
  if (!curr)
    {
      prev->next=new;
      prev->next->next=0;
      return;
    }	
  while(1)
    {
      if(curr->x >= new->x)
	{
	  new->next = curr;
	  prev->next=new;
	  return;
	}
      if (!curr->next)
	{
	  curr->next=new;
	  curr->next->next=0;
	  return;
	}	
      prev = curr;
      curr = curr->next;	
    }
}



void getpolysize(int num, int* list,int* xmin, int* ymin, int* xmax, int* ymax)
{
  int i, x1, y1, x2, y2;
  *xmax = list[0];
  *ymax = list[1];
  *xmin = list[0];
  *ymin = list[1];
  for(i=0; i<num; i++)
    {
      if (list[2*i]>*xmax) *xmax=list[2*i];
      else   
	if (list[2*i]<*xmin) *xmin=list[2*i];
      if (list[2*i+1]>*ymax) *ymax=list[2*i+1];
      else
	if (list[2*i+1]<*ymin) *ymin=list[2*i+1];	
    }
}
