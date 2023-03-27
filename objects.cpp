#include<bits/stdc++.h>
#include <GL/glut.h>
#define PI 3.14159

float ver[8][3] = {
    {-3.0,0.15,-1.5},
    {-3.0,0.15,1.5},
    {3.0,0.15,1.5},
    {3.0,0.15,-1.5},
    {-3.0,-0.0,-1.5},
    {-3.0,-0.0,1.5},
    {3.0,-0.0,1.5},
    {3.0,-0.0,-1.5},
};

float ver1[8][3] = {
    {-3.0,0.0,-1.5},
    {-3.0,0.0,1.5},
    {3.0,0.0,1.5},
    {3.0,0.0,-1.5},
    {-3.0,-0.15,-1.5},
    {-3.0,-0.15,1.5},
    {3.0,-0.15,1.5},
    {3.0,-0.15,-1.5},
};

void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
    glColor3f(0.188f,1.0f,0.0f);
    glVertex3fv(ver[a]);
    glVertex3fv(ver[b]);
    glVertex3fv(ver[c]);
    glVertex3fv(ver[d]);

    glColor3f(0.588f,0.294f,0.0f);
    glVertex3fv(ver1[a]);
    glVertex3fv(ver1[b]);
    glVertex3fv(ver1[c]);
    glVertex3fv(ver1[d]);
    
    glEnd();
}

void colorcube()
{
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
}

void drawWalls()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(3.0,0.15,1.5);
    glVertex3f(3.0,0.20,1.5);
    glVertex3f(3.0,0.20,-1.5);
    glVertex3f(3.0,0.15,-1.5);

    glVertex3f(-3.0,0.15,1.5);
    glVertex3f(-3.0,0.20,1.5);
    glVertex3f(-3.0,0.20,-1.5);
    glVertex3f(-3.0,0.15,-1.5);

    glVertex3f(-3.0,0.15,1.5);
    glVertex3f(-3.0,0.20,1.5);
    glVertex3f(3.0,0.20,1.5);
    glVertex3f(3.0,0.15,1.5);

    glVertex3f(-3.0,0.15,-1.5);
    glVertex3f(-3.0,0.20,-1.5);
    glVertex3f(3.0,0.20,-1.5);
    glVertex3f(3.0,0.15,-1.5);
    
    glEnd();
}


void bench2(float c1[],float c2[])

{

 

    //Legs

    float radius=0.050;

    float xo=c1[0]+radius,yo=c1[1],zo=c1[2],xo2=c2[0]+radius,yo2=c2[1],zo2=c2[2];

    for(int i=1;i<500;i++){

        float x=c1[0]+radius*(cos(2*PI*i/500));

        float z=c1[2]+radius*(sin(2*PI*i/500));

        float x2=c2[0]+radius*(cos(2*PI*i/500));

        float z2=c2[2]+radius*(sin(2*PI*i/500));

        glBegin(GL_QUADS);

        glColor3f(0.135,0.065,0.001);

        glVertex3f(xo,yo,zo);

        glVertex3f(x,yo,z);

        glVertex3f(x,(yo+0.100),z);

        glVertex3f(xo,(yo+0.100),zo);//Taking the y axis of ground to be 0

        glEnd();

        glBegin(GL_QUADS);

        glColor3f(0.135,0.065,0.001);

        glVertex3f(xo2,yo2,zo2);

        glVertex3f(x2,yo2,z2);

        glVertex3f(x2,(yo2+0.100),z2);

        glVertex3f(xo2,(yo2+0.100),zo2);//Taking the y axis of ground to be 0

        glEnd();

        xo=x;

        zo=z;

        xo2=x2;

        zo2=z2;

    }

 

    glBegin(GL_QUADS);

    glColor3f(0.135,0.065,0.001); //Front

    glVertex3f(c1[0]-0.100,c1[1]+0.100,c1[2]+0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.100,c2[2]+0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.130,c2[2]+0.100);

    glVertex3f(c1[0]-0.100,c2[1]+0.130,c2[2]+0.100);

    glColor3f(0.135,0.065,0.001); //side R

    glVertex3f(c2[0]+0.100,c2[1]+0.100,c2[2]+0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.100,c2[2]-0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.130,c2[2]-0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.130,c2[2]+0.100);

    glColor3f(0.135,0.065,0.001); //Side L

    glVertex3f(c1[0]+0.100,c1[1]+0.100,c1[2]+0.100);

    glVertex3f(c1[0]+0.100,c1[1]+0.100,c1[2]-0.100);

    glVertex3f(c1[0]+0.100,c1[1]+0.130,c1[2]-0.100);

    glVertex3f(c1[0]+0.100,c1[1]+0.130,c1[2]+0.100);

    glColor3f(0.135,0.065,0.001); //Back

    glVertex3f(c1[0]-0.100,c1[1]+0.100,c1[2]-0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.100,c2[2]-0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.130,c2[2]-0.100);

    glVertex3f(c1[0]-0.100,c2[1]+0.130,c2[2]-0.100);

    glColor3f(0.135,0.065,0.001); //Top

    glVertex3f(c1[0]-0.100,c1[1]+0.130,c1[2]+0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.130,c2[2]+0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.130,c2[2]-0.100);

    glVertex3f(c1[0]-0.100,c1[1]+0.130,c1[2]-0.100);

    glColor3f(0.135,0.065,0.001); //Bottom

    glVertex3f(c1[0]-0.100,c1[1]+0.100,c1[2]+0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.100,c2[2]+0.100);

    glVertex3f(c2[0]+0.100,c2[1]+0.100,c2[2]-0.100);

    glVertex3f(c1[0]-0.100,c1[1]+0.100,c1[2]-0.100);

    glEnd();

}