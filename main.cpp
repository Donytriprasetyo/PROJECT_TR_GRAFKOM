#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#define M_PI 3.14

float a = 0;
float b = 0;
float c = 0;
float d = 0;
float e = 0;
float f = 0;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void init(void){
    glClearColor(0, 1, 254/255.f, 0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glLineWidth(4);
    glMatrixMode(GL_MODELVIEW);
}

void drawCylinder(float rbase,float rtop,float height){
    float i;
    glPushMatrix();
    glTranslatef(0,0.0,-rbase/4);
    for(i=0;i<=height;i+=rbase/25)
    {
        glTranslatef(0,0.0,rbase/25);
        glutSolidTorus(3,rbase-((i*(rbase-rtop))/height),20,16);
    }
    glTranslatef(0,0.0,rbase/4);
    glPopMatrix();
}

void lingkaran(float TITIK_LAYAR_X, float TITIK_LAYAR_Y, float LEBAR_X, float LEBAR_Y, float JUMLAH_SUDUT, float ROTASI){
    GLfloat derajat = (360.0f / JUMLAH_SUDUT) * M_PI / 180.0f;
    glBegin(GL_TRIANGLE_FAN);
        GLfloat sudut = 0.0f - ROTASI;
        for (int _k = 0; _k < JUMLAH_SUDUT; ++_k)
        {
            glVertex2f(TITIK_LAYAR_X + (LEBAR_X * cos(sudut)), TITIK_LAYAR_Y + (LEBAR_Y * sin(sudut)));
            sudut += derajat;
        }
    glEnd();
}

void lingkaran2(float TITIK_LAYAR_X, float TITIK_LAYAR_Y, float LEBAR_X, float LEBAR_Y, float JUMLAH_SUDUT, float ROTASI){
    GLfloat derajat = (360.0f / JUMLAH_SUDUT) * M_PI / 180.0f;
    glBegin(GL_LINE_STRIP);
        GLfloat sudut = 0.0f - ROTASI;
        for (int _k = 0; _k < JUMLAH_SUDUT; ++_k)
        {
            glVertex2f(TITIK_LAYAR_X + (LEBAR_X * cos(sudut)), TITIK_LAYAR_Y + (LEBAR_Y * sin(sudut)));
            sudut += derajat;
        }
    glEnd();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void idle() {
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        f = f + 3;
        if (f > 360) f = 0;
        glutPostRedisplay();
        break;
    case '3':
        f = f - 3;
        if (f > 360) f = 0;
        glutPostRedisplay();
        break;
    case '2':
        d = d + 3;
        if (d > 360) d = 0;
        glutPostRedisplay();
        break;
    case '8':
        d = d - 3;
        if (d > 360) d = 0;
        glutPostRedisplay();
        break;
    case '4':
        e = e + 3;
        if (e > 360) e = 0;
        glutPostRedisplay();
        break;
    case '6':
        e = e - 3;
        if (e > 360) e = 0;
        glutPostRedisplay();
        break;
    case 'w':
        c = c + 3;
        glutPostRedisplay();
        break;
    case 's':
        c = c - 3;
        glutPostRedisplay();
        break;
    case '7':
        b = b + 3;
        glutPostRedisplay();
        break;
    case '9':
        b = b - 3;
        glutPostRedisplay();
        break;
    case 'a':
        a = a - 3;
        glutPostRedisplay();
        break;
    case 'd':
        a = a + 3;
        glutPostRedisplay();
        break;
    }
}

void lapanganutama(){
        //Lapangan Main-FULL
    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(0, -0.5, 0);
    glScalef(27, 0.3, 19.5);
    glutSolidCube(5);
    glPopMatrix();
    //Lapngan Main-HIJAU
    glPushMatrix();
    glColor3f(50/255.f, 205/255.f, 50/255.f);
    glTranslatef(0, 0, 0);
    glScalef(20.5, 0.3, 13);
    glutSolidCube(5);
    glPopMatrix();
    //Garis Utama MAIN-Putih
        //Line Utama
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-52.5, 0.3, -34);
    glVertex3f(52.5, 0.3, -34);
    glVertex3f(52.5, 0.3, 34);
    glVertex3f(-52.5, 0.3, 34);
    glEnd();
        //Line MID
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 0.5, 0);
    glScalef(0.25, 0.25, 13.5);
    glutSolidCube(5);
    glPopMatrix();
        //Line Gawang 1
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(-52, 0.8, -20.15);
    glVertex3f(-36, 0.8, -20.15);
    glVertex3f(-36, 0.8, 20.15);
    glVertex3f(-52, 0.8, 20.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(-52, 0.8, -9.15);
    glVertex3f(-47, 0.8, -9.15);
    glVertex3f(-47, 0.8, 9.5);
    glVertex3f(-52, 0.8, 9.5);
    glEnd();
    glPopMatrix();
        //Line Gawang 2
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(52, 0.8, -20.15);
    glVertex3f(36, 0.8, -20.15);
    glVertex3f(36, 0.8, 20.15);
    glVertex3f(52, 0.8, 20.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(52, 0.8, -9.15);
    glVertex3f(47, 0.8, -9.15);
    glVertex3f(47, 0.8, 9.5);
    glVertex3f(52, 0.8, 9.5);
    glEnd();
    glPopMatrix();
    //Lingkaran MAIN+Penalty
    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 0, 1);
    lingkaran(0, 0, 1.5, 1.5, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0 ,0);
    glTranslatef(0, 0, 2);
    lingkaran(-41.5, 0, 1, 1, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 31, 0 ,0);
    glTranslatef(0, 0, 2);
    lingkaran(41.5, 0, 1, 1, 1000, 120);
    glPopMatrix();
    //Garis Lingkaran 1-4+Main Putih
    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 0, 1);
    lingkaran2(0, 0, 9.15, 9.15, 1000, 120);
    glPopMatrix();
        //SIDE LANE-CORNER
    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 0, 1);
    lingkaran2(-52, -33.5, 4, 4, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 0, 1);
    lingkaran2(52, 33.5, 4, 4, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 0, 1);
    lingkaran2(-52, 33.5, 4, 4, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 0, 1);
    lingkaran2(52, -33.5, 4, 4, 1000, 120);
    glPopMatrix();
    //Closing 1/4 Circle
        //1
    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(-53.5, 0.15, -37.5);
    glScalef(2.5, 0.5, 1.5);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(-56, 0.15, -35.5);
    glScalef(1.5, 0.5, 2.5);
    glutSolidCube(5);
    glPopMatrix();
        //2
    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(-53.5, 0.15, 37.5);
    glScalef(2.5, 0.5, 1.5);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(-56, 0.15, 35.5);
    glScalef(1.5, 0.5, 2.5);
    glutSolidCube(5);
    glPopMatrix();
        //3
    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(53.5, 0.15, -37.5);
    glScalef(2.5, 0.5, 1.5);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(56, 0.15, -35.5);
    glScalef(1.5, 0.5, 2.5);
    glutSolidCube(5);
    glPopMatrix();
        //4
    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(53.5, 0.15, 37.5);
    glScalef(2.5, 0.5, 1.5);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(56, 0.15, 35.5);
    glScalef(1.5, 0.5, 2.5);
    glutSolidCube(5);
    glPopMatrix();
        //1/2 Lingkaran 1-2
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 1, 0);
    glRotatef(270, 1, 0, 0);
    lingkaran2(39.5, 0, 6, 9, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(50/255.f, 205/255.f, 50/255.f);
    glTranslatef(41.35, -0.75, 0);
    glScalef(1.9, 1, 4);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 1, 0);
    glRotatef(270, 1, 0, 0);
    lingkaran2(-39.5, 0, 6, 9, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(50/255.f, 205/255.f, 50/255.f);
    glTranslatef(-41.35, -0.75, 0);
    glScalef(1.9, 1, 4);
    glutSolidCube(5);
    glPopMatrix();

    //garis belakang bangku cadangan
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 0.5, 49);
    glScalef(27, 0.25, 0.25);
    glutSolidCube(5);
    glPopMatrix();
    //Gawang 1
        //TIANG UTAMA
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-52, 2.8, -4.15);
    glScalef(0.15, 2.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-52, 6.5, 0);
    glScalef(0.15, 0.25, 2.75);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-52, 2.8, 4.15);
    glScalef(0.15, 2.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
        //Tiang Kecil
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-54.5, 3, -4.15);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(30, 0, 0, 2);
    glTranslatef(-43, 32, -4.15);
    glScalef(1.15, 0.15, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-54.5, 5, 0);
    glScalef(0.15, 0.15, 2.75);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(30, 0, 0, 2);
    glTranslatef(-43, 32, 4.15);
    glScalef(1.15, 0.15, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-54.5, 3, 4.15);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
    //Gawang 2
        //Tiang Utama
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(52, 2.8, -4.15);
    glScalef(0.15, 2.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(52, 6.5, 0);
    glScalef(0.15, 0.25, 2.75);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(52, 2.8, 4.15);
    glScalef(0.15, 2.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
        //Tiang Kecil
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(54.5, 3, -4.15);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(30, 0, 0, -2);
    glTranslatef(43, 32, -4.15);
    glScalef(1.15, 0.15, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(54.5, 5, 0);
    glScalef(0.15, 0.15, 2.75);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(30, 0, 0, -2);
    glTranslatef(43, 32, 4.15);
    glScalef(1.15, 0.15, 0.15);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(54.5, 3, 4.15);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
    //CONER 1-4
        //Corner 1
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-51.75, 2, -32.75);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
        //Corner 2
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-51.75, 2, 32.75);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
        //Corner 3
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(51.75, 2, -32.75);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
        //Corner 4
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(51.75, 2, 32.75);
    glScalef(0.15, 1.75, 0.15);
    glutSolidCube(3);
    glPopMatrix();
}

void sponsor(){
    //kanan panjang
    glPushMatrix();
    glTranslatef(0,2.51,-43);
    glScalef(38,1,0.3);
    glColor3f(0.9,0.9,0.9);
    glutSolidCube(2);
    glPopMatrix();

    //atas
    glPushMatrix();
    glTranslatef(-60,2.51,-18);
    glScalef(0.3,1,13);
    glColor3f(1.0,1.0,1.0);
    glutSolidCube(2);
    glPopMatrix();

    //bawah
    glPushMatrix();
    glTranslatef(60,2.51,-18);
    glScalef(0.3,1,13);
    glColor3f(1.0,1.0,1.0);
    glutSolidCube(2);
    glPopMatrix();
}

void tribun1(){

    //tribun
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(-67.5,1.6,0);
    glScalef(0.3,1.5,48.7);
    glutSolidCube(2);
    glPopMatrix();

    //tibun miring
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-95.5, 0+10, -49);
    glVertex3f(-67.5, 0, -49);
    glVertex3f(-67.5, 0, 49);
    glVertex3f(-95.5, 0+10, 49);
    glEnd();

    //tribun segitiga
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-95.5,10,-60);
    glVertex3f(-95.5,10,-49);
    glVertex3f(-67.5,0,-49);
    glVertex3f(-67.5,0,-51);
    glEnd();

    //tribun naik
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-95.5, 5+15, -60);
    glVertex3f(-95.5, 10, -60);
    glVertex3f(-95.5, 10, 49);
    glVertex3f(-95.5, 5+15, 49);
    glEnd();

    //tribun datar
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-98.5, 5+15, -60);
    glVertex3f(-90.5, 5+15, -60);
    glVertex3f(-90.5, 5+15, 49);
    glVertex3f(-98.5, 5+15, 49);
    glEnd();

    //pagar tribun1
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(-90.8,21.51,-10.5);
    glScalef(0.3,1.5,59.60);
    glutSolidCube(2);
    glPopMatrix();

    //penyambung pagar tribun besar 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-90.5, 20, 49);
    glVertex3f(-90.5, 23, 49);
    glVertex3f(-54, 23, 85.2);
    glVertex3f(-54, 20, 85.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-91, 20, 49.3);
    glVertex3f(-91, 23, 49.3);
    glVertex3f(-54.5, 23, 85.4);
    glVertex3f(-54.5, 20, 85.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-90.5, 20.1, 49);
    glVertex3f(-91, 20.1, 49.3);
    glVertex3f(-54.5, 20.1, 85.5);
    glVertex3f(-54, 20.1, 85.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-90.5, 23, 49);
    glVertex3f(-91, 23, 49.3);
    glVertex3f(-54.5, 23, 85.5);
    glVertex3f(-54, 23, 85.2);
    glEnd();

    //penyambung pagar tribun besar 2
    //sambungan 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-90.5, 20, -70);
    glVertex3f(-90.5, 23, -70);
    glVertex3f(-80, 23, -75);
    glVertex3f(-80, 20, -75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-91.1, 20, -70.5);
    glVertex3f(-91.1, 23, -70.5);
    glVertex3f(-80, 23, -75.5);
    glVertex3f(-80, 20, -75.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-90.5, 23, -70);
    glVertex3f(-91.1, 23, -70.5);
    glVertex3f(-80, 23, -75.5);
    glVertex3f(-80, 23, -75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-90.5, 20, -70);
    glVertex3f(-91.1, 20, -70.5);
    glVertex3f(-80, 20, -75.5);
    glVertex3f(-80, 20, -75);
    glEnd();

    //sambungan 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-80, 20, -75);
    glVertex3f(-80, 23, -75);
    glVertex3f(-60, 23, -77);
    glVertex3f(-60, 20, -77);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-80, 20, -75.5);
    glVertex3f(-80, 23, -75.5);
    glVertex3f(-60, 23, -77.2);
    glVertex3f(-60, 20, -77.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-80, 23, -75.5);
    glVertex3f(-80, 23, -75);
    glVertex3f(-60, 23, -77);
    glVertex3f(-60, 23, -77.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-80, 20, -75.5);
    glVertex3f(-80, 20, -75);
    glVertex3f(-60, 20, -77);
    glVertex3f(-60, 20, -77.2);
    glEnd();

    //tribun miring atas
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-130.5, 10+25, -60);
    glVertex3f(-98.5, 15+5, -60);
    glVertex3f(-98.5, 15+5, 49);
    glVertex3f(-130.5, 10+25, 49);
    glEnd();

    //tribunmiring1
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1.0);
    glVertex3f(-132.5, 10+27, -75); //atas kanan
    glVertex3f(-90.5, 15+5, -70); // bawah kanan
    glVertex3f(-98.5, 15+5, -60); // bawah kiri
    glVertex3f(-134.5, 10+27, -60); //atas kiri
    glEnd();

    //tribunmiring2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-136.5, 10+29, -90);
    glVertex3f(-80.5, 15+5, -75);
    glVertex3f(-90.5, 15+5, -70);
    glVertex3f(-132.5, 10+27, -75);
    glEnd();

    //tribunmiring3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-60.5, 15+5, -77);
    glVertex3f(-60.5, 10+30, -110);
    glVertex3f(-136.5, 10+29, -90);
    glVertex3f(-80.5, 15+5, -75);
    glEnd();

    //alastribunmiring1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1, 1.0);
    glVertex3f(-90.5, 5+15, -60);
    glVertex3f(-98.5, 5+15, -60);
    glVertex3f(-98.5, 5+15, -75);
    glVertex3f(-90.5, 5+15, -70);
    glEnd();

    //tribun naik atas
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-130.5, 5+15, -49);
    glVertex3f(-85.5, 5+15, -49);
    glVertex3f(-85.5, 5+15, 49);
    glVertex3f(-98.5, 5+15, 49);
    glEnd();

    //tribun belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-130.5, 10+25, -49);
    glVertex3f(-98.5, 15+5, -49);
    glVertex3f(-98.5, 15+5, 49);
    glVertex3f(-130.5, 10+25, 49);
    glEnd();

    //tembok tribun
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-130.5, 10+25, -60);
    glVertex3f(-130.5, 50+5, -60);
    glVertex3f(-130.5, 50+5, 49);
    glVertex3f(-130.5, 10+25, 49);
    glEnd();

    //segitigapenutuptribun
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 1);
    glVertex3f(-100.5, 0, -61); //atas kanan
    glVertex3f(-100.5, 10, -61); // bawah kanan
    glVertex3f(-67, 0, -51); // bawah kiri
    glEnd();

    //tembok
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-90.5, 0, -70); //atas kanan
    glVertex3f(-90.5, 15+5, -70); // bawah kanan
    glVertex3f(-95.5, 15+5, -60); // bawah kiri
    glVertex3f(-95.5, 0, -60); //atas kiri
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-80.5, 0, -75);
    glVertex3f(-80.5, 15+5, -75);
    glVertex3f(-90.5, 15+5, -70);
    glVertex3f(-90.5, 0, -70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-60.5, 15+5, -85);
    glVertex3f(-60.5, 0, -85);
    glVertex3f(-80.5, 0, -75);
    glVertex3f(-80.5, 15+5, -75);
    glEnd();

    //tribunsambungan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1, 1.0);
    glVertex3f(-90.5, 20, 49);
    glVertex3f(-95.5, 20, 49);
    glVertex3f(-53.5, 20, 90);
    glVertex3f(-54, 20, 85.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1, 1.0);
    glVertex3f(-98.5, 20, 46);
    glVertex3f(-125.5, 20+11, 45);
    glVertex3f(-53.5, 20+20,108);
    glVertex3f(-53.5, 20, 90);
    glEnd();

    //temboksambungan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1, 1.0);
    glVertex3f(-90.5, 20, 49);
    glVertex3f(-98.5, 0, 49);
    glVertex3f(-53.5, 0, 90);
    glVertex3f(-54, 20, 85.2);
    glEnd();
}

void tribun2(){
    //tribun2
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(67.5,1.6,0);
    glScalef(0.3,1.5,48.7);
    glutSolidCube(2);
    glPopMatrix();

    //tibun miring
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(95.5, 0+10, -49);
    glVertex3f(67.5, 0, -49);
    glVertex3f(67.5, 0, 49);
    glVertex3f(95.5, 0+10, 49);
    glEnd();

    //tribun naik 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(95.5, 5+15, -86);
    glVertex3f(95.5, 0, -86);
    glVertex3f(95.5, 0, 49);
    glVertex3f(95.5, 5+15, 49);
    glEnd();

    //tribun datar
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(98.5, 5+15, -60);
    glVertex3f(90.5, 5+15, -60);
    glVertex3f(90.5, 5+15, 49);
    glVertex3f(98.5, 5+15, 49);
    glEnd();

    //penyambung pagar tribun besar 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.7, 20, -47.8);
    glVertex3f(90.7, 23, -47.8);
    glVertex3f(60.8, 23, -77);
    glVertex3f(60.8, 20, -77);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(91.2, 20, -48.3);
    glVertex3f(91.2, 23, -48.3);
    glVertex3f(61.4, 23, -77.5);
    glVertex3f(61.4, 20, -77.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.7, 23, -47.8);
    glVertex3f(91.2, 23, -48.3);
    glVertex3f(61.4, 23, -77.5);
    glVertex3f(60.8, 23, -77);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.7, 20, -47.8);
    glVertex3f(91.2, 20, -48.3);
    glVertex3f(61.4, 20, -77.5);
    glVertex3f(60.8, 20, -77);
    glEnd();

    //penyambung pagar tribun besar 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.5, 20, 49);
    glVertex3f(90.5, 23, 49);
    glVertex3f(54, 23, 85.2);
    glVertex3f(54, 20, 85.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(91, 20, 49.3);
    glVertex3f(91, 23, 49.3);
    glVertex3f(54.5, 23, 85.4);
    glVertex3f(54.5, 20, 85.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.5, 20.1, 49);
    glVertex3f(91, 20.1, 49.3);
    glVertex3f(54.5, 20.1, 85.5);
    glVertex3f(54, 20.1, 85.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.5, 23, 49);
    glVertex3f(91, 23, 49.3);
    glVertex3f(54.5, 23, 85.5);
    glVertex3f(54, 23, 85.2);
    glEnd();

    //tribunsambung
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, .0);
    glVertex3f(120.5, 30, -48.8);
    glVertex3f(90, 20, -49);
    glVertex3f(61, 20, -77);
    glVertex3f(61, 36, -100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(98.5, 20, -60);
    glVertex3f(90.5, 20, -60);
    glVertex3f(61, 20, -79);
    glEnd();

    //pagar tribun2
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(90.8,21.51,1);
    glScalef(0.3,1.5,49);
    glutSolidCube(2);
    glPopMatrix();

    //tribun miring atas 2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(130.5, 10+25, -49);
    glVertex3f(97, 15+7, -49);
    glVertex3f(98.5, 15+5, 49);
    glVertex3f(130.5, 10+25, 49);
    glEnd();

    //tembok tribun 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(130.5, 10+25, -50);
    glVertex3f(130.5, 50+5, -50);
    glVertex3f(130.5, 50+5, 49);
    glVertex3f(130.5, 10+25, 49);
    glEnd();

    //tembok
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(98.5, 0, 49);
    glVertex3f(98.5, 20, 49);
    glVertex3f(54, 20, 89);
    glVertex3f(54, 0, 89);
    glEnd();
}

void ataptribun1(){
    //atap tribun
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(-101.5,56,-5);
    glScalef(29,1,49);
    glutSolidCube(2);
    glPopMatrix();
    //Tiang Utama 1-BIRU
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-133, 45, -52.5);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 2-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-133, 45, -41.05);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 3-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-133, 45, -30.6);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 4-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-133, 45, -20.15);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 5-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-133, 45, -9.7);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 6-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-133, 45, 0.75);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 7-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-133, 45, 11.2);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 8-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-133, 45, 21.65);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 9-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-133, 45, 32.1);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 10-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-133, 45, 42.5);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
}

void ataptribun2(){
    //atap tribun
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(101.5,56,6);
    glScalef(29,1,55);
    glutSolidCube(2);
    glPopMatrix();
    //Sambung Kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(120.5, 57, -49);
    glVertex3f(73, 57, -49);
    glVertex3f(68, 57, -66);
    glVertex3f(123, 57, -62);
    glEnd();
    //Sambung Kanan Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(123, 57, -62);
    glVertex3f(68, 57, -66);
    glVertex3f(122, 57, -70);
    glEnd();
    //Sambung Kanan Quads
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(122, 57, -70);
    glVertex3f(68, 57, -66);
    glVertex3f(59, 57, -80);
    glVertex3f(117, 57, -82);
    glEnd();
    //Sambung Kanan Quad-2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(117, 57, -82);
    glVertex3f(59, 57, -80);
    glVertex3f(61, 57, -100);
    glVertex3f(108, 57, -100);
    glEnd();

    //Tiang Utama 1-BIRU
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(133, 45, -47.5);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 2-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(133, 45, -36.05);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 3-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(133, 45, -25.6);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 4-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(133, 45, -15.15);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 5-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(133, 45, -4.7);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 6-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(133, 45, 5.75);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 7-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(133, 45, 16.2);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 8-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(133, 45, 26.65);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 9-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(133, 45, 37.1);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 10-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(133, 45, 47.5);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 11-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(133, 45, 57.95);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();

}

void ataptribunbesar1(){
    //Atap Tribun
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(5,56,86);
    glScalef(68,1,25);
    glutSolidCube(2);
    glPopMatrix();
    //Sambung Kiri-Kecil 1
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-63, 57, 105);
    glVertex3f(-63, 57, 61);
    glVertex3f(-66, 57, 61);
    glVertex3f(-73, 57, 105);
    glEnd();
    //Sambung Kiri-Kecil 2
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-120, 57, 43);
    glVertex3f(-72, 57, 43);
    glVertex3f(-72, 57, 53);
    glVertex3f(-120, 57, 60);
    glEnd();
    //Sambung Kiri-Kecil 3
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-132.5, 57, 43);
    glVertex3f(-120, 57, 43);
    glVertex3f(-120, 57, 50);
    glVertex3f(-132.5, 57, 50);
    glEnd();
    //Sambung Kiri-BESAR
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-66, 57, 61);
    glVertex3f(-72, 57, 53);
    glVertex3f(-120, 57, 60);
    glVertex3f(-73, 57, 105);
    glEnd();

    //Kanan Kecil
    //1
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(130.5, 57, 61);
    glVertex3f(73, 57, 61);
    glVertex3f(126.5, 57, 75);
    glEnd();
    //2
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(126.5, 57, 75);
    glVertex3f(73, 57, 61);
    glVertex3f(119, 57, 88);
    glEnd();
    //3
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(119, 57, 88);
    glVertex3f(73, 57, 61);
    glVertex3f(110, 57, 101);
    glEnd();
    //4
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(110, 57, 101);
    glVertex3f(73, 57, 61);
    glVertex3f(102.5, 57, 105);
    glEnd();
    //5
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(102.5, 57, 105);
    glVertex3f(73, 57, 61);
    glVertex3f(90, 57, 108.5);
    glEnd();
    //6
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(90, 57, 108.5);
    glVertex3f(73, 57, 61);
    glVertex3f(73, 57, 111);
    glEnd();

    //TIANG PENYANGGA
    //Tiang Utama 1-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-61.55, 45, 113);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 2-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-51.55, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 3-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-41.55, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 4-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-31.55, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 5-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-21.55, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 6-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-16.55, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 7-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-11.55, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 8-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-1.55, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 9-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(8.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 10-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(18.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 11-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(23.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 12-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(28.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 13-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(38.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 14-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(48.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 15-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(58.45, 45, 113);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 16-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(68.45, 45, 113);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 17-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(78.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 18-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(88.45, 45, 110);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 18-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(105.95, 45, 105);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 20-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(120, 45, 90);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 21-Biru
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(128.5, 45, 75);
    glScalef(1, 25, 0.75);
    glutSolidCube(3);
    glPopMatrix();

}

void tribunbesar1(){

    //alas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(67.5, 0, 49);
    glVertex3f(67.5, 0, 89);
    glVertex3f(-67.5, 0, 89);
    glVertex3f(-67.5, 0, 49);
    glEnd();

    //tribunbawah1
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-35, 0, 59);
    glVertex3f(-35, 10, 89);
    glVertex3f(-54, 10, 89);
    glVertex3f(-54, 0, 59);
    glEnd();

    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-54,10,89);
    glVertex3f(-54,0,59);
    glVertex3f(-64,0,89);
    glEnd();

    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-35,10,89);
    glVertex3f(-35,0,59);
    glVertex3f(-35,0,89);
    glEnd();

    //tribunbawah2
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-4, 0, 59);
    glVertex3f(-4, 10, 89);
    glVertex3f(-30, 10, 89);
    glVertex3f(-30, 0, 59);
    glEnd();

    //kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-30,10,89);
    glVertex3f(-30,0,59);
    glVertex3f(-30,0,89);
    glEnd();

    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-4,10,89);
    glVertex3f(-4,0,59);
    glVertex3f(-4,0,89);
    glEnd();

    //tribunbawah3
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(4, 0, 59);
    glVertex3f(4, 10, 89);
    glVertex3f(30, 10, 89);
    glVertex3f(30, 0, 59);
    glEnd();

    //kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(4,10,89);
    glVertex3f(4,0,59);
    glVertex3f(4,0,89);
    glEnd();

    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(30,10,89);
    glVertex3f(30,0,59);
    glVertex3f(30,0,89);
    glEnd();

    //tribunbawah4
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35, 0, 59);
    glVertex3f(35, 10, 89);
    glVertex3f(54, 10, 89);
    glVertex3f(54, 0, 59);
    glEnd();


    //kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(35,10,89);
    glVertex3f(35,0,59);
    glVertex3f(35,0,89);
    glEnd();

    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(54,10,89);
    glVertex3f(54,0,59);
    glVertex3f(64,0,89);
    glEnd();

    //tibun atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-54, 15+5, 89);
    glVertex3f(-54, 40, 110);
    glVertex3f(54, 40, 110);
    glVertex3f(54, 15+5, 89);
    glEnd();

    //tribunsambung
    glBegin(GL_QUADS);
    glColor3f(0, 0.0, 0.0);
    glVertex3f(98.5, 20, 49);
    glVertex3f(54, 20, 89);
    glVertex3f(54, 20, 85);
    glVertex3f(90.5, 20, 49);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0.0, 0.0);
    glVertex3f(98.5, 20, 49);
    glVertex3f(54, 20, 89);
    glVertex3f(54, 40, 110);
    glVertex3f(130, 35, 49);
    glEnd();

    //tembok tribun 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 0, 1.0);
    glVertex3f(-54, 20, 89);
    glVertex3f(-54, 0, 89);
    glVertex3f(54, 0, 89);
    glVertex3f(54, 20, 89);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-54, 15+5, 89);
    glVertex3f(-54, 20, 85);
    glVertex3f(54, 20, 85);
    glVertex3f(54, 15+5, 89);
    glEnd();

    //tembok tribun 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-54, 10+30, 110);
    glVertex3f(-54, 50+5, 110);
    glVertex3f(54, 50+5, 110);
    glVertex3f(54, 10+30, 110);
    glEnd();

    //pagar tribun
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(0,21.5,85.5);
    glScalef(54,1.5,0.3);
    glutSolidCube(2);
    glPopMatrix();
}

void tribunbesar2(){
    //alas
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(67.5, 0, -48);
    glVertex3f(67.5, 0, -84);
    glVertex3f(-67.5, 0, -84);
    glVertex3f(-67.5, 0, -48);
    glEnd();

    //tribun1
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-40, 0, -55);
    glVertex3f(-40, 13, -84);
    glVertex3f(61, 13, -84);
    glVertex3f(61, 0, -55);
    glEnd();

    //tembok tribun
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(61, 10+13.5, -84);
    glVertex3f(61, 0, -84);
    glVertex3f(-61, 0, -84);
    glVertex3f(-61, 10+13.5, -84);
    glEnd();

    //alas atas
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-61, 10+30, -110);
    glVertex3f(-61, 10+10, -78);
    glVertex3f(61, 10+10, -78);
    glVertex3f(61, 10+30, -110);
    glEnd();

    //alas tibun lt2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-61, 20, -78);
    glVertex3f(-61, 20, -77);
    glVertex3f(61, 20, -77);
    glVertex3f(61, 20, -78);
    glEnd();

    //pagar tribun lt2
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(0,21.5,-77);
    glScalef(61,1.5,0.3);
    glutSolidCube(2);
    glPopMatrix();

    //alas tangga
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-61, 10+30, -113);
    glVertex3f(-61, 10+30, -110);
    glVertex3f(61, 10+30, -110);
    glVertex3f(61, 10+30, -113);
    glEnd();

    //tangga1
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(45, 40, -111);
    glVertex3f(45, 50, -99);
    glVertex3f(56, 50, -99);
    glVertex3f(56, 40, -111);
    glEnd();

    //tangga2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(25, 40, -111);
    glVertex3f(25, 50, -99);
    glVertex3f(36, 50, -99);
    glVertex3f(36, 40, -111);
    glEnd();

    //tangga3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(5, 40, -111);
    glVertex3f(5, 50, -99);
    glVertex3f(16, 50, -99);
    glVertex3f(16, 40, -111);
    glEnd();

    //tangga4
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-15, 40, -111);
    glVertex3f(-15, 50, -99);
    glVertex3f(-4, 50, -99);
    glVertex3f(-4, 40, -111);
    glEnd();

    //tangga5
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-35, 40, -111);
    glVertex3f(-35, 50, -99);
    glVertex3f(-24, 50, -99);
    glVertex3f(-24, 40, -111);
    glEnd();

    //tangga6
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-55, 40, -111);
    glVertex3f(-55, 50, -99);
    glVertex3f(-44, 50, -99);
    glVertex3f(-44, 40, -111);
    glEnd();

    //alas tribun lt3
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-60, 50, -99);
    glVertex3f(-60, 50, -95);
    glVertex3f(61, 50, -95);
    glVertex3f(61, 50, -99);
    glEnd();

    //pagar tribun lt3
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(0.5,51.5,-95);
    glScalef(60.5,1.5,0.3);
    glutSolidCube(2);
    glPopMatrix();

    //tribun atas
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-60, 60, -111);
    glVertex3f(-60, 50, -99);
    glVertex3f(-55, 50, -99);
    glVertex3f(-55, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-55, 60, -111);
    glVertex3f(-55, 53.3, -103);
    glVertex3f(-44, 53.3, -103);
    glVertex3f(-44, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-44, 60, -111);
    glVertex3f(-44, 50, -99);
    glVertex3f(-35, 50, -99);
    glVertex3f(-35, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-35, 60, -111);
    glVertex3f(-35, 53.3, -103);
    glVertex3f(-24, 53.3, -103);
    glVertex3f(-24, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-24, 60, -111);
    glVertex3f(-24, 50, -99);
    glVertex3f(-15, 50, -99);
    glVertex3f(-15, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-15, 60, -111);
    glVertex3f(-15, 53.3, -103);
    glVertex3f(-4, 53.3, -103);
    glVertex3f(-4, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-4, 60, -111);
    glVertex3f(-4, 50, -99);
    glVertex3f(5, 50, -99);
    glVertex3f(5, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(5, 60, -111);
    glVertex3f(5, 53.3, -103);
    glVertex3f(16, 53.3, -103);
    glVertex3f(16, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(16, 60, -111);
    glVertex3f(16, 50, -99);
    glVertex3f(25, 50, -99);
    glVertex3f(25, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(25, 60, -111);
    glVertex3f(25, 53.3, -103);
    glVertex3f(36, 53.3, -103);
    glVertex3f(36, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(36, 60, -111);
    glVertex3f(36, 50, -99);
    glVertex3f(45, 50, -99);
    glVertex3f(45, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(45, 60, -111);
    glVertex3f(45, 53.3, -103);
    glVertex3f(56, 53.3, -103);
    glVertex3f(56, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(56, 60, -111);
    glVertex3f(56, 50, -99);
    glVertex3f(61, 50, -99);
    glVertex3f(61, 60, -111);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-60, 87, -140);
    glVertex3f(-60, 60, -111);
    glVertex3f(61, 60, -111);
    glVertex3f(61, 87, -140);
    glEnd();

    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,1);
    glVertex3f(-60,13,-84);
    glVertex3f(-40,0,-55);
    glVertex3f(-60,0,-70);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-60,13,-84);
    glVertex3f(-40,0,-55);
    glVertex3f(-40,13,-84);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(61,13,-84);
    glVertex3f(61,0,-55);
    glVertex3f(67,0,-65);
    glVertex3f(67,10,-84);
    glEnd();

    //tembok
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(61, 20, -84);
    glVertex3f(61, 0, -84);
    glVertex3f(95, 0, -84);
    glVertex3f(95, 20, -84);
    glEnd();
}

void bangkucadangan1(){
    //belakang
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(15,3,48);
    glScalef(6,2,0.3);
    glutSolidCube(3);
    glPopMatrix();

    //alas
    glPushMatrix();
    glColor3f(0.9,0.8,0.8);
    glTranslatef(15,0.6,46);
    glScalef(9,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    //atap
    glPushMatrix();
    glColor3f(0.9,0.8,0.8);
    glRotatef(94,0.8,2.8,0.8);
    glTranslatef(-35.5,30,15.2);
    glScalef(2.3,0.8,9);
    glutSolidCube(2);
    glPopMatrix();

    //samping kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(24, 8.5, 44.3);
    glVertex3f(24.1, 6.2, 43);
    glVertex3f(24.1, 3.2, 48.4);
    glVertex3f(24.1, 6.2, 48.4);
    glEnd();

    //samping kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(5.9, 8.6, 44.3);
    glVertex3f(5.9, 6.3, 43);
    glVertex3f(5.9, 3.3, 48.4);
    glVertex3f(5.9, 6.3, 48.4);
    glEnd();

    //bangku1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku1.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku2
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(9,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku2.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(9,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku3
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(11,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku3.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(11,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku4
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku4.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku5
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(15,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku5.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(15,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku6
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(17,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku6.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(17,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku7
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku7.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku8
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(21,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku8.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(21,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku9
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(23,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku9.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(23,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();
}

void bangkucadangan2(){
     //belakang
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-15,3,48);
    glScalef(5.99,2,0.3);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9,0.8,0.8);
    glTranslatef(-15,0.6,46);
    glScalef(9,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    //atap
    glPushMatrix();
    glColor3f(0.9,0.8,0.8);
    glRotatef(94,0.8,2.8,0.8);
    glTranslatef(-35.8,29.8,-14.8);
    glScalef(2.3,0.8,9);
    glutSolidCube(2);
    glPopMatrix();

    //samping kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-24.2, 8.5, 44.3);
    glVertex3f(-24.5, 6, 43);
    glVertex3f(-24, 3, 48.4);
    glVertex3f(-24.1, 6, 48.4);
    glEnd();

    //samping kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-6.001, 8.5, 44.5);
    glVertex3f(-6.001, 6, 43);
    glVertex3f(-6.001, 3, 48.4);
    glVertex3f(-6.001, 6, 48.4);
    glEnd();

    //bangku1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-7,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku1.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-7,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku2
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-9,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku2.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-9,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku3
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku3.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku4
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-13,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku4.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-13,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku5
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-15,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku5.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-15,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku6
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku6.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku7
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-19,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku7.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-19,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku8
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku8.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();

    //bangku9
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-23,3,47.5);
    glScalef(1,6,0.5);
    glutSolidCube(1);
    glPopMatrix();

    //bangku9.1
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-23,2.2,46.5);
    glScalef(1,0.5,2);
    glutSolidCube(1);
    glPopMatrix();
}

void bangkutribun1(){
    //dudukan
    double y = 0;
    for ( double x=0; x>=-24; x-=2){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(-70+x,1+y,0);
        glScalef(1,2,97.7);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
        }
    //tempatduduk
    y=-0.8;
    for (int z = 0; z<=24; z+=2 ){
        y+=0.8;
        for (double x=0; x<=96; x+=1.5){
        glColor3f(0.0, 0.5, 1.0);
        glPushMatrix();
        glTranslatef(-70.4-z,2.5+y,48-x);
        glScalef(0.3,1.5,1);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-70-z,2.2+y,48-x);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
        }
    }
    //dudukanatas
    y=0;
    for ( double x=0; x>=-32; x-=2){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(-97+x,20.8+y,-8);
        glScalef(1,2,114);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.9;
        }

    //tempatduduk1
    y=-0.88;
    for (int z = 0; z<=32; z+=2 ){
        y+=0.9;
        for (double x=0; x<=113.5; x+=1.5){
        glColor3f(0.0, 0.5, 1.0);
        glPushMatrix();
        glTranslatef(-97.35-z,22.3+y,48-x);
        glScalef(0.3,1.5,1);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-97-z,22+y,48-x);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
        }
    }
}

void bangkutribun2(){
    //dudukan
    double y = 0;
    for (int x=0; x>=-24; x-=2){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(70-x,1+y,0);
        glScalef(1,2,97.7);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
        }
    //tempatduduk
    y=-0.8;
    for (int z = 0; z<=24; z+=2 ){
        y+=0.8;
        for (int x=0; x<=96; x+=2){
        glColor3f(0.0, 0.5, 1.0);
        glPushMatrix();
        glTranslatef(70.35+z,2.5+y,48.5-x);
        glScalef(0.3,1.5,1);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(70+z,2.2+y,48.5-x);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
        }
    }

    //dudukanatas
    y=0;
    for ( double x=0; x>=-32; x-=2){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(97-x,20.8+y,0);
        glScalef(1,2,97.7);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.88;
        }

    //tempatduduk1
    y=-0.88;
    for (int z = 0; z<=32; z+=2 ){
        y+=0.9;
        for (double x=0; x<=96; x+=1.5){
        glColor3f(0.0, 0.5, 1.0);
        glPushMatrix();
        glTranslatef(97.35+z,22.3+y,48-x);
        glScalef(0.3,1.5,1);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(97+z,22+y,48-x);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
        }
    }
}

void bangkutribunbesar2(){
    //dudukan1
    double y = 0;
    for (double x=0; x>=-25; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(10,1.5+y,-56+x);
        glScalef(99,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=1.1;
    }
    //dudukan2
    y = 1.1;
    double z =0;
    for (double x=0; x>=-22.5; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(-35.5,1.5+y,-58.5+x);
        glScalef(10+z,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=1.1;
        z+=3.5;
    }
    //tempatduduk1
    y = -1.1;
    for (z=0; z>=-25; z-=2.5){
        y +=1.1;
        for (double x=0; x>=-96; x-=2){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-38-x,3+y,-56.1+z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-38-x,2.6+y,-55.5+z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }
    //tempatduduk2
    y = -1.1;
    int w = -3;
    for (z=0; z>=-25; z-=2.5){
        y +=1.1;
        w +=2.5;
        for (double x=0; x>=2-w; x-=2){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-38+x,3+y,-56.1+z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-38+x,2.6+y,-55.5+z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }
    //dudukan3
    y = 0;
    for (double x=0; x>=-25; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(-5.8,23.5+y,-80+x);
        glScalef(133,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=1.5;
    }
    //tempatduduk3
    y = -1.5;
    for (z=0; z>=-25; z-=2.5){
        y +=1.5;
        for (double x=0; x>=-132; x-=2){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-72-x,25.1+y,-80.3+z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-72-x,24.8+y,-80+z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }

    //dudukan4
    y = 0;
    for (double x=0; x>=-32.5; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(0.3,56.5+y,-105+x);
        glScalef(120,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=2.3;
    }

    //tempatduduk3
    y = -2.3;
    for (z=0; z>=-32.5; z-=2.5){
        y +=2.3;
        for (double x=0; x>=-118; x-=2){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-58.8-x,58+y,-105.3+z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-58.8-x,57.5+y,-105+z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }
}

void tembokluar(){
    //PIMTU
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-120, 0, 61);
    glVertex3f(-120, 57, 61);
    glVertex3f(-73, 57, 106);
    glVertex3f(-73, 0, 106);
    glEnd();

    glPushMatrix();
    glColor3f(0.42, 0.42, 0.42);
    glRotatef(45, 0, -1, 0);
    glTranslatef(-5, 20, 133);
    glScalef(15, 13, 3);
    glutSolidCube(3);
    glPopMatrix();
    //1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-115, 0, 80);
    glVertex3f(-115, 20, 80);
    glVertex3f(-105, 20, 90);
    glVertex3f(-105, 0, 90);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-98, 0, 98);
    glVertex3f(-98, 20, 98);
    glVertex3f(-88, 20, 108);
    glVertex3f(-88, 0, 108);
    glEnd();

    //TRIBUN 1-Besar 1
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-133, 25, -55);
    glVertex3f(-133, 57, -55);
    glVertex3f(-133, 57, 50);
    glVertex3f(-133, 25, 50);
    glEnd();
    //TRIBUN 1-Kecil 1
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-133, 57, 50);
    glVertex3f(-120, 57, 50);
    glVertex3f(-120, 0, 50);
    glVertex3f(-133, 0, 50);
    glEnd();
    //TRIBUN 1-Kecil 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, 50);
    glVertex3f(-120, 57, 50);
    glVertex3f(-120, 57, 60);
    glVertex3f(-120, 0, 60);
    glEnd();
    //TRIBUN 1-Besar 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, 60);
    glVertex3f(-120, 57, 60);
    glVertex3f(-73, 57, 105);
    glVertex3f(-73, 0, 105);
    glEnd();
    //TRIBUN 1-Kecil 3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-73, 0, 105);
    glVertex3f(-73, 57, 105);
    glVertex3f(-63, 57, 105);
    glVertex3f(-63, 0, 105);
    glEnd();
    //TRIBUN 1-Kecil 4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-63, 0, 105);
    glVertex3f(-63, 57, 105);
    glVertex3f(-63, 57, 111);
    glVertex3f(-63, 0, 111);
    glEnd();
    //TRIBUN 1-Besar 3 TRIBUN BESAR FULL
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-63, 25, 111);
    glVertex3f(-63, 57, 111);
    glVertex3f(73, 57, 111);
    glVertex3f(73, 25, 111);
    glEnd();
    //TRIBUN BESAR 1-Kecil
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(73, 25, 111);
    glVertex3f(73, 57, 111);
    glVertex3f(73, 57, 105);
    glVertex3f(73, 25, 105);
    glEnd();
    //TRIBUN BESAR 1-Kecil 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(73, 25, 105);
    glVertex3f(73, 57, 105);
    glVertex3f(88, 57, 105);
    glVertex3f(88, 25, 105);
    glEnd();
    //TRIBUN BESAR 1-Kecil 3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(88, 25, 105);
    glVertex3f(88, 57, 105);
    glVertex3f(98, 57, 103);
    glVertex3f(98, 25, 103);
    glEnd();
    //TRIBUN BESAR 1-Kecil 4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(98, 25, 103);
    glVertex3f(98, 57, 103);
    glVertex3f(108, 57, 101);
    glVertex3f(108, 25, 101);
    glEnd();
    //TRIBUN-BESAR 1-Kecil 5
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(108, 25, 101);
    glVertex3f(108, 57, 101);
    glVertex3f(119, 57, 88);
    glVertex3f(119, 25, 88);
    glEnd();
    //TRIBUN-BESAR 1-Kecil 6
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(119, 25, 88);
    glVertex3f(119, 57, 88);
    glVertex3f(125, 57, 78);
    glVertex3f(125, 25, 78);
    glEnd();
    //TRIBUN-BESAR 1-Kecil 7
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(125, 25, 78);
    glVertex3f(125, 57, 78);
    glVertex3f(131, 57, 57);
    glVertex3f(131, 25, 57);
    glEnd();
    //TRIBUN-BESAR 1-Kecil 8
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(131, 25, 57);
    glVertex3f(131, 57, 57);
    glVertex3f(132, 57, 50);
    glVertex3f(132, 25, 50);
    glEnd();
    //TRIBUN-BESAR 1-Besar FULL
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(132, 25, 50);
    glVertex3f(132, 57, 50);
    glVertex3f(132, 57, -50);
    glVertex3f(132, 25, -50);
    glEnd();
    //TRIBUN-BESAR 1-Kecil Lanjutan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(132, 0, -50);
    glVertex3f(132, 57, -50);
    glVertex3f(119, 57, -50);
    glVertex3f(119, 0, -50);
    glEnd();
    //TRIBUN-BESAR 1-Kecil L 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(119, 0, -50);
    glVertex3f(119, 57, -50);
    glVertex3f(122, 57, -60);
    glVertex3f(122, 0, -60);
    glEnd();
    //TRIBUN-BESAR 1-Kecil L-3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(122, 0, -60);
    glVertex3f(122, 57, -60);
    glVertex3f(120, 57, -70);
    glVertex3f(120, 0, -70);
    glEnd();
    //TRIBUN-BESAR 1-Kecil L-4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(120, 0, -70);
    glVertex3f(120, 57, -70);
    glVertex3f(108, 57, -100);
    glVertex3f(108, 0, -100);
    glEnd();
    //TRIBUN-BESAR 1-Kecil L-5
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(108, 0, -100);
    glVertex3f(108, 57, -100);
    glVertex3f(61, 57, -100);
    glVertex3f(61, 0, -100);
    glEnd();

    //TRIBUN-BESAR 2-Kecil X++
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(61, 0, -100);
    glVertex3f(61, 33, -100);
    glVertex3f(50, 33, -100);
    glVertex3f(50, 0, -100);
    glEnd();
    //TRIBUN-BESAR 2-Kecil 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(50, 0, -100);
    glVertex3f(50, 33, -100);
    glVertex3f(50, 33, -115);
    glVertex3f(50, 0, -115);
    glEnd();
    //TRIBUN-BESAR 2-BESAR SEBERANG TIANG
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(50, 0, -115);
    glVertex3f(50, 33, -115);
    glVertex3f(-60, 33, -115);
    glVertex3f(-60, 0, -115);
    glEnd();
    //TRIBUN-BESAR 2-Kecil Last
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-60, 0, -115);
    glVertex3f(-60, 33, -115);
    glVertex3f(-60, 33, -100);
    glVertex3f(-60, 0, -100);
    glEnd();
    //TRIBUN-BESAR 2-BESAR LANJUTAN
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-60, 0, -110);
    glVertex3f(-60, 40, -110);
    glVertex3f(-136, 40, -90);
    glVertex3f(-136, 0, -90);
    glEnd();
    //TRIBUN-BESAR 2-BESAR LAST
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-136, 0, -90);
    glVertex3f(-136, 40, -90);
    glVertex3f(-134, 40, -50);
    glVertex3f(-134, 0, -50);
    glEnd();
    //TRIBUN-BESAR 2-Kecil LAST
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-134, 0, -50);
    glVertex3f(-134, 30, -50);
    glVertex3f(-124, 30, -50);
    glVertex3f(-124, 0, -50);
    glEnd();

    //TEMBOK TRIBUN BESAR 2-Penyangga 1
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(0, 40, -123);
    glScalef(40, 1.5, 7);
    glutSolidCube(3);
    glPopMatrix();
    //TRIBUN BESAR-2 Penyangga 2 Bawah
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(0, 0, -115);
    glScalef(40, 1.5, 12);
    glutSolidCube(3);
    glPopMatrix();
    //TEMBOK TRIBUN-BESAR 2-Tiang 1
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(-52, 18, -123);
    glScalef(4, 13, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TEMBOK TRIBUN-BESAR 2-Tiang 2
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(-27, 18, -123);
    glScalef(4, 13, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TEMBOK TRIBUN-BESAR 2-Tiang 3
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(-9, 18, -123);
    glScalef(4, 13, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TEMBOK TRIBUN-BESAR 2-Tiang 4
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(13, 18, -123);
    glScalef(4, 13, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TEMBOK TRIBUN-BESAR 2-Tiang 5
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(34, 18, -123);
    glScalef(4, 13, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TEMBOK TRIBUN-BESAR 2-Tiang 6
    glPushMatrix();
    glColor3f(0.65, 0.65, 0.65);
    glTranslatef(56, 18, -123);
    glScalef(4, 13, 5);
    glutSolidCube(3);
    glPopMatrix();


    //TEMBOK PENYANGGA PANJANG
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslatef(-134, 50, -3);
    glScalef(0.75, 5, 37);
    glutSolidCube(3);
    glPopMatrix();

    //TEMBOK DEPAN
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslatef(-35, 50, 115);
    glScalef(10, 2, 1);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslatef(55, 50, 115);
    glScalef(15, 2, 1);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslatef(135, 50, 5);
    glScalef(1, 2, 20);
    glutSolidCube(5);
    glPopMatrix();

    //TEMBOK LUAR-BAWAH 25-T1
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-133, 25, -55);
    glVertex3f(-120, 25, -55);
    glVertex3f(-120, 25, 50);
    glVertex3f(-133, 25, 50);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, -55);
    glVertex3f(-120, 25, -55);
    glVertex3f(-120, 25, 50);
    glVertex3f(-120,0, 50);
    glEnd();
    //TEMBOK LUAR-BAWAH SAMBUNG T1-T1 BESAR
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-63, 0, 105);
    glVertex3f(-63, 25, 105);
    glVertex3f(-63, 25, 98);
    glVertex3f(-63, 0, 98);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 BESAR 1
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-63, 25, 111);
    glVertex3f(-63, 25, 98);
    glVertex3f(73, 25, 98);
    glVertex3f(73, 25, 111);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 BESAR 2 Bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-63, 0, 98);
    glVertex3f(-63, 25, 98);
    glVertex3f(85, 25, 98);
    glVertex3f(85, 0, 98);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 CURVE 1
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(73, 25, 105);
    glVertex3f(73, 25, 98);
    glVertex3f(85, 25, 98);
    glVertex3f(85, 25, 105);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 CURVE 2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(85, 25, 105);
    glVertex3f(85, 25, 98);
    glVertex3f(95, 25, 95);
    glVertex3f(95, 25, 103);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 Curve 2 Bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(85, 0, 98);
    glVertex3f(85, 25, 98);
    glVertex3f(95, 25, 95);
    glVertex3f(95, 0, 95);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 Curve 3
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95, 25, 103);
    glVertex3f(95, 25, 95);
    glVertex3f(105, 25, 92);
    glVertex3f(105, 25, 101);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 Curve 3 Bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(95, 0, 95);
    glVertex3f(95, 25, 95);
    glVertex3f(105, 25, 92);
    glVertex3f(105, 0, 92);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 Curve 4
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(105, 25, 101);
    glVertex3f(105, 25, 92);
    glVertex3f(115, 25, 80);
    glVertex3f(115, 25, 92);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 Curve 4 Bawah
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(105, 0, 92);
    glVertex3f(105, 25, 92);
    glVertex3f(115, 25, 80);
    glVertex3f(115, 0, 80);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-T1 Curve 5
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(115, 25, 92);
    glVertex3f(115, 25, 80);
    glVertex3f(125, 25, 70);
    glVertex3f(125, 25, 78);
    glEnd();
    //TEMBOK LUAR-BAWAH 25-TI RATA
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(115, 25, 92);
    glVertex3f(131, 25, 65);
    glVertex3f(132, 25, -50);
    glVertex3f(115, 25, -50);
    glEnd();
    //TEMBOK LUAR-AWAH 25-TI RATA BAWAH
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(115, 0, 80);
    glVertex3f(115, 25, 80);
    glVertex3f(115, 25, -53);
    glVertex3f(115, 0, -53);
    glEnd();

}

void bangkutribunbesar1(){
    //dudukan1
    double y = 0;
    for (double x=0; x>=-25; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(44.3,1.2+y,61-x);
        glScalef(18.5,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
    }
    //temaptduduk1
    y = -0.8;
    double z;
    for (z=0; z>=-25; z-=2.5){
        y +=0.8;
        for (double x=0; x>=-17; x-=1.5){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(36.1-x,2.8+y,61.3-z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(36-x,2.3+y,61-z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }

    //dudukan2
    y = 0;
    for (double x=0; x>=-25; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(17,1.2+y,61-x);
        glScalef(25,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
    }

    //temaptduduk2
    y = -0.8;
    z = 0;
    for (z=0; z>=-25; z-=2.5){
        y +=0.8;
        for (double x=0; x>=-24; x-=1.5){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(5-x,2.8+y,61.3-z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(5-x,2.3+y,61-z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }

    //dudukan3
    y = 0;
    for (double x=0; x>=-25; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(-17,1.2+y,61-x);
        glScalef(25,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
    }

    //temaptduduk2
    y = -0.8;
    z = 0;
    for (z=0; z>=-25; z-=2.5){
        y +=0.8;
        for (double x=0; x>=-24; x-=1.5){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-29-x,2.8+y,61.3-z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-29-x,2.3+y,61-z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }

    //dudukan4
    y = 0;
    for (double x=0; x>=-25; x-=2.5){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(-44.3,1.2+y,61-x);
        glScalef(18.5,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
    }

    //tempatduduk4
    y = -0.8;
    z = 0;
    for (z=0; z>=-25; z-=2.5){
        y +=0.8;
        for (double x=0; x>=-17; x-=1.5){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-52.5-x,2.8+y,61.3-z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-52-x,2.3+y,61-z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }

    //dudukan5
    y = 0;
    for (double x=0; x>=-18; x-=2){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glTranslatef(0,21.5+y,90-x);
        glScalef(107.5,2,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=2;
    }
    //tempatduduk5
    y = -2;
    z = 0;
    for (z=0; z>=-18; z-=2){
        y +=2;
        for (double x=0; x>=-106; x-=1.5){
        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-52.5-x,23.4+y,90.3-z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glTranslatef(-52.5-x,22.7+y,90-z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }
}

void papanscore(){
    //papanscore1
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(130,45,0);
    glScalef(1,12,15);
    glutSolidCube(1);
    glPopMatrix();

    //papanscore2
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-130,45,0);
    glScalef(1,12,15);
    glutSolidCube(1);
    glPopMatrix();

}

void tiangbaru(){
    //LAMPU
    //1
    //TIANG
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(-65, 50, -120);
    glScalef(0.5, 25, 0.5);
    glutSolidCube(5);
    glPopMatrix();
    //LAMPU
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(-65, 100, -120);
    glScalef(5, 5, 0.75);
    glutSolidCube(5);
    glPopMatrix();
    //2
    //TIANG
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(65, 50, -120);
    glScalef(0.5, 25, 0.5);
    glutSolidCube(5);
    glPopMatrix();
    //LAMPU
    //1
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(65, 100, -120);
    glScalef(5, 5, 0.75);
    glutSolidCube(5);
    glPopMatrix();

    //3
    //TIANG
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(-65, 50, 120);
    glScalef(0.5, 25, 0.5);
    glutSolidCube(5);
    glPopMatrix();
    //LAMPU
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(-65, 100, 120);
    glScalef(5, 5, 0.75);
    glutSolidCube(5);
    glPopMatrix();
    //4
    //TIANG
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(65, 50, 120);
    glScalef(0.5, 25, 0.5);
    glutSolidCube(5);
    glPopMatrix();
    //LAMPU
    //1
    glPushMatrix();
    glColor3f(230/255.f, 230/255.f, 250/255.f);
    glTranslatef(65, 100, 120);
    glScalef(5, 5, 0.75);
    glutSolidCube(5);
    glPopMatrix();

    //TRIBUN 1
    //TIANG MIRING ATAS-1
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, -52.5);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-2
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, -41);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-3
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, -30.5);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-4
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, -20);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-5
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, -10);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-6
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, 0.5);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-7
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, 11);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-8
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, 21.5);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-9
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, 32);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-10
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(-136, -26, 42.5);
    glScalef(11.5, 1, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 1
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-128, 15, -52.5);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 2
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-128, 15, -41.05);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 3
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-128, 15, -30.6);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 4
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-128, 15, -20.15);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 5
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-128, 15, -9.7);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 6
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-128, 15, 0.75);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 7
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-128, 15, 11.2);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 8
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-128, 15, 21.65);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 9
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-128, 15, 32.1);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 10
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-128, 15, 42.5);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();


    //TRIBUN 1 BESAR
    //TIANG MIRING ATAS-1
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-61.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-2
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-51.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-3
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-41.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-4
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-31.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-5 ORANGE
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-21.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-6
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-16.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-7
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-11.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-8
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(-1.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-9
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(8.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-10 Orange
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(18.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-11
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(23.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-12
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(28.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-13
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(38.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-14
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(48.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-15
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(58.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-16
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(68.5, 120, 34);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TANG MIRING ATAS-17
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(78.5, 118, 33);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TANG MIRING ATAS-18
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(88.5, 116, 31);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
     //TANG MIRING ATAS-19
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 2, 0, 0);
    glTranslatef(106, 116, 29);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-21
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(47, 131, 75);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-21
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(40, 125, 91);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();


    //TIANG BAWAH 1
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-61, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 2
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-51.55, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 3
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-41.55, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 4
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-31.55, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 5
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-21.55, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 6
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-16.55, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 7
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(-11.55, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 8
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(-1.55, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 9
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(8.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 10 ORANGE
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(18.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 11
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(23.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 12
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(28.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 13
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(38.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 14
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(48.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 15
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(58.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 16
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(68.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 17
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(78.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 18
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(88.45, 15, 110);
    glScalef(1, 1, 5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 19
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(105.95, 15, 102.5);
    glRotatef(45, 0, 1, 0);
    glScalef(1, 1, 5.5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 20
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(120, 15, 90);
    glRotatef(45, 0, 1, 0);
    glScalef(1, 1, 5.5);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH 21
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(120, 15, 75);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();


    //TRIBUN 2
    //TIANG MIRING ATAS-1
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, -47.5);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-2
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, -35.5);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-3 ORANGE
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, -25.5);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-4
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, -15.5);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-5
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, -5);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-6
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, 5.5);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-7
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, 16);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-8
    glPushMatrix();
    glColor3f(100/255.f, 149/255.f, 237/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, 26.5);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-9 ORANGE
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, 36.75);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-10
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, 47.25);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG MIRING ATAS-10
    glPushMatrix();
    glColor3f(240/255.f, 1, 240/255.f);
    glRotatef(40, 0, 0, -2);
    glTranslatef(48, 132, 57.75);
    glScalef(0.75, 11.5, 1);
    glutSolidCube(3);
    glPopMatrix();

    //TIANG BAWAH-1
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(130, 15, -47.5);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-2
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(130, 15, -36.05);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-3 ORANGE
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(130, 15, -25.6);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-4
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(130, 15, -15.15);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-5
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(130, 15, -4.7);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-6
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(130, 15, 5.75);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-7
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(130, 15, 16.2);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-8
    glPushMatrix();
    glColor3f(0, 0, 205/255.f);
    glTranslatef(130, 15, 26.65);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-9
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(130, 15, 37.1);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-10
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(130, 15, 47.5);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();
    //TIANG BAWAH-11
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(130, 15, 57.95);
    glScalef(5, 1, 1);
    glutSolidCube(3);
    glPopMatrix();

}

void alas(){
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(0, -6.1, 0);
    glScalef(50, 0.5, 50);
    glutSolidCube(25);
    glPopMatrix();

}

void parkir(){
    glPushMatrix();
    glColor3f(119/255.f, 136/255.f, 153/255.f);
    glTranslatef(250, 0, 10);
    glScalef(50, 0.5, 40);
    glutSolidCube(3);
    glPopMatrix();
    //GARIS 1
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(250, 2, -20);
    glScalef(40, 0.5, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //GARIS LAIN
    for ( double x=0; x>=-100; x-=10){
        glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(300+x, 2, -20);
        glScalef(0.5, 0.5, 15);
        glutSolidCube(3);
        glPopMatrix();
        }
    //GARIS 2
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(250, 2, 40);
    glScalef(40, 0.5, 0.75);
    glutSolidCube(3);
    glPopMatrix();
    //GARIS LAIN
    for ( double x=0; x>=-100; x-=10){
        glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(300+x, 2, 40);
        glScalef(0.5, 0.5, 15);
        glutSolidCube(3);
        glPopMatrix();
        }
}

void bangunanluar(){
    //DASAR
    glPushMatrix();
    glColor3f(0.85, 0.85, 0.85);
    glTranslatef(0,15,200);
    glScalef(40,40,70);
    glutSolidCube(1);
    glPopMatrix();
    //ATAS
    glPushMatrix();
    glColor3f(0.75, 0.75, 0.75);
    glTranslatef(0, 35, 200);
    glScalef(10, 1, 20);
    glutSolidCube(5);
    glPopMatrix();
    //ATAP-2
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-20, 40, 250);
    glVertex3f(-20, 40, 160);
    glVertex3f(20, 40, 160);
    glVertex3f(20, 40, 250);
    glEnd();
    //PINTU
    //1
    glBegin(GL_QUADS);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(-18, 0, 237);
    glVertex3f(-18, 10, 237);
    glVertex3f(-12, 10, 237);
    glVertex3f(-12, 0, 237);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(-7, 0, 237);
    glVertex3f(-7, 10, 237);
    glVertex3f(3, 10, 237);
    glVertex3f(3, 0, 237);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(8, 0, 237);
    glVertex3f(8, 10, 237);
    glVertex3f(14, 10, 237);
    glVertex3f(14, 0, 237);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(-18, 0, 163);
    glVertex3f(-18, 10, 163);
    glVertex3f(-12, 10, 163);
    glVertex3f(-12, 0, 163);
    glEnd();
    //5
    glBegin(GL_QUADS);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(-7, 0, 163);
    glVertex3f(-7, 10, 163);
    glVertex3f(3, 10, 163);
    glVertex3f(3, 0, 163);
    glEnd();
    //6
    glBegin(GL_QUADS);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(8, 0, 163);
    glVertex3f(8, 10, 163);
    glVertex3f(14, 10, 163);
    glVertex3f(14, 0, 163);
    glEnd();

}

void lapanganlatihan(){
    //Lapangan Latihan FULL
    glPushMatrix();
    glColor3f(34/255.f, 139/255.f, 35/255.f);
    glTranslatef(-350, 1.5, -100);
    glScalef(27, 0.5, 19.5);
    glutSolidCube(5);
    glPopMatrix();
    //Lapangan Latihan-Putih
    //Line Utama
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(-402.5, 3, -134);
    glVertex3f(-297.5, 3, -134);
    glVertex3f(-297.5, 3, -70);
    glVertex3f(-402.5, 3, -70);
    glEnd();
    //LINE MID
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-350, 3, -70);
    glVertex3f(-350, 3, -134);
    glEnd();
    //Line Gawang 1
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(-402, 3.8, -120.15);
    glVertex3f(-386, 3.8, -120.15);
    glVertex3f(-386, 3.8, -79.85);
    glVertex3f(-402, 3.8, -79.85);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(-402, 3.8, -109.15);
    glVertex3f(-397, 3.8, -109.15);
    glVertex3f(-397, 3.8, -90.5);
    glVertex3f(-402, 3.8, -90.5);
    glEnd();
    glPopMatrix();
    //Line Gawang 2
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(-298, 3.8, -120.15);
    glVertex3f(-314, 3.8, -120.15);
    glVertex3f(-314, 3.8, -79.85);
    glVertex3f(-298, 3.8, -79.85);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(-298, 3.8, -109.15);
    glVertex3f(-303, 3.8, -109.15);
    glVertex3f(-303, 3.8, -90.5);
    glVertex3f(-298, 3.8, -90.5);
    glEnd();
    glPopMatrix();
    //Lingkaran MAIN+Penalty
    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 100, 3);
    lingkaran(-350, 0, 1.5, 1.5, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0 ,0);
    glTranslatef(0, 100, 3);
    lingkaran(-391.5, 0, 1, 1, 1000, 120);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0 ,0);
    glTranslatef(0, 100, 3);
    lingkaran(-308.5, 0, 1, 1, 1000, 120);
    glPopMatrix();
    //Garis Lingkaran 1-4+Main Putih
    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(270, 1, 0, 0);
    glTranslatef(0, 100, 3);
    lingkaran2(-350, 0, 9.15, 9.15, 1000, 120);
    glPopMatrix();


}

void bangkumiring(){
    //bangkutribunbesar1tribun2
    double y = 0;
    double z = 0;
    for (double x=0; x>=-14; x-=2){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glRotatef(42.1,0,90,-8);
        glTranslatef(10,26.3+y,103-x);
        glScalef(54+z,1,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=2;
        z+=5;
    }
        y = -2;
        double w =-2;
        for (z=0; z>=-14; z-=2){
        y +=2;
        w+=2;
        for (double x=0; x>=-52+z*2.3; x-=1.5){
            glPushMatrix();
            glColor3f(0,0.5,1.0);
            glRotatef(42.1,0,90,-8);
            glTranslatef(-16-w-x,27.5+y,103.3-z);
            glScalef(1,1.5,0.3);
            glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
            glColor3f(0.0, 0.5, 1.0);
            glRotatef(42.1,0,90,-8);
            glTranslatef(-16-w-x,27+y,103-z);
            glScalef(1,0.3,1);
            glutSolidCube(1);
            glPopMatrix();
        }
        }

    //bangkutribunbesar1tribun2
    y = 0;
    z = 0;
    for (double x=0; x>=-10; x-=2){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glRotatef(-43,0,90,-8);
        glTranslatef(-5,28+y,102-x);
        glScalef(53+z,1,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=2;
        z+=4;
    }
    y = -2;
    w =-2;
    for (z=0; z>=-10; z-=2){
    y +=2;
    w+=2;
    for (double x=0; x>=-52+z*1.9; x-=1.5){
        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(-43,0,90,-8);
        glTranslatef(-30.5-w-x,29.2+y,102.3-z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.5, 1.0);
        glRotatef(-43,0,90,-8);
        glTranslatef(-30.5-w-x,28.6+y,102-z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }
    //bangkutribunbesar2tribun2
    y = 0;
    z = 0;
    for (double x=0; x>=-12.5; x-=3){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glRotatef(139,-1,75,5);
        glTranslatef(-18,10.5+y,104-x);
        glScalef(45+z,1,1);
        glutSolidCube(1);
        glPopMatrix();
        y+=2;
        z+=6;
        }
    y = -2;
    w =-3;
    for (z=0; z>=-12; z-=3){
    y +=2;
    w+=3;
    for (double x=0; x>=-42+z*2.1; x-=1.5){
        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(139,-1,75,5);
        glTranslatef(-39-w-x,11.7+y,104.4-z);
        glScalef(1,1.5,0.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(139,-1,75,5);
        glTranslatef(-39-w-x,11.1+y,104-z);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }

    //tribunbesar2tribun1
    y=0;
    for ( double x=0; x>=-24; x-=1.6){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glRotatef(275,0,80,6);
        glTranslatef(-88+x,14+y,80);
        glScalef(1,2,24);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
        }
    y = -0.8;
    w =-3;
    for (z=0; z>=-23; z-=1.6){
    y +=0.8;
    w+=3;
    for ( double x=0; x>=-22.5; x-=1.5){
        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(275,0,80,6);
        glTranslatef(-88.3+z,15.5+y,91.3+x);
        glScalef(0.3,1.5,1);;
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(275,0,80,6);
        glTranslatef(-88+z,15.2+y,91.3+x);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }
    y=0;
    for ( double x=0; x>=-10; x-=1.6){
        glPushMatrix();
        glColor3f(1,0.5,0.5);
        glRotatef(287,0,80,5);
        glTranslatef(-115+x,25+y,87.5);
        glScalef(1,2,34);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.5;
        }
    y = -0.5;
    w =-3;
    for (z=0; z>=-10; z-=1.6){
    y +=0.5;
    w+=3;
    for ( double x=0; x>=-32.5; x-=1.5){
        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(287,0,80,5);
        glTranslatef(-115.3+z,26.5+y,103+x);
        glScalef(0.3,1.5,1);;
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(287,0,80,5);
        glTranslatef(-115+z,26.2+y,103+x);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }

    y=0;
    for ( double x=0; x>=-32; x-=2){
        glPushMatrix();
        glRotatef(360,0,0,-5);
        glColor3f(1,0.5,0.5);
        glTranslatef(-97+x,24+y,-71);
        glScalef(1,2,10);
        glutSolidCube(1);
        glPopMatrix();
        y+=0.8;
        }
    y = -0.8;
    for (z=0; z>=-32; z-=2){
    y +=0.8;
    for ( double x=0; x>=-9; x-=1.5){
        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(360,0,0,-5);
        glTranslatef(-97.3+z,25.5+y,-66.3+x);
        glScalef(0.3,1.5,1);;
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0.5,1.0);
        glRotatef(360,0,0,-5);
        glTranslatef(-97+z,25.2+y,-66.3+x);
        glScalef(1,0.3,1);
        glutSolidCube(1);
        glPopMatrix();
    }
    }
}

void jalan(){
    //Jalan Utama
    glPushMatrix();
    glColor3f(0.88, 0.88, 0.88);
    glTranslatef(-200, 2, 0);
    glScalef(8, 0.5, 250);
    glutSolidCube(5);
    glPopMatrix();
    //Garis
    for ( double z=0; z>=-1250; z-=50){
        glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(-200, 3, 650+z);
        glScalef(0.75, 0.5, 10);
        glutSolidCube(3);
        glPopMatrix();
        }
    //Jalan Utama 2
    glPushMatrix();
    glColor3f(0.88, 0.88, 0.88);
    glTranslatef(50, 2, 280);
    glScalef(250, 0.5, 8);
    glutSolidCube(5);
    glPopMatrix();
    for ( double x=0; x>=-1250; x-=50){
        glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(650+x, 3, 280);
        glScalef(10, 0.5, 0.75);
        glutSolidCube(3);
        glPopMatrix();
        }

}

void var(){

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,2,37);
    glScalef(1,3,0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,4,37);
    glScalef(3,3,0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0,4.1,36.7);
    glScalef(2,2,0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,5.5,36.8);
    glScalef(3,0.5,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(1.5,4.8,36.8);
    glScalef(0.5,2,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1.5,4.8,36.8);
    glScalef(0.5,2,1);
    glutSolidCube(1);
    glPopMatrix();
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 200.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glTranslatef(a, b, c);
    glRotatef(d, 1, 0, 0);
    glRotatef(e, 0, 1, 0);
    glRotatef(f, 0, 0, 1);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    lapanganutama();
    sponsor();
    tribun1();
    tribun2();
    ataptribun1();
    ataptribun2();
    ataptribunbesar1();
    tribunbesar1();
    tribunbesar2();
    bangkucadangan1();
    bangkucadangan2();
    bangkutribun1();
    bangkutribun2();
    bangkutribunbesar2();
    tembokluar();
    bangkutribunbesar1();
    papanscore();
    tiangbaru();
    alas();
    parkir();
    bangunanluar();
    lapanganlatihan();
    bangkumiring();
    jalan();
    var();

    glutSwapBuffers();
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 1, 5000);
    glTranslatef(0, 0, -150);
    glViewport(0,0,1920,1080);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("PROJECT_TR_GRAFKOM");
    glutDisplayFunc(Display);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(Display);

    glutTimerFunc(1, timer, 0);
    init();
    glutMainLoop();
}
