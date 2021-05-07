#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

#define PI 3.14159265
double degree = 45;
double xCoord = -80;
double yCoord = 25;

/*
Flow:
1. Rotate the  center of circle about the origin by 45 degree
2. Continue rotating till the y > 0
3. Once, y <= 0 just follow translation in the y axis in the down direction
4. Continue step 3 till y > -70
5. Once y <= -70, remove the circle
*/

void put_pixel(double x, double y) { glVertex2d(x, y); }

vector<vector<double>> multiplyMatrix(vector<vector<double>> a,
                                      vector<vector<double>> b) {
  vector<vector<double>> resMatrix(a.size(), vector<double>(3, 0));
  for (int i = 0; i < a.size(); ++i) {
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

void drawGoal() {
  glBegin(GL_POLYGON);
  put_pixel(-90, -92);
  put_pixel(90, -92);
  put_pixel(90, -70);
  put_pixel(-90, -70);
  glEnd();
}

void drawBall(double x, double y) {
  double pi = PI;
  float radius = 10;
  glPointSize(3.0);
  glBegin(GL_POINTS);

  for (float i = 0.0; i <= 2 * pi; i += 0.05)
    put_pixel(x + (sin(i) * radius), y + (cos(i) * radius));

  glEnd();
}

void goalAnimation() {
  vector<vector<double>> point = {{xCoord, yCoord, 1}};

  if (yCoord > 0) {
    vector<vector<double>> mat = set_rotate_matrix(-1 * degree);
    point = multiplyMatrix(point, mat);

    xCoord = point[0][0];
    yCoord = point[0][1];
  } else if (yCoord <= 0 && yCoord > -70) {
    vector<vector<double>> mat = set_translation_matrix(0, -10);
    point = multiplyMatrix(point, mat);

    xCoord = point[0][0];
    yCoord = point[0][1];
  } else {
    xCoord = -80;
    yCoord = 25;
  }
}

void timer(int id) {
  goalAnimation();
  glutPostRedisplay();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  drawBall(xCoord, yCoord);
  drawGoal();

  glutTimerFunc(300, timer, 1);

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
