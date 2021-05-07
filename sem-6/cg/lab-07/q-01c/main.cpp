#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

#define PI 3.14159265
double degree = 53.2;
double txCenter = -60;

vector<vector<double>> leftLegPoints = {{-60, 0, 1}, {-65, -10, 1}};

vector<vector<double>> leftHandPoints = {{-60, 12, 1}, {-65, 2, 1}};

vector<vector<double>> rightLegPoints = {{-60, 0, 1}, {-55, -10, 1}};

vector<vector<double>> rightHandPoints = {{-60, 12, 1}, {-55, 2, 1}};

bool leftLegBack = true; // assumption: left leg back, right leg front initially

void put_pixel(float r, float g, float b, double x, double y) {
  glColor3f(r, g, b);
  glVertex2d(x, y);
}

/*
Flow:
1. Back leg (bl) rotates by 53.2 and coincides with front leg(fl) about the
txCenter point
2. Translate the bl forward by 10 units in the x-axis
3. Rotate the fl in clockwise direction by 53.2 about its own point
4. We update the new txCenter to txCenter + 10, fl becomes bl and bl becomes fl
5. We repeat step 1-4 till txCenter < 90
*/

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

vector<vector<double>> set_rotate_point_matrix(double degree, int px, int py) {
  // T(-px, -py).R(degree).T(px, py)
  vector<vector<double>> rPointMatrix(3, vector<double>(3, 0));
  rPointMatrix = multiplyMatrix(set_translation_matrix(-1 * px, -1 * py),
                                set_rotate_matrix(degree));
  rPointMatrix = multiplyMatrix(rPointMatrix, set_translation_matrix(px, py));
  return rPointMatrix;
}

void walk() {
  vector<vector<double>> step1Matrix =
      set_rotate_point_matrix(degree, txCenter, 0);
  vector<vector<double>> step2Matrix = set_translation_matrix(10, 0);
  vector<vector<double>> step3MatrixLeg =
      set_rotate_point_matrix(-1 * degree, txCenter + 5, -10);

  if (leftLegBack) {

    leftLegPoints = multiplyMatrix(leftLegPoints, step1Matrix);
    leftLegPoints = multiplyMatrix(leftLegPoints, step2Matrix);
    rightLegPoints = multiplyMatrix(rightLegPoints, step3MatrixLeg);

    leftLegBack = false;
  } else {
    rightLegPoints = multiplyMatrix(rightLegPoints, step1Matrix);
    rightLegPoints = multiplyMatrix(rightLegPoints, step2Matrix);
    leftLegPoints = multiplyMatrix(leftLegPoints, step3MatrixLeg);

    leftLegBack = true;
  }

  txCenter += 10;
  vector<vector<double>> step4Matrix = set_translation_matrix(0, 12);
  leftHandPoints = multiplyMatrix(leftLegPoints, step4Matrix);
  rightHandPoints = multiplyMatrix(rightLegPoints, step4Matrix);
}

void drawLegs() {
  // left leg
  glBegin(GL_LINES);

  for (auto point : leftLegPoints)
    put_pixel(0, 1, 1, point[0], point[1]);
  glEnd();

  // right leg
  glBegin(GL_LINES);
  for (auto point : rightLegPoints)
    put_pixel(1, 0, 1, point[0], point[1]);
  glEnd();
}

void drawHands() {
  // left hand
  glBegin(GL_LINES);

  for (auto point : leftHandPoints)
    put_pixel(0, 1, 1, point[0], point[1]);
  glEnd();

  // right right
  glBegin(GL_LINES);
  for (auto point : rightHandPoints)
    put_pixel(1, 0, 1, point[0], point[1]);
  glEnd();
}

void drawCircle(double xMiddle) {
  double yMiddle = 19;
  float pi = PI;
  glPointSize(3.0);
  glBegin(GL_POINTS);

  for (float i = 0.0; i <= 2 * pi; i += 0.05)
    put_pixel(1, 1, 1, xMiddle + (sin(i) * 4), yMiddle + (cos(i) * 4));

  glEnd();
}

void timer(int id) {
  if (txCenter <= 75)
    walk();
  glutPostRedisplay();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);
  glLineWidth(3);

  drawLegs();
  drawHands();

  glBegin(GL_LINES);
  put_pixel(1, 1, 1, txCenter, 0);
  put_pixel(1, 1, 1, txCenter, 15);
  glEnd();

  drawCircle(txCenter);

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

  glutCreateWindow("Animated movement");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
