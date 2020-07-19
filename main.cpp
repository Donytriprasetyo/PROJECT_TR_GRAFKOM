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
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
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
    glTranslatef(-90.8,21.51,-5.4);
    glScalef(0.3,1.5,54.49);
    glutSolidCube(2);
    glPopMatrix();

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
    glVertex3f(-132.5, 10+27, -75);
    glVertex3f(-90.5, 15+5, -70);
    glVertex3f(-98.5, 15+5, -60);
    glVertex3f(-134.5, 10+27, -60);
    glEnd();

    //tribunmiring2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-136.5, 10+29, -90);
    glVertex3f(-80.5, 15+5, -75);
    glVertex3f(-90.5, 15+5, -70);
    glVertex3f(-138.5, 10+29, -76);
    glEnd();

    //tribunmiring3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-60.5, 10+30, -112);
    glVertex3f(-60.5, 15+5, -77);
    glVertex3f(-85.5, 15+5, -75);
    glVertex3f(-142.5, 10+30, -90);
    glEnd();

    //alastribunmiring1
    glBegin(GL_QUADS);
    glColor3f(1.0, 0, 1.0);
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
    glVertex3f(-130.5, 10+25, -49);
    glVertex3f(-130.5, 50+5, -49);
    glVertex3f(-130.5, 50+5, 49);
    glVertex3f(-130.5, 10+25, 49);
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
    glVertex3f(95.5, 5+15, -49);
    glVertex3f(95.5, 5, -49);
    glVertex3f(95.5, 5, 49);
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
    glVertex3f(90.8, 20, -60);
    glVertex3f(90.8, 23, -60);
    glVertex3f(60.8, 23, -77);
    glVertex3f(60.8, 20, -77);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.8, 20, -60.8);
    glVertex3f(90.8, 23, -60.8);
    glVertex3f(60.8, 23, -77.8);
    glVertex3f(60.8, 20, -77.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.8, 23, -60);
    glVertex3f(90.8, 23, -60.8);
    glVertex3f(60.8, 23, -77.8);
    glVertex3f(60.8, 23, -77);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(90.8, 20, -60);
    glVertex3f(90.8, 20, -60.8);
    glVertex3f(60.8, 20, -77.8);
    glVertex3f(60.8, 20, -77);
    glEnd();

    //pagar tribun2
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(90.8,21.51,-5.4);
    glScalef(0.3,1.5,54.49);
    glutSolidCube(2);
    glPopMatrix();

    //tribun miring atas 2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1.0);
    glVertex3f(130.5, 10+25, -60);
    glVertex3f(98.5, 15+5, -60);
    glVertex3f(98.5, 15+5, 49);
    glVertex3f(130.5, 10+25, 49);
    glEnd();

    //tembok tribun 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(130.5, 10+25, -49);
    glVertex3f(130.5, 50+5, -49);
    glVertex3f(130.5, 50+5, 49);
    glVertex3f(130.5, 10+25, 49);
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
    glTranslatef(58.45, 45, 112.5);
    glScalef(0.75, 25, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Tiang Utama 16-Orange
    glPushMatrix();
    glColor3f(221/255.f, 52/255.f, 0);
    glTranslatef(68.45, 45, 112.5);
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
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-54, 10+5, 89);
    glVertex3f(-54, 40, 110);
    glVertex3f(54, 40, 110);
    glVertex3f(54, 10+5, 89);
    glEnd();

    //tembok tribun 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 0, 1.0);
    glVertex3f(-54, 15, 89);
    glVertex3f(-54, 0, 89);
    glVertex3f(54, 0, 89);
    glVertex3f(54, 15, 89);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-54, 10+5, 89);
    glVertex3f(-54, 12, 85);
    glVertex3f(54, 12, 85);
    glVertex3f(54, 10+5, 89);
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
    glTranslatef(0,13.6,85);
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

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

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

    glutSwapBuffers();
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 1, 5000);
    glTranslatef(0, 0, -150);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
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
