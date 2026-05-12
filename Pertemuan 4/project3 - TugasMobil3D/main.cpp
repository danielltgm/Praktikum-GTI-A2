#include <math.h>
#include <GL/glut.h>

// Kamera
float angle = 0.0f;
float deltaAngle = 0.0f;
float x = 0.0f;
float y = 4.0f;
float z = 18.0f;
float lx = 0.0f;
float ly = 0.0f;
float lz = -1.0f;

int deltaMove = 0;
int w, h;
float ratio;

// Lighting
const GLfloat light_ambient[]  = {0.3f,0.3f,0.3f,1.0f};
const GLfloat light_diffuse[]  = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[] = {0.0f,15.0f,10.0f,1.0f};

// Reshape
void Reshape(int w1, int h1){
    if(h1 == 0)
        h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

// Kamera
void orientMe(float ang){
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(
        x,y,z,
        x+lx,y+ly,z+lz,
        0.0f,1.0f,0.0f
    );
}

void moveMeFlat(int i){
    x = x + i*(lx)*0.25f;
    z = z + i*(lz)*0.25f;
    glLoadIdentity();
    gluLookAt(
        x,y,z,
        x+lx,y+ly,z+lz,
        0.0f,1.0f,0.0f
    );
}

// Grid
void Grid(){
    float i;
    glDisable(GL_LIGHTING);
    glColor3f(0.4f,0.4f,0.4f);
    glBegin(GL_LINES);
    for(i=-50;i<=50;i+=1){
        glVertex3f(i,0,-50);
        glVertex3f(i,0,50);

        glVertex3f(-50,0,i);
        glVertex3f(50,0,i);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

// Jalan
void jalan(){
    glDisable(GL_LIGHTING);
    glColor3f(0.1f,0.1f,0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-50,0.01f,-5);
    glVertex3f(50,0.01f,-5);
    glVertex3f(50,0.01f,5);
    glVertex3f(-50,0.01f,5);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);

    for(float i=-50;i<50;i+=5){
        glBegin(GL_QUADS);

        glVertex3f(i,0.02f,-0.2f);
        glVertex3f(i+2,0.02f,-0.2f);
        glVertex3f(i+2,0.02f,0.2f);
        glVertex3f(i,0.02f,0.2f);

        glEnd();
    }

    glEnable(GL_LIGHTING);
}

// Roda
void roda(){
    glPushMatrix();

    glColor3f(0.05f,0.05f,0.05f);
    glScalef(1.0f,1.0f,0.5f);
    glutSolidTorus(0.2,0.5,20,20);

    glPopMatrix();
}

// Body mobil
void badanMobil(){
    // bawah
    glPushMatrix();
    glColor3f(0.0f,0.3f,1.0f);
    glScalef(5.0f,1.2f,2.2f);
    glutSolidCube(1);
    glPopMatrix();

    // atas
    glPushMatrix();
    glTranslatef(-0.2f,1.0f,0.0f);
    glColor3f(0.0f,0.5f,1.0f);
    glScalef(2.8f,1.0f,2.0f);

    glutSolidCube(1);
    glPopMatrix();

    // spoiler belakang
    glPushMatrix();
    glTranslatef(2.1f,1.2f,0.0f);
    glColor3f(0.1f,0.1f,0.1f);
    glScalef(0.2f,0.5f,2.0f);
    glutSolidCube(1);

    glPopMatrix();

    // atap spoiler
    glPushMatrix();
    glTranslatef(2.4f,1.5f,0.0f);
    glColor3f(0.1f,0.1f,0.1f);
    glScalef(1.2f,0.1f,2.0f);
    glutSolidCube(1);
    glPopMatrix();
}

// Jendela
void jendela(){
    glColor3f(0.2f,0.8f,1.0f);

    // kiri
    glPushMatrix();
    glTranslatef(-0.2f,1.0f,1.11f);
    glScalef(2.0f,0.7f,0.05f);
    glutSolidCube(1);
    glPopMatrix();

    // kanan
    glPushMatrix();
    glTranslatef(-0.2f,1.0f,-1.11f);
    glScalef(2.0f,0.7f,0.05f);
    glutSolidCube(1);
    glPopMatrix();
}

// Lampu
void lampu(){
    // depan kiri
    glPushMatrix();
    glTranslatef(-2.6f,0.0f,0.8f);
    glColor3fz1.0f,1.0f,0.0f);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    // depan kanan
    glPushMatrix();
    glTranslatef(-2.6f,0.0f,-0.8f);
    glColor3f(1.0f,1.0f,0.0f);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    // belakang kiri
    glPushMatrix();
    glTranslatef(2.6f,0.0f,0.8f);
    glColor3f(1.0f,0.0f,0.0f);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    // belakang kanan
    glPushMatrix();
    glTranslatef(2.6f,0.0f,-0.8f);
    glColor3f(1.0f,0.0f,0.0f);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
}

// Mobil
void mobil3D(){
    glPushMatrix();
    glTranslatef(0.0f,1.0f,0.0f);
    badanMobil();
    jendela();
    lampu();

    // roda depan kiri
    glPushMatrix();
    glTranslatef(-1.8f,-0.8f,1.3f);
    roda();
    glPopMatrix();

    // roda depan kanan
    glPushMatrix();
    glTranslatef(-1.8f,-0.8f,-1.3f);
    roda();
    glPopMatrix();

    // roda belakang kiri
    glPushMatrix();
    glTranslatef(1.8f,-0.8f,1.3f);
    roda();
    glPopMatrix();

    // roda belakang kanan
    glPushMatrix();
    glTranslatef(1.8f,-0.8f,-1.3f);
    roda();
    glPopMatrix();
    glPopMatrix();
}

// Pohon
void pohon(float px, float pz){
    glPushMatrix();
    glTranslatef(px,0,pz);

    // batang
    glPushMatrix();
    glColor3f(0.5f,0.3f,0.1f);
    glTranslatef(0,1,0);
    glScalef(0.5f,2.0f,0.5f);
    glutSolidCube(1);
    glPopMatrix();

    // daun
    glPushMatrix();
    glColor3f(0.0f,0.7f,0.0f);
    glTranslatef(0,3,0);
    glutSolidSphere(1.2,20,20);
    glPopMatrix();
    glPopMatrix();
}

// Display
void display(){
    if(deltaMove)
        moveMeFlat(deltaMove);
    if(deltaAngle){
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(
        x,y,z,
        x+lx,y+ly,z+lz,
        0.0f,1.0f,0.0f
    );
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    Grid();
    jalan();
    mobil3D();

    pohon(-8,-8);
    pohon(8,-8);
    pohon(-8,8);
    pohon(8,8);

    glutSwapBuffers();
}

// Keyboard
void pressKey(int key, int xx, int yy){
    switch(key){
        case GLUT_KEY_LEFT :
            deltaAngle = -0.01f;
            break;
        case GLUT_KEY_RIGHT :
            deltaAngle = 0.01f;
            break;
        case GLUT_KEY_UP :
            deltaMove = 1;
            break;
        case GLUT_KEY_DOWN :
            deltaMove = -1;
            break;
    }
}

void releaseKey(int key, int x, int y){
    switch(key){
        case GLUT_KEY_LEFT :
        case GLUT_KEY_RIGHT :
            deltaAngle = 0.0f;
            break;
        case GLUT_KEY_UP :
        case GLUT_KEY_DOWN :
            deltaMove = 0;
            break;
    }
}

// Lighting
void lighting(){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

// Init
void init(){
    glClearColor(0.5f,0.8f,1.0f,1.0f);
    glShadeModel(GL_SMOOTH);
    lighting();
}

// Main
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    
    glutCreateWindow("Daniel - TugasMobil3D");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutReshapeFunc(Reshape);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutIgnoreKeyRepeat(1);
    init();
    glutMainLoop();
    return 0;
}
