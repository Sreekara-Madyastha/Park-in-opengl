#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include "movement.cpp"
#include "objects.cpp"

int widthWindow=900, heightWindow=700;
static GLdouble viewer[] = {0.0,0.8,2.0};

void displayMe(void)
{
    glRotatef(Rx,1,0,0);
    glRotatef(Ry,0,1,0);
    glRotatef(Rz,0,0,1);
    glTranslatef(Tx,Ty,Tz);
    glScalef(S,S,S);
    
    GLfloat v[8][3]={
        {0,0,0},
        {0,0.1,0},
        {0.1,0.1,0},
        {0.1,0,0},
        {0,0,0.1},
        {0,0.1,0.1},
        {0.1,0.1,0.1},
        {0.1,0,0.1},
        
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    colorcube();
    drawWalls();
    float c1[]={-0.9,0.15,-1.3},c2[]={-0.70,0.15,-1.3};
    bench2(c1,c2);
    float c3[]={-0.4,0.15,-1.3},c4[]={-0.2,0.15,-1.3};
    bench2(c3,c4);
    float c5[]={0.10,0.15,-1.3},c6[]={0.30,0.15,-1.3};
    bench2(c5,c6);
    spam_grass();
    roads();
    Lake(1.4,0.7,0.4);
    glutSwapBuffers();
}
void MyInit(){
    glClearColor(0,0,0,1);
    glColor3f(1,0,0);
    glEnable(GL_DEPTH_TEST);
}
void reshapeWindowChange(int width, int height){
	if(height == 0)
		height = 1;
	float ratio = 10.0 * width / height;
	widthWindow = width;
	heightWindow = height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,width, height);
	gluPerspective(45,ratio, .1, 100);
}

void initialize(){
	glClearColor(0.45,0.843,1,1);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
}

void displayGraphics(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,widthWindow, heightWindow);
    gluPerspective(45,(float)widthWindow/heightWindow, .1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);


    displayMe();

}
int main(int argc,char** argv)
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(widthWindow, heightWindow);
	glutInitWindowPosition(400,100);
	glutCreateWindow("cube");
	glutDisplayFunc(displayGraphics);
	glutReshapeFunc(reshapeWindowChange);
	glutKeyboardFunc(keyboard);
    glutMotionFunc(mouse);
	initialize();
	glutMainLoop();
	return 1;
}