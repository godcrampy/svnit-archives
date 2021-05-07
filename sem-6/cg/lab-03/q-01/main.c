#include <stdio.h>

#include "graphics.h"

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  setcolor(WHITE);
  rectangle(150, 180, 250, 300);
  rectangle(250, 180, 420, 300);
  rectangle(180, 250, 220, 300);
  line(200, 100, 150, 180);
  line(200, 100, 250, 180);
  line(200, 100, 370, 100);
  line(370, 100, 420, 180);
  setcolor(RED);
  floodfill(152, 182, WHITE);
  floodfill(252, 182, WHITE);
  setcolor(BLUE);
  floodfill(182, 252, WHITE);
  setcolor(YELLOW);
  floodfill(200, 105, WHITE);
  floodfill(210, 105, WHITE);
  getch();
  closegraph();
  return 0;
}
