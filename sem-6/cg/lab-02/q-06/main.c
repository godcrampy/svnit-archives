#include "graphics.h"
#include <stdio.h>

int main() {
  int graphicdriver = DETECT, graphicmode = VGAMAX;
  initgraph(&graphicdriver, &graphicmode, "");
  outtextxy(50, 50 + 50, "Traffic signal in graphics.h");
  // initilizing variables
  int middlex, middley;
  // getting middle x and y
  middlex = getmaxx() / 2;
  middley = getmaxy() / 2;
  // setting color as white for the outline
  setcolor(WHITE);
  rectangle(middlex - 30, middley - 80, middlex + 30, middley + 80);
  setcolor(RED);
  fillcircle(middlex, middley - 50, 22);
  // filling red color to signify stop sign
  floodfill(middlex, middley - 50, RED);
  // setting color as white for the outline
  setcolor(YELLOW);
  fillcircle(middlex, middley, 20);
  // filling yellow color to signify ready sign
  floodfill(middlex, middley, YELLOW);
  // setting white color for outline
  setcolor(GREEN);
  fillcircle(middlex, middley + 50, 22);
  // filling green color to signify go sign
  floodfill(middlex, middley + 50, GREEN);
  getch();
  return 0;
}