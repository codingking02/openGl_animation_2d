#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <math.h>
#include <stdlib.h>
#include <bits/stdc++.h>


float step = 0;
float move = 0.025;
float addx = 0;
float addy = 0;

float shiftUp = 7;
float carShift = 4;
float shiftRightRays =-3;
float shiftRightCar=2;

using std::pair;
pair<float,float> rotate(float x, float y, float turn) {

    float x2 = (x + 8) * cos(turn) - (y - 8) * sin(turn) - 8;
    float y2 = (x + 8) * sin(turn) + (y - 8) * cos(turn) + 8;

    return { x2,y2 };
}
void handle() {
    glColor3f(68.0 / 255, 47.0 / 255, 16.0 / 255);
    glBegin(GL_POLYGON);
    for (int j = 0; j <= 360; j++) {
        double angles = j * 3.14 / 180;
        glVertex2f((0.1 * cos(angles)) + 0.3, (0.2 * sin(angles)) - 7.5 + shiftUp);
    }
    glEnd();
}
void sun() {
    //255, 242, 0
    glColor3f(255.0 / 255, 242.0 / 255, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = i * 3.14 / 180;
        glVertex2f((2 * cos(angle)) - 7, (4 * sin(angle)) + 6);
    }
    glEnd();
    glFlush();
}
void car() {
    //car bottom
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    glVertex2d(-5 + step - carShift, -5);
    glVertex2d(4 + step - carShift, -5);

    glVertex2d(-5 + step - carShift, -5);
    glVertex2d(-5 + step - carShift, -7);

    glVertex2d(4 + step - carShift, -5);
    glVertex2d(4 + step - carShift, -7);

    glVertex2d(-5 + step - carShift, -7);
    glVertex2d(4 + step - carShift, -7);

    glEnd();
    //top
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    glVertex2d(-2 + step - carShift+shiftRightCar, -3);
    glVertex2d(2 + step - carShift+shiftRightCar, -3);

    glVertex2d(-2 + step - carShift+shiftRightCar, -3);
    glVertex2d(-2 + step - carShift+shiftRightCar, -5);

    glVertex2d(2 + step - carShift+shiftRightCar, -3);
    glVertex2d(2 + step - carShift+shiftRightCar, -5);

    glVertex2d(2 + step - carShift+shiftRightCar, -5);
    glVertex2d(-2 + step - carShift+shiftRightCar, -5);

    glEnd();

    // wheels
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = i * 3.14 / 180;
        glVertex2f((1 * cos(angle)) - 2 + step - carShift, (2 * sin(angle)) - 8);
    }
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = i * 3.14 / 180;
        glVertex2f((1 * cos(angle)) + 2 + step - carShift, (2 * sin(angle)) - 8);
    }
    glEnd();
}
void home() {
    //home roof
    //79, 60, 49
    glColor3f(79.0 / 255, 60.0 / 255, 49.0 / 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0 + shiftUp);
    glVertex2d(2, -5);

    glVertex2d(0, 0 + shiftUp);
    glVertex2d(-2, -5 + shiftUp);

    glVertex2d(-2, -5 + shiftUp);
    glVertex2d(2, -5 + shiftUp);
    glEnd();

    //home body
    glColor3f(233.0 / 255, 155.0 / 255, 65.0 / 255);
    glBegin(GL_POLYGON); //left side
    glVertex2d(-2, -5 + shiftUp);
    glVertex2d(-2, -9 + shiftUp);

    glVertex2d(2, -5 + shiftUp);
    glVertex2d(2, -9 + shiftUp);

    glVertex2d(2, -9 + shiftUp);
    glVertex2d(-2, -9 + shiftUp);
    glEnd();
    glColor3f(144.0 / 255, 77.0 / 255, 35.0 / 255);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, -6 + shiftUp);
    glVertex2f(0.5, -9 + shiftUp);

    glVertex2f(-0.5, -6 + shiftUp);
    glVertex2f(-0.5, -9 + shiftUp);

    glVertex2f(-0.5, -6 + shiftUp);
    glVertex2f(0.5, -6 + shiftUp);

    glVertex2f(-0.5, -9 + shiftUp);
    glVertex2f(0.5, -9 + shiftUp);
    glEnd();
}
void ground() {
    glColor3f(121.0/255,124.0/255,128.0/255);
    glBegin(GL_POLYGON);
    glVertex2d(-12, -2);
    glVertex2d(12, -2);

    glVertex2d(-12, -2);
    glVertex2d(-12, -10);

    glVertex2d(12, -2);
    glVertex2d(12, -10);

    glVertex2d(-12, -10);
    glVertex2d(12, -10);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(5);

    ground();
    home();
    handle();
    car();
    sun();


    glEnd();
    glFlush();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    step += move;
    if (step > 14 || step < 0) {
        move = -move;
    }

}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 0);
    glutInitWindowSize(1200, 800);

    glutCreateWindow("Zeyad Ahmed 20101629 Ahmed Abed 20103379");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glClearColor(102.0 / 255, 102.0 / 255, 1.0, 1.0);

    glutMainLoop();
}
