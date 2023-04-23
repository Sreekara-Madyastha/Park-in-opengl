#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
// #include<GL/gl.h>
// #include "SOIL/SOIL.h" 



float Angle=0;
float Direction=0;
float people[2][2]={{0.3,0.2},{-2.3,0.7}};

#include "movement.cpp"
#include "objects.cpp"

int widthWindow=900, heightWindow=700;
static GLfloat viewer[] = {0.0,1.8,-2.8};





void spin(){
    if(wheel_on){
        T=T+5;
        if(T>360){
            T=0;
        }
        glutPostRedisplay();
    }
}


void displayMe(void)
{
    glTranslatef(Tx,Ty,Tz);
    glRotatef(Rx,1,0,0);
    glRotatef(Ry,0,1,0);
    glRotatef(Rz,0,0,1);
    
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
    Lake(1.5,0.4,0.5);
    seeSaw();
    slide();
    ferris_wheel(-0.3,0.7);
    person(people[0][0],people[0][1],0);
    person(people[1][0],people[1][1],1);
    Lights_spam();
    Tree_spam();
    swing();
    merryGoRound();
    Entrance();
    shop();
    Bases();
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

 

    glClearColor(0,0,0,1);
    glClearDepth(1.0f);
 

    GLfloat globalAmbient[] = {0.3, 0.3, 0.3, 1.0};

 

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);

    glShadeModel(GL_SMOOTH);

 

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

 
for(float i=-0.5;i<=1;i++){
        Street_light(2.2,i);
        Street_light(0.8,i);
    }
        Street_light(-1.4,0.3);
        Street_light(-2.9,0.3);
    Street_light(-0.3,-0.4);

    GLfloat L_Ambient[] = {1, 1, 1, 1};

    GLfloat L_Diffuse[]= {0.0, 0.0, 0.0, 1.0};

    GLfloat L1_postion[] = {2.2,0.6,-0.5, 1.0};
    GLfloat L2_postion[] = {2.2,0.6,-0.5, 1.0};
    GLfloat L3_postion[] = {0.8,0.6,0.5, 1.0};
    GLfloat L4_postion[] = {0.8,0.6,0.5, 1.0};
    GLfloat L5_postion[] = {-1.4,0.6,0.3, 1.0};
    GLfloat L6_postion[] = {-2.9,0.6,0.3, 1.0};
    GLfloat L7_postion[] = {-0.3,0.6,-0.4, 1.0};

   
 

    glLightfv(GL_LIGHT1, GL_AMBIENT, L_Ambient);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, L_Diffuse);

    glLightfv(GL_LIGHT1, GL_POSITION, L1_postion);

 

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1);

    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 1);

    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 1);

 

    glLightfv(GL_LIGHT2, GL_AMBIENT, L_Ambient);

    glLightfv(GL_LIGHT2, GL_DIFFUSE, L_Diffuse);

    glLightfv(GL_LIGHT2, GL_POSITION, L2_postion);

 

    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1);

    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 1);

    glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 1);

 

    glLightfv(GL_LIGHT3, GL_AMBIENT, L_Ambient);

    glLightfv(GL_LIGHT3, GL_DIFFUSE, L_Diffuse);

    glLightfv(GL_LIGHT3, GL_POSITION, L3_postion);

 

    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1);

    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 1);

    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 1);

 

    glLightfv(GL_LIGHT4, GL_AMBIENT, L_Ambient);

    glLightfv(GL_LIGHT4, GL_DIFFUSE, L_Diffuse);

    glLightfv(GL_LIGHT4, GL_POSITION, L4_postion);

 

    glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1);

    glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 1);

    glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 1);

 

    glLightfv(GL_LIGHT5, GL_AMBIENT, L_Ambient);

    glLightfv(GL_LIGHT5, GL_DIFFUSE, L_Diffuse);

    glLightfv(GL_LIGHT5, GL_POSITION, L5_postion);

 

    glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 1);

    glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 1);

    glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 1);

 

    glLightfv(GL_LIGHT6, GL_AMBIENT, L_Ambient);

    glLightfv(GL_LIGHT6, GL_DIFFUSE, L_Diffuse);

    glLightfv(GL_LIGHT6, GL_POSITION, L4_postion);

 

    glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, 1);

    glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 1);

    glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 1);

 

    glLightfv(GL_LIGHT7, GL_AMBIENT, L_Ambient);

    glLightfv(GL_LIGHT7, GL_DIFFUSE, L_Diffuse);

    glLightfv(GL_LIGHT7, GL_POSITION, L5_postion);

 

    glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 1);

    glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 1);

    glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 1);

 

 


 

    GLfloat specularReflectance[] = {1, 1, 1, 1.0};

 

    glMaterialfv(GL_FRONT, GL_SPECULAR, specularReflectance);

 

    glMateriali(GL_FRONT, GL_SHININESS, 50);

 

    glEnable(GL_COLOR_MATERIAL);

 

    glEnable(GL_LIGHT0);

    glEnable(GL_LIGHT1);

    glEnable(GL_LIGHT2);

    glEnable(GL_LIGHT3);

    glEnable(GL_LIGHT4);

    glEnable(GL_LIGHT5);

    glEnable(GL_LIGHT6);

    glEnable(GL_LIGHT7);
    
    glEnable(GL_NORMALIZE);
    GLUquadricObj *qobj;


    qobj = gluNewQuadric();

    gluQuadricDrawStyle(qobj, GLU_FILL);

    gluQuadricNormals(qobj, GLU_SMOOTH);

    //glEnable(GL_LIGHT1);

   

}

void displayGraphics(){
	// glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,widthWindow, heightWindow);
    gluPerspective(45,(float)widthWindow/heightWindow, .1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);


    displayMe();
    glFlush();

}
int main(int argc,char** argv)
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(widthWindow, heightWindow);
	glutInitWindowPosition(400,100);
	glutCreateWindow("PARK IN OPENGL");
    initialize();
	glutDisplayFunc(displayGraphics);

    glutIdleFunc(spin);
	glutReshapeFunc(reshapeWindowChange);
	glutKeyboardFunc(keyboard);
    glutSpecialFunc(Person_movement);
    glutMotionFunc(mouse);
	
	glutMainLoop();
	return 1;
}
