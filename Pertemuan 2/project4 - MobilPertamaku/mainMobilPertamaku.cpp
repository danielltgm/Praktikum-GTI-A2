#include <GL/glut.h>
#include <math.h>

void lingkaran(float x, float y, float r){
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        float sudut = i * 3.1416 / 180;
        glVertex2f(x + cos(sudut)*r, y + sin(sudut)*r);
    }
    glEnd();
}

void gambarRoda(){

    glPushMatrix();

    // Ban
    glColor3f(0,0,0);
    lingkaran(0,0,0.5);

    // Velg
    glColor3f(0.8,0.8,0.8);
    lingkaran(0,0,0.25);

    glPopMatrix();
}

void gambarMobil(){

    glPushMatrix();
    glTranslatef(0,0,0);

    // Badan mobil
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-2,0);
    glVertex2f(2,0);
    glVertex2f(2,1);
    glVertex2f(-2,1);
    glEnd();

    // Atap mobil (trapesium)
    glColor3f(0.8,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.2,1);
    glVertex2f(1.2,1);
    glVertex2f(0.8,1.8);
    glVertex2f(-0.8,1.8);
    glEnd();

    // Jendela
    glColor3f(0.5,0.8,1);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,1.05);
    glVertex2f(0.7,1.05);
    glVertex2f(0.5,1.6);
    glVertex2f(-0.5,1.6);
    glEnd();

    // Garis pemisah jendela, supaya terlihat memiliki 2 jendela
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0,1.05);
    glVertex2f(0,1.6);
    glEnd();

    // gagang pintu
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.2,0.45);
    glVertex2f(0.6,0.45);
    glVertex2f(0.6,0.55);
    glVertex2f(0.2,0.55);
    glEnd();

    // lampu depan
    glColor3f(1,1,0);
    lingkaran(2,0.5,0.2);

    // Roda depan
    glPushMatrix();
    glTranslatef(1.2,-0.2,0);
    gambarRoda();
    glPopMatrix();

    // roda belakang
    glPushMatrix();
    glTranslatef(-1.2,-0.2,0);
    gambarRoda();
    glPopMatrix();

    glPopMatrix();
}

void gambarJalan(){
	// Jalan raya
    // Jalan
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);
    glVertex2f(-20,-1);
    glVertex2f(20,-1);
    glVertex2f(20,0);
    glVertex2f(-20,0);
    glEnd();

    // Garis jalan
    glColor3f(1,1,1);
    for(int i=-20;i<20;i+=3){
        glBegin(GL_QUADS);
        glVertex2f(i,-0.55);
        glVertex2f(i+1,-0.55);
        glVertex2f(i+1,-0.45);
        glVertex2f(i,-0.45);
        glEnd();
    }
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    gambarJalan();
    gambarMobil();

    glFlush();
}

void init(){
    glClearColor(0.6,0.8,1,1);
    gluOrtho2D(-10,10,-5,5);
}

int main(int argc, char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,500);
    glutCreateWindow("Daniel Lamganda Tua Gultom");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
