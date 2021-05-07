#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

int rx = 0, ry = 0, xpos = 0, ypos = 0;

void init(void) { glClearColor(0, 0, 0, 0); }

void put_pixel(int x, int y) { glVertex2d(x, y); }

void draw_ellipse() {
  vector<pair<int, int>> coords, temp;
  int x = 0, y = ry;
  int p = ry * ry - rx * rx * ry + rx * rx / 4;
  int dx = 2 * ry * ry * x;
  int dy = 2 * rx * rx * y;

  while (dx < dy) {
    coords.push_back({x, y});
    coords.push_back({y, x});
    if (p < 0) {
      ++x;
      dx = 2 * ry * ry * x;
      p += 2 * ry * ry * x + ry * ry;
    } else {
      ++x;
      --y;
      dx = 2 * ry * ry * x;
      dy = 2 * rx * rx * y;
      p += (2 * ry * ry * x) + (ry * ry) - (2 * rx * rx * y);
    }
  }

  p = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) -
      rx * rx * ry * ry;

  while (y > 0) {
    coords.push_back({x, y});
    coords.push_back({y, x});
    if (p > 0) {
      --y;
      dy = 2 * rx * rx * y;
      p += rx * rx - dy;
    } else {
      ++x;
      --y;
      dx = 2 * ry * ry * x;
      dy = 2 * rx * rx * y;
      p += dx - dy + rx * rx;
    }
  }

  for (auto p : coords) {
    int a = p.first, b = p.second;
    put_pixel(a + xpos, b + ypos);
    put_pixel(-a + xpos, b + ypos);
    put_pixel(a + xpos, -b + ypos);
    put_pixel(-a + xpos, -b + ypos);
  }
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  glBegin(GL_POINTS);

  draw_ellipse();

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
  cout << "Enter radii of ellipse: ";
  cin >> rx >> ry;
  cout << "Enter x and y: ";
  cin >> xpos >> ypos;
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
