#include <graphics.h>
#include <stdio.h>

void bresenhams(int x0, int y0, int x1, int y1) {
  int dx, dy, p, x, y;
  dx = x1 - x0;
  dy = y1 - y0;
  x = x0;
  y = y0;
  p = 2 * dy - dx;
  while (x < x1) {
    if (p >= 0) {
      putpixel(x, y, RED);
      y = y + 1;
      p = p + 2 * dy - 2 * dx;
    } else {
      putpixel(x, y, RED);
      p = p + 2 * dy;
    }
    x = x + 1;
  }
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void draw_line_bres(int x1, int y1, int x2, int y2) {
  if (abs(y2 - y1) > abs(x2 - x1)) {
    draw_line_bres(y1, x1, y2, x2);
    return;
  }
  if (x1 > x2) {
    swap(&x1, &x2);
    swap(&y1, &y2);
  }
  int inc = y1 > y2 ? -1 : 1;
  int m_new = 2 * (y2 - y1);
  int slope_error_new = m_new + inc == 1 ? -(x2 - x1) : (x2 - x1);
  for (int x = x1, y = y1; x <= x2; x++) {
    putpixel(y, x, 4);

    slope_error_new += m_new;

    if (inc == 1 && slope_error_new >= 0) {
      y += inc;
      slope_error_new -= 2 * (x2 - x1);
    } else if (inc == -1 && slope_error_new <= 0) {
      y += inc;
      slope_error_new += 2 * (x2 - x1);
    }
  }
}

int main() {
  int gd = DETECT, gm, i;
  int x0, x1, y0, y1;
  printf("Enter (x0, y0): ");
  scanf("%d %d", &x0, &y0);
  printf("Enter (x1, y1): ");
  scanf("%d %d", &x1, &y1);
  initgraph(&gd, &gm, "");
  draw_line_bres(x0, y0, x1, y1);
  getch();
  closegraph();
  return 0;
}
