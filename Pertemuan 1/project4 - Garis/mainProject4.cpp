#include <GL/glut.h>

void Garis(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);   // warna putih
        glVertex3f(0.0f, 0.0f, 0.0f);  // titik awal
        glVertex3f(0.5f, 0.5f, 0.0f);  // titik akhir
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Daniel Lamganda Tua Gultom");
    glutDisplayFunc(Garis);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // background biru
    glutMainLoop();
    return 0;
}
