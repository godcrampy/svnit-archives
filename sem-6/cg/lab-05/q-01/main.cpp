#include <GL/glut.h>
#include <math.h>

void init(void) { glClearColor(0, 0, 0, 0); }

void draw_triangles() {
  glBegin(GL_TRIANGLES);

  glVertex2d(5, 60);
  glVertex2d(5, 65);
  glVertex2d(10, 60);

  glVertex2d(5, 70);
  glVertex2d(25, 70);
  glVertex2d(15, 60);

  glEnd();
}

void draw_triangle_strip() {
  glBegin(GL_TRIANGLE_STRIP);

  glVertex2d(40, 70);
  glVertex2d(40, 60);
  glVertex2d(50, 70);
  glVertex2d(60, 60);
  glVertex2d(65, 70);
  glVertex2d(67, 57);

  glEnd();
}

void draw_triangle_fan() {
  glBegin(GL_TRIANGLE_FAN);

  glVertex2d(80, 70);
  glVertex2d(80, 80);
  glVertex2d(83, 78);
  glVertex2d(85, 75);
  glVertex2d(84, 69);

  glEnd();
}

void draw_quad() {
  glBegin(GL_QUADS);

  glVertex2d(5, 10);
  glVertex2d(12, 20);
  glVertex2d(30, 22);
  glVertex2d(30, 8);

  glVertex2d(35, 20);
  glVertex2d(45, 25);
  glVertex2d(38, 5);
  glVertex2d(35, 5);

  glEnd();
}

void draw_quad_strip() {
  glBegin(GL_QUAD_STRIP);

  glVertex2d(50, 5);
  glVertex2d(48, 15);
  glVertex2d(55, 6);
  glVertex2d(53, 16);
  glVertex2d(60, 8);
  glVertex2d(55, 17);
  glVertex2d(65, 10);
  glVertex2d(64, 20);

  glEnd();
}

void draw_polygon() {
  glBegin(GL_POLYGON);

  glVertex2d(72, 5);
  glVertex2d(70, 15);
  glVertex2d(75, 25);
  glVertex2d(85, 27);
  glVertex2d(82, 18);

  glEnd();
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPointSize(3.0);

  draw_triangles();
  draw_triangle_strip();
  draw_triangle_fan();

  draw_quad();
  draw_quad_strip();

  draw_polygon();

  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(0, 120, 0, 100);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(200, 100);
  glutInitWindowSize(1200, 900);
  glutInitDisplayMode(GLUT_RGB);

  glutCreateWindow("Example");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}