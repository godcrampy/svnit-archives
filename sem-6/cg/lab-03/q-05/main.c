#include <graphics.h>
#include <stdio.h>

void dda(int x0, int y0, int x1, int y1) {

  double dx = (double)(x1 - x0);
  double dy = (double)(y1 - y0);
  double steps;
  if (abs(dx) >= abs(dy)) {
    steps = abs(dx);
  } else {
    steps = abs(dy);
  }
  double inc_x = dx / steps;
  double inc_y = dy / steps;
  double x = x0;
  double y = y0;
  int i = 1;
  while (i <= steps) {
    putpixel(x, y, YELLOW);
    x += inc_x;
    y += inc_y;
    i = i + 1;
  }
}

int main(int argc, char const *argv[]) {
  int gd = DETECT, gm, i;
  int x0, x1, y0, y1;
  // printf("Enter (x0, y0): ");
  // scanf("%d %d", &x0, &y0);
  // printf("Enter (x1, y1): ");
  // scanf("%d %d", &x1, &y1);

  initgraph(&gd, &gm, "");
  dda(10, 10, 10, 100);
  dda(50, 10, 60, 100);
  dda(90, 10, 180, 100);
  dda(130, 10, 300, 100);
  dda(170, 10, 370, 50);
  dda(240, 10, 350, 10);
  getch();
  closegraph();

  return 0;
}
