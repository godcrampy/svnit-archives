#include "graphics.h"
#include <stdlib.h>

void wait_for_char() {

  // Wait for a key press
  int in = 0;

  while (in == 0) {
    in = getchar();
  }
}

int main(int argc, char *argv[]) {
  int gdriver, gmode;
  int dppoints[14] = {200, 150, 300, 250, 400, 150, 425,
                      350, 300, 275, 150, 350, 200, 150};
  int fppoints[14] = {500, 150, 600, 250, 700, 150, 725,
                      350, 600, 275, 450, 350, 500, 150};
  gdriver = VGA;
  gmode = VGAMAX;
  initgraph(&gdriver, &gmode, "");
  printf("libgraph shapes and colors demo\n");

  setcolor(RED);
  setfontcolor(RED);
  outtextxy(5, 60, "line");
  line(200, 20, 700, 100);
  setcolor(BLUE);
  setfontcolor(BLUE);
  outtextxy(5, 200, "circle arc pieslice");
  circle(300, 200, 50);
  arc(500, 200, 180, 280, 50);
  pieslice(680, 200, 0, 110, 50);
  setcolor(LIGHTGREEN);
  pieslice(680, 200, 111, 210, 50);
  setcolor(LIGHTRED);
  pieslice(680, 200, 210, 360, 50);
  setcolor(YELLOW);
  setfontcolor(YELLOW);
  outtextxy(5, 400, "ellipse fillellipse sector");
  ellipse(300, 400, 0, 360, 100, 50);
  fillellipse(500, 400, 50, 110);
  sector(680, 400, 0, 110, 100, 50);
  setcolor(LIGHTGRAY);
  sector(680, 400, 111, 210, 100, 50);
  setcolor(MAGENTA);
  sector(680, 400, 211, 360, 100, 50);
  getch();
  cleardevice();
  setfontcolor(WHITE);
  printf("libgraph shapes and colors demo\n");
  setcolor(GREEN);
  setfontcolor(GREEN);
  outtextxy(5, 60, "rectangle");
  rectangle(200, 40, 600, 130);
  setcolor(CYAN);
  setfontcolor(CYAN);
  outtextxy(5, 200, "drawpoly fillpoly");
  drawpoly(7, dppoints);
  fillpoly(7, fppoints);
  setcolor(LIGHTBLUE);
  setfontcolor(LIGHTBLUE);
  outtextxy(5, 450, "bar bar3d");
  bar(200, 350, 270, 525);
  bar3d(500, 350, 570, 525, 30, 1);
  getch();

  wait_for_char();

  closegraph();
  return (0);
}
