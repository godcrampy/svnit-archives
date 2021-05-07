#include "graphics.h"
#include <stdio.h>

int main() {
  int graphicdriver = DETECT, graphicmode = VGAMAX;
  initgraph(&graphicdriver, &graphicmode, "");
  outtextxy(10, 10 + 10, "Circle inside Circle");
  // creating circle inside circle
  setcolor(RED);
  circle(200, 200, 100);
  setcolor(BLUE);
  circle(200, 200, 80);
  setcolor(YELLOW);
  circle(200, 200, 60);
  setcolor(BROWN);
  circle(200, 200, 40);
  getch();
  return 0;
}