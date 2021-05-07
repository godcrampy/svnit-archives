#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

#define PI 3.14159265
double degree = 0;

vector<vector<double>> cacheMatrix{{{-20, 30, 1}, {0, 30, 1}, {-10, 40, 1}}};

void put_pixel(float r, float g, float b, double x, double y) {
  glColor3f(r, g, b);
  glVertex2d(x, y);
}

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

vector<vector<double>> set_translation_matrix(int dx, int dy) {
  vector<vector<double>> tMatrix{
      {1, 0, 0}, {0, 1, 0}, {(double)dx, (double)dy, 1}};
  return tMatrix;
}

vector<vector<double>> set_rotate_matrix(double degree) {
  vector<vector<double>> rMatrix{
      {cos(degree * PI / 180), sin(degree * PI / 180), 0},
      {sin(-1 * degree * PI / 180), cos(degree * PI / 180), 0},
      {0, 0, 1}};
  return rMatrix;
}

vector<vector<double>> set_rotate_point_matrix(double degree, int px, int py) {
  // T(-px, -py).R(degree).T(px, py)
  vector<vector<double>> rPointMatrix(3, vector<double>(3, 0));
  rPointMatrix = multiplyMatrix(set_translation_matrix(-1 * px, -1 * py),
                                set_rotate_matrix(degree));
  rPointMatrix = multiplyMatrix(rPointMatrix, set_translation_matrix(px, py));
  return rPointMatrix;
}

void timer(int id) {
  degree += 30;
  if (degree == 360) {
    cacheMatrix = {};
    degree = 0;
  }
  glutPostRedisplay();
}

void placePoints() {
  vector<vector<double>> res = set_rotate_point_matrix(degree, 25, 40);
  vector<vector<double>> temp(3, vector<double>(3, 0));
  vector<vector<double>> points{{{-20, 30, 1}, {0, 30, 1}, {-10, 40, 1}}};
  points = multiplyMatrix(points, res);

  for (int i = 0; i < 3; ++i)
    cacheMatrix.push_back({points[i][0], points[i][1]});
  temp = points;
  for (int i = 0; i < cacheMatrix.size(); ++i)
    put_pixel(1, 0, 1, cacheMatrix[i][0], cacheMatrix[i][1]);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  glBegin(GL_TRIANGLES);
  placePoints();
  glEnd();

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

  glutCreateWindow("Continuous Rotation");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
