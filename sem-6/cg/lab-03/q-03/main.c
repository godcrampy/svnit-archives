#include <math.h>
#include <stdio.h>

#include "graphics.h"
int main() {
  int gd = DETECT, gm, a, b, i, r, x, y;
  initgraph(&gd, &gm, "");
  // draw the top rectangle
  setcolor(RED);
  rectangle(110, 40, 220, 58);
  floodfill(111, 43, WHITE);
  setcolor(WHITE);
  rectangle(110, 58, 220, 78);
  floodfill(111, 59, WHITE);
  setcolor(GREEN);
  rectangle(110, 78, 220, 98);
  floodfill(111, 79, WHITE);
  // Ashok chakra
  //
  a = 160;
  b = 68;
  r = 13;
  setcolor(BLUE);
  circle(a, b, r);
  for (i = 0; i <= 360; i = i + 25) {
    x = r * cos(i * 3.14 / 180);
    y = r * sin(i * 3.14 / 180);
    line(a, b, a + x, b - y);
  }
  getch();
  return 0;
}
