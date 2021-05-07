#!
/* libgraph - TurboC graphics API on GNU/Linux
* libgraph.scm: Creates the Guile loadable module.
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
!#

;; Loadable module for libgraph functions


(define-module (libgraph libgraph))


(defmacro with-color (color expr)
  `(let ((old (getcolor)))
     (setcolor ,color)
     ,expr
     (setcolor old)))


(defmacro with-linewidth (width expr)
  `(let ((settings (getlinesettings)))
     (setlinestyle (car settings) (cadr settings) ,width)
     ,expr
     (apply setlinestyle settings)))


(defmacro with-fontcolor (color expr)
  `(let ((old (getfontcolor)))
     (setfontcolor ,color)
     ,expr
     (setfontcolor old)))



(defmacro with-screen (screen expr)
  `(let ((old (bg-switch-screen ,screen)))
     ,expr
     (bg-switch-screen old)))




(export DETECT USER VGA)
(export VGALO VGAMED VGAHI VGAMAX VGA640 VGA800 VGA1024 USERMODE)
(export BLACK BLUE GREEN CYAN RED MAGENTA BROWN LIGHTGRAY DARKGRAY LIGHTBLUE LIGHTGREEN LIGHTCYAN LIGHTRED LIGHTMAGENTA YELLOW WHITE)
(export SOLID_LINE DOTTED_LINE CENTER_LINE DASHED_LINE USERBIT_LINE NORM_WIDTH THICK_WIDTH)

(export initgraph closegraph detectgraph setgraphmode getgraphmode restorecrtmode getmaxx getmaxy cleardevice putpixel getpixel setcolor getcolor setbkcolor getbkcolor getx gety moveto moverel setfontcolor getfontcolor line lineto linerel circle arc pieslice rectangle drawpoly fillpoly ellipse fillellipse genellipse sector floodfill bar bar3d  getmaxcolor outtext outtextxy textheight textwidth getmaxmode  getmoderange getdrivername getmodename getarccoords kbhit getch  getche gr-delay getchar putchar getlinesettings setlinestyle with-color with-linewidth with-fontcolor get-screen set-screen switch-screen with-screen bg-switch-screen)

(dynamic-call "scm_init_libgraph" (dynamic-link "libguile-libgraph"))

