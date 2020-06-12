#include <iostream>
#include <math.h> 
#include <GL/glut.h>
#include <Windows.h>

double rad, red, rid, rud, rod = 0;

const double PI = 3.141592653589793;

void garislingkaran(double radius, int garis) {
	double circle = (double)garis;
	glColor3ub(255, 255, 255);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= garis; i++) {
		float sudut = i * (2 * PI / garis);
		float x = 50 + radius * cos(sudut);
		float y = 50 + radius * sin(sudut);
		glVertex2f(x, y);
	}
	glEnd();
}

void Matahari(double radius, int garis) {
	double circle = (double)garis;
	glColor3ub(255, 255, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= garis; i++) {
		float sudut = i * (2 * PI / garis);
		float x = 50 + radius * cos(sudut);
		float y = 50 + radius * sin(sudut);
		glVertex2f(x, y);
	}
	glEnd();
}

void planet() {

	// Merkurius
	glPointSize(9);
	glBegin(GL_POINTS);
	{

		glColor3ub(192, 192, 192);
		glVertex2f(sin(rad) * 10 + 50, cos(rad) * 10 + 50);
	}glEnd();

	// Venus
	glPointSize(12);
	glBegin(GL_POINTS);
	{

		glColor3ub(211, 211, 211);
		glVertex2f(sin(rod) * 20 + 50, cos(rod) * 20 + 50);
	}glEnd();

	// Bumi
	glPointSize(13);
	glBegin(GL_POINTS);
	{
		glColor3ub(0, 0, 255);
		glVertex2f(sin(red) * 30 + 50, cos(red) * 30 + 50);
	}glEnd();

	// Mars
	glPointSize(13);
	glBegin(GL_POINTS);
	{
		glColor3ub(210, 105, 30);
		glVertex2f(sin(rid / 1.5) * 40 + 50, cos(rid / 1.5) * 40 + 50);
	}glEnd();

	glFlush();
}

void OnDisplayUpdate(int) {
	rad += 0.01f;
	red += 0.03f;
	rod += 0.02f;
	rid += 0.04f;


	std::cout << sin(rad) + 50 << std::endl;

	glutPostRedisplay();
	glutTimerFunc(17, OnDisplayUpdate, 1);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	Matahari(5.5, 50);
	garislingkaran(10, 80);
	garislingkaran(20, 80);
	garislingkaran(30, 80);
	garislingkaran(40, 80);
	planet();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("Imanuel Noval Amanda Prahara 672018145");

	gluOrtho2D(0, 100, 100, 0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_POINT_SMOOTH);

	glutTimerFunc(16, OnDisplayUpdate, 1);
	glutDisplayFunc(renderScene);
	glutMainLoop();

	return(0);
}
