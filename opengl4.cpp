//Включить 3 источника света, задать отражающие свойства поверхностей,
//положение и цвет источников света.Рекомендуется цвет поверхностей
//сделать одинаковым, а отражающие свойства – разными.
//Вывести несколько объемных объектов.Источники света должны иметь
//различный цвет.Необходимо организовать вращение сцены, управляемое с
//клавиатуры(сцена с объектами объекты вращается, источники неподвижны)

#define ESCAPE '\033'

#include <glut.h>

#include <iostream>

#include<math.h>

GLint WinWid = 800, WinHei = 800;

double rotate_y = 0;

double rotate_x = 0;

void Timer(int)

{

	glutPostRedisplay();
	glutTimerFunc(60, Timer, 0);

}
/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)

{

	WinWid = w;
	WinHei = h;

	glViewport(0, 0, w, h);
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -600.0, 600.0);
	glMatrixMode(GL_MODELVIEW);

}

void Keyboard(int key, int x, int y) { //перемещение сцены с помощью клавиш

	if (key == GLUT_KEY_RIGHT)

		rotate_y += 5;

	else if (key == GLUT_KEY_LEFT)

		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)

		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)

		rotate_x -= 5;

	glutPostRedisplay();

}

float ambient[] = { 0.4, 0.4, 0.4, 1.0 };  //цвет фонового излучения источника света
float diffuse[] = { 0.0, 1.0, 0.0, 1.0 };//цвет рассеянного излучения источника света
float diffuse2[] = { 1.0, 0.0, 0.0, 1.0 };
float diffuse3[] = { 0.0, 0.0, 1.0, 1.0 };

float spec[] = { 1.0, 0.0, 0.0, 1.0 }; //цвет зеркального излучения источника света
float spec2[] = { 0.0, 1.0, 0.0, 1.0 };
float spec3[] = { 1.0, 1.0, 0.0, 1.0 };
float specref[] = { 1.0, 1.0, 1.0, 1.0 };

float lpos1[] = { WinWid / 2 - 100, WinHei / 2 + 100, 10.0, 1.0 }; //направление источника направленного света
float lpos2[] = { -WinWid / 2 + 100, WinHei / 2 - 100, 10.0, 1.0 };
float lpos3[] = { 0, -WinHei / 2 + 100, 10.0, 1.0 };
float black[] = { 0.0, 0.0, 0.0, 1.0 };

void Draw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);// включаем  света 
	glEnable(GL_LIGHT0); // включаем источник света 0
	glEnable(GL_LIGHT1); // включаем источник света 1
	glEnable(GL_LIGHT2); // включаем источник света 2
	glEnable(GL_COLOR_MATERIAL);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); //переменные для 0 источника света
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, lpos1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec);

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);   //переменные для 1 источника света
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, lpos2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec2);

	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient); //переменные для 2 источника света
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse3);
	glLightfv(GL_LIGHT2, GL_POSITION, lpos3);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spec3);


	// сфера
	glColor3f(0.5, 0.5, 0.1);
	glPushMatrix(); //записываем матрицу в стек
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specref);//задаем параметры материала
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 20);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glRotatef(rotate_y, 0, 1, 0);//поворот объекта по у
	glRotatef(rotate_x, 1, 0, 0);
	glTranslatef(-200, 0, 0);
	glScalef(100, 100, 100);
	glutSolidSphere(0.8, 40, 40);// сфера
	glPopMatrix();//восстанавливаем матрицу из стека

	// куб

	glPushMatrix(); //записываем матрицу в стек
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specref); //задаем параметры материала
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 70);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);//поворот объекта по х
	glRotatef(rotate_x, 1, 0, 0);
	glColor3f(0.1, 0.5, 0.1);
	glScalef(100, 100, 100);
	glutSolidCube(1);
	glPopMatrix();//восстанавливаем матрицу из стека

	// чайник
	glColor3f(0.1, 0.5, 0.1);
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specref);//задаем параметры материала
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, -10);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);//поворот объекта по у
	glRotatef(rotate_x, 1, 0, 0);//поворот объекта по х
	glTranslatef(200, 0, 0);
	glScalef(55, 55, 55);
	glutSolidTeapot(1.5);
	glPopMatrix();//восстанавливаем матрицу из стека

	glutSwapBuffers();

}

int main(int argc, char** argv)

{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WinWid, WinHei);
	glutCreateWindow("Лаба4");

	glutDisplayFunc(Draw);//отрисовка сцены
	glutReshapeFunc(Reshape);

	glutTimerFunc(60, Timer, 0);
	glutSpecialFunc(Keyboard);
	glutMainLoop();

	return 0;

}