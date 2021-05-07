#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

#define PI 3.14159265
double degree = 0;

void put_pixel(double x, double y) { glVertex2d(x, y); }

vector<vector<double>> multiplyMatrix(vector<vector<double>> a,
                                      vector<vector<double>> b) {
  vector<vector<double>> resMatrix(3, vector<double>(3, 0));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        resMatrix[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return resMatrix;
}

vector<vector<double>> set_rotate_matrix(double degree) {
  vector<vector<double>> rMatrix{
      {cos(degree * PI / 180), sin(degree * PI / 180), 0},
      {sin(-1 * degree * PI / 180), cos(degree * PI / 180), 0},
      {0, 0, 1}};
  return rMatrix;
}

void drawBladeOne() {
  vector<vector<double>> points = {{-40, -30, 1}, {0, 0, 1}, {-38, -40, 1}};
  vector<vector<double>> outputMatrix = set_rotate_matrix(degree);
  points = multiplyMatrix(points, outputMatrix);

  glBegin(GL_TRIANGLES);

  for (vector<double> point : points)
    put_pixel(point[0], point[1]);
  glEnd();
}

void drawBladeTwo() {
  vector<vector<double>> points = {
      {40, -30, 1},
      {0, 0, 1},
      {38, -40, 1},
  };

  vector<vector<double>> outputMatrix = set_rotate_matrix(degree);
  points = multiplyMatrix(points, outputMatrix);

  glBegin(GL_TRIANGLES);
  for (vector<double> point : points)
    put_pixel(point[0], point[1]);
  glEnd();
}

void drawBladeThree() {
  vector<vector<double>> points = {{-5, 50, 1}, {0, 0, 1}, {5, 45, 1}};

  vector<vector<double>> outputMatrix = set_rotate_matrix(degree);
  points = multiplyMatrix(points, outputMatrix);

  glBegin(GL_TRIANGLES);
  for (vector<double> point : points)
    put_pixel(point[0], point[1]);
  glEnd();
}

void timer(int id) {
  degree += 30;
  if (degree == 360)
    degree = 0;
  glutPostRedisplay();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  drawBladeOne();
  drawBladeTwo();
  drawBladeThree();

  glBegin(GL_POLYGON);
  put_pixel(-1, 0);
  put_pixel(1, 0);
  put_pixel(1, -70);
  put_pixel(-1, -70);
  glEnd();

  glutTimerFunc(200, timer, 1);

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

  glutCreateWindow("Animated movement");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
