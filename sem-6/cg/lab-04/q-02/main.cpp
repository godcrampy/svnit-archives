#include <GL/glut.h>
#include <math.h>

void init(void) { glClearColor(0, 0, 0, 0); }

void draw_points() {
  double r = 50;
  double x = r * cos(60 * M_PI / 180);
  double y = r * sin(60 * M_PI / 180);

  glVertex2d(r, 0);
  glVertex2d(x, y);
  glVertex2d(-1 * x, y);
  glVertex2d(-1 * r, 0);

  glVertex2d(x, -1 * y);
  glVertex2d(-1 * x, -1 * y);
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  glBegin(GL_LINES);

  draw_points();

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