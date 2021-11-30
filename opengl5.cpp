#include <glut.h>
#include <iostream>
#include<math.h>

GLint WinWid = 800, WinHei = 800;
int Angle = 0.0;
int Angle1 = 0.0;
int Angle2 = 0.0;
int Angle3 = 0.0;
float Scale = 1.0;

float ambient[] = { 0.4, 0.4, 0.4, 1.0 };
float diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
float diffuse2[] = { 1.0, 0.0, 0.0, 1.0 };
float diffuse3[] = { 0.0, 0.0, 1.0, 1.0 };
float spec[] = { 1.0, 0.0, 0.0, 1.0 };
float spec2[] = { 0.0, 1.0, 0.0, 1.0 };
float spec3[] = { 1.0, 1.0, 0.0, 1.0 };
float specref[] = { 1.0, 1.0, 1.0, 1.0 };
float lpos1[] = { WinWid / 2 - 100, WinHei / 2 + 100, 10.0, 1.0 };
float lpos2[] = { -WinWid / 2 + 100, WinHei / 2 - 100, 10.0, 1.0 };
float lpos3[] = { 0, -WinHei / 2 + 100, 10.0, 1.0 };
float black[] = { 0.0, 0.0, 0.0, 1.0 };

void Timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 0);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd': Angle++;
		break;
	case 'a': Angle--;
		break;
	case 's': Angle1++;
		break;
	case 'w': Angle1--;
		break;
	case 'q': Angle2++;
		break;
	case 'e': Angle2--;
		break;
	}
}

void Reshape(GLint w, GLint h)
{
	WinWid = w;
	WinHei = h;

	glViewport(0, 0, w, h);
	glClearColor(0.3, 0.7, 0.4, 0.9);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -600.0, 600.0);
	glMatrixMode(GL_MODELVIEW);

}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(Angle3, 0.1, 0.1, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_COLOR_MATERIAL);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, lpos1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec);

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, lpos2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec2);

	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse3);
	glLightfv(GL_LIGHT2, GL_POSITION, lpos3);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spec3);

	Angle3 += 1;

	glPopMatrix();

	//тор

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specref);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 70);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glRotatef(Angle, 0.0, 1.0, 0.0);
	glRotatef(Angle1, 1, 0, 0);
	glRotatef(Angle2, 0, 0, 1);
	glColor3f(1, 0.2, 0.2);
	glutSolidTorus(20, 40, 10, 20);
	glPopMatrix();

	//тетраэдр

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.3, 0.3, 0.3, 0.3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specref);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 0.9);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glRotatef(Angle, 0.0, 1.0, 0.0);
	glRotatef(Angle1, 1, 0, 0);
	glRotatef(Angle2, 0, 0, 1);
	glScalef(300, 300, 300);
	glutSolidTetrahedron();
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WinWid, WinHei);
	glutCreateWindow("Лаба 5");
	glutDisplayFunc(Draw);
	glutReshapeFunc(Reshape);
	glutTimerFunc(1, Timer, 0);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();

	return 0;

}