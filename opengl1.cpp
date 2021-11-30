// opengl1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <glut.h>

void init(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //для очистки буфера цвета
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void display(void)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON); //задает многоугольник с количеством углов равным количеству заданных вершин
	glVertex3f(0.25, 0.25, 0.0); //вершины задаются
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//режим одинарной буферизации.
	glutInitWindowSize(500, 500);//выбираем размер окна
	glutInitWindowPosition(100, 100);
	glutCreateWindow("first");

	init();
	glutDisplayFunc(display);//задает функцию рисования изображения

	glutMainLoop();

	return 0;
}

