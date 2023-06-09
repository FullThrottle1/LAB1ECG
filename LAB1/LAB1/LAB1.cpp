
#include <GL/freeglut.h>

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);//������� ������ �����
    glutSwapBuffers();//�������� ������� ����� � ����� ����� �������
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);//������� ��������� ������, ������� ������������ ���� ����
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);//������������� glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//��������� ����� GLUT(������� ����������� � ����� �����)
    glutInitWindowSize(1024, 768);//������� ����
    glutInitWindowPosition(100, 100);//������� ����
    glutCreateWindow("Lecture 1");//�������� ����

    InitializeGlutCallbacks();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//������������� ����, ������� ����� ����������� �� ����� ������� ������ �����

    glutMainLoop();//���� GLUT

    return 0;
}