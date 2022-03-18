#include <GL/glut.h>
#include<iostream>
using namespace std;
int rx = 150, ry = 150, x = 0, y = 0;

int xCenter = 250, yCenter = 250;


void myinit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void circuloPoint()
{
	float x = 0;
	float y = ry;
	float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (1);
	float dx = 2 * (ry * ry) * x;
	float dy = 2 * (rx * rx) * y;
	glColor3ub(rand() % 10, rand() % 10, rand() % 10);
	while (dx < dy)
	{
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);
		if (p1 < 0)
		{
			x = x + 1;
			dx = 2 * (ry * ry) * x;
			p1 = p1 + dx + (ry * ry);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dx = 2 * (ry * ry) * x;
			dy = 2 * (rx * rx) * y;
			p1 = p1 + dx - dy + (ry * ry);
		}
	}
	glFlush();


	float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y
		- 1) * (y - 1) - (rx * rx) * (ry * ry);
	//glColor3ub(rand() % 255, rand() % 255, rand() % 255);

	while (y > 0)
	{
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);
		if (p2 > 0)
		{
			x = x;
			y = y - 1;
			dy = 2 * (rx * rx) * y;
			p2 = p2 - dy + (rx * rx);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			dy = dy - 2 * (rx * rx);
			dx = dx + 2 * (ry * ry);
			p2 = p2 + dx -
				dy + (rx * rx);
		}
	}
	glFlush();
}

void lineaPoint()
{
	

	
		for (x = 0; x<rx*2; x++) {
			
			setPixel(xCenter + x, yCenter - y);

	
		}
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	circuloPoint();
	lineaPoint();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("CIRCULO");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}