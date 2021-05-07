#include "graphics.h"
#include <stdio.h>

int main() {
  int gr = DETECT, gm = VGAMAX;
  initgraph(&gr, &gm, "");
  // Printing message for user
  outtextxy(50, 200, "Smiley from graphics.h");
  // for head
  setcolor(YELLOW);
  circle(300, 300, 40);
  // for left eye
  circle(290, 290, 6);
  // for right eye
  circle(310, 290, 6);
  // for smiley lips
  arc(300, 310, 360, 180, 20);
  getch();
  return 0;
}