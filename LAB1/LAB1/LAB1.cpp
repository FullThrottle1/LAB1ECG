
#include <GL/freeglut.h>

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);//Очистка буфера кадра
    glutSwapBuffers();//Поменять фоновый буфер и буфер кадра местами
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);//Функция обратного вызова, которая отрисовывает один кадр
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);//Инициализация glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//Настройка опций GLUT(Двойная буферизация и буфер цвета)
    glutInitWindowSize(1024, 768);//Размеры окна
    glutInitWindowPosition(100, 100);//Позиция окна
    glutCreateWindow("Lecture 1");//Название окна

    InitializeGlutCallbacks();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//Устанавливает цвет, который будет использован во время очистки буфера кадра

    glutMainLoop();//Цикл GLUT

    return 0;
}