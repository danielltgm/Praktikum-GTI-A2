#include <windows.h>
#include <GL/glut.h>

// Variabel rotasi global
GLfloat xRotated, yRotated, zRotated;  

// prosedur untuk menggambar kubus wireframe dengan rotasi
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -4.0);   
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glRotatef(zRotated, 0.0, 0.0, 1.0);

    glutWireCube(1.0);              // Kubus normal
    glutSwapBuffers();              // Tukar buffer untuk animasi halus
}

// prosedur untuk mengatur proyeksi perspektif saat ukuran window berubah
void Reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}

// idle untuk update sudut rotasi agar kubus berputar terus
void Idle(void)
{
    xRotated += 0.3;
    yRotated += 0.1;
    zRotated += -0.4;
    Display();
}

// inisialisasi GLUT dan jalankan loop
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   
    glutInitWindowSize(300, 300);
    glutCreateWindow("Daniel Lamganda Tua Gultom");

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);      // Mode wireframe
    xRotated = yRotated = zRotated = 0.0;           
    glClearColor(0.0, 0.0, 0.0, 0.0);               

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);                             // Animasi otomatis
    glutMainLoop();
    return 0;
}
