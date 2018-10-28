#include <windows.h>	// standard Windows app include
#include <string>
#include <iostream>
#include <time.h>
#include <math.h>
//OpenGL
#include <GLFW/glfw3.h>
#include <gl/gl.h>	// standard OpenGL include
#include <gl/glu.h>	// OpenGL utilties
#include <GL/glut.h>

using namespace std;



//TESTOWE KOLKO JAPIERDOLE TU SIE RYSUJE PRAWIE ZE PISKELAMNI
void DrawCircle(float cx, float cy, float r, int num_segments)
{

	int i;
	float theta = 2 * 3.1415926 / num_segments;
	float c = cosf(theta);
	float s = sinf(theta);
	float t;
	float x = r;
	float y = 0;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < num_segments; i++)
	{

		glVertex2f(x + cx, y + cy);
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}
// TAKI PRAWIE ZE GAME LOOP 
void Display(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();                                  // Reset The Current Matrix to E
	glOrtho(0, 800, 600, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
	glLoadIdentity();  // Reset The View

	DrawCircle(200, 200, 50, 360); //Draw circle	
	DrawCircle(100, 100, 50, 360); //check

	glFlush();

}


int main(int argc, char **argv)
{
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Intro");
	glutDisplayFunc(Display); 
	glutMainLoop();
	return 0;
}