#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

int r = 0;

void init(void) { glClearColor(0, 0, 0, 0); }

void put_pixel(int x, int y) { glVertex2d(x, y); }

void draw_circle() {
  vector<pair<int, int>> coords, temp;
  int x = 0, y = r, p = 5 / 4 - r;

  while (x <= y) {
    coords.push_back({x, y});
    if (p < 0) {
      p += 2 * x + 3;
    } else {
      p += 2 * (x - y) + 5;
      --y;
    }
    ++x;
  }

  // complete octant
  for (auto p : coords) {
    int a = p.first, b = p.second;
    temp.push_back({b, a});
    temp.push_back({-b, a});
    temp.push_back({-b, -a});
    temp.push_back({b, -a});
    temp.push_back({-a, -b});
    temp.push_back({-a, b});
    temp.push_back({a, -b});
  }

  for (auto p : temp) {
    coords.push_back(p);
  }

  for (auto p : temp) {
    coords.push_back(p);
  }

  for (auto p : coords) {
    put_pixel(p.first, p.second);
  }
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  glBegin(GL_POINTS);

  draw_circle();

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
  cout << "Enter radius of circle: ";
  cin >> r;

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
