/*
 *  Programul arata cum se compun transformarile de rotatie si de translatie pentru desenarea obiectelor rotite sau translatate.
 *  Interactiune: left, right, up, down
 */
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"
void myinit(void);
void drawPlane(void);
void CALLBACK day1Add(void);
void CALLBACK day1Subtract(void);
void CALLBACK yea1rAdd(void);
void CALLBACK year1Subtract(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

static int year1 = 0, day1 = 0, year2 = 0, day2 = 0;

void CALLBACK day1Add(void)
{
    day1 = (day1 + 10) % 360;
}

void CALLBACK day1Subtract(void)
{
    day1 = (day1 - 10) % 360;
}

void CALLBACK yea1rAdd(void)
{
    year1 = (year1 + 5) % 360;
}

void CALLBACK year1Subtract(void)
{
    year1 = (year1 - 5) % 360;
}

void CALLBACK day2Add(void)
{
    day2 = (day2 + 10) % 360;
}

void CALLBACK day2Subtract(void)
{
    day2 = (day2 - 10) % 360;
}

void CALLBACK year2Add(void)
{
    year2 = (year2 + 5) % 360;
}

void CALLBACK year2Subtract(void)
{
    year2 = (year2 - 5) % 360;
}



void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0);
    glPushMatrix();//pentru a nu iesi obiectele din fereastra la reapelarea functiei display()

    glRotatef(30, 1.0, 1.0, 1.0);
    /*  SOARELE    */


    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    auxWireSphere(1.0);
    glPopMatrix();
    glColor3f(0, 0, 1);

    /*  Pamantul */

    glRotatef((GLfloat)year1, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef((GLfloat)day1, 0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    auxWireSphere(0.2);
    glPopMatrix();
    glColor3f(1, 1, 1);

    glRotatef((GLfloat)year2, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)day2, 0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    auxWireSphere(0.1);
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

void myinit(void) {
    glShadeModel(GL_FLAT);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}


int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow("planete");
    myinit();
    auxKeyFunc(AUX_LEFT, year1Subtract);
    auxKeyFunc(AUX_RIGHT, yea1rAdd);
    auxKeyFunc(AUX_UP, day1Add);
    auxKeyFunc(AUX_DOWN, day1Subtract);

    auxKeyFunc(AUX_LEFT, year2Subtract);
    auxKeyFunc(AUX_RIGHT, year2Add);
    auxKeyFunc(AUX_UP, day2Add);
    auxKeyFunc(AUX_DOWN, day2Subtract);

    //auxKeyFunc(AUX_Z, yearSubtract);
    // auxKeyFunc(AUX_X, yearAdd);

    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}