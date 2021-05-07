#include "graphics.h"
#include <stdlib.h>

int main() {
  int graphicdriver = DETECT, graphicmode = VGAMAX;
  initgraph(&graphicdriver, &graphicmode, "");
  outtextxy(100, 100 + 100, "Car from graphics.h");

  rectangle(350, 275, 250, 400);
  rectangle(350, 350, 400, 400);
  circle(350, 410, 10);
  circle(275, 410, 10);
  getch();
  return 0;
}