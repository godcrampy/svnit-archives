#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

void init(void) { glClearColor(0, 0, 0, 0); }

void put_pixel(int x, int y) { glVertex2d(x, y); }

void DDA(int x0, int y0, int x1, int y1) {
  float dx, dy, steps, x, y;
  dx = (float)(x1 - x0);
  dy = (float)(y1 - y0);
  if (abs(dx) >= abs(dy)) {
    steps = abs(dx);
  } else {
    steps = abs(dy);
  }
  dx = dx / steps;
  dy = dy / steps;
  x = (int)x0;
  y = (int)y0;
  int i = 1;
  while (i <= steps) {
    put_pixel(x, y);
    x += dx;
    y += dy;
    i = i + 1;
  }
}

void midpoint1(int xc, int yc, int r) {
  int p, x, y;
  p = 1 - r;
  x = 0;
  y = r;
  while (x <= y) {
    put_pixel(-x + xc, -y + yc);
    put_pixel(-y + xc, -x + yc);
    put_pixel(y + xc, -x + yc);
    put_pixel(x + xc, -y + yc);
    if (p < 0) {
      x++;
      p = p + 2 * x + 3;
    } else {
      y--;
      x++;
      p = p + 2 * x - 2 * y + 5;
    }
  }
}

void midpoint2(int xc, int yc, int r) {
  int p, x, y;
  p = 1 - r;
  x = 0;
  y = r;
  while (x <= y) {
    put_pixel(x + xc, y + yc);
    put_pixel(y + xc, x + yc);
    put_pixel(-x + xc, y + yc);
    put_pixel(-y + xc, x + yc);
    if (p < 0) {
      x++;
      p = p + 2 * x + 3;
    } else {
      y--;
      x++;
      p = p + 2 * x - 2 * y + 5;
    }
  }
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  glBegin(GL_POINTS);

  int x0 = 0;
  int x1 = 0;
  int y0 = 0;
  int y1 = 0;

  cout << "Enter the coordinates point A: ";
  cin >> x0 >> y0;
  cout << "Enter the coordinates point B: ";
  cin >> x1 >> y1;

  DDA(x0, y0, x1, y1);
  int mx = (x0 + x1) / 2;
  int my = (y0 + y1) / 2;
  int c1x = (x0 + mx) / 2;
  int c1y = (y0 + my) / 2;
  int c2x = (x1 + mx) / 2;
  int c2y = (y1 + my) / 2;
  int r1 = sqrt(((mx - c1x) * (mx - c1x)) + ((my - c1y) * (my - c1y)));
  int r2 = sqrt(((mx - c2x) * (mx - c2x)) + ((my - c2y) * (my - c2y)));
  midpoint2(c1x, c1y, r1);
  midpoint1(c2x, c2y, r2);

  glEnd();

  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(-100, 100, -100, 100);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_RGB);

  glutCreateWindow("Example");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
