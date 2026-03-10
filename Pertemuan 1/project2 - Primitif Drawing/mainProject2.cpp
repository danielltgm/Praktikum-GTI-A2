#include <GL/glut.h>

void Jendela(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // membersihkan layar
    glFlush();                    // memastikan semua perintah tereksekusi
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Daniel Lamganda Tua Gultom");
    
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // warna latar biru
    glutDisplayFunc(Jendela);
    glutMainLoop();
    return 0;
}
