#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

#define PI 3.14159265
double tx = -80;
bool flag = false; // right to left => false ; left to right => true
double radius = 15;

void put_pixel(double x, double y) { glVertex2d(x, y); }

void drawCircle(double xMiddle) {
  double yMiddle = 0;
  float pi = PI;
  glPointSize(1.0);
  glBegin(GL_POINTS);

  for (float i = 0.0; i <= 2 * pi; i += 0.05)
    put_pixel(xMiddle + (sin(i) * radius), yMiddle + (cos(i) * radius));

  glEnd();
}

void timer(int id) {
  if (tx >= 80)
    flag = true;
  if (tx <= -80)
    flag = false;

  if (!flag) {
    tx += 32;
    flag = false;

  } else {
    tx -= 32;
    flag = true;
  }
  glutPostRedisplay();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  drawCircle(tx + 15);

  glutTimerFunc(1000, timer, 1);

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

void init(void) { glClearColor(0, 0, 0, 0); }

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_RGB);

  glutCreateWindow("Animated movement Circle");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
