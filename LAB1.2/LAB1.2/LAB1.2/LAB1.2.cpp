#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO;//Глобальная переменная для хранения указателя на буфер вершин

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);//Очистка буфера кадра

    glEnableVertexAttribArray(0);//Разрешение использования каждого атрибута вершины
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//Привязка буфера, приготавливая его для отрисовки
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//Uоворит конвейеру как воспринимать данные внутри буфера

    glDrawArrays(GL_POINTS, 0, 1);//Функция для отрисовки

    glDisableVertexAttribArray(0);//Отлкючение атрибутов вершины

    glutSwapBuffers();//Меняет фоновый буфер и буфер кадра местами
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);//Функция обратного вызова, которая отображает один кадр
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[1];//Создание массива  из одного вектора
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);//Отображается по центру окна

    glGenBuffers(1, &VBO);//Функция генерации объекта
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//Привязка указателя к названию цели
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);//Наполнение объекта данными
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);//Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//Настройка опций GLUT
    glutInitWindowSize(1024, 768);//Размеры окна
    glutInitWindowPosition(100, 100);//Позиция окна
    glutCreateWindow("Lecture 02");//Название окна

    InitializeGlutCallbacks();

    GLenum res = glewInit();//Инициализация GLEW и проверка на ошибки
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//Устанавливает цвет, который будет использован во время очистки буфера кадра

    CreateVertexBuffer();

    glutMainLoop();//Цикл GLUT

    return 0;
}
