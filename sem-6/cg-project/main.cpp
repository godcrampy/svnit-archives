#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iostream>
#define ESCAPE 27
using namespace std;
GLint window;
GLint window2;
GLint Xsize = 1200;
GLint Ysize = 600;
float i, theta;
GLint nml = 0, day = 1;

char name3[] = "MINI PROJECT : CAR GARAGE";  // display string

GLfloat xt = 0.0, yt = 0.0, zt = 0.0, xw = 0.0;
GLfloat xs = 1.0, ys = 1.0, zs = 1.0;
GLfloat xangle = 0.0, yangle = 0.0, zangle = 0.0, angle = 0.0;

GLfloat r = 0.3, g = 0.8, b = 1;       // car color
GLfloat r1 = 0.3, g1 = 0.3, b1 = 0.7;  // ignition system colors
GLfloat r2 = r, g2 = g, b2 = b;        // engine cover color
GLint light = 1;
int count = 1, flg = 1;
// count if 1 open window nothing for count=0
// no need of flg
int view = 0;              // For changing window's data
int flag1 = 0, aflag = 1;  // to switch car driving mode
// flag1 is for driving mode switching
// aflag for day and night mode.(nightmode=0)
int flag2 = 0, wheelflag = 0;  // to switch fog effect
// flag2 if 2 it is given fog values for night and evening mode
// wheelflag for wheel mode
int flag3 = 0;   // for ignition color
int flag4 = 0;   // for wheel spokes color
int flag6 = 0;   // for travel mode
int flag7 = 0;   // Tinted glass
int flag8 = 0;   // double exhaust
int flag9 = 0;   // for engine cover color
int flag10 = 0;  // For radiant mode
int flag11 = 0;  // Retro Mode
int flag12 = 0;  // for windscreen
float ra = 0.08, x = 0;
// ra is actual radius of wheel of car
int flag5 = 0;  // for radius of wheel
GLUquadricObj *t;

static void SpecialKeyFunc(int Key, int x, int y);

GLvoid Transform(GLfloat Width, GLfloat Height) {
  glViewport(0, 0, Width, Height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, Width / Height, 0.1, 100.0);
  glMatrixMode(GL_MODELVIEW);
}

GLvoid InitGL(GLfloat Width, GLfloat Height) {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glLineWidth(3.0);         /* Add line width,   ditto */
  Transform(Width, Height); /* Perform the transformation */
  t = gluNewQuadric();
  gluQuadricDrawStyle(t, GLU_FILL);
  gluQuadricTexture(t, GLU_TRUE);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  GLfloat ambientLight[4], diffuseLight[4], specularLight[4], position[4];
  if (flag10 == 1) {
    ambientLight[0] = 0.9f;
    ambientLight[1] = 0.0f;
    ambientLight[2] = 0.5f;
    ambientLight[3] = 1.0f;
    // ambientLight = { 0.9f, 0.0f, 0.5f, 1.0f };
    diffuseLight[0] = 0.9f;
    diffuseLight[1] = 0.0f;
    diffuseLight[2] = 0.5f;
    diffuseLight[3] = 1.0f;

    specularLight[0] = 0.9f;
    specularLight[1] = 0.0f;
    specularLight[2] = 0.5f;
    specularLight[3] = 1.0f;

    position[0] = 1.5f;
    position[1] = 1.0f;
    position[2] = 4.0f;
    position[3] = 1.0f;
  } else {
    ambientLight[0] = 0.2f;
    ambientLight[1] = 0.2f;
    ambientLight[2] = 0.2f;
    ambientLight[3] = 1.0f;
    // ambientLight = { 0.9f, 0.0f, 0.5f, 1.0f };
    diffuseLight[0] = 0.8f;
    diffuseLight[1] = 0.8f;
    diffuseLight[2] = 0.8f;
    diffuseLight[3] = 1.0f;

    specularLight[0] = 0.5f;
    specularLight[1] = 0.5f;
    specularLight[2] = 0.5f;
    specularLight[3] = 1.0f;

    position[0] = 1.5f;
    position[1] = 1.0f;
    position[2] = 4.0f;
    position[3] = 1.0f;
  }
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
  glLightfv(GL_LIGHT0, GL_POSITION, position);
}
void init() {
  glClearColor(0, 0, 0, 0);
  glPointSize(7.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 900.0, 0.0, 600.0, 50.0, -50.0);
  glutPostRedisplay();
}
void display_string(int x, int y, char *string, int font) {
  int len, i;
  glColor3f(0.8, 0.52, 1.0);
  glRasterPos2f(x, y);
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    if (font == 1) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    if (font == 2) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    if (font == 3) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
    if (font == 4) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, string[i]);
  }
}
void drawwheel() {
  int r = 95, r1 = 10, r2 = 120;
  float xc = 150, yc = 300, x, y;
  glBegin(GL_LINE_LOOP);
  for (float i = 0; i <= 360; i++) {
    x = r * cos((i * 3.14) / 180);
    y = r * sin((i * 3.14) / 180);
    glVertex2f(x + xc, y + yc);
  }
  glEnd();
  for (float i = 0; i <= 360; i = i + 30) {
    x = r * cos((i * 3.14) / 180);
    y = r * sin((i * 3.14) / 180);
    glBegin(GL_LINES);
    glVertex2f(xc, yc);
    glVertex2f(x + xc, y + yc);
    glEnd();
  }
  glBegin(GL_LINE_LOOP);
  for (float i = 0; i <= 360; i++) {
    x = r1 * cos((i * 3.14) / 180);
    y = r1 * sin((i * 3.14) / 180);
    glVertex2f(x + xc, y + yc);
  }
  glEnd();
  glBegin(GL_LINE_LOOP);
  for (float i = 0; i <= 360; i++) {
    x = r2 * cos((i * 3.14) / 180);
    y = r2 * sin((i * 3.14) / 180);
    glVertex2f(x + xc, y + yc);
  }
  glEnd();
}
void display1(void) {
  glClearColor(0.2f, 1.0f, 0.7f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  display_string(360, 550, "COMPUTER GRAPHICS", 1);
  glBegin(GL_LINE_LOOP);
  glVertex2i(600, 590);
  glVertex2i(600, 470);
  glVertex2i(330, 470);
  glVertex2i(330, 590);
  glEnd();
  display_string(360, 500, name3, 2);
  display_string(360, 450 - 30, "Read The Following Instructions", 2);
  glBegin(GL_LINES);
  glVertex2i(360, 445 - 30);
  glVertex2i(560, 445 - 30);
  glEnd();
  display_string(370, 360, "MOUSE OPERATIONS", 2);
  glBegin(GL_LINES);
  glVertex2i(370, 355);
  glVertex2i(520, 355);
  glEnd();
  display_string(370, 330, "RIGHT CLICK FOR CUSTOMIZATIONS", 3);
  display_string(370, 290, "KEYBOARD OPERATIONS", 2);
  glBegin(GL_LINES);
  glVertex2i(370, 285);
  glVertex2i(540, 285);
  glEnd();
  display_string(370, 260, "X-Y-Z KEYS FOR CORRESPONDING ROTATION", 3);
  display_string(370, 220 + 10, "U-F FOR CAMERA VIEW SETTINGS", 3);
  display_string(370, 190 + 10,
                 "USE LEFT ARROW(<-) AND RIGHT ARROW(->) TO MOVE CAR", 3);
  display_string(370, 140, "ESCAPE TO QUIT", 2);
  glBegin(GL_LINES);
  glVertex2i(370, 135);
  glVertex2i(490, 135);
  glEnd();
  display_string(330, 50, "PRESS SPACE BAR TO ENTER", 1);
  glBegin(GL_LINE_LOOP);
  glVertex2i(635, 20);
  glVertex2i(280, 20);
  glVertex2i(280, 90);
  glVertex2i(635, 90);
  glEnd();
  drawwheel();
  glBegin(GL_QUADS);
  glVertex2i(690, 100);
  glVertex2i(720, 80);
  glVertex2i(820, 280);
  glVertex2i(790, 300);
  glEnd();
  glBegin(GL_LINE_STRIP);
  glVertex2i(720, 330);
  glVertex2i(740, 370);
  glVertex2i(900, 290);
  glVertex2i(880, 250);
  glEnd();
  glBegin(GL_LINES);
  glVertex2i(790, 300);
  glVertex2i(720, 330);
  glEnd();
  glBegin(GL_LINES);
  glVertex2i(820, 280);
  glVertex2i(880, 250);
  glEnd();
  /*
      //Texture code
      GLfloat texCoords[] = {
      0.0f, 0.0f,  // Lower-left corner
      1.0f, 0.0f,  // Lower-right corner
      0.5f, 1.0f   // Top-center corner
      };
      GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  int width, height;
  unsigned char* image = SOIL_load_image("texture.jpg", &width, &height, 0,
  SOIL_LOAD_RGB); glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
  GL_RGB, GL_UNSIGNED_BYTE, image); glBindTexture(GL_TEXTURE_2D, 0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glBindTexture(GL_TEXTURE_2D, texture);

  //End of texture code
  */
  int r = 95, r1 = 10, r2 = 120;
  float xc = 150, yc = 300, x, y;
  // concentric circles for design
  for (float i = 0; i <= 360; i++) {
    x = 15 * cos((i * 3.14) / 180);
    y = 15 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 50, y + 550);
    glEnd();
  }
  for (float i = 0; i <= 360; i++) {
    x = 2 * cos((i * 3.14) / 180);
    y = 2 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 50, y + 550);
    glEnd();
  }

  for (float i = 0; i <= 360; i++) {
    x = 15 * cos((i * 3.14) / 180);
    y = 15 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 100, y + 30);
    glEnd();
  }
  for (float i = 0; i <= 360; i++) {
    x = 2 * cos((i * 3.14) / 180);
    y = 2 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 100, y + 30);
    glEnd();
  }

  for (float i = 0; i <= 360; i++) {
    x = 15 * cos((i * 3.14) / 180);
    y = 15 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 300, y + 200);
    glEnd();
  }
  for (float i = 0; i <= 360; i++) {
    x = 2 * cos((i * 3.14) / 180);
    y = 2 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 300, y + 200);
    glEnd();
  }

  for (float i = 0; i <= 360; i++) {
    x = 15 * cos((i * 3.14) / 180);
    y = 15 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 600, y + 350);
    glEnd();
  }
  for (float i = 0; i <= 360; i++) {
    x = 2 * cos((i * 3.14) / 180);
    y = 2 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 600, y + 350);
    glEnd();
  }

  for (float i = 0; i <= 360; i++) {
    x = 15 * cos((i * 3.14) / 180);
    y = 15 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 850, y + 90);
    glEnd();
  }
  for (float i = 0; i <= 360; i++) {
    x = 2 * cos((i * 3.14) / 180);
    y = 2 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 850, y + 90);
    glEnd();
  }

  display_string(650, 550, "PROJECT MADE BY:", 1);
  display_string(650, 510, "U18CO021-SAHIL LALIT BONDRE", 2);
  display_string(650, 490, "U18CO022-CH SURYA TEJA", 2);
  display_string(650, 470, "U18CO028-N.N.S.S DAIVIK", 2);
  display_string(650, 450, "U18CO059-AEMIE JARIWALA", 2);

  for (float i = 0; i <= 360; i++) {
    x = 15 * cos((i * 3.14) / 180);
    y = 15 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 280, y + 490);
    glEnd();
  }
  for (float i = 0; i <= 360; i++) {
    x = 2 * cos((i * 3.14) / 180);
    y = 2 * sin((i * 3.14) / 180);
    glBegin(GL_POINTS);
    glVertex2f(x + 280, y + 490);
    glEnd();
  }
  glutPostRedisplay();
  glutSwapBuffers();
}

void display2() {
  glClearColor(0.45f, 0.45f, 0.45f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glutPostRedisplay();
}
GLvoid DrawGLScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (view == 0) {
    init();
    display1();
  } else {
    if (count == 1) InitGL(1250, 600);
    display2();
    if (aflag == 1) /* Initialize our window. */
      glClearColor(1, 1, 1, 1);
    else
      glClearColor(0.1, 0.1, 0.1, 0);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-1.0, 0.0, -3.5);
    glRotatef(xangle, 1.0, 0.0, 0.0);
    glRotatef(yangle, 0.0, 1.0, 0.0);
    glRotatef(zangle, 0.0, 0.0, 1.0);
    glTranslatef(xt, yt, zt);
    glScalef(xs, ys, zs);
    glEnable(GL_COLOR_MATERIAL);

    if (flag2 == 1) {
      GLfloat fogcolour[4] = {1.0, 1.0, 1.0, 1.0};

      glFogfv(GL_FOG_COLOR, fogcolour);
      glFogf(GL_FOG_DENSITY, 0.1);
      glFogi(GL_FOG_MODE, GL_EXP);
      glFogf(GL_FOG_START, 3.0);
      glFogf(GL_FOG_END, 100.0);
      glHint(GL_FOG_HINT, GL_FASTEST);
      glEnable(GL_FOG);
    }
    if (flag2 == 0) {
      glDisable(GL_FOG);
    }

    if (!aflag) {
      glBegin(GL_POINTS);
      glColor3f(1, 1, 1);
      glPointSize(200.0);
      int ccount = 0;
      float x = 10, y = 10;
      while (ccount < 20) {
        glVertex2f(x, y);
        x += 10;
        y += 10;
        if (y > Ysize) y -= 10;
        if (x > Xsize) x -= 10;
        ccount++;
      }
      glEnd();
    }

    glColor3f(1.0, .75, 0.0);
    glPointSize(30.0);
    glBegin(GL_POINTS);
    glVertex3f(0.2, 0.3, 0.3);
    glVertex3f(0.2, 0.3, 0.5);
    glEnd();
    glPointSize(200.0);

    glBegin(GL_QUADS); /* OBJECT MODULE*/

    /* top of cube*/
    //************************FRONT BODY****************************************
    if (flag9 == 0 || flag9 == 2) {
      r2 = r;
      g2 = g;
      b2 = b;
    } else if (flag9 == 1) {
      r2 = 0;
      g2 = 0;
      b2 = 0;
    } else {
      r2 = 0.9;
      g2 = 0;
      b2 = 0.4;
    }
    glColor3f(r2, g2, b2);
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.2, 0.4, 0.2);
    if (flag11 == 0) {
      glColor3f(r, g, b);
    } else {
      glColor3f(0.1f, 0.1f, 0.1f);
    }
    /* bottom of cube*/
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(0.2, 0.2, 0.2);

    /* front of cube*/
    glVertex3f(0.2, 0.2, 0.6);
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.2, 0.4, 0.2);
    glVertex3f(0.2, 0.2, 0.2);

    /* back of cube.*/
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.6, 0.2, 0.2);

    /* left of cube*/
    glVertex3f(0.2, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.2, 0.4, 0.6);

    /* Right of cube */
    glVertex3f(0.2, 0.2, 0.2);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.2, 0.4, 0.2);
    //****************************************************************************
    glColor3f(r, g, b);
    glVertex3f(0.7, 0.65, 0.6);
    glVertex3f(0.7, 0.65, 0.2);
    glVertex3f(1.7, 0.65, 0.2);  // top cover
    glVertex3f(1.7, 0.65, 0.6);
    if (flag6 == 1) {
      glColor3f(0, 0, 0);
      glVertex3f(0.8, 0.7, 0.6);
      glVertex3f(0.8, 0.7, 0.2);
      glVertex3f(1.6, 0.7, 0.2);  // luggage
      glVertex3f(1.6, 0.7, 0.6);
    }
    if (flag6 == 2) {
      glColor3f(0.9, 0.9, 1.0);
      glVertex3f(0.8, 0.7, 0.6);
      glVertex3f(0.8, 0.7, 0.2);
      glVertex3f(1.6, 0.7, 0.2);  // luggage
      glVertex3f(1.6, 0.7, 0.6);
    }
    if (flag12 == 1) {
      glColor3f(0.3, 0.3, 0.3);
      glVertex3f(0.9, 0.67, 0.6);
      glVertex3f(0.9, 0.67, 0.2);
      glVertex3f(1.05, 0.67, 0.2);  // wind screen
      glVertex3f(1.05, 0.67, 0.6);
    }

    //***************************back guard******************************
    glColor3f(r, g, b); /* Set The Color*/
    glVertex3f(1.8, 0.5, 0.6);
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.4, 0.6);

    if (flag11 == 0) {
      glColor3f(r, g, b);
    } else {
      glColor3f(0.1f, 0.1f, 0.1f);
    }
    /* bottom of cube*/
    glVertex3f(2.1, 0.2, 0.6);
    glVertex3f(2.1, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8, 0.2, 0.6);

    /* back of cube.*/
    glVertex3f(2.1, 0.4, 0.6);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.2, 0.2);
    glVertex3f(2.1, 0.2, 0.6);

    /* left of cube*/
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.2, 0.2);

    /* Right of cube */
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8, 0.5, 0.6);
    glVertex3f(2.1, 0.4, 0.6);
    glVertex3f(2.1, 0.2, 0.6);
    //******************MIDDLE BODY************************************
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8, 0.5, 0.6);

    /* bottom of cube*/
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.6);

    /* back of cube.*/
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.5, 0.2);
    //*********************ENTER WINDOW**********************************
    if (flag7 == 1) {
      glColor3f(0.2, 0.2, 0.2);
    } else if (flag11 == 1) {
      glColor3f(0.7, 0.7, 0.7);
    } else {
      glColor3f(0.3, 0.3, 0.3);
    }
    glVertex3f(0.77, 0.63, 0.2);
    glVertex3f(0.75, 0.5, 0.2);  // quad front window
    glVertex3f(1.2, 0.5, 0.2);
    glVertex3f(1.22, 0.63, 0.2);

    glVertex3f(1.27, 0.63, .2);
    glVertex3f(1.25, 0.5, 0.2);  // quad back window
    glVertex3f(1.65, 0.5, 0.2);
    glVertex3f(1.67, 0.63, 0.2);

    glColor3f(r, g, b);
    glVertex3f(0.7, 0.65, 0.2);
    glVertex3f(0.7, 0.5, .2);  // first separation
    glVertex3f(0.75, 0.5, 0.2);
    glVertex3f(0.77, 0.65, 0.2);

    glVertex3f(1.2, 0.65, 0.2);
    glVertex3f(1.2, 0.5, .2);  // second separation
    glVertex3f(1.25, 0.5, 0.2);
    glVertex3f(1.27, 0.65, 0.2);

    glVertex3f(1.65, 0.65, 0.2);
    glVertex3f(1.65, 0.5, .2);  // 3d separation
    glVertex3f(1.7, 0.5, 0.2);
    glVertex3f(1.7, 0.65, 0.2);

    glVertex3f(0.75, 0.65, 0.2);
    glVertex3f(0.75, 0.63, 0.2);  // line strip
    glVertex3f(1.7, 0.63, 0.2);
    glVertex3f(1.7, 0.65, 0.2);

    glVertex3f(0.75, 0.65, 0.6);
    glVertex3f(0.75, 0.63, 0.6);  // line strip
    glVertex3f(1.7, 0.63, 0.6);
    glVertex3f(1.7, 0.65, 0.6);

    if (flag7 == 1) {
      glColor3f(0.2, 0.2, 0.2);
    } else if (flag11 == 1) {
      glColor3f(0.7, 0.7, 0.7);
    } else {
      glColor3f(0.3, 0.3, 0.3);
    }
    glVertex3f(0.77, 0.63, 0.6);
    glVertex3f(0.75, 0.5, 0.6);  // quad front window
    glVertex3f(1.2, 0.5, 0.6);
    glVertex3f(1.22, 0.63, 0.6);

    glVertex3f(1.27, 0.63, .6);
    glVertex3f(1.25, 0.5, 0.6);  // quad back window
    glVertex3f(1.65, 0.5, 0.6);
    glVertex3f(1.67, 0.63, 0.6);

    glColor3f(r, g, b);
    glVertex3f(0.7, 0.65, 0.6);
    glVertex3f(0.7, 0.5, .6);  // first separation
    glVertex3f(0.75, 0.5, 0.6);
    glVertex3f(0.77, 0.65, 0.6);

    glVertex3f(1.2, 0.65, 0.6);
    glVertex3f(1.2, 0.5, .6);  // second separation
    glVertex3f(1.25, 0.5, 0.6);
    glVertex3f(1.27, 0.65, 0.6);

    glVertex3f(1.65, 0.65, 0.6);
    glVertex3f(1.65, 0.5, .6);
    glVertex3f(1.7, 0.5, 0.6);
    glVertex3f(1.7, 0.65, 0.6);
    glEnd();

    //**************************************************************
    glBegin(GL_QUADS);

    /* top of cube*/
    if (flag7 == 1) {
      glColor3f(0.2, 0.2, 0.2);
    } else if (flag11 == 1) {
      glColor3f(0.7, 0.7, 0.7);
    } else {
      glColor3f(0.3, 0.3, 0.3);
    }
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);  // quad front window
    glVertex3f(0.7, 0.65, 0.2);
    glVertex3f(0.7, 0.65, 0.6);

    glVertex3f(1.7, 0.65, .6);
    glVertex3f(1.7, 0.65, 0.2);  // quad back window
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(1.8, 0.5, 0.6);

    //*****************************road and surrounding
    // development***********************************
    if (flag1) {
      glPushMatrix();
      glTranslatef(xw, 0, 0);
      glColor3f(0, 1, 0);
      glVertex3f(-100, 0.1, -100);
      glVertex3f(-100, 0.1, 0);  // a green surroundings
      glVertex3f(100, 0.1, 0);
      glVertex3f(100, 0.1, -100);

      glColor3f(0.7, 0.7, 0.7);
      glVertex3f(-100, 0.1, 0);
      glVertex3f(-100, 0.1, 0.45);  // a long road
      glVertex3f(100, 0.1, 0.45);
      glVertex3f(100, 0.1, 0);

      glColor3f(1.0, 0.75, 0.0);
      glVertex3f(-100, 0.1, 0.45);  // a median
      glVertex3f(-100, 0.1, 0.55);
      glVertex3f(100, 0.1, 0.55);
      glVertex3f(100, 0.1, 0.45);

      glColor3f(0.7, 0.7, 0.7);
      glVertex3f(-100, 0.1, 0.55);
      glVertex3f(-100, 0.1, 1);  // a long road
      glVertex3f(100, 0.1, 1);
      glVertex3f(100, 0.1, 0.55);

      glColor3f(0, 1, 0);
      glVertex3f(-100, 0.1, 1);
      glVertex3f(-100, 0.1, 100);  // a green surroundings
      glVertex3f(100, 0.1, 100);
      glVertex3f(100, 0.1, 1);
      glPopMatrix();
    }
    glEnd();

    if (wheelflag) {
      glPushMatrix();
      glTranslatef(xw, 0, 0);
      glColor3f(0.5, .2, 0.3);
      glBegin(GL_QUADS);
      for (i = 0; i < 200; i += 0.2) {
        glVertex3f(-100 + i, 0, 1);
        glVertex3f(-99.9 + i, 0, 1);
        glVertex3f(-99.9 + i, 0.2, 1);
        glVertex3f(-100 + i, 0.2, 1);
        i += 0.5;
      }
      for (i = 0; i < 200; i += 0.2) {
        glVertex3f(-100 + i, 0, 0);
        glVertex3f(-99.9 + i, 0, 0);
        glVertex3f(-99.9 + i, 0.2, 0);
        glVertex3f(-100 + i, 0.2, 0);
        i += 0.5;
      }
      glEnd();
      glPopMatrix();
    }
    //
    glBegin(GL_TRIANGLES); /* start drawing the cube.*/

    /* top of cube*/
    if (flag7 == 1) {
      glColor3f(0.2, 0.2, 0.2);
    } else if (flag11 == 1) {
      glColor3f(0.7, 0.7, 0.7);
    } else {
      glColor3f(0.3, 0.3, 0.3);
    }
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.7, 0.65, 0.6);  // tri front window
    glVertex3f(0.7, 0.5, 0.6);

    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.7, 0.65, 0.2);  // tri front window
    glVertex3f(0.7, 0.5, 0.2);

    glVertex3f(1.7, 0.65, 0.2);
    glVertex3f(1.8, 0.5, 0.2);  // tri back window
    glVertex3f(1.7, 0.5, 0.2);

    glVertex3f(1.7, 0.65, 0.6);
    glVertex3f(1.8, 0.5, 0.6);  // tri back window
    glVertex3f(1.7, 0.5, 0.6);

    glEnd();
    //************IGNITION SYSTEM
    glPushMatrix();
    if (flag3 == 0) {
      glColor3f(r1, g1, b1);
      glTranslatef(1.65, 0.2, 0.3);
      glRotatef(90.0, 0, 1, 0);
      gluCylinder(t, 0.02, 0.03, .5, 10, 10);
    } else if (flag3 == 1) {
      glColor3f(0, 0, 0);
      glTranslatef(1.65, 0.2, 0.3);
      glRotatef(90.0, 0, 1, 0);
      gluCylinder(t, 0.02, 0.03, .5, 10, 10);
    } else if (flag3 == 2) {
      glColor3f(0.9, 0, 0.4);
      glTranslatef(1.65, 0.2, 0.3);
      glRotatef(90.0, 0, 1, 0);
      gluCylinder(t, 0.02, 0.03, .5, 10, 10);
    } else {
      glColor3f(0.6, 0, 0.1);
      glTranslatef(1.65, 0.2, 0.3);
      glRotatef(90.0, 0, 1, 0);
      gluCylinder(t, 0.02, 0.03, .5, 10, 10);
    }

    if (flag3 == 0 && flag8 == 1) {
      glColor3f(r1, g1, b1);
      glTranslatef(-1.65, -0.2, -0.3);
      glTranslatef(1.45, 0.2, 0.3);
      glRotatef(0, 0, 1, 0);
      gluCylinder(t, 0.02, 0.03, .5, 10, 10);
    }
    if (flag3 == 1 && flag8 == 1) {
      glColor3f(0, 0, 0);
      glTranslatef(-1.65, -0.2, -0.3);
      glTranslatef(1.45, 0.2, 0.3);
      glRotatef(0, 0, 1, 0);
      gluCylinder(t, 0.02, 0.03, .5, 10, 10);
    }
    if (flag3 == 2 && flag8 == 1) {
      glColor3f(0.9, 0, 0.4);
      glTranslatef(-1.65, -0.2, -0.3);
      glTranslatef(1.45, 0.2, 0.3);
      glRotatef(0, 0, 1, 0);
      gluCylinder(t, 0.02, 0.03, .5, 10, 10);
    }

    glPopMatrix();
    //********************WHEEL
    if (flag4 == 0 && flag11 != 1) {
      glColor3f(0.7, 0.7, 0.7);
    } else if (flag4 == 1 && flag11 != 1) {
      glColor3f(0.3, 1, 0.5);
    } else if (flag4 == 2 && flag11 != 1) {
      glColor3f(0.9, 0, 0.4);
    } else {
      glColor3f(r, g, b);
    }
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 40) {
      glVertex3f(0.6, 0.2, 0.62);
      glVertex3f(0.6 + (ra * (cos(((theta + angle) * 3.14) / 180))),
                 0.2 + (ra * (sin(((theta + angle) * 3.14) / 180))), 0.62);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 40) {
      glVertex3f(0.6, 0.2, 0.18);
      glVertex3f(0.6 + (ra * (cos(((theta + angle) * 3.14) / 180))),
                 0.2 + (ra * (sin(((theta + angle) * 3.14) / 180))), 0.18);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 40) {
      glVertex3f(1.7, 0.2, 0.18);
      glVertex3f(1.7 + (ra * (cos(((theta + angle) * 3.14) / 180))),
                 0.2 + (ra * (sin(((theta + angle) * 3.14) / 180))), 0.18);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta < 360; theta = theta + 40) {
      glVertex3f(1.7, 0.2, 0.62);
      glVertex3f(1.7 + (ra * (cos(((theta + angle) * 3.14) / 180))),
                 0.2 + (ra * (sin(((theta + angle) * 3.14) / 180))), 0.62);
    }
    glEnd();
    glTranslatef(0.6, 0.2, 0.6);
    if (flag11 == 0) {
      glColor3f(0, 0, 0);
    }
    if (flag11 == 1) {
      glColor3f(0.7, 0.7, 0.7);
    }
    glutSolidTorus(0.025, ra, 10, 25);

    glTranslatef(0, 0, -0.4);
    glutSolidTorus(0.025, ra, 10, 25);

    glTranslatef(1.1, 0, 0);
    glutSolidTorus(0.025, ra, 10, 25);

    glTranslatef(0, 0, 0.4);
    glutSolidTorus(0.025, ra, 10, 25);
    glPopMatrix();
    //*************************************************************
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glutPostRedisplay();
    glutSwapBuffers();
  }
}

void NormalKey(GLubyte key, GLint x, GLint y) {
  switch (key) {
    case ESCAPE:
      printf("Escape Key is Pressed. Quit.\n");
      glutDestroyWindow(window);
      exit(0);
      break;

    case ' ':
      view = 1;
      DrawGLScene();
      break;

    case 'x':
      xangle += 5.0;
      glutPostRedisplay();
      break;

    case 'X':
      xangle -= 5.0;
      glutPostRedisplay();
      break;

    case 'y':
      yangle += 5.0;
      glutPostRedisplay();
      break;

    case 'Y':
      yangle -= 5.0;
      glutPostRedisplay();
      break;

    case 'z':
      zangle += 5.0;
      glutPostRedisplay();
      break;

    case 'Z':
      zangle -= 5.0;
      glutPostRedisplay();
      break;

    case 'u': /* Move up */
      yt += 0.2;
      glutPostRedisplay();
      break;

    case 'U':
      yt -= 0.2; /* Move down */
      glutPostRedisplay();
      break;

    case 'f': /* Move forward */
      zt += 0.2;
      glutPostRedisplay();
      break;

    case 'F':
      zt -= 0.2; /* Move away */
      glutPostRedisplay();
      break;

    default:
      break;
  }
}

static void SpecialKeyFunc(int Key, int x, int y) {
  switch (Key) {
    case GLUT_KEY_RIGHT:
      if (!wheelflag) xt += 0.2;
      if (wheelflag) {
        angle += 5;
        xw += 0.2;
      }
      glutPostRedisplay();
      break;

    case GLUT_KEY_LEFT:
      if (!wheelflag) xt -= 0.2;
      if (wheelflag) {
        angle += 5;
        xw -= 0.2;
      }
      glutPostRedisplay();
      break;
  }
}

void myMenu(int id) {
  if (id == 1) {
    flag1 = 0;
    wheelflag = 0;
    glutPostRedisplay();
  }
  if (id == 2) {
    flag1 = 1;
    flag2 = 0;
    wheelflag = 0;
    xangle += 5.0;
    glutPostRedisplay();
  }
  if (id == 49) {
    flag1 = 0;
    flag2 = 0;
    wheelflag = 0;
    glutPostRedisplay();
  }
  if (id == 4) {
    wheelflag = 1;
    glutPostRedisplay();
  }

  if (id == 12) {
    aflag = 1;
    day = 1;
    glClearColor(1, 1, 1, 1);
    glDisable(GL_FOG);
    glutPostRedisplay();
  }
  if (id == 21) {
    flag3 = 1;
    glutPostRedisplay();
  }
  if (id == 41) {
    flag3 = 0;
    glutPostRedisplay();
  }
  if (id == 24) {
    flag3 = 2;
    glutPostRedisplay();
  }
  if (id == 22) {
    flag4 = 1;
    glutPostRedisplay();
  }
  if (id == 23) {
    flag4 = 2;
    glutPostRedisplay();
  }
  if (id == 40) {
    flag4 = 0;
    glutPostRedisplay();
  }
  if (id == 25) {
    flag5 = 1;
    ra = 0.12;
    glutPostRedisplay();
  }
  if (id == 26) {
    flag5 = 2;
    ra = 0.18;
    glutPostRedisplay();
  }
  if (id == 39) {
    flag5 = 0;
    ra = 0.08;
    glutPostRedisplay();
  }
  if (id == 27) {
    flag1 = 0;
    wheelflag = 0;
    flag2 = 0;
    flag3 = 0;
    flag4 = 0;
    flag5 = 0;
    flag6 = 0;
    flag7 = 0;
    flag8 = 0;
    flag9 = 0;
    flag10 = 0;
    flag11 = 0;
    ra = 0.08;
    r = 0.3;
    g = 0.8;
    b = 1.0;
    glutPostRedisplay();
  }
  if (id == 32) {
    flag6 = 1;
    glutPostRedisplay();
  }
  if (id == 33) {
    flag6 = 2;
    glutPostRedisplay();
  }
  if (id == 37) {
    flag6 = 0;
    glutPostRedisplay();
  }
  if (id == 35) {
    flag7 = 1;
    glutPostRedisplay();
  }
  if (id == 36) {
    flag7 = 0;
    glutPostRedisplay();
  }
  if (id == 34) {
    flag12 = 1;
    glutPostRedisplay();
  }
  if (id == 38) {
    flag12 = 0;
    glutPostRedisplay();
  }
  if (id == 42) {
    flag8 = 0;
    glutPostRedisplay();
  }
  if (id == 43) {
    flag8 = 1;
    glutPostRedisplay();
  }
  if (id == 47) {
    flag10 = 1;
    glutPostRedisplay();
  }
  if (id == 48) {
    flag11 = 1;
    glutPostRedisplay();
  }
  if (id == 44) {
    flag9 = 1;
    glutPostRedisplay();
  }
  if (id == 45) {
    flag9 = 2;
    glutPostRedisplay();
  }
  if (id == 46) {
    flag9 = 3;
    glutPostRedisplay();
  }
  if (id == 31) {
    flag3 = 0;
    flag4 = 0;
    flag5 = 0;
    flag6 = 0;
    flag7 = 0;
    flag8 = 0;
    flag9 = 0;
    flag10 = 0;
    flag11 = 0;
    ra = 0.08;
    r = 0.3;
    g = 0.8;
    b = 1.0;
    glutPostRedisplay();
  }
  if (id == 29) {
    r = 0.9;
    g = 0.0;
    b = 0.4;
    flag3 = 3;
    flag5 = 2;
    ra = 0.18;
    glutPostRedisplay();
  }

  if (id == 30) {
    r = 0.3;
    g = 1.0;
    b = 0.5;
    flag3 = 1;
    flag5 = 1;
    ra = 0.12;
    glutPostRedisplay();
  }

  if (id == 13) {
    aflag = 0;
    day = 0;
    flag2 = 2;
    glClearColor(0.1, 0.1, 0.1, 0);
    GLfloat fogcolour[4] = {0.0, 0.0, 0.0, 1.0};

    glFogfv(GL_FOG_COLOR, fogcolour);
    glFogf(GL_FOG_DENSITY, 0.35);
    glFogi(GL_FOG_MODE, GL_EXP);
    glHint(GL_FOG_HINT, GL_FASTEST);
    glEnable(GL_FOG);

    glutPostRedisplay();
  }

  if (id == 28) {
    aflag = 0;
    day = 0;
    flag2 = 2;
    glClearColor(0.1, 0.1, 0.1, 0);
    GLfloat fogcolour[4] = {0.0, 0.0, 0.0, 1.0};

    glFogfv(GL_FOG_COLOR, fogcolour);
    glFogf(GL_FOG_DENSITY, 0.1);
    glFogi(GL_FOG_MODE, GL_EXP);
    glHint(GL_FOG_HINT, GL_FASTEST);
    glEnable(GL_FOG);

    glutPostRedisplay();
  }
}

void colorMenu(int id) {
  if (id == 6) {
    r = g = 0;
    b = 1;
    glutPostRedisplay();
  }
  if (id == 7) {
    r = 0.8;
    b = g = 0;
    glutPostRedisplay();
  }
  if (id == 8) {
    g = 1;
    r = b = 0;
    glutPostRedisplay();
  }
  if (id == 9) {
    r = b = g = 0;
    glutPostRedisplay();
  }
  if (id == 10) {
    b = 0;
    r = g = 1;
    glutPostRedisplay();
  }
  if (id == 11) {
    b = r = g = .7;
    glutPostRedisplay();
  }
  if (id == 12) {
    r = g = b = 1;
    glutPostRedisplay();
  }
  if (id == 13) {
    r = 0;
    g = 255;
    b = 0;
    glutPostRedisplay();
  }
  if (id == 14) {
    r = 0;
    g = 255;
    b = 255;
    glutPostRedisplay();
  }
  if (id == 15) {
    r = 255;
    g = 0;
    b = 255;
    glutPostRedisplay();
  }
  if (id == 16) {
    r = 192;
    g = 192;
    b = 192;
    glutPostRedisplay();
  }
  if (id == 17) {
    r = 128;
    g = 0;
    b = 0;
    glutPostRedisplay();
  }
  if (id == 18) {
    r = 128;
    g = 128;
    b = 0;
    glutPostRedisplay();
  }
  if (id == 19) {
    r = 0;
    g = 128;
    b = 128;
    glutPostRedisplay();
  }
  if (id == 20) {
    r = 128;
    g = 0;
    b = 128;
    glutPostRedisplay();
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(Xsize, Ysize);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("CAR GARAGE");
  glutDisplayFunc(DrawGLScene);
  glutKeyboardFunc(NormalKey);
  glutSpecialFunc(SpecialKeyFunc);
  InitGL(Xsize, Ysize);
  int submenu = glutCreateMenu(colorMenu);
  glutAddMenuEntry("Blue", 6);
  glutAddMenuEntry("Red", 7);
  glutAddMenuEntry("Green", 8);
  glutAddMenuEntry("Black", 9);
  glutAddMenuEntry("Yellow", 10);
  glutAddMenuEntry("Grey", 11);
  glutAddMenuEntry("White", 12);
  glutAddMenuEntry("Lime", 13);
  glutAddMenuEntry("Aqua", 14);
  glutAddMenuEntry("Magenta", 15);
  glutAddMenuEntry("Silver", 16);
  glutAddMenuEntry("Maroon", 17);
  glutAddMenuEntry("Olive", 18);
  glutAddMenuEntry("Teal", 19);
  glutAddMenuEntry("Purple", 20);

  glutCreateMenu(myMenu);
  glutAddMenuEntry("Car Model Mode", 1);
  glutAddMenuEntry("Extreme Special Edition", 29);
  glutAddMenuEntry("Premium Edition", 30);
  glutAddMenuEntry("Normal Edition", 31);
  glutAddMenuEntry("Car Driving Mode", 2);
  glutAddMenuEntry("Normal Mode", 49);
  glutAddMenuEntry("Wheel Effect", 4);
  glutAddSubMenu("Car Colors", submenu);
  glutAddMenuEntry("Day Mode", 12);
  glutAddMenuEntry("Evening Mode", 28);
  glutAddMenuEntry("Night Mode", 13);
  glutAddMenuEntry("Use Single Exhaust", 42);
  glutAddMenuEntry("Use Double Exhaust", 43);
  glutAddMenuEntry("Premium Exhaust Color", 21);
  glutAddMenuEntry("Extreme Exhaust Color", 24);
  glutAddMenuEntry("Normal Exhaust Color", 41);
  glutAddMenuEntry("Premium Wheel Spokes Color", 22);
  glutAddMenuEntry("Extreme Wheel Spokes Color", 23);
  glutAddMenuEntry("Normal Wheel Spokes Color", 40);
  glutAddMenuEntry("Premium Wheels", 25);
  glutAddMenuEntry("Extreme Wheels", 26);
  glutAddMenuEntry("Normal Wheels", 39);
  glutAddMenuEntry("Add Luggage Carrier-->Dark", 32);
  glutAddMenuEntry("Add Luggage Carrier-->Light", 33);
  glutAddMenuEntry("Remove Luggage Carrier", 37);
  glutAddMenuEntry("Add WindScreen", 34);
  glutAddMenuEntry("Remove WindScreen", 38);
  glutAddMenuEntry("Use Tinted Glass For Windows", 35);
  glutAddMenuEntry("Use Normal Glass For Windows", 36);
  glutAddMenuEntry("Premium Engine Cover Color", 44);
  glutAddMenuEntry("Normal Engine Cover Color", 45);
  glutAddMenuEntry("Extreme Engine Cover Color", 46);
  glutAddMenuEntry("Radiant Model", 47);
  glutAddMenuEntry("Retro Model", 48);
  glutAddMenuEntry("Reset All My Modifications", 27);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
  return 1;
}
