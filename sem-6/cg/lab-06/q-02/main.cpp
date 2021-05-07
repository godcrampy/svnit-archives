#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

vector<vector<double>> points;
vector<vector<double>> transformation_matrix = {
    {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

void init(void) { glClearColor(0, 0, 0, 0); }

void put_pixel(int x, int y) { glVertex2d(x, y); }

vector<vector<double>> matrix_multiply(vector<vector<double>> a,
                                       vector<vector<double>> b) {
  int r1 = a.size();
  int c1 = a[0].size();
  int r2 = b.size();
  int c2 = b[0].size();

  if (c1 != r2) {
    cout << "Error in matrix sizes: " << r1 << " " << c1 << " " << r2 << " "
         << c2 << "\n";
    exit(EXIT_FAILURE);
  }

  vector<vector<double>> mul(r1, vector<double>(c2));

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      mul[i][j] = 0;
      for (int k = 0; k < c1; k++) {
        mul[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return mul;
}

void translation(double x, double y) {
  vector<vector<double>> v = {{1, 0, 0}, {0, 1, 0}, {x, y, 1}};
  transformation_matrix = matrix_multiply(transformation_matrix, v);
}

void rotation(double deg) {
  double cosVal = cos(deg * M_PI / 180);
  double sinVal = sin(deg * M_PI / 180);

  vector<vector<double>> v = {
      {cosVal, sinVal, 0}, {-sinVal, cosVal, 0}, {0, 0, 1}};
  transformation_matrix = matrix_multiply(transformation_matrix, v);
}

void scaling(double sx, double sy) {
  vector<vector<double>> v = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
  transformation_matrix = matrix_multiply(transformation_matrix, v);
}

void draw_points() {
  glBegin(GL_LINE_LOOP);

  for (auto p : points) {
    put_pixel(p[0], p[1]);
  }

  glEnd();
}

void draw_axis() {
  glBegin(GL_LINES);

  put_pixel(-100, 0);
  put_pixel(100, 0);
  put_pixel(0, 100);
  put_pixel(0, -100);

  glEnd();
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);
  draw_axis();
  draw_points();
  points = matrix_multiply(points, transformation_matrix);
  draw_points();

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
  cout << "Enter number of coordinate points: ";
  points = vector<vector<double>>(0);
  int n;
  cin >> n;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cout << "Enter points " << i + 1 << ": ";
    cin >> x >> y;
    points.push_back({(double)x, (double)y, 1.0});
  }

  cout << "Enter s for scaling, t for translation, r for rotation: ";
  string s;
  cin >> s;

  if (s == "s") {
    double sx, sy;
    cout << "Enter sx, sy: ";
    cin >> sx >> sy;
    scaling(sx, sy);

  } else if (s == "t") {
    double tx, ty;
    cout << "Enter tx, ty: ";
    cin >> tx >> ty;
    translation(tx, ty);

  } else if (s == "r") {
    double degree;
    cout << "Enter degree: ";
    cin >> degree;
    rotation(degree);
  }

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
