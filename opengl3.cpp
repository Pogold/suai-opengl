//Включить источник света, задать отражающие свойства поверхностей :
//диффузное, зеркальное отражение, цвет поверхности.
//Вывести несколько объемных объектов.Каждый из них должен иметь
//различные свойства поверхностей(доминирующее зеркальное или
//    диффузное отражение, различный цвет внешних поверхностей).

#include <glut.h>
#include <iostream>
int spin = 0;
//Инициализация
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);//включаем свет
    glEnable(GL_LIGHT1);//включаем источник свет 1
    glEnable(GL_LIGHT0);//включаем источник свет 0
    glEnable(GL_DEPTH_TEST);

}

void drawSnowMan() {  // рисуем снеговика

    glColor3f(0.0f, 1.0f, 0.3f);
    // тело снеговика
    glTranslatef(0.0f, 0.75f, 0.0f);
    glutSolidSphere(0.75f, 20, 20);
    // голова снеговика
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f, 20, 20);
    // глаза снеговика
    glPushMatrix();
   glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f, 10, 10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f, 10, 10);
    glPopMatrix();
    // нос снеговика
   glColor3f(1.0f, 0.5f, 0.5f);
    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.08f, 0.5f, 10, 2);
}

void display(void)
{
    GLfloat light_pos1[] = { -1.0,0.0,1.5,1.0 };  // переменные для источников света
    GLfloat light_pos2[] = { 1.0,0.0,1.5,1.0 };
    GLfloat position[] = { 0.0,0.0,1.5,1.0 }; //направление источника направленного света
    GLfloat white_light[] = { 0.8, 0.8, 0.8, 1.0 };//цвет рассеянного излучения источника света
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//цвет зеркального излучения источника света
    GLfloat mat_shininess[] = { 100.0 };
    GLfloat light_ambient[] = { 0.0, 0.4, 1.7, 1.0 };//цвет фонового излучения источника света

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// очищаем
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos1);// задаем позицию источника света 0
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);// задаем позицию  источника света 1

    glPushMatrix();
    glTranslated(-1.7, 0.0, 0.0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glutSolidTeapot(0.5);// чайник
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6, -1.0, 0.0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);// задаем источника света 0
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);// задаем источника света 1
    drawSnowMan();// снеговик
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, -0.2, -1.4);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);// задаем параметры материала
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);// задаем параметры материала
    glutSolidSphere(0.8, 40, 40);// сфера
    glPopMatrix();

    glFlush();
    glutSwapBuffers(); //смена буферов
}
//Изменение размеров окна
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Лаба3");
    init();

    glutDisplayFunc(display); //отрисовка сцены
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}