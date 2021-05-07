/* libgraph - TurboC graphics API on GNU/Linux
 * guile-libgraph.c: Function interfaces for the Guile API.
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

#include <graphics.h>
#include <libguile.h>

#define SCM_INUMR(X) SCM_INUM (scm_inexact_to_exact (X))


scm_t_bits screen_tag;




#define FUNC_NAME "initgraph"
static SCM scm_initgraph(SCM driver, SCM mode, SCM path_to_driver)
{
  int gd, gm;
  SCM_VALIDATE_INUM (1, driver);
  SCM_VALIDATE_INUM (2, mode);

  gd = SCM_INUM (driver);
  gm = SCM_INUM (mode);
  initgraph(&gd, &gm, 0);

  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "closegraph"
static SCM scm_closegraph (void)
{
  closegraph ();
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "detectgraph"
static SCM scm_detectgraph (SCM driver, SCM mode)
{
  int gd, gm;
  SCM_VALIDATE_INUM (1, driver);
  SCM_VALIDATE_SYMBOL (2, mode);

  gd = SCM_INUM (driver);
  detectgraph (&gd, &gm);
  scm_c_define (SCM_SYMBOL_CHARS (mode), SCM_MAKINUM (gm));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "setgraphmode"
static SCM scm_setgraphmode (SCM mode)
{
  SCM_VALIDATE_INUM (1, mode);
  setgraphmode (SCM_INUM (mode));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "getgraphmode"
static SCM scm_getgraphmode (void)
{
  return SCM_MAKINUM (getgraphmode ());
}
#undef FUNC_NAME

#define FUNC_NAME "restorecrtmode"
static SCM scm_restorecrtmode (void)
{
  restorecrtmode ();
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "getmaxx"
static SCM scm_getmaxx (void)
{
  return SCM_MAKINUM (getmaxx ());
}
#undef FUNC_NAME


#define FUNC_NAME "getmaxy"
static SCM scm_getmaxy (void)
{
  return SCM_MAKINUM (getmaxy ());
}
#undef FUNC_NAME


#define FUNC_NAME "cleardevice"
static SCM scm_cleardevice (void)
{
  cleardevice();
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "putpixel"
static SCM scm_putpixel (SCM x, SCM y, SCM color)
{
  SCM_VALIDATE_NUMBER (1, x);
  SCM_VALIDATE_NUMBER (2, y);
  SCM_VALIDATE_INUM (3, color);

  putpixel (SCM_INUMR (x), SCM_INUMR (y), SCM_INUM (color));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "getpixel"
static SCM scm_getpixel (SCM x, SCM y)
{
  SCM_VALIDATE_NUMBER (1, x);
  SCM_VALIDATE_NUMBER (2, y);

  return SCM_MAKINUM (getpixel (SCM_INUMR (x), SCM_INUMR (y)));
}
#undef FUNC_NAME


#define FUNC_NAME "setcolor"
static SCM scm_setcolor (SCM color)
{
  SCM_VALIDATE_INUM (1, color);
  setcolor (SCM_INUM (color));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "getcolor"
static SCM scm_getcolor (void)
{
  return SCM_MAKINUM (getcolor ());
}
#undef FUNC_NAME


#define FUNC_NAME "setbkcolor"
static SCM scm_setbkcolor (SCM color)
{
  SCM_VALIDATE_INUM (1, color);
  setbkcolor (SCM_INUM (color));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "getbkcolor"
static SCM scm_getbkcolor (void)
{
  return SCM_MAKINUM (getbkcolor ());
}
#undef FUNC_NAME


#define FUNC_NAME "getx"
static SCM scm_getx (void)
{
  return SCM_MAKINUM (getx ());
}
#undef FUNC_NAME


#define FUNC_NAME "gety"
static SCM scm_gety (void)
{
  return SCM_MAKINUM (gety ());
}
#undef FUNC_NAME


#define FUNC_NAME "moveto"
static SCM scm_moveto (SCM x, SCM y)
{
  SCM_VALIDATE_NUMBER (1, x);
  SCM_VALIDATE_NUMBER (2, y);
  moveto (SCM_INUMR (x), SCM_INUMR (y));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

#define FUNC_NAME "moverel"
static SCM scm_moverel (SCM dx, SCM dy)
{
  SCM_VALIDATE_NUMBER (1, dx);
  SCM_VALIDATE_NUMBER (2, dy);
  moverel (SCM_INUMR (dx), SCM_INUMR (dy));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "setfontcolor"
static SCM scm_setfontcolor (SCM color)
{
  SCM_VALIDATE_INUM (1, color);
  setfontcolor (SCM_INUM (color));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME
 

#define FUNC_NAME "getfontcolor"
static SCM scm_getfontcolor (void)
{
  return SCM_MAKINUM (getfontcolor ());
}
#undef FUNC_NAME


#define FUNC_NAME "line"
static SCM scm_line (SCM x1, SCM y1, SCM x2, SCM y2)
{
  SCM_VALIDATE_NUMBER (1, x1);
  SCM_VALIDATE_NUMBER (2, y1);
  SCM_VALIDATE_NUMBER (3, x2);
  SCM_VALIDATE_NUMBER (4, y1);

  line (SCM_INUMR (x1), SCM_INUMR (y1), SCM_INUMR (x2),\
	SCM_INUMR (y2));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME	


#define FUNC_NAME "lineto"
static SCM scm_lineto (SCM x, SCM y)
{
  SCM_VALIDATE_NUMBER (1, x);
  SCM_VALIDATE_NUMBER (2, y);

  lineto (SCM_INUMR (x), SCM_INUMR (y));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME	


#define FUNC_NAME "linerel"
static SCM scm_linerel (SCM dx, SCM dy)
{
  SCM_VALIDATE_NUMBER (1, dx);
  SCM_VALIDATE_NUMBER (2, dy);

  linerel (SCM_INUMR (dx), SCM_INUMR (dy));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME	


#define FUNC_NAME "getlinesettings"
static SCM gr_getlinesettings (void)
{
  struct linesettingstype settings;
  getlinesettings (&settings);
  return scm_list_3 (SCM_MAKINUM (settings.linestyle),
		     SCM_MAKINUM (settings.upattern),
		     SCM_MAKINUM (settings.thickness));
}
#undef FUNC_NAME


#define FUNC_NAME "setlinestyle"
static SCM gr_setlinestyle (SCM linestyle, SCM upattern, SCM thickness)
{
  SCM_VALIDATE_INUM (1, linestyle);
  SCM_VALIDATE_INUM (2, upattern);
  SCM_VALIDATE_INUM (3, thickness);
  setlinestyle (SCM_INUM (linestyle), 
		SCM_INUM (upattern), 
		SCM_INUM (thickness));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "circle"
static SCM scm_circle (SCM xc, SCM yc, SCM radius)
{
  SCM_VALIDATE_NUMBER (1, xc);
  SCM_VALIDATE_NUMBER (2, yc);
  SCM_VALIDATE_INUM (3, radius);

  circle (SCM_INUMR (xc), SCM_INUMR (yc), SCM_INUM (radius));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

#define FUNC_NAME "arc"
static SCM scm_arc (SCM xc, SCM yc, SCM stangle, SCM endangle,\
		    SCM radius)
{
  SCM_VALIDATE_NUMBER (1, xc);
  SCM_VALIDATE_NUMBER (2, yc);
  SCM_VALIDATE_NUMBER (3, stangle);
  SCM_VALIDATE_NUMBER (4, endangle);
  SCM_VALIDATE_NUMBER (5, radius);
	
  arc (SCM_INUMR (xc), SCM_INUMR (yc), SCM_INUMR (stangle),\
       SCM_INUMR (endangle), SCM_INUMR (radius));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "pieslice"
static SCM scm_pieslice (SCM xc, SCM yc, SCM stangle, SCM endangle,\
			 SCM radius)
{
  SCM_VALIDATE_NUMBER (1, xc);
  SCM_VALIDATE_NUMBER (2, yc);
  SCM_VALIDATE_NUMBER (3, stangle);
  SCM_VALIDATE_NUMBER (4, endangle);
  SCM_VALIDATE_NUMBER (5, radius);
	
  pieslice (SCM_INUMR (xc), SCM_INUMR (yc), SCM_INUMR (stangle),\
	    SCM_INUMR (endangle), SCM_INUMR (radius));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "rectangle"
static SCM scm_rectangle (SCM left, SCM top, SCM right, SCM bottom)
{
  SCM_VALIDATE_NUMBER (1, left);
  SCM_VALIDATE_NUMBER (2, top);
  SCM_VALIDATE_NUMBER (3, right);
  SCM_VALIDATE_NUMBER (4, bottom);
  rectangle (SCM_INUMR (left), SCM_INUMR (top), SCM_INUMR (right),\
	     SCM_INUMR (bottom));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "drawpoly"
static SCM scm_drawpoly (SCM polypoints)
{
  int np, *pp, i;
  SCM curr;
  SCM_ASSERT (scm_list_p(polypoints) == SCM_BOOL_T, polypoints,
	      SCM_ARG1, FUNC_NAME);
  np = scm_ilength (polypoints) / 2;
  pp = calloc (np*2, sizeof(int));
  for (i=0; i < np*2; i++)
    {
      curr = SCM_CAR (polypoints);
      SCM_VALIDATE_NUMBER (2, curr);
      pp[i] = SCM_INUMR (curr);
      polypoints = SCM_CDR (polypoints);
    }
  drawpoly (np, pp);
  return SCM_UNSPECIFIED;
} 
#undef FUNC_NAME

#define FUNC_NAME "fillpoly"
static SCM scm_fillpoly (SCM polypoints)
{
  int np, *pp, i;
  SCM curr;
  SCM_ASSERT (scm_list_p(polypoints) == SCM_BOOL_T, polypoints,
	      SCM_ARG1, FUNC_NAME);
  np = scm_ilength (polypoints) / 2;
  pp = calloc (np*2, sizeof(int));
  for (i=0; i < np*2; i++)
    {
      curr = SCM_CAR (polypoints);
      SCM_VALIDATE_NUMBER (2, curr);
      pp[i] = SCM_INUMR (curr);
      polypoints = SCM_CDR (polypoints);
    }
  fillpoly (np, pp);
  return SCM_UNSPECIFIED;
} 
#undef FUNC_NAME


#define FUNC_NAME "ellipse"
static SCM scm_ellipse (SCM xc, SCM yc, SCM stangle,\
			SCM endangle, SCM xradius, SCM yradius)
{
  SCM_VALIDATE_NUMBER (1, xc);
  SCM_VALIDATE_NUMBER (2, yc);
  SCM_VALIDATE_NUMBER (3, stangle);
  SCM_VALIDATE_NUMBER (4, endangle);
  SCM_VALIDATE_NUMBER (5, xradius);
  SCM_VALIDATE_NUMBER (6, yradius);
		
  ellipse (SCM_INUMR (xc), SCM_INUMR (yc), SCM_INUMR (stangle),\
	   SCM_INUMR (endangle), SCM_INUMR (xradius), SCM_INUMR (yradius));
  return SCM_UNSPECIFIED;
} 
#undef FUNC_NAME


#define FUNC_NAME "fillellipse"
static  SCM scm_fillellipse (SCM xc, SCM yc, SCM xradius,\
			     SCM yradius)
{
  SCM_VALIDATE_NUMBER (1, xc);
  SCM_VALIDATE_NUMBER (2, yc);
  SCM_VALIDATE_NUMBER (5, xradius);
  SCM_VALIDATE_NUMBER (6, yradius);
		
  fillellipse (SCM_INUMR (xc), SCM_INUMR (yc), SCM_INUMR (xradius),\
	       SCM_INUMR (yradius));
  return SCM_UNSPECIFIED;
} 
#undef FUNC_NAME


#define FUNC_NAME "genellipse"
static  SCM scm_genellipse (SCM xc, SCM yc, SCM xradius,\
			    SCM yradius, SCM angle)
{
  SCM_VALIDATE_NUMBER (1, xc);
  SCM_VALIDATE_NUMBER (2, yc);
  SCM_VALIDATE_NUMBER (3, xradius);
  SCM_VALIDATE_NUMBER (4, yradius);
  SCM_VALIDATE_NUMBER (5, angle);
    
  genellipse (SCM_INUMR (xc), SCM_INUMR (yc), SCM_INUMR (xradius),\
	      SCM_INUMR (yradius), SCM_INUMR (angle));
  
  return SCM_UNSPECIFIED;
} 
#undef FUNC_NAME



#define FUNC_NAME "sector"
static SCM scm_sector (SCM xc, SCM yc, SCM stangle,\
		       SCM endangle, SCM xradius, SCM yradius)
{
  SCM_VALIDATE_NUMBER (1, xc);
  SCM_VALIDATE_NUMBER (2, yc);
  SCM_VALIDATE_NUMBER (3, stangle);
  SCM_VALIDATE_NUMBER (4, endangle);
  SCM_VALIDATE_NUMBER (5, xradius);
  SCM_VALIDATE_NUMBER (6, yradius);
		
  sector (SCM_INUMR (xc), SCM_INUMR (yc), SCM_INUMR (stangle),\
	  SCM_INUMR (endangle), SCM_INUMR (xradius), SCM_INUMR (yradius));
  return SCM_UNSPECIFIED;
} 
#undef FUNC_NAME


#define FUNC_NAME "floodfill"
static SCM  scm_floodfill (SCM x, SCM y, SCM boundarycolor)
{
  SCM_VALIDATE_NUMBER (1, x);
  SCM_VALIDATE_NUMBER (2, y);
  SCM_VALIDATE_INUM (3, boundarycolor);
  floodfill (SCM_INUMR (x), SCM_INUMR (y), SCM_INUM (boundarycolor));
  return SCM_UNSPECIFIED;
} 
#undef FUNC_NAME


#define FUNC_NAME "bar"
static SCM scm_bar (SCM left, SCM top, SCM right, SCM bottom)
{
  SCM_VALIDATE_NUMBER (1, left);
  SCM_VALIDATE_NUMBER (2, top);
  SCM_VALIDATE_NUMBER (3, right);
  SCM_VALIDATE_NUMBER (4, bottom);
  bar (SCM_INUMR (left), SCM_INUMR (top), SCM_INUMR (right),\
       SCM_INUMR (bottom));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

#define FUNC_NAME "bar3d"
static SCM scm_bar3d (SCM left, SCM top, SCM right, SCM bottom,\
		      SCM depth, SCM topflag)
{
  SCM_VALIDATE_NUMBER (1, left);
  SCM_VALIDATE_NUMBER (2, top);
  SCM_VALIDATE_NUMBER (3, right);
  SCM_VALIDATE_NUMBER (4, bottom);
  SCM_VALIDATE_NUMBER (5, depth);
  SCM_VALIDATE_BOOL (6, topflag);
  bar3d (SCM_INUMR (left), SCM_INUMR (top), SCM_INUMR (right),\
	 SCM_INUMR (bottom), SCM_INUMR (depth), SCM_NFALSEP (topflag));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


#define FUNC_NAME "getmaxcolor"
static SCM scm_getmaxcolor (void)
{
  return SCM_MAKINUM (getmaxcolor ());
}
#undef FUNC_NAME

#define FUNC_NAME "outtext"
static SCM scm_outtext (SCM textstring)
{
  SCM_VALIDATE_STRING (1, textstring);
  outtext (SCM_STRING_CHARS (textstring));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

#define FUNC_NAME "outtextxy"
static SCM scm_outtextxy (SCM x, SCM y, SCM textstring)
{
  SCM_VALIDATE_NUMBER (1, x);
  SCM_VALIDATE_NUMBER (2, y);
  SCM_VALIDATE_STRING (3, textstring);
  outtextxy (SCM_INUMR (x), SCM_INUMR (y),\
	     SCM_STRING_CHARS (textstring));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME



#define FUNC_NAME "textheight"
static SCM scm_textheight (SCM textstring)
{
  SCM_VALIDATE_STRING (1, textstring);
  return SCM_MAKINUM (textheight (SCM_STRING_CHARS (textstring)));
}
#undef FUNC_NAME




#define FUNC_NAME "textwidth"
static SCM scm_textwidth (SCM textstring)
{
  SCM_VALIDATE_STRING (1, textstring);
  return SCM_MAKINUM (textwidth (SCM_STRING_CHARS (textstring)));
}
#undef FUNC_NAME


#define FUNC_NAME "getmaxmode"
static SCM scm_getmaxmode (void)
{
  return SCM_MAKINUM (getmaxmode ());
}
#undef FUNC_NAME


#define FUNC_NAME "getmoderange"
static SCM scm_getmoderange (SCM gd, SCM lomode, SCM himode)
{
  int lo, hi;
  SCM_VALIDATE_INUM (1, gd);
  SCM_VALIDATE_SYMBOL (2, lomode);
  SCM_VALIDATE_SYMBOL (3, himode);
  getmoderange (SCM_INUM (gd), &lo, &hi);
  scm_c_define (SCM_SYMBOL_CHARS (lomode), SCM_MAKINUM (lo));
  scm_c_define (SCM_SYMBOL_CHARS (himode), SCM_MAKINUM (hi));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME



#define FUNC_NAME "getdrivername"
static SCM scm_getdrivername (void)
{
  char *name = getdrivername ();
  SCM scm_str = scm_mem2string (name, strlen (name));
  free (name);
  return scm_str;
}
#undef FUNC_NAME


#define FUNC_NAME "getmodename"
static SCM scm_getmodename (SCM mode_number)
{
  char *name; 
  SCM scm_str;
  SCM_VALIDATE_INUM (1, mode_number);
  name = getmodename (SCM_INUM (mode_number));
  scm_str = scm_mem2string (name, strlen (name));
  free(name);
  return scm_str;
}
#undef FUNC_NAME


#define FUNC_NAME "getarccoords"
static SCM scm_getarccoords (SCM arccoords)
{
  struct arccoordstype arc_c;
  SCM arc_scm;
  SCM_VALIDATE_SYMBOL (1, arccoords);
  getarccoords (&arc_c);
  arc_scm = scm_cons (SCM_MAKINUM (arc_c.x), scm_cons (SCM_MAKINUM (arc_c.y), scm_cons (SCM_MAKINUM (arc_c.xstart), scm_cons (SCM_MAKINUM (arc_c.ystart), scm_cons (SCM_MAKINUM (arc_c.xend), scm_cons (SCM_MAKINUM (arc_c.yend), SCM_EOL))))));
	
  scm_c_define (SCM_SYMBOL_CHARS (arccoords), arc_scm);
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

#define FUNC_NAME "kbhit"
static SCM scm_kbhit (void)
{
  if (kbhit ()) 
    return SCM_BOOL_T;
  else
    return SCM_BOOL_F;
} 
#undef FUNC_NAME


#define FUNC_NAME "getch"
static SCM scm_getch (void)
{
  return SCM_MAKE_CHAR (getch ());
} 
#undef FUNC_NAME

#define FUNC_NAME "getche"
static SCM scm_getche (void)
{
  return SCM_MAKE_CHAR (getche ());
} 
#undef FUNC_NAME

#define FUNC_NAME "gr-delay"
static SCM scm_delay (SCM milisec)
{
  SCM_VALIDATE_NUMBER (1, milisec);
  delay (SCM_INUMR (milisec));
  return milisec;
}
#undef FUNC_NAME


#define FUNC_NAME "getchar"
static SCM scm_getchar (void)
{
  return SCM_MAKE_CHAR ((char)getchar());
}
#undef FUNC_NAME


#define FUNC_NAME "putchar"
static SCM scm_putchar (SCM character)
{
  SCM_VALIDATE_CHAR (1, character);
  return SCM_MAKE_CHAR ((char)putchar (SCM_CHAR (character)));
}
#undef FUNC_NAME



#define FUNC_NAME "get-screen"
static SCM gr_get_screen (void)
{
  SDL_Surface *save;
  save = SDL_ConvertSurface (screen, screen->format, SDL_SWSURFACE);

  SCM_RETURN_NEWSMOB (screen_tag, save);
}
#undef FUNC_NAME



#define FUNC_NAME "set-screen"
static SCM gr_set_screen (SCM newscreen)
{
  SCM_ASSERT (SCM_SMOB_PREDICATE (screen_tag, newscreen), newscreen, 
	      SCM_ARG2, FUNC_NAME);
  SDL_BlitSurface ((SDL_Surface *)SCM_SMOB_DATA (newscreen), 
		   0, screen, 0);

  return (SCM_UNSPECIFIED);
}
#undef FUNC_NAME



#define FUNC_NAME "switch-screen"
static SCM gr_switch_screen (SCM newscreen)
{
  SCM oldscreen;
  SCM_ASSERT (SCM_SMOB_PREDICATE (screen_tag, newscreen), newscreen, 
	      SCM_ARG2, FUNC_NAME);
  oldscreen = gr_get_screen();
  gr_set_screen (newscreen);
  return (oldscreen);
}
#undef FUNC_NAME


#define FUNC_NAME "bg-switch-screen"
static SCM gr_bg_switch_screen (SCM newscreen)
{
  SDL_Surface *backup;
  SCM_ASSERT (SCM_SMOB_PREDICATE (screen_tag, newscreen), newscreen, 
	      SCM_ARG2, FUNC_NAME);
  backup = screen;
  screen = (SDL_Surface *)SCM_SMOB_DATA (newscreen);
  SCM_RETURN_NEWSMOB (screen_tag, backup);  
}
#undef FUNC_NAME


static size_t 
free_screen (SCM screen_smob)
{
  SDL_FreeSurface ((SDL_Surface *)SCM_SMOB_DATA (screen_smob));
  return (0);
}


static int
print_screen (SCM screen_smob, SCM port, scm_print_state *pstate)
{
  char *output;
  asprintf (&output, "#<screen %d>", screen_smob);
  scm_puts (output, port);
  free (output);
  
  return (1);
}


void define_constants (void)
{
  scm_c_define ("DETECT", SCM_MAKINUM (DETECT));
  scm_c_define ("USER", SCM_MAKINUM (USER));
  scm_c_define ("VGA", SCM_MAKINUM (VGA));
  scm_c_define ("VGALO", SCM_MAKINUM (VGALO));
  scm_c_define ("VGAMED", SCM_MAKINUM(VGAMED));
  scm_c_define ("VGAHI", SCM_MAKINUM(VGAHI));
  scm_c_define ("VGAMAX", SCM_MAKINUM(VGAMAX));
  scm_c_define ("VGA640", SCM_MAKINUM(VGA640));
  scm_c_define ("VGA800", SCM_MAKINUM(VGA800));
  scm_c_define ("VGA1024", SCM_MAKINUM(VGA1024));
  scm_c_define ("USERMODE", SCM_MAKINUM(USERMODE));
  scm_c_define ("BLACK", SCM_MAKINUM(BLACK));
  scm_c_define ("BLUE", SCM_MAKINUM(BLUE));
  scm_c_define ("GREEN", SCM_MAKINUM(GREEN));
  scm_c_define ("CYAN", SCM_MAKINUM(CYAN));
  scm_c_define ("RED", SCM_MAKINUM(RED));
  scm_c_define ("MAGENTA", SCM_MAKINUM(MAGENTA));
  scm_c_define ("BROWN", SCM_MAKINUM(BROWN));
  scm_c_define ("LIGHTGRAY", SCM_MAKINUM(LIGHTGRAY));
  scm_c_define ("DARKGRAY", SCM_MAKINUM(DARKGRAY));
  scm_c_define ("LIGHTBLUE", SCM_MAKINUM(LIGHTBLUE));
  scm_c_define ("LIGHTGREEN", SCM_MAKINUM(LIGHTGREEN));
  scm_c_define ("LIGHTCYAN", SCM_MAKINUM(LIGHTCYAN));
  scm_c_define ("LIGHTRED", SCM_MAKINUM(LIGHTRED));
  scm_c_define ("LIGHTMAGENTA", SCM_MAKINUM(LIGHTMAGENTA));
  scm_c_define ("YELLOW", SCM_MAKINUM(YELLOW));
  scm_c_define ("WHITE", SCM_MAKINUM(WHITE));
  scm_c_define ("SOLID_LINE", SCM_MAKINUM (SOLID_LINE));
  scm_c_define ("DOTTED_LINE", SCM_MAKINUM (DOTTED_LINE));
  scm_c_define ("CENTER_LINE", SCM_MAKINUM (CENTER_LINE));
  scm_c_define ("DASHED_LINE", SCM_MAKINUM (DASHED_LINE));
  scm_c_define ("USERBIT_LINE", SCM_MAKINUM (USERBIT_LINE));
  scm_c_define ("NORM_WIDTH", SCM_MAKINUM (NORM_WIDTH));
  scm_c_define ("THICK_WIDTH", SCM_MAKINUM (THICK_WIDTH));
}

void define_procedures (void)
{
  scm_c_define_gsubr ("initgraph", 2, 1, 0, scm_initgraph);
  scm_c_define_gsubr ("closegraph", 0, 0, 0, scm_closegraph);
  scm_c_define_gsubr ("detectgraph", 2, 0, 0, scm_detectgraph);
  scm_c_define_gsubr ("setgraphmode", 1, 0, 0, scm_setgraphmode);
  scm_c_define_gsubr ("getgraphmode", 0, 0, 0, scm_getgraphmode);
  scm_c_define_gsubr ("restorecrtmode", 0, 0, 0, scm_restorecrtmode);
  scm_c_define_gsubr ("getmaxx", 0, 0, 0, scm_getmaxx);
  scm_c_define_gsubr ("getmaxy", 0, 0, 0, scm_getmaxy);
  scm_c_define_gsubr ("cleardevice", 0, 0, 0, scm_cleardevice);
  scm_c_define_gsubr ("putpixel", 3, 0, 0, scm_putpixel);
  scm_c_define_gsubr ("getpixel", 2, 0, 0, scm_getpixel);
  scm_c_define_gsubr ("setcolor", 1, 0, 0, scm_setcolor);
  scm_c_define_gsubr ("getcolor", 0, 0, 0, scm_getcolor);
  scm_c_define_gsubr ("setbkcolor", 1, 0, 0, scm_setbkcolor);
  scm_c_define_gsubr ("getbkcolor", 0, 0, 0, scm_getbkcolor);
  scm_c_define_gsubr ("getx", 0, 0, 0, scm_getx);
  scm_c_define_gsubr ("gety", 0, 0, 0, scm_gety);
  scm_c_define_gsubr ("moveto", 2, 0, 0, scm_moveto);
  scm_c_define_gsubr ("moverel", 2, 0, 0, scm_moverel);
  scm_c_define_gsubr ("setfontcolor", 1, 0, 0, scm_setfontcolor);
  scm_c_define_gsubr ("getfontcolor", 0, 0, 0, scm_getfontcolor);
  scm_c_define_gsubr ("line", 4, 0, 0, scm_line);
  scm_c_define_gsubr ("getlinesettings", 0, 0, 0, gr_getlinesettings);
  scm_c_define_gsubr ("setlinestyle", 3, 0, 0, gr_setlinestyle);
  scm_c_define_gsubr ("lineto", 2, 0, 0, scm_lineto);
  scm_c_define_gsubr ("linerel", 2, 0, 0, scm_linerel);
  scm_c_define_gsubr ("circle", 3, 0, 0, scm_circle);
  scm_c_define_gsubr ("arc", 5, 0, 0, scm_arc);
  scm_c_define_gsubr ("pieslice", 5, 0, 0, scm_pieslice);
  scm_c_define_gsubr ("rectangle", 4, 0, 0, scm_rectangle);
  scm_c_define_gsubr ("drawpoly", 1, 0, 0, scm_drawpoly);
  scm_c_define_gsubr ("fillpoly", 1, 0, 0, scm_fillpoly);
  scm_c_define_gsubr ("ellipse", 6, 0, 0, scm_ellipse);
  scm_c_define_gsubr ("fillellipse", 4, 0, 0, scm_fillellipse);
  scm_c_define_gsubr ("genellipse", 5, 0, 0, scm_genellipse);
  scm_c_define_gsubr ("sector", 6, 0, 0, scm_sector);
  scm_c_define_gsubr ("floodfill", 3, 0, 0, scm_floodfill);
  scm_c_define_gsubr ("bar", 4, 0, 0, scm_bar);
  scm_c_define_gsubr ("bar3d", 6, 0, 0, scm_bar3d);
  scm_c_define_gsubr ("getmaxcolor", 0, 0, 0, scm_getmaxcolor);
  scm_c_define_gsubr ("outtext", 1, 0, 0, scm_outtext);
  scm_c_define_gsubr ("outtextxy", 3, 0, 0, scm_outtextxy);
  scm_c_define_gsubr ("textheight", 1, 0, 0, scm_textheight);
  scm_c_define_gsubr ("textwidth", 1, 0, 0, scm_textwidth);
  scm_c_define_gsubr ("getmaxmode", 0, 0, 0, scm_getmaxmode);
  scm_c_define_gsubr ("getmoderange", 3, 0, 0, scm_getmoderange);
  scm_c_define_gsubr ("getdrivername", 0, 0, 0, scm_getdrivername);
  scm_c_define_gsubr ("getmodename", 1, 0, 0, scm_getmodename);
  scm_c_define_gsubr ("getarccoords", 1, 0, 0, scm_getarccoords);
  scm_c_define_gsubr ("kbhit", 0, 0, 0, scm_kbhit);
  scm_c_define_gsubr ("getch", 0, 0, 0, scm_getch);
  scm_c_define_gsubr ("getche", 0, 0, 0, scm_getche);
  scm_c_define_gsubr ("gr-delay", 1, 0, 0, scm_delay);
  scm_c_define_gsubr ("getchar", 0, 0, 0, scm_getchar);
  scm_c_define_gsubr ("putchar", 1, 0, 0, scm_putchar);
  scm_c_define_gsubr ("get-screen", 0, 0, 0, gr_get_screen);
  scm_c_define_gsubr ("set-screen", 1, 0, 0, gr_set_screen);
  scm_c_define_gsubr ("switch-screen", 1, 0, 0, gr_switch_screen);
  scm_c_define_gsubr ("bg-switch-screen", 1, 0, 0, gr_bg_switch_screen);
}	





void scm_init_libgraph (void)
{
  screen_tag = scm_make_smob_type ("screen", sizeof(SDL_Surface *));
  scm_set_smob_free (screen_tag, free_screen);
  scm_set_smob_print (screen_tag, print_screen);
  scm_set_smob_equalp (screen_tag, 0);

  define_constants ();
  define_procedures ();
}

