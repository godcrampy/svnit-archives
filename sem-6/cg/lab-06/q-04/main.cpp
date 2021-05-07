#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

using namespace std;

#define PI 3.14159265
double xLeftBoundary = -70;
double yBottomBoundary = -30;
double xRightBoundary = 70;
double upperBottomY = -1;
double xLeftUpper = -1, xRightUpper = -1;

void put_pixel(double x, double y) { glVertex2d(x, y); }

void createTriangle(double leftX, double rightX, double yCoord, double mid) {
  glBegin(GL_LINE_LOOP);
  put_pixel(leftX - 5, yCoord);
  put_pixel(leftX + mid, yCoord + 15);
  put_pixel(rightX + 5, yCoord);
  put_pixel(rightX + 8, yCoord + 5);
  put_pixel(rightX - mid, yCoord + 23);
  put_pixel(leftX - 8, yCoord + 5);
  glEnd();
}

void slantUpperFoundation(vector<double> prevCoordLeft,
                          vector<double> prevCoordRight) {
  put_pixel(prevCoordLeft[0], prevCoordLeft[1]);
  put_pixel(prevCoordLeft[0] + 5, prevCoordLeft[1] + 5);
  put_pixel(prevCoordRight[0] - 5, prevCoordRight[1] + 5);
  put_pixel(prevCoordRight[0], prevCoordRight[1]);
}

void createSlantFoundation() {
  glBegin(GL_LINE_LOOP);
  slantUpperFoundation({xLeftBoundary, yBottomBoundary + 5 + 40},
                       {xRightBoundary, yBottomBoundary + 5 + 40});
  glEnd();

  double xLeft1 = xLeftBoundary + 5;
  double xRight1 = xRightBoundary - 5;
  double y1 = yBottomBoundary + 45 + 5;

  glBegin(GL_LINE_LOOP);
  slantUpperFoundation({xLeft1, y1}, {xRight1, y1});
  glEnd();

  double xLeft2 = xLeft1 + 5;
  double xRight2 = xRight1 - 5;
  double y2 = y1 + 5;

  glBegin(GL_LINE_LOOP);
  slantUpperFoundation({xLeft2, y2}, {xRight2, y2});
  glEnd();

  double xLeft3 = xLeft2 + 5;
  double xRight3 = xRight2 - 5;
  double y3 = y2 + 5;

  glBegin(GL_LINE_LOOP);
  slantUpperFoundation({xLeft3, y3}, {xRight3, y3});
  glEnd();

  upperBottomY = y3 + 5;
  xLeftUpper = xLeft3 + 5;
  xRightUpper = xRight3 - 5;
}

void verticalBaseFoundation(double distance) {
  put_pixel(xLeftBoundary + distance, yBottomBoundary + 10);
  put_pixel(xLeftBoundary + distance, yBottomBoundary + 10 + 30);
  put_pixel(xLeftBoundary + 5 + distance, yBottomBoundary + 10 + 30);
  put_pixel(xLeftBoundary + 5 + distance, yBottomBoundary + 10);
}

void drawOutlineFoundation() {
  glBegin(GL_LINE_LOOP);
  put_pixel(xLeftBoundary, yBottomBoundary);
  put_pixel(xLeftBoundary, yBottomBoundary + 10);
  put_pixel(xRightBoundary, yBottomBoundary + 10);
  put_pixel(xRightBoundary, yBottomBoundary);
  glEnd();

  glBegin(GL_LINE_LOOP);
  verticalBaseFoundation(5);
  verticalBaseFoundation(30);
  verticalBaseFoundation(xRightBoundary - xLeftBoundary - 35);
  verticalBaseFoundation(xRightBoundary - xLeftBoundary - 10);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xLeftBoundary, yBottomBoundary + 40);
  put_pixel(xLeftBoundary, yBottomBoundary + 5 + 40);
  put_pixel(xRightBoundary, yBottomBoundary + 5 + 40);
  put_pixel(xRightBoundary, yBottomBoundary + 40);
  glEnd();

  createSlantFoundation();

  // left upper box
  glBegin(GL_LINE_LOOP);
  put_pixel(xLeftUpper, upperBottomY);
  put_pixel(xLeftUpper, upperBottomY + 20);
  put_pixel(xLeftUpper + 30, upperBottomY + 20);
  put_pixel(xLeftUpper + 30, upperBottomY);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xLeftUpper - 5, upperBottomY + 20);
  put_pixel(xLeftUpper - 5, upperBottomY + 20 + 5);
  put_pixel(xLeftUpper + 30, upperBottomY + 20 + 5);
  put_pixel(xLeftUpper + 30, upperBottomY + 20);
  glEnd();

  // right upper box
  glBegin(GL_LINE_LOOP);
  put_pixel(xRightUpper, upperBottomY);
  put_pixel(xRightUpper, upperBottomY + 20);
  put_pixel(xRightUpper - 30, upperBottomY + 20);
  put_pixel(xRightUpper - 30, upperBottomY);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xRightUpper + 5, upperBottomY + 20);
  put_pixel(xRightUpper + 5, upperBottomY + 20 + 5);
  put_pixel(xRightUpper - 30, upperBottomY + 20 + 5);
  put_pixel(xRightUpper - 30, upperBottomY + 20);
  glEnd();

  glBegin(GL_LINE_STRIP);
  put_pixel(xLeftUpper - 5, upperBottomY + 25);
  put_pixel(xLeftUpper + 7, upperBottomY + 25 + 15);
  put_pixel(xLeftUpper + 7 + 30, upperBottomY + 25 + 15);
  glEnd();

  glBegin(GL_LINE_STRIP);
  put_pixel(xRightUpper + 5, upperBottomY + 25);
  put_pixel(xRightUpper - 7, upperBottomY + 25 + 15);
  put_pixel(xRightUpper - 7 - 30, upperBottomY + 25 + 15);
  glEnd();

  double mid = ((xRightUpper - 30) - (xLeftUpper + 30)) / 2;
  createTriangle(xLeftUpper + 30, xRightUpper - 30, upperBottomY + 25, mid);
}

void verticalWindows(double xMiddle, double yMiddle) {
  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 5, yMiddle - 8);
  put_pixel(xMiddle - 5, yMiddle + 8);
  put_pixel(xMiddle + 5, yMiddle + 8);
  put_pixel(xMiddle + 5, yMiddle - 8);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 3, yMiddle + 2);
  put_pixel(xMiddle - 3, yMiddle + 6);
  put_pixel(xMiddle + 3, yMiddle + 6);
  put_pixel(xMiddle + 3, yMiddle + 2);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 3, yMiddle - 2);
  put_pixel(xMiddle - 3, yMiddle - 6);
  put_pixel(xMiddle + 3, yMiddle - 6);
  put_pixel(xMiddle + 3, yMiddle - 2);
  glEnd();
}

void horizontalWindows(double xMiddle, double yMiddle) {
  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 10, yMiddle - 5);
  put_pixel(xMiddle - 10, yMiddle + 5);
  put_pixel(xMiddle + 10, yMiddle + 5);
  put_pixel(xMiddle + 10, yMiddle - 5);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 4, yMiddle - 3);
  put_pixel(xMiddle - 8, yMiddle - 3);
  put_pixel(xMiddle - 8, yMiddle + 3);
  put_pixel(xMiddle - 4, yMiddle + 3);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle + 4, yMiddle + 3);
  put_pixel(xMiddle + 8, yMiddle + 3);
  put_pixel(xMiddle + 8, yMiddle - 3);
  put_pixel(xMiddle + 4, yMiddle - 3);
  glEnd();
}

void drawDoor(double xMiddle) {
  double yCoord = yBottomBoundary + 10;
  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 12, yCoord);
  put_pixel(xMiddle - 12, yCoord + 25);
  put_pixel(xMiddle + 12, yCoord + 25);
  put_pixel(xMiddle + 12, yCoord);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 10, yCoord);
  put_pixel(xMiddle - 10, yCoord + 23);
  put_pixel(xMiddle + 10, yCoord + 23);
  put_pixel(xMiddle + 10, yCoord);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(xMiddle - 8, yCoord + 23 - 10);
  put_pixel(xMiddle - 8, yCoord + 23 - 3);
  put_pixel(xMiddle + 8, yCoord + 23 - 3);
  put_pixel(xMiddle + 8, yCoord + 23 - 10);
  glEnd();
}

void drawCircle(double xMiddle) {
  double yCoord = yBottomBoundary + 10;
  double yMiddle = yCoord + 23 - 10 - 4;
  float radius = 2;
  float pi = PI;
  glPointSize(1.0);
  glBegin(GL_POINTS);

  for (float i = 0.0; i <= 2 * pi; i += 0.05)
    put_pixel(xMiddle + (sin(i) * radius), yMiddle + (cos(i) * radius));

  glEnd();
}

void drawSemiCircle(double xMiddle, double yMiddle) {
  float radius = 8;
  float pi = PI;
  glPointSize(1.0);
  glBegin(GL_POINTS);

  for (float i = -1 * pi / 2; i <= pi / 2; i += 0.05)
    put_pixel(xMiddle + (sin(i) * radius), yMiddle + (cos(i) * radius));

  glEnd();

  glBegin(GL_LINE_STRIP);
  put_pixel(xMiddle + (sin(-1 * pi / 2) * radius),
            yMiddle + (cos(-1 * pi / 2) * radius));
  put_pixel(xMiddle + (sin(pi / 2) * radius), yMiddle + (cos(pi / 2) * radius));
  glEnd();
}

void drawInnerDesigns() {
  double mid = (xRightBoundary + xLeftBoundary) / 2;
  glBegin(GL_LINE_LOOP);
  put_pixel(mid - 25, yBottomBoundary);
  put_pixel(mid - 25, yBottomBoundary + 4);
  put_pixel(mid + 25, yBottomBoundary + 4);
  put_pixel(mid + 25, yBottomBoundary);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(mid - 20, yBottomBoundary + 4);
  put_pixel(mid - 20, yBottomBoundary + 7);
  put_pixel(mid + 20, yBottomBoundary + 7);
  put_pixel(mid + 20, yBottomBoundary + 4);
  glEnd();

  glBegin(GL_LINE_LOOP);
  put_pixel(mid - 15, yBottomBoundary + 7);
  put_pixel(mid - 15, yBottomBoundary + 10);
  put_pixel(mid + 15, yBottomBoundary + 10);
  put_pixel(mid + 15, yBottomBoundary + 7);
  glEnd();

  verticalWindows(xLeftBoundary + 10 + 10, yBottomBoundary + 25);
  verticalWindows(xRightBoundary - 10 - 10, yBottomBoundary + 25);
  drawDoor(mid);
  drawCircle(mid + 6);

  horizontalWindows(xLeftUpper + 15, upperBottomY + 10);
  horizontalWindows(xRightUpper - 15, upperBottomY + 10);

  double midUpperWindow = ((xRightUpper - 30) + (xLeftUpper + 30)) / 2;
  horizontalWindows(midUpperWindow, upperBottomY + 15);
  drawSemiCircle(midUpperWindow, upperBottomY + 25);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  drawOutlineFoundation();
  drawInnerDesigns();
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

  glutCreateWindow("House Structure");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}
