#include <graphics.h>

int main(int argc, char const *argv[]) {
  int gdriver = VGA;
  int gmode = VGAMAX;
  initgraph(&gdriver, &gmode, "");
  int xmid = getmaxx() / 2;
  int y1 = 100;
  int y2 = 150;
  int y3 = 300;
  int y4 = 350;
  int diff = 50;
  int roof[] = {
      xmid,
      y1,
      xmid + diff,
      y2,
      xmid,
      y3,
      xmid + diff / 2,
      y4,
      xmid - diff / 2,
      y4,
      xmid,
      y3,
      xmid - diff,
      y2,
      xmid,
      y1,
  };
  setcolor(YELLOW);
  fillpoly(8, roof);
  setcolor(RED);
  line(xmid, y2, getmaxx(), getmaxy());
  line(xmid, y3 - 50, getmaxx(), getmaxy());

  getchar();
  closegraph();
  return 0;
}
