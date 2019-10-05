/*******************************************************
 * Homework 2: OpenGL                                  *
 * CS 148 (Summer 2016), Stanford University           *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = { 0,1,4,1 };
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
	// TODO: Your code here!
	glPushMatrix();//Push/Pop is there to make the graph pop back to 0,0,0
	glTranslated(1, 0, 0);
	glutSolidTeapot(.20);
	//
	for (int i = 0; i < 9; i++) {
		//glPushMatrix();
		glTranslated(-.2, -.6, 0);
		glRotatef(324, 0, 0, 1);
		glutSolidTeapot(.20);
	}
	glPopMatrix();
}

void problem2() {//15 cubes //scaling is off
	// TODO: Your code here!
	glPushMatrix();//Push/Pop is there to make the graph pop back to 0,0,0
	glTranslated(-1.5, 0, 0);
	glutSolidCube(.25);
	for (int i = 0; i < 14; i++) {
		//glPushMatrix();
		glTranslated(.25, .01 + (0.00047 * i), 0);//the weird scaling number is to keep the base of the staircase flat/straight
		glScaled(1, 1.07 + (.005*i), 1);
		glutSolidCube(.25);
	}
	glPopMatrix();
}

/*
Scaling:
	glTranslated(.25, .01 + (0.00115 * i), 0);
		glScaled(1, 1.07 + (.01*i), 1);
		glutSolidCube(.25);

No Scaling: 
glPushMatrix();
	glTranslated(.25, .01, 0);
	glScaled(1,1.06, 1);
	glutSolidCube(.25);
*/

void problem3() {
	// TODO: Your code here!
	glPushMatrix();//Push/Pop is there to make the graph pop back to 0,0,0
	glTranslated(-.4, 2, 0);
	for (int i = 0; i < 6; i++) {
		glTranslated(.4, -.5, 0);
		glutSolidTeapot(.2);
		for (int j = 0; j < i+1; j++) {
			glPushMatrix();
			glTranslated(-.8 * j, 0, 0);
			glutSolidTeapot(.2);
			glPopMatrix();
		}
	}
	glPopMatrix();
}

void problem4() {//A rough approximation of a UH Hand Sign with a triforce on the back
	// TODO: Your code here!

	/*
	A
	*/
	glBegin(GL_TRIANGLES);

	glVertex3f(.33, -.75, -.3);
	glVertex3f(.66, -1.25, -.3);
	glVertex3f(0, -1.25, -.3);

	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex3f(-.33, -.75, -.3);
	glVertex3f(0, -1.25, -.3);
	glVertex3f(-.66, -1.25, -.3);

	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex3f(0, -.25, -.3);
	glVertex3f(.33, -.75, -.3);
	glVertex3f(-.33, -.75, -.3);

	glEnd();//Triforce placed on the back of the hand to fulfill the manually input triangle requirement

	//Making a hand
	//Wrist
	glPushMatrix();
	glScaled(1, 2, .5);
	glTranslated(-.01, -1.25, 0 );//moving the hand because the triangles are too hard to move
	glutSolidCube(1);

		//Palm
		glPushMatrix();
		glScaled(1.5, .75, 1);
		glTranslated(-.01, 1.1, 0); 
		glutSolidCube(1);

			//Finger1
			//Joint 1
			glPushMatrix();
			glTranslated(.395, .75, 0);
			glScaled(.2, .5, 1);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

			//Joint2
			glTranslated(0, 1, 0);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

			//Joint3
			glTranslated(0, 1, 0);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

		glPopMatrix(); //back to palm
			
			//Finger2
			//Joint 1
		glPushMatrix();
			glTranslated(.15, .75, 0);
			glScaled(.2, .5, 1);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

			//Joint2
			glTranslated(0, 1, 0);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

			//Joint3
			glTranslated(0, 1, 0);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

		glPopMatrix(); //back to palm

			//Finger4: Pinky
			//Joint1
			glPushMatrix();
			glTranslated(-.395, .67, 0);
			glScaled(.2, .3, 1);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);
			//Joint2
			glTranslated(0, 1, 0);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

			//Joint3
			glTranslated(0, 1, 0);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);
			
			glPopMatrix();//back to palm

			//Finger3
			//Joint1
			glPushMatrix();
			glTranslated(-.15, .75, 0);
			glScaled(.2, .5, 1);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

			//Joint2
			glTranslated(0, 0, 1);
			glRotated(15, 1, 0, 0);
			glutSolidCube(1);
			//Joint3
			glTranslated(0, -1, 0);
			glRotated(10, 1, 0, 0);
			glutSolidCube(1);

			glPopMatrix();//back to palm

			//Thumb
			//Joint1
			glPushMatrix();
			glTranslated(.5, 0, .7);
			glScaled(.2, .5, 1);
			glRotated(20, 4, 0, 0);
			glutSolidCube(1);

			glPopMatrix();//back to palm
			//Joint2
			glTranslated(.1, .1, 1.25);
			glScaled(.6, .2, 1);
			glutSolidCube(1);



		
			
			glPopMatrix();
			glPopMatrix();

}
//scale first, then rotate to not have a distorted shape

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowWidth, windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	while (true) {
		cin.get();
	}

	return 0;
}