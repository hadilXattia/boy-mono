/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <cstdio>

static int slices = 20;
static int stacks = 50;
int a = 180;
float z = -5;
float xNouv = 0;
float yNouv = 0.65;
float zNouv = -5.9;
float zCam = 4.5;
double s = -3.14159;
int neutre = 1000;
int r = 1;
int v = 1;
int b = 1;
float e1=0,e2=1.9,e3=0,e4=1,e5=-3,e6=0,e7=1,e8=0;
void tClavierSpec(int key, int x, int y);
void tClavierCouleur(unsigned char key, int x, int y);
void sMouse(int button, int state, int x, int y);
bool wheelPress = false;
int zoomS = 1;
bool mousePress = false;
int angleS = 1;
float radius =3;
int angle = 0;
/* GLUT callback Handlers */

void kWheel(int key,int dir,int x,int y)
{ if (mousePress)
        angle += 2*angleS;
    if (wheelPress){
        radius+= 0.3 * zoomS;
        wheelPress = false;
    }
    glutPostRedisplay();

}
void kMouse(int button,int state,int x,int y)
{
    mousePress = true;
    switch (button)
    {
    case GLUT_LEFT_BUTTON :
        if(state == GLUT_DOWN)
        {
            angleS = -1;
        }
        else if (state == GLUT_UP) mousePress = false;
        break;
    case GLUT_RIGHT_BUTTON :
        if(state == GLUT_DOWN)
        {
            angleS = 1;
        }
        else if (state == GLUT_UP) mousePress = false;
        break;
    }
    glutPostRedisplay();
}
static GLfloat itf(float x)
{
    return x/255;
}
static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(e1,e2,zCam,e3,e4,e5,e6,e7,e8);
    glScalef(0.5,0.5,0.5);
    glColor3d(r,v,b);

    glPushMatrix();

    glRotated(a,0,1,0);
    glTranslatef(xNouv,yNouv,zNouv);

    //Head
    glPushMatrix();
        glTranslatef(0,0.55,0.05);
        glutSolidSphere(0.15,slices,stacks);
    glPopMatrix();

    //Body


    //Body(vue de face)
    glPushMatrix();
    //glColor3f(0,0,1);
        glBegin(GL_POLYGON);
        glVertex3f(-0.2,0.4,0.1);//1
        glVertex3f(0.2,0.4,0.1);//2
        glVertex3f(0.2,-0.2,0.1);//3
        glVertex3f(-0.2,-0.2,0.1);//4

        glEnd();
    glPopMatrix();

    //Body(vue de droit)
    glPushMatrix();
    //glColor3f(0,1,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.2,0.4,0.1);//1
        glVertex3f(0.2,0.4,0);//2
        glVertex3f(0.2,-0.2,0);//3
        glVertex3f(0.2,-0.2,0.1);//4

        glEnd();
    glPopMatrix();

    //Body(vue de gauche)
    glPushMatrix();
    //glColor3f(0,1,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.2,0.4,0.1);//1
        glVertex3f(-0.2,0.4,0);//2
        glVertex3f(-0.2,-0.2,0);//3
        glVertex3f(-0.2,-0.2,0.1);//4
        glEnd();
    glPopMatrix();

    //Body(vue de arriére)
    glPushMatrix();
    //glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.2,0.4,0);//1
        glVertex3f(0.2,0.4,0);//2
        glVertex3f(0.2,-0.2,0);//3
        glVertex3f(-0.2,-0.2,0);//4

        glEnd();
    glPopMatrix();

    //Right hand

    //Right hand(vue de face)
    glPushMatrix();
    //glColor3d(0,0,1);
    glTranslatef(-0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.28,0.4,0.1);//1
        glVertex3f(0.64,0.1,0.1);//2
        glVertex3f(0.6,0.03,0.1);//3
        glVertex3f(0.28,0.3,0.1);//4
        glEnd();
    glPopMatrix();

    //Right hand(vue de droit)
    glPushMatrix();
    //glColor3d(0,1,0);
    glTranslatef(-0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.64,0.1,0.1);//1
        glVertex3f(0.64,0.1,0);//2
        glVertex3f(0.6,0.03,0);//3
        glVertex3f(0.6,0.03,0.1);//4
        glEnd();
    glPopMatrix();

    //Right hand(vue de haut)
    glPushMatrix();
    //glColor3d(1,0,0);
    glTranslatef(-0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.28,0.4,0.1);//1
        glVertex3f(0.28,0.4,0);//2
        glVertex3f(0.64,0.1,0);//3
        glVertex3f(0.64,0.1,0.1);//4
        glEnd();
    glPopMatrix();

    //Right hand(vue de bas)
    glPushMatrix();
    //glColor3d(0,1,0);
    glTranslatef(-0.075,0,0);
        glBegin(GL_POLYGON);

        glVertex3f(0.28,0.3,0.1);//1
        glVertex3f(0.28,0.3,0);//2
        glVertex3f(0.6,0.03,0);//3
        glVertex3f(0.6,0.03,0.1);//4
        glEnd();
    glPopMatrix();


    //Right hand(vue de gauche)
    glPushMatrix();
    //glColor3d(1,1,0);
    glTranslatef(-0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.28,0.4,0.1);//1
        glVertex3f(0.28,0.4,0);//2
        glVertex3f(0.28,0.3,0);//3
        glVertex3f(0.28,0.3,0.1);//4
        glEnd();
    glPopMatrix();

    //Right hand(vue d'arriére)
    glPushMatrix();
    //glColor3d(1,0,0);
    glTranslatef(-0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.28,0.4,0);//1
        glVertex3f(0.64,0.1,0);//2
        glVertex3f(0.6,0.03,0);//3
        glVertex3f(0.28,0.3,0);//4
        glEnd();
    glPopMatrix();

    //Left hand

    //Left hand(vue de face)
    glPushMatrix();
    //glColor3d(0,0,1);
    glTranslatef(0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.28,0.4,0.1);//1
        glVertex3f(-0.64,0.1,0.1);//2
        glVertex3f(-0.6,0.03,0.1);//3
        glVertex3f(-0.28,0.3,0.1);//4
        glEnd();
    glPopMatrix();

     //Left hand(vue de droit)
    glPushMatrix();
    //glColor3d(0,1,0);
    glTranslatef(0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.28,0.4,0.1);//1
        glVertex3f(-0.28,0.4,0);//2
        glVertex3f(-0.28,0.3,0);//3
        glVertex3f(-0.28,0.3,0.1);//4
        glEnd();
    glPopMatrix();

    //Left hand(vue de haut)
    glPushMatrix();
    //glColor3d(0,1,0);
    glTranslatef(0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.28,0.4,0.1);//1
        glVertex3f(-0.28,0.4,0);//2
        glVertex3f(-0.64,0.1,0);//3
        glVertex3f(-0.64,0.1,0.1);//4
        glEnd();
    glPopMatrix();

    //Left hand(vue de bas)
    glPushMatrix();
    //glColor3d(0,1,0);
    glTranslatef(0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.28,0.3,0.1);//1
        glVertex3f(-0.28,0.3,0);//2
        glVertex3f(-0.6,0.03,0);//3
        glVertex3f(-0.6,0.03,0.1);//4
        glEnd();
    glPopMatrix();

     //Left hand(vue de gauche)
    glPushMatrix();
    //glColor3d(1,1,0);
    glTranslatef(0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.64,0.1,0.1);//1
        glVertex3f(-0.64,0.1,0);//2
        glVertex3f(-0.6,0.03,0);//3
        glVertex3f(-0.6,0.03,0.1);//4
        glEnd();
    glPopMatrix();

     //Left hand(vue d'arriére)
    glPushMatrix();
    //glColor3d(1,0,0);
    glTranslatef(0.075,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.28,0.4,0);//1
        glVertex3f(-0.64,0.1,0);//2
        glVertex3f(-0.6,0.03,0);//3
        glVertex3f(-0.28,0.3,0);//4
        glEnd();
    glPopMatrix();

    //Right foot

    //Right foot(vue de face)
    glPushMatrix();
    //glColor3d(0,0,1);
        glBegin(GL_POLYGON);
        glVertex3f(0.1,-0.2,0.1);//1
        glVertex3f(0.2,-0.2,0.1);//2
        glVertex3f(0.2,-0.7,0.1);//3
        glVertex3f(0.1,-0.7,0.1);//4
        glEnd();
    glPopMatrix();

    //Right foot(vue de droit)
    glPushMatrix();
    //glColor3d(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.2,-0.2,0.1);//1
        glVertex3f(0.2,-0.2,0);//2
        glVertex3f(0.2,-0.7,0);//3
        glVertex3f(0.2,-0.7,0.1);//4
        glEnd();
    glPopMatrix();

    //Right foot(vue de gauche)
    glPushMatrix();
    //glColor3d(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.1,-0.2,0.1);//1
        glVertex3f(0.1,-0.2,0);//2
        glVertex3f(0.1,-0.7,0);//3
        glVertex3f(0.1,-0.7,0.1);//4
        glEnd();
    glPopMatrix();

    //Right foot(vue d'arriére)
    glPushMatrix();
    //glColor3d(0,1,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.1,-0.2,0);//1
        glVertex3f(0.2,-0.2,0);//2
        glVertex3f(0.2,-0.7,0);//3
        glVertex3f(0.1,-0.7,0);//4
        glEnd();
    glPopMatrix();

    //Left foot

    //Left foot(vue de face)
    glPushMatrix();
    //glColor3d(0,0,1);
        glBegin(GL_POLYGON);
        glVertex3f(-0.1,-0.2,0.1);//1
        glVertex3f(-0.2,-0.2,0.1);//2
        glVertex3f(-0.2,-0.7,0.1);//3
        glVertex3f(-0.1,-0.7,0.1);//4
        glEnd();
    glPopMatrix();

    //Left foot(vue de droit)
    glPushMatrix();
    //glColor3d(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.1,-0.2,0.1);//1
        glVertex3f(-0.1,-0.2,0);//2
        glVertex3f(-0.1,-0.7,0);//3
        glVertex3f(-0.1,-0.7,0.1);//4
        glEnd();
    glPopMatrix();

    //Left foot(vue de gauche)
    glPushMatrix();
    //glColor3d(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.2,-0.2,0.1);//1
        glVertex3f(-0.2,-0.2,0);//2
        glVertex3f(-0.2,-0.7,0);//3
        glVertex3f(-0.2,-0.7,0.1);//4
        glEnd();
    glPopMatrix();

    //Left foot(vue d'arriére)
    glPushMatrix();
    //glColor3d(0,1,0);
        glBegin(GL_POLYGON);
        glVertex3f(-0.1,-0.2,0);//1
        glVertex3f(-0.2,-0.2,0);//2
        glVertex3f(-0.2,-0.7,0);//3
        glVertex3f(-0.1,-0.7,0);//4
        glEnd();
    glPopMatrix();

    //Right eye
    glPushMatrix();
    glColor3d(0,1,1);
        glTranslated(0.06,0.58,0.2);
        glutSolidSphere(0.025,slices,stacks);
    glPopMatrix();

    //Left eye
    glPushMatrix();
    glColor3d(0,1,1);
        glTranslated(-0.06,0.58,0.2);
        glutSolidSphere(0.025,slices,stacks);
    glPopMatrix();

    //Smile
    glPushMatrix();
    glTranslated(0,0,0);
        glBegin(GL_POLYGON);
            glColor3d(0,1,1);

    for(int i=0;i<neutre;i++){
        glVertex3f(cos(3.14159/1000*i)/15,sin(s/1000*i)/15+0.5,0.2);
    }
        glEnd();
    glPopMatrix();

    glPopMatrix();

    //piste (vert)
    glPushMatrix();
    //glTranslatef(0,-0.05,4);
    glColor3ub(63, 111, 7);
    glTranslatef(0,0,0);
    glScalef(10,10,6);
    glRotated(90,1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);
        glVertex3f(-1,-1,0);
    glEnd();
    glPopMatrix();

    //piste (gris)

    glPushMatrix();
    //glTranslatef(0,-0.05,4);
    glColor3ub(96, 96, 96);
    glTranslatef(0,0.01,0);
    glScalef(2.1,0,5.9);
    glRotated(90,1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);
        glVertex3f(-1,-1,0);
    glEnd();
    glPopMatrix();

        glColor3f(itf(255),itf(255),itf(255));
    for(float i = -4.49; i<5; i+= 1.25)
    {
        glBegin(GL_QUADS);
        glVertex3f(-0.1,-0.44,i+0.5);
        glVertex3f(0.1,-0.44,i+0.5);
        glVertex3f(0.1,-0.44,i-0.5);
        glVertex3f(-0.1,-0.44,i-0.5);
        glEnd();
    }

    //obstacle 1
    glPushMatrix();
        glTranslatef(1,0.5,-4);
        glColor3d(255,0,0);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,4,0.5);
        glutSolidCube(1);
    glPopMatrix();

    //obstacle 2
    glPushMatrix();
        glTranslatef(-1,0.5,-2);
        glColor3d(255,255,255);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
           glScalef(0.5,4,0.5);
        glutSolidCube(1);
    glPopMatrix();

    //obstacle 3
    glPushMatrix();
        glTranslatef(0,0.5,1);
         glColor3d(255,0,0);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,4,0.5);
        glutSolidCube(1);
    glPopMatrix();
    //obstacle 4
    glPushMatrix();
        glTranslatef(-1,0.5,3);
                 glColor3d(255,0,0);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,4,0.5);
        glutSolidCube(1);
    glPopMatrix();
       //obstacle 5
    glPushMatrix();
        glTranslatef(0.5,0.5,4.8);
glColor3d(255,255,255);

        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,4,0.5);
        glutSolidCube(1);
    glPopMatrix();

    //trees
    //tree 1 left
    glPushMatrix();
        glTranslatef(3,1,-1);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 1
    glPushMatrix();
        glTranslatef(3,2,-1);
       glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();


    //tree 2 left
    glPushMatrix();
        glTranslatef(3,1,2);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 2
    glPushMatrix();
        glTranslatef(3,2,2);
        glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    //tree 3 left
    glPushMatrix();
        glTranslatef(3,1,5);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 3
    glPushMatrix();
        glTranslatef(3,2,5);
       glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    //tree 1 right
    glPushMatrix();
        glTranslatef(-3,1,-1);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 1
    glPushMatrix();
        glTranslatef(-3,2,-1);
       glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    //tree 2 right
    glPushMatrix();
        glTranslatef(-3,1,2);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 2
    glPushMatrix();
        glTranslatef(-3,2,2);
       glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    //tree 3 right
    glPushMatrix();
        glTranslatef(-3,1,5);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 3
    glPushMatrix();
        glTranslatef(-3,2,5);
        glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();
      //tree 4 right
    glPushMatrix();
        glTranslatef(-6,1,-1);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 1
    glPushMatrix();
        glTranslatef(-6,2,-1);
       glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

    //tree 5 right
    glPushMatrix();
        glTranslatef(-6,1,2);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 2
    glPushMatrix();
      glTranslatef(-6,2,2);
       glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();

     //tree 4 left
    glPushMatrix();
        glTranslatef(6,1,-1);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 1
    glPushMatrix();
        glTranslatef(6,2,-1);
       glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();


    //tree 5 left
    glPushMatrix();
        glTranslatef(6,1,2);
        glColor3ub(139, 69, 19);
        //glRotatef(angle, 0.1, 0.2, 0.5);
        //glColor3ub(255,255,0);
        glScalef(0.5,2.5,0.2);
        glutSolidCube(1);
    glPopMatrix();

    //leaves 2
    glPushMatrix();
        glTranslatef(6,2,2);
        glColor3ub(0, 102, 51);
        glutSolidSphere(0.5,slices,stacks);
    glPopMatrix();


    glutSwapBuffers();
}

void Resize(int width, int height) {



    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glEnable(GL_DEPTH_TEST);
    glutSpecialFunc(tClavierSpec);
    glutKeyboardFunc(tClavierCouleur);
    glutMouseFunc(sMouse);
    glutDisplayFunc(display);
    glutReshapeFunc(Resize);
    glutMainLoop();
    return EXIT_SUCCESS;
}
bool gameStart = false;
float x = 0;
void tClavierSpec(int key, int x, int yZ)
{
    switch(key){
    case GLUT_KEY_UP:
        yNouv += 0.05; break;
    case GLUT_KEY_DOWN:
        yNouv -= 0.05; break;
    case GLUT_KEY_LEFT:
        xNouv += 0.05; break;
    case GLUT_KEY_RIGHT:
        xNouv -= 0.05; break;
    default:
        printf("choisir une autre touche"); break;
    }
    glutPostRedisplay();
}
void tClavierCouleur(unsigned char key, int x, int y){
    switch(key){
        case 'x':
               r = 1; v = 1; b = 1; break;
        case'h':e1=0,e2=1.9,e3=0,e4=1,e5=-3,e6=0,e7=1,e8=0,zCam=4.5;

               break;

   case 'L':
        case 'l':
           e1=0,e2=1.9,zCam=-4.5,e3=0,e4=1,e5=3,e6=0,e7=1,e8=0;

             glutPostRedisplay;
             break;
             case 'a':
        zNouv+=0.05;break;

    case 'r':
        r = 1; v = 0; b = 0; break;
    case 'b':
        r = 0; v = 0; b = 1; break;
    case 'v':
        r = 0; v = 1; b = 0; break;
    case 's':
        s= -3.14159; neutre = 1000; break;
    case 't':
        s = 3.14159; neutre = 1000; break;
    case 'z':
        zNouv+=0.05; zCam-=0.025;break;
    case 'w':
         zNouv-=0.05; zCam+=0.025;break;
    case 'i':
        neutre = 0; break;
    default:
        printf("choisir une autre touche"); break;
    }
    glutPostRedisplay();
}

void sMouse (int button, int state, int x, int y){
    switch(button){
    case GLUT_LEFT_BUTTON:
        //printf("boutton gauche");
        if(state == GLUT_DOWN) {a+=20;}
        break;
    case GLUT_RIGHT_BUTTON:
        //printf("boutton droit");
        if(state == GLUT_DOWN) {a-=20;}
        break;
    default:
        printf("choose another key"); break;
    }
}
