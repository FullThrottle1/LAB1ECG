#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO;//Постоянная переменная для хранения указателя на буфер вершин

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);//Очистка буфера кадра

    glEnableVertexAttribArray(0);//Разрешаем использование атрибутов вершин
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//Привязка буфера к цели(хранит массив вершин)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//Вызов говорит как использовать данные внутри буфера(индекс, кол-во компонентов, тип компонентов, не именные, число байтов, смещение)

    glDrawArrays(GL_TRIANGLES, 0, 3);//Функция для отрисовки

    glDisableVertexAttribArray(0);//Отключение каждого атрибута вершины

    glutSwapBuffers();//Меняем буфер фоновый и буфер кадра местами
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);//Функция обратного вызова, которая отображает один кадр
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[3];
    Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

    glGenBuffers(1, &VBO);//Генерация объектов буфера
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//Привязка буфера к цели
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);//Заполнение данными
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);//Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//Настройка опций 
    glutInitWindowSize(1024, 768);//Размеры окна
    glutInitWindowPosition(100, 100);//Позиция окна на экране
    glutCreateWindow("Lecture 03");//Название окна

    InitializeGlutCallbacks();

    GLenum res = glewInit();//Инициализация GLEW и проверка на ошибки
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//Устанавливает цвет, который будет использован при очистке буфера

    CreateVertexBuffer();

    glutMainLoop();//Цикл GLUT

    return 0;
}