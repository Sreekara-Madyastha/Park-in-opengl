#include <iostream>
#include <GL/glut.h>
#include "SOIL/SOIL.h"
#define PI 3.14159
using namespace std;

GLint LoadGLTexture(const char *filename)
{
    GLuint textureID = SOIL_load_OGL_texture(
        filename,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    return textureID;
}


void Cylin_draw(float radius,float height,float X,float Y,float Z);
void Draw_cube(float v[][3]);

float ver[8][3] = {
    {-3.0, 0.15, -1.5},
    {-3.0, 0.15, 1.5},
    {3.0, 0.15, 1.5},
    {3.0, 0.15, -1.5},
    {-3.0, -0.0, -1.5},
    {-3.0, -0.0, 1.5},
    {3.0, -0.0, 1.5},
    {3.0, -0.0, -1.5},
};

void spam_grass(void)
{
    for (float p = -1.5; p < 1.5; p += 0.015)
    { // Left area
        for (float q = -3.0; q < -1.307; q += 0.015)
        {
            float radius = 0.005;
            float xo = q;
            float yo = p;
            float zo = 0.163;
            for (int i = 1; i < 10; i++)
            {
                float x = q + radius * (cos(2 * PI * i / 10));
                float y = p + radius * (sin(2 * PI * i / 10));
                glColor3f(0, 0.51, 0);
                glBegin(GL_TRIANGLES);
                glVertex3f(q + 0.02, zo, p);
                glVertex3f(xo, 0.15, yo);
                glVertex3f(x, 0.15, y);
                glEnd();
                xo = x;
                yo = y;
            }
        }
    }
    for (float p = -0.1; p < 1.5; p += 0.015)
    { // Middle Bottom part
        for (float q = -1.1; q < 0.5; q += 0.015)
        {
            float radius = 0.005;
            float xo = q;
            float yo = p;
            float zo = 0.163;
            for (int i = 1; i < 10; i++)
            {
                float x = q + radius * (cos(2 * PI * i / 10));
                float y = p + radius * (sin(2 * PI * i / 10));
                glColor3f(0, 0.51, 0);
                glBegin(GL_TRIANGLES);
                glVertex3f(q + 0.02, zo, p);
                glVertex3f(xo, 0.15, yo);
                glVertex3f(x, 0.15, y);
                glEnd();
                xo = x;
                yo = y;
            }
        }
    }
    for (float p = -1.5; p < -0.3; p += 0.015)
    { // Middle Top part
        for (float q = -1.1; q < 0.5; q += 0.015)
        {
            float radius = 0.005;
            float xo = q;
            float yo = p;
            float zo = 0.163;
            // Top Cone
            for (int i = 1; i < 10; i++)
            {
                float x = q + radius * (cos(2 * PI * i / 10));
                float y = p + radius * (sin(2 * PI * i / 10));
                glColor3f(0, 0.51, 0);
                glBegin(GL_TRIANGLES);
                glVertex3f(q + 0.02, zo, p);
                glVertex3f(xo, 0.15, yo);
                glVertex3f(x, 0.15, y);
                glEnd();
                xo = x;
                yo = y;
            }
        }
    }
    for (float p = -1.5; p < 1.5; p += 0.015)
    { // Right part
        for (float q = 0.7; q < 2.3; q += 0.015)
        {
            float radius = 0.005;
            float xo = q;
            float yo = p;
            float zo = 0.163;
            // Top Cone
            for (int i = 1; i < 10; i++)
            {
                float x = q + radius * (cos(2 * PI * i / 10));
                float y = p + radius * (sin(2 * PI * i / 10));
                glColor3f(0, 0.51, 0);
                glBegin(GL_TRIANGLES);
                glVertex3f(q + 0.02, zo, p);
                glVertex3f(xo, 0.15, yo);
                glVertex3f(x, 0.15, y);
                glEnd();
                xo = x;
                yo = y;
            }
        }
    }
    for (float p = -1.5; p < 1.5; p += 0.015)
    { // Rightmost part
        for (float q = 2.5; q < 2.98; q += 0.015)
        {
            float radius = 0.005;
            float xo = q;
            float yo = p;
            float zo = 0.163;
            // Top Cone
            for (int i = 1; i < 10; i++)
            {
                float x = q + radius * (cos(2 * PI * i / 10));
                float y = p + radius * (sin(2 * PI * i / 10));
                glColor3f(0, 0.51, 0);
                glBegin(GL_TRIANGLES);
                glVertex3f(q + 0.02, zo, p);
                glVertex3f(xo, 0.15, yo);
                glVertex3f(x, 0.15, y);
                glEnd();
                xo = x;
                yo = y;
            }
        }
    }
}

void roads(void)
{
    glColor3f(1,1,1);
    GLuint texture = LoadGLTexture("images/road.png");
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    // Left road  X Z Y
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.3, 0.151, -1.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.1, 0.151, -1.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.1, 0.151, 1.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.3, 0.151, 1.5);
    glEnd();
    
    // Middle road
    glBegin(GL_QUADS);
    // glColor3f(0, 0, 0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5, 0.151, -1.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.7, 0.151, -1.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.7, 0.151, 1.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5, 0.151, 1.5);
    glEnd();
    
    // Right road
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(2.3, 0.151, -1.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(2.5, 0.151, -1.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(2.5, 0.151, 1.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(2.3, 0.151, 1.5);
    glEnd();
    
    // Left to Middle road
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.1, 0.151, -0.1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.1, 0.151, -0.3);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.151, -0.3);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5, 0.151, -0.1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
}

float ver1[8][3] = {
    {-3.0, 0.0, -1.5},
    {-3.0, 0.0, 1.5},
    {3.0, 0.0, 1.5},
    {3.0, 0.0, -1.5},
    {-3.0, -0.15, -1.5},
    {-3.0, -0.15, 1.5},
    {3.0, -0.15, 1.5},
    {3.0, -0.15, -1.5},
};

void quad(int a, int b, int c, int d)
{
    glBegin(GL_QUADS);
    glColor4f(0.588f, 0.294f, 0.0f, 0.2);
    glVertex3fv(ver[a]);
    glVertex3fv(ver[b]);
    glVertex3fv(ver[c]);
    glVertex3fv(ver[d]);

    glColor3f(0.588f, 0.294f, 0.0f);
    glVertex3fv(ver1[a]);
    glVertex3fv(ver1[b]);
    glVertex3fv(ver1[c]);
    glVertex3fv(ver1[d]);

    glEnd();
}

void colorcube()
{
    quad(0, 3, 2, 1);
    quad(2, 3, 7, 6);
    quad(0, 4, 7, 3);
    quad(1, 2, 6, 5);
    quad(4, 5, 6, 7);
    quad(0, 1, 5, 4);
}

void drawWalls()
{
    glBegin(GL_QUADS);
    glColor3f(0.825f, 0.768f, 0.631f);
    glVertex3f(3.0, 0.15, 1.5);
    glVertex3f(3.0, 0.20, 1.5);
    glVertex3f(3.0, 0.20, -1.5);
    glVertex3f(3.0, 0.15, -1.5);

    glVertex3f(-3.0, 0.15, 1.5);
    glVertex3f(-3.0, 0.20, 1.5);
    glVertex3f(-3.0, 0.20, -1.5);
    glVertex3f(-3.0, 0.15, -1.5);

    glVertex3f(-3.0, 0.15, 1.5);
    glVertex3f(-3.0, 0.20, 1.5);
    glVertex3f(3.0, 0.20, 1.5);
    glVertex3f(3.0, 0.15, 1.5);

    glVertex3f(-3.0, 0.15, -1.5);
    glVertex3f(-3.0, 0.20, -1.5);
    glVertex3f(3.0, 0.20, -1.5);
    glVertex3f(3.0, 0.15, -1.5);

    glEnd();
}

void bench2(float c1[], float c2[])
{

    // Legs

    float radius = 0.030;

    float xo = c1[0] + radius, yo = c1[1], zo = c1[2], xo2 = c2[0] + radius, yo2 = c2[1], zo2 = c2[2];

    for (int i = 1; i < 500; i++)
    {

        float x = c1[0] + radius * (cos(2 * PI * i / 500));

        float z = c1[2] + radius * (sin(2 * PI * i / 500));

        float x2 = c2[0] + radius * (cos(2 * PI * i / 500));

        float z2 = c2[2] + radius * (sin(2 * PI * i / 500));

        glBegin(GL_QUADS);

        // glColor3f(0,0,0.7);

        glColor3f(0.135, 0.065, 0.001);

        glVertex3f(xo, yo, zo);

        glVertex3f(x, yo, z);

        glVertex3f(x, (yo + 0.07), z);

        glVertex3f(xo, (yo + 0.07), zo); // Taking the y axis of ground to be 0

        glEnd();

        glBegin(GL_QUADS);

        glColor3f(0.135, 0.065, 0.001);

        glVertex3f(xo2, yo2, zo2);

        glVertex3f(x2, yo2, z2);

        glVertex3f(x2, (yo2 + 0.07), z2);

        glVertex3f(xo2, (yo2 + 0.07), zo2); // Taking the y axis of ground to be 0

        glEnd();

        xo = x;

        zo = z;

        xo2 = x2;

        zo2 = z2;
    }

    glBegin(GL_QUADS);

    glColor3f(0.135, 0.065, 0.001); // Front

    glVertex3f(c1[0] - 0.05, c1[1] + 0.07, c1[2] + 0.05);
    glVertex3f(c2[0] + 0.05, c2[1] + 0.07, c2[2] + 0.05);
    glVertex3f(c2[0] + 0.05, c2[1] + 0.123, c2[2] + 0.05);
    glVertex3f(c1[0] - 0.05, c2[1] + 0.123, c2[2] + 0.05);

    glColor3f(0.135, 0.065, 0.001); // side R

    glVertex3f(c2[0] + 0.05, c2[1] + 0.07, c2[2] + 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.07, c2[2] - 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.123, c2[2] - 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.123, c2[2] + 0.05);

    glColor3f(0.135, 0.065, 0.001); // Side L

    glVertex3f(c1[0] + 0.05, c1[1] + 0.07, c1[2] + 0.05);

    glVertex3f(c1[0] + 0.05, c1[1] + 0.07, c1[2] - 0.05);

    glVertex3f(c1[0] + 0.05, c1[1] + 0.123, c1[2] - 0.05);

    glVertex3f(c1[0] + 0.05, c1[1] + 0.123, c1[2] + 0.05);

    glColor3f(0.135, 0.065, 0.001); // Back

    glVertex3f(c1[0] - 0.05, c1[1] + 0.07, c1[2] - 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.07, c2[2] - 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.123, c2[2] - 0.05);

    glVertex3f(c1[0] - 0.05, c2[1] + 0.123, c2[2] - 0.05);

    glColor3f(0.135, 0.065, 0.001); // Top

    glVertex3f(c1[0] - 0.05, c1[1] + 0.123, c1[2] + 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.123, c2[2] + 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.123, c2[2] - 0.05);

    glVertex3f(c1[0] - 0.05, c1[1] + 0.123, c1[2] - 0.05);

    glColor3f(0.135, 0.065, 0.001); // Bottom

    glVertex3f(c1[0] - 0.05, c1[1] + 0.07, c1[2] + 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.07, c2[2] + 0.05);

    glVertex3f(c2[0] + 0.05, c2[1] + 0.07, c2[2] - 0.05);

    glVertex3f(c1[0] - 0.05, c1[1] + 0.07, c1[2] - 0.05);

    glEnd();
}

void cuboid(float X,float Y,float Z,float L,float B,float H){
    float cuboid[8][3]={
        {X,Y,Z},
        {X+L,Y,Z},
        {X+L,Y,Z-B},
        {X,Y,Z-B},
        {X,Y-H,Z},
        {X+L,Y-H,Z},
        {X+L,Y-H,Z-B},
        {X,Y-H,Z-B},
    };
    glBegin(GL_QUADS);
        
        glVertex3f(cuboid[0][0],cuboid[0][1],cuboid[0][2]);
        glVertex3f(cuboid[1][0],cuboid[1][1],cuboid[1][2]);
        glVertex3f(cuboid[2][0],cuboid[2][1],cuboid[2][2]);
        glVertex3f(cuboid[3][0],cuboid[3][1],cuboid[3][2]);

        glVertex3f(cuboid[4][0],cuboid[4][1],cuboid[4][2]);
        glVertex3f(cuboid[5][0],cuboid[5][1],cuboid[5][2]);
        glVertex3f(cuboid[6][0],cuboid[6][1],cuboid[6][2]);
        glVertex3f(cuboid[7][0],cuboid[7][1],cuboid[7][2]);
        
        glVertex3f(cuboid[0][0],cuboid[0][1],cuboid[0][2]);
        glVertex3f(cuboid[1][0],cuboid[1][1],cuboid[1][2]);
        glVertex3f(cuboid[5][0],cuboid[5][1],cuboid[5][2]);
        glVertex3f(cuboid[4][0],cuboid[4][1],cuboid[4][2]);

        glVertex3f(cuboid[2][0],cuboid[2][1],cuboid[2][2]);
        glVertex3f(cuboid[3][0],cuboid[3][1],cuboid[3][2]);
        glVertex3f(cuboid[7][0],cuboid[7][1],cuboid[7][2]);
        glVertex3f(cuboid[6][0],cuboid[6][1],cuboid[6][2]);

        glVertex3f(cuboid[1][0],cuboid[1][1],cuboid[1][2]);
        glVertex3f(cuboid[2][0],cuboid[2][1],cuboid[2][2]);
        glVertex3f(cuboid[6][0],cuboid[6][1],cuboid[6][2]);
        glVertex3f(cuboid[5][0],cuboid[5][1],cuboid[5][2]);

        glVertex3f(cuboid[0][0],cuboid[0][1],cuboid[0][2]);
        glVertex3f(cuboid[3][0],cuboid[3][1],cuboid[3][2]);
        glVertex3f(cuboid[7][0],cuboid[7][1],cuboid[7][2]);
        glVertex3f(cuboid[4][0],cuboid[4][1],cuboid[4][2]);

    glEnd();
}

void drawCylinder(float radius,float height,float X,float Y,float Z){
    float Cx=X,Cy=Y,Cz=Z;
    for(int i=1;i<1000;i++){
        float x=Cx+radius*(cos(2*PI*i/1000));
        float z=Cz+radius*(sin(2*PI*i/1000));
        glBegin(GL_QUADS);
        glVertex3f(Cx,Cy,Cz);
        glVertex3f(x,Cy,z);
        glVertex3f(x,Cy+height,z);
        glVertex3f(Cx,Cy+height,Cz);
        glEnd();
    }
}

void seat(){
    glRotatef(45,1,0,0);
    drawCylinder(0.005,0.1414,0.0,-0.1414,0.0);
    glRotatef(-90,1,0,0);
    drawCylinder(0.005,0.1414,0.0,-0.1414,0.0);
    glRotatef(45,1,0,0);
    cuboid(-0.05,-0.1,0.1,0.1,0.2,0.01);
}

void ferris_wheel(float X,float Z){
    glTranslatef(X,0.0,Z);
    float h=0.9;
    float r=0.7*h;
    // stand
    glColor3f(0,0.5,0.5);
    drawCylinder(0.01,h,0.0,0.15,+0.15);
    drawCylinder(0.01,h,0.0,0.15,-0.15);

    //outer ring
    glColor3f(0.5,0.5,0.5);

    glTranslatef(0,h+0.15,-0.15);
    glutSolidTorus(0.02,r,50,50);
    glTranslatef(0,0.0,0.3);
    glutSolidTorus(0.02,r,50,50);
    glColor3f(0,0.5,0.5);
    glRotatef(90,1,0,0);
    drawCylinder(0.01,0.3,0.0,-0.3,0.0);
    glRotatef(-90,1,0,0);

    glTranslatef(0,-h-0.15,-0.15);

    //drawing spikes and seats
    for(int j=0;j<12;j++){
        glTranslatef(0.0,h+0.15,0);
        glRotatef(-360*j/12-T,0,0,1);
        //spikes
        glColor3f(0.0,0.0,0.0);
        drawCylinder(0.01,r,0.0,0.0,0.0);
        //seat
        glColor3f(0.3,0.8,0.1);
        glTranslatef(0.0,r,0.0);
        glRotatef(360*j/12+T,0,0,1);
        seat();
        //connecting rod
        glColor3f(0.5,0.5,0.5);
        glRotatef(90,1,0,0);
        drawCylinder(0.005,0.3,0.0,-0.15,0.0);
        glRotatef(-90,1,0,0);

        glRotatef(-360*j/12-T,0,0,1);
        glTranslatef(0.0,-r,0.0);

        glRotatef(360*j/12+T,0,0,1);
        glTranslatef(0.0,-h-0.15,0);
    }
    glTranslatef(-X,0.0,-Z);

}

void person(float X,float Z){

    
    glTranslatef(X,0,Z);
    glRotatef(Direction,0,1,0);
    float h=0.2;
    //legs
    glColor3f(0.0,0.0,0.0);
    
    
    glTranslatef(-0.15*h,0.4*h+0.15,0.0);
    glRotatef(-Angle,1,0,0);
    cuboid(0.0,0.0,0.0,0.15*h,0.2*h,0.3*h);
    glRotatef(Angle,1,0,0);
    glTranslatef(0.15*h,-0.4*h-0.15,0.0);

    glTranslatef(0.0,0.4*h+0.15,0.0);
    glRotatef(Angle,1,0,0);
    cuboid(0.0,0.0,0.0,0.15*h,0.2*h,0.3*h);
    glRotatef(-Angle,1,0,0);
    glTranslatef(0.0,-0.4*h-0.15,0.0);

    //arms
    glColor3f(1.0,0.8,0.6);
    
    glTranslatef(0.15*h,0.8*h+0.15,0.0);
    glRotatef(-Angle,1,0,0);
    cuboid(0.0,0.0,0.0,0.1*h,0.2*h,0.3*h);
    glRotatef(Angle,1,0,0);
    glTranslatef(-0.15*h,-0.8*h-0.15,0.0);

    glTranslatef(-0.25*h,0.8*h+0.15,0.0);
    glRotatef(Angle,1,0,0);
    cuboid(0.0,0.0,0.0,0.1*h,0.2*h,0.3*h);
    glRotatef(-Angle,1,0,0);
    glTranslatef(0.25*h,-0.8*h-0.15,0.0);


    glColor3f(0.6,0.7,0.9);
    glTranslatef(0.14*h,0.81*h+0.15,+0.01*h);
    glRotatef(-Angle,1,0,0);
    cuboid(0.0,0.0,0.0,0.12*h,0.22*h,0.1*h);
    glRotatef(Angle,1,0,0);
    glTranslatef(-0.14*h,-0.81*h-0.15,-0.01*h);
    

    glTranslatef(-0.26*h,0.81*h+0.15,+0.01*h);
    glRotatef(Angle,1,0,0);
    cuboid(0.0,0.0,0.0,0.12*h,0.22*h,0.1*h);
    glRotatef(-Angle,1,0,0);
    glTranslatef(0.26*h,-0.81*h-0.15,-0.01*h);
    
    //body
    glColor3f(0.6,0.7,0.9);
    cuboid(-0.15*h,0.8*h+0.15,0.0,0.3*h,0.2*h,0.4*h);

    //head
    glColor3f(1.0,0.8,0.6);
    cuboid(-0.1*h,h+0.15,0.0,0.2*h,0.2*h,0.2*h);
    //hair
    glColor3f(0.0,0.0,0.0);
    cuboid(-0.11*h,1.01*h+0.15,+0.01*h,0.22*h,0.22*h,0.06*h);
    cuboid(-0.11*h,1.01*h+0.15,-0.1*h,0.22*h,0.11*h,0.21*h);

    //eyes
    glColor3f(0.0,0.0,0.0);
    cuboid(+(5/70)*h,(0.75+0.8/5)*h+0.15,0.01*h,(2.5/70)*h,0.01*h,(0.2/5)*h);
    glColor3f(1.0,1.0,1.0);
    cuboid(+(5/70)*h+(0.2/7)*h,(0.75+0.8/5)*h+0.15,0.01*h,(2.5/70)*h,0.01*h,(0.2/5)*h);

    glColor3f(0.0,0.0,0.0);
    cuboid(-(5/70)*h-(0.6/7)*h,(0.75+0.8/5)*h+0.15,0.01*h,(2.5/70)*h,0.01*h,(0.2/5)*h);
    glColor3f(1.0,1.0,1.0);
    cuboid(-(5/70)*h-(0.6/7)*h+(0.2/7)*h,(0.75+0.8/5)*h+0.15,0.01*h,(2.5/70)*h,0.01*h,(0.2/5)*h);
    
    glRotatef(-Direction,0,1,0);
    glTranslatef(-X,0,-Z);
}

void make_sphere(){
    glutSolidSphere(1, 30, 30); 
}

void make_cube()
{
    glTranslatef(0.5,0.5,0.5);
    glutSolidCube(1); 
}

void trunk(float x, float y, float z)
{
    glColor3f(0.67, 0.34, 0);
    drawCylinder(0.08, 0.20, x + 0.1, y + 0.15, z - 0.1);
    float x1=x,y1=y,z1=z;
    
    glTranslatef(x, y+0.2, z);
    x=0;y=0;z=0;
    glScalef(0.03, 0.035, 0.03);
    // trunk
    //  glPushMatrix();
    //  glTranslatef(x,y,z);
    //  glScalef(6,6,-6);
    //  make_cube();
    //  glPopMatrix();

    // middle part
    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1, y + 6, z + 1);
    glScalef(8, 7, -8);
    make_cube();
    glPopMatrix();

    // spheres
    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1, y + 6, z + 1);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7, y + 6, z + 1);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7, y + 6, z - 7);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1, y + 6, z - 7);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    // 2nd line
    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1, y + 8, z + 1);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7, y + 8, z + 1);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7, y + 8, z - 7);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1, y + 8, z - 7);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    // 3rd line
    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1, y + 11, z + 1);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7, y + 11, z + 1);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7, y + 11, z - 7);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1, y + 11, z - 7);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    // middle line 1

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 3, y + 6, z + 1.5);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7.5, y + 6, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 3, y + 6, z - 7.5);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1.5, y + 6, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    // middle line  2

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 3, y + 8.5, z + 2);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 8, y + 8.5, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 3, y + 8.5, z - 8);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 2, y + 8.5, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    // middle line  3

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 3, y + 11.5, z + 1.5);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 7.5, y + 11.5, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 3, y + 11.5, z - 7.5);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x - 1.5, y + 11.5, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    // top corner
    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 4, y + 13, z - 4);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 2, y + 12.5, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 5, y + 12.5, z - 3);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 2, y + 12.5, z - 4);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 5, y + 12.5, z - 4);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 2, y + 12.5, z - 2);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 5, y + 12.5, z - 2);
    glScalef(2.5, 2.5, -2.5);
    make_sphere();
    glPopMatrix();

    glColor3f(0, 0.8, 0);
    glPushMatrix();
    glTranslatef(x + 2, y + 12.5, z - 1);
    glScalef(3, 3, 3);
    make_sphere();
    glPopMatrix();
    glScalef(1 / 0.03, 1 / 0.035, 1 / 0.03);
    glTranslatef(-x1-0, -y1-0.2, -z1-0);
}

void Tree_spam(){
    trunk(2.6,0.0,-0.9);
    trunk(2.6,0.0,-0.3);
    trunk(2.6,0.0,0.3);
    trunk(2.6,0.0,0.9);
}

void Lake(float x1, float y1, float r)
{
    glColor3f(1,1,1);
    GLuint texture = LoadGLTexture("images/water.jpeg");
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    float x2, y2;
    float radius = r;
    float xo = x1, yo = y1 + r;
    float angle;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1, 0.165, y1);
    for (angle = 1.0f; angle < 361.0f; angle += 0.2)
    {
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glTexCoord2f((angle/361.0), (angle/361.0));glVertex3f(x2, 0.165, y2);
    }
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(1.35, 0.165, 0.7);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.65, 0.165, 0.7);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(1.65, 0.165, 1.5);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(1.35, 0.165, 1.5);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    //end of water
    glColor3f(0.135, 0.065, 0.001);
    Cylin_draw(0.02, 0.05, 1.25, 0.15, 1.15);
    Cylin_draw(0.02, 0.05, 1.75, 0.15, 1.15);
    Cylin_draw(0.02, 0.05, 1.75, 0.15, 1.35);
    Cylin_draw(0.02, 0.05, 1.25, 0.15, 1.35);
    Cylin_draw(0.008, 0.13, 1.25, 0.21, 1.15);
    Cylin_draw(0.008, 0.13, 1.75, 0.21, 1.15);
    Cylin_draw(0.008, 0.13, 1.25, 0.21, 1.35);
    Cylin_draw(0.008, 0.13, 1.75, 0.21, 1.35);
    float v1[8][3] = {
        {1.22, 0.20, 1.38}, {1.22, 0.20, 1.31}, {1.78, 0.20, 1.31}, {1.78, 0.20, 1.38}, {1.22, 0.21, 1.38}, {1.22, 0.21, 1.31}, {1.78, 0.21, 1.31}, {1.78, 0.21, 1.38}};
    float v2[8][3] = {
        {1.22, 0.20, 1.31}, {1.22, 0.20, 1.25}, {1.78, 0.20, 1.25}, {1.78, 0.20, 1.31}, {1.22, 0.21, 1.31}, {1.22, 0.21, 1.25}, {1.78, 0.21, 1.25}, {1.78, 0.21, 1.31}};
    float v3[8][3] = {
        {1.22, 0.20, 1.25}, {1.22, 0.20, 1.19}, {1.78, 0.20, 1.19}, {1.78, 0.20, 1.25}, {1.22, 0.21, 1.25}, {1.22, 0.21, 1.19}, {1.78, 0.21, 1.19}, {1.78, 0.21, 1.25}};
    float v4[8][3] = {
        {1.22, 0.20, 1.19}, {1.22, 0.20, 1.12}, {1.78, 0.20, 1.12}, {1.78, 0.20, 1.19}, {1.22, 0.21, 1.19}, {1.22, 0.21, 1.12}, {1.78, 0.21, 1.12}, {1.78, 0.21, 1.19}};
    glColor3f(0.438, 0.344, 0.218);
    Draw_cube(v1);
    glColor3f(0.454, 0.321, 0.225);
    Draw_cube(v2);
    glColor3f(0.438, 0.344, 0.218);
    Draw_cube(v3);
    glColor3f(0.454, 0.321, 0.225);
    Draw_cube(v4);
    glColor3f(0.135, 0.065, 0.001);
    float v5[8][3] = {
        {1.22, 0.33, 1.36}, {1.78, 0.33, 1.36}, {1.78, 0.33, 1.34}, {1.22, 0.33, 1.34}, {1.22, 0.31, 1.36}, {1.78, 0.31, 1.36}, {1.78, 0.31, 1.34}, {1.22, 0.31, 1.34}};
    Draw_cube(v5);
    float v6[8][3] = {
        {1.22, 0.33, 1.16}, {1.78, 0.33, 1.16}, {1.78, 0.33, 1.14}, {1.22, 0.33, 1.14}, {1.22, 0.31, 1.16}, {1.78, 0.31, 1.16}, {1.78, 0.31, 1.14}, {1.22, 0.31, 1.14}};
    Draw_cube(v6);

    // Side walls
    // Straight track
    glColor3f(0.3425,0.3375,0.32);
    float v7[8][3] = {
        {1.32, 0.14, 1.495}, {1.32, 0.20, 1.495}, {1.32, 0.20, 0.87}, {1.32, 0.14, 0.87}, {1.38, 0.14, 1.495}, {1.38, 0.20, 1.495}, {1.38, 0.20, 0.87}, {1.38, 0.14, 0.87}};
    Draw_cube(v7);
    glColor3f(0.3425,0.3375,0.32);
    float v8[8][3] = {
        {1.62, 0.14, 1.495}, {1.62, 0.20, 1.495}, {1.62, 0.20, 0.87}, {1.62, 0.14, 0.87}, {1.68, 0.14, 1.495}, {1.68, 0.20, 1.495}, {1.68, 0.20, 0.87}, {1.68, 0.14, 0.87}};
    Draw_cube(v8);
    // Circle Boundary
    float x_o = 1.97, y_o = 0.4, z_o = 0.14;
    float a_o = 2.03, b_o = 0.4, c_o = 0.14;
    glColor3f(0.3425,0.3375,0.32);
    for (float p = 0; p <= ((77.3) * PI) / 180; p += (8 * (PI) / 180))
    {
        float x_1 = 1.5 + (0.47) * cos(p), y_1 = 0.4 + (0.47) * sin(p), z_1 = 0.20;
        float a_1 = 1.5 + (0.53) * cos(p), b_1 = 0.4 + (0.53) * sin(p), c_1 = 0.20;
        float v[8][3] = {
            {x_o, z_o, y_o}, {x_1, z_o, y_1}, {x_1, z_1, y_1}, {x_o, z_1, y_o}, {a_o, z_o, b_o}, {a_1, z_o, b_1}, {a_1, z_1, b_1}, {a_o, z_1, b_o}};
        Draw_cube(v);
        x_o = 1.5+(0.47) * cos(p+((4*(PI))/180));
        y_o = 0.4+(0.47) * sin(p+((4*(PI))/180));
        a_o = 1.5+(0.53) * cos(p+((4*(PI))/180));
        b_o = 0.4+(0.53) * sin(p+((4*(PI))/180));   
    }
    glColor3f(0.304, 0.286, 0.41);
    for (float p = 0; p <= ((77.3) * PI) / 180; p += (8 * (PI) / 180))
    {
        x_o = 1.5+(0.47) * cos(p+((4*(PI))/180));
        y_o = 0.4+(0.47) * sin(p+((4*(PI))/180));
        a_o = 1.5+(0.53) * cos(p+((4*(PI))/180));
        b_o = 0.4+(0.53) * sin(p+((4*(PI))/180));   
        float x_1 = 1.5 + (0.47) * cos(p), y_1 = 0.4 + (0.47) * sin(p), z_1 = 0.20;
        float a_1 = 1.5 + (0.53) * cos(p), b_1 = 0.4 + (0.53) * sin(p), c_1 = 0.20;
        float v[8][3] = {
            {x_o, z_o, y_o}, {x_1, z_o, y_1}, {x_1, z_1, y_1}, {x_o, z_1, y_o}, {a_o, z_o, b_o}, {a_1, z_o, b_1}, {a_1, z_1, b_1}, {a_o, z_1, b_o}};
        Draw_cube(v);
    }

    glColor3f(0.304, 0.286, 0.41);
    x_o = 1.97, y_o = 0.4, z_o = 0.14;
    a_o = 2.03, b_o = 0.4, c_o = 0.14;
    for (float p = 2 * PI; p >= ((102.7) * PI) / 180; p -= (8 * (PI) / 180))
    {
        float x_1 = 1.5 + (0.47) * cos(p), y_1 = 0.4 + (0.47) * sin(p), z_1 = 0.20;
        float a_1 = 1.5 + (0.53) * cos(p), b_1 = 0.4 + (0.53) * sin(p), c_1 = 0.20;
        float v[8][3] = {
            {x_o, z_o, y_o}, {x_1, z_o, y_1}, {x_1, z_1, y_1}, {x_o, z_1, y_o}, {a_o, z_o, b_o}, {a_1, z_o, b_1}, {a_1, z_1, b_1}, {a_o, z_1, b_o}};
        Draw_cube(v);
        x_o = 1.5+(0.47) * cos(p-((4*(PI))/180));
        y_o = 0.4+(0.47) * sin(p-((4*(PI))/180));
        a_o = 1.5+(0.53) * cos(p-((4*(PI))/180));
        b_o = 0.4+(0.53) * sin(p-((4*(PI))/180)); 
    }
    glColor3f(0.3425,0.3375,0.32);
    for (float p = 2 * PI; p >= ((102.7) * PI) / 180; p -= (8 * (PI) / 180))
    {
        x_o = 1.5+(0.47) * cos(p-((4*(PI))/180));
        y_o = 0.4+(0.47) * sin(p-((4*(PI))/180));
        a_o = 1.5+(0.53) * cos(p-((4*(PI))/180));
        b_o = 0.4+(0.53) * sin(p-((4*(PI))/180)); 
        float x_1 = 1.5 + (0.47) * cos(p), y_1 = 0.4 + (0.47) * sin(p), z_1 = 0.20;
        float a_1 = 1.5 + (0.53) * cos(p), b_1 = 0.4 + (0.53) * sin(p), c_1 = 0.20;
        float v[8][3] = {
            {x_o, z_o, y_o}, {x_1, z_o, y_1}, {x_1, z_1, y_1}, {x_o, z_1, y_o}, {a_o, z_o, b_o}, {a_1, z_o, b_1}, {a_1, z_1, b_1}, {a_o, z_1, b_o}};
        Draw_cube(v);
    }
}

void Draw_cube(float v[][3]){
    glBegin(GL_QUADS);
    
    //Front
    glVertex3f(v[0][0], v[0][1], v[0][2]);
    glVertex3f(v[1][0], v[1][1], v[1][2]);
    glVertex3f(v[2][0], v[2][1], v[2][2]);
    glVertex3f(v[3][0], v[3][1], v[3][2]);
    //Back
    glVertex3f(v[4][0], v[4][1], v[4][2]);
    glVertex3f(v[5][0], v[5][1], v[5][2]);
    glVertex3f(v[6][0], v[6][1], v[6][2]);
    glVertex3f(v[7][0], v[7][1], v[7][2]);
    //R side
    glVertex3f(v[1][0], v[1][1], v[1][2]);
    glVertex3f(v[5][0], v[5][1], v[5][2]);
    glVertex3f(v[6][0], v[6][1], v[6][2]);
    glVertex3f(v[2][0], v[2][1], v[2][2]);
    //L side
    glVertex3f(v[0][0], v[0][1], v[0][2]);
    glVertex3f(v[4][0], v[4][1], v[4][2]);
    glVertex3f(v[7][0], v[7][1], v[7][2]);
    glVertex3f(v[3][0], v[3][1], v[3][2]);
    //Top
    glVertex3f(v[0][0], v[0][1], v[0][2]);
    glVertex3f(v[1][0], v[1][1], v[1][2]);
    glVertex3f(v[5][0], v[5][1], v[5][2]);
    glVertex3f(v[4][0], v[4][1], v[4][2]);
    //Bottom
    glVertex3f(v[3][0], v[3][1], v[3][2]);
    glVertex3f(v[7][0], v[7][1], v[7][2]);
    glVertex3f(v[6][0], v[6][1], v[6][2]);
    glVertex3f(v[2][0], v[2][1], v[2][2]);

    glEnd();
}

void Cylin_draw(float radius,float height,float X,float Y,float Z){
    float Cx=X,Cy=Y,Cz=Z;
    for(int i=1;i<10;i++){
        float x=Cx+radius*(cos(2*PI*i/10));
        float z=Cz+radius*(sin(2*PI*i/10));
        glBegin(GL_QUADS);
        glVertex3f(Cx,Cy,Cz);
        glVertex3f(x,Cy,z);
        glVertex3f(x,Cy+height,z);
        glVertex3f(Cx,Cy+height,Cz);
        glEnd();
    }
}

void drawHorizontalCylinder(float radius,float height,float X,float Y,float Z){

    float Cx=X,Cy=Y,Cz=Z;

    for(int i=1;i<1000;i++){

        float x=Cx+radius*(cos(2*PI*i/1000));

        float y=Cy+radius*(sin(2*PI*i/1000));

        glBegin(GL_QUADS);

        glVertex3f(Cx,Cy,Cz);

        glVertex3f(x,y,Cz);

        glVertex3f(x,y,Cz+height);

        glVertex3f(Cx,Cy,Cz+height);

        glEnd();

    }

}

void slide()
{
    glScalef(1.5,1.5,1.5);
    glTranslatef(-3.55,0,0.45);

    float vert[8][3] = {
    {2.1,0.17,-1.3},
    {1.65,0.28,-1.3},
    {1.675,0.28,-1.3},
    {2.125,0.17,-1.3},
    {2.1,0.17,-1.4},
    {1.65,0.28,-1.4},
    {1.675,0.28,-1.4},
    {2.125,0.17,-1.4},
    };

    glBegin(GL_QUADS);

    // front
    glColor3f(0,0,1);

    glVertex3fv(vert[0]);

    glVertex3fv(vert[1]);

    glVertex3fv(vert[2]);

    glVertex3fv(vert[3]);

    //back

    glVertex3fv(vert[0+4]);

    glVertex3fv(vert[1+4]);

    glVertex3fv(vert[2+4]);

    glVertex3fv(vert[3+4]);

    // left

    glColor3f(1,0,0);

    glVertex3fv(vert[0]);

    glVertex3fv(vert[3]);

    glVertex3fv(vert[7]);

    glVertex3fv(vert[4]);

    // right

    glVertex3fv(vert[2]);

    glVertex3fv(vert[3]);

    glVertex3fv(vert[6]);

    glVertex3fv(vert[5]);

    // top

    glVertex3fv(vert[2]);

    glVertex3fv(vert[3]);

   glVertex3fv(vert[7]);

    glVertex3fv(vert[6]);

    // bottom

    glVertex3fv(vert[0]);

    glVertex3fv(vert[1]);

    glVertex3fv(vert[5]);

    glVertex3fv(vert[4]);

 

    glEnd();

 

    glColor3f(0,1,0);

 

    drawCylinder(0.0075,0.035,2.05,0.15,-1.38);

    drawCylinder(0.0075,0.035,2.05,0.15,-1.32);

 

    drawCylinder(0.005,0.2,1.65,0.15,-1.39);

    drawCylinder(0.005,0.2,1.65,0.15,-1.31);

 

    glColor3f(0,0,1);

    glBegin(GL_QUADS);

    glVertex3f(2.125,0.17,-1.3);

    glVertex3f(1.675,0.28,-1.3);

    glVertex3f(1.675,0.30,-1.3);

    glVertex3f(2.125,0.19,-1.3);

 

    glVertex3f(2.125,0.17,-1.4);

    glVertex3f(1.675,0.28,-1.4);

    glVertex3f(1.675,0.30,-1.4);

    glVertex3f(2.125,0.19,-1.4);

 

    glVertex3f(1.675,0.28,-1.4);

    glVertex3f(1.65,0.28,-1.4);

    glVertex3f(1.65,0.30,-1.4);

    glVertex3f(1.675,0.30,-1.4);

 

    glVertex3f(1.675,0.28,-1.3);

    glVertex3f(1.65,0.28,-1.3);

    glVertex3f(1.65,0.30,-1.3);

    glVertex3f(1.675,0.30,-1.3);

    glEnd();

    glColor3f(0,1,0);

    drawHorizontalCylinder(0.005,0.1,1.65,0.35,-1.4);

    drawHorizontalCylinder(0.005,0.08,1.65,0.17,-1.39);
    drawHorizontalCylinder(0.005,0.08,1.65,0.20,-1.39);
    drawHorizontalCylinder(0.005,0.08,1.65,0.23,-1.39);
    drawHorizontalCylinder(0.005,0.08,1.65,0.26,-1.39);

    glTranslatef(3.55,0,-0.45);
    glScalef(0.66,0.66,0.66);
}

void seeSaw()
{
    glScalef(1.5,1.5,1.5);
    glTranslatef(-2.18,0,0.45);
    float vert[8][3] = {

        {1.4-0.2+0.05,0.175+0.025,-1.4},

        {1.15-0.2-0.05,0.175+0.025,-1.4},

        {1.15-0.2-0.05,0.2+0.025,-1.4},

        {1.4-0.2+0.05,0.2+0.025,-1.4},

        {1.4-0.2+0.05,0.175+0.025,-1.35},

        {1.15-0.2-0.05,0.175+0.025,-1.35},

        {1.15-0.2-0.05,0.2+0.025,-1.35},

        {1.4-0.2+0.05,0.2+0.025,-1.35},

    };

 

    glBegin(GL_TRIANGLES);

    glColor3f(0,0,0);

    glVertex3f(1.075,0.1875+0.025,-1.39);

    glVertex3f(1.1,0.15,-1.39);

    glVertex3f(1.05,0.15,-1.39);

 

    glVertex3f(1.075,0.1875+0.025,-1.36);

    glVertex3f(1.1,0.15,-1.36);

    glVertex3f(1.05,0.15,-1.36);

    glEnd();

 

    glColor3f(0,0,0);

    drawCylinder(0.005,0.035,0.98,0.225,-1.39);

    drawCylinder(0.005,0.035,0.98,0.225,-1.36);

    drawHorizontalCylinder(0.005,0.04,0.98,0.225+0.035,-1.395);

 

    drawCylinder(0.005,0.035,1.17,0.225,-1.39);

    drawCylinder(0.005,0.035,1.17,0.225,-1.36);

    drawHorizontalCylinder(0.005,0.04,1.17,0.225+0.035,-1.395);

 

    glBegin(GL_QUADS);

 

    glColor3f(0,0,0);

    glVertex3f(1.075,0.1875+0.025,-1.39);

    glVertex3f(1.075,0.1875+0.025,-1.36);

    glVertex3f(1.1,0.15,-1.36);

    glVertex3f(1.1,0.15,-1.39);

 

    glVertex3f(1.075,0.1875+0.025,-1.39);

    glVertex3f(1.075,0.1875+0.025,-1.36);

    glVertex3f(1.05,0.15,-1.36);

    glVertex3f(1.05,0.15,-1.39);

 

    glColor3f(1,0,0);

    // front

    glVertex3fv(vert[0]);

    glVertex3fv(vert[1]);

    glVertex3fv(vert[2]);

    glVertex3fv(vert[3]);

    //back

    glVertex3fv(vert[0+4]);

    glVertex3fv(vert[1+4]);

    glVertex3fv(vert[2+4]);

    glVertex3fv(vert[3+4]);

    // left

    glVertex3fv(vert[0]);

    glVertex3fv(vert[3]);

    glVertex3fv(vert[7]);

    glVertex3fv(vert[4]);

    // right

    glVertex3fv(vert[2]);

    glVertex3fv(vert[3]);

    glVertex3fv(vert[6]);

    glVertex3fv(vert[5]);

    // top

    glVertex3fv(vert[2]);

    glVertex3fv(vert[3]);

    glVertex3fv(vert[7]);

    glVertex3fv(vert[6]);

    // bottom

    glVertex3fv(vert[0]);

    glVertex3fv(vert[1]);

   glVertex3fv(vert[5]);

    glVertex3fv(vert[4]);


    glEnd();
    glTranslatef(2.18,0,-0.45);
    glScalef(0.666,0.666,0.666);
}

void Street_light(float x,float z){
    float v[8][3]={
        {x-0.05,0.14,z-0.05},{x+0.05,0.14,z-0.05},{x+0.05,0.14,z+0.05},{x-0.05,0.14,z+0.05},{x-0.05,0.18,z-0.05},{x+0.05,0.18,z-0.05},{x+0.05,0.18,z+0.05},{x-0.05,0.18,z+0.05}
    };
    glColor3f(0.304, 0.286, 0.41);
    Draw_cube(v);
    glColor3f(0.3425,0.3375,0.32);
    Cylin_draw(0.02,0.14,x,0.17,z);
    Cylin_draw(0.01,0.32,x,0.30,z);
    glColor3f(1,1,0);
    glPushMatrix();
    glTranslatef(x,0.60,z);
    glutSolidSphere(0.045,30,30);
    // glTranslatef(x,-0.60,z);
    glPopMatrix();
}

void Lights_spam(){
    for(float i=-1.0;i<=1.0;i++){
        Street_light(2.2,i);
        Street_light(0.8,i);
        Street_light(-1.4,i);
    }
    Street_light(-0.3,-0.4);

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslatef(0.97,0.48,-1.0);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    glColor3f(0.8,0.3,0.09);
    glPushMatrix();
    glTranslatef(1.03,0.48,-1.0);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(1.0,0.52,-1.0);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    glColor3f(0,0,1);
    Cylin_draw(0.01,0.06,1.0,0.44,-1.0);
    glColor3f(0.55,0.45,0);
    Cylin_draw(0.01,0.34,1.0,0.1,-1.0);
    glColor3f(0.39,0.195,0.312);
    glPushMatrix();
    glTranslatef(1.0,0.5,-1.0);
    glutWireSphere(0.1,10,10);
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
    glTranslatef(1.97,0.48,-1.0);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    glColor3f(0.8,0.3,0.09);
    glPushMatrix();
    glTranslatef(2.03,0.48,-1.0);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(2.0,0.52,-1.0);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    glColor3f(0,0,1);
    Cylin_draw(0.01,0.06,2.0,0.44,-1.0);
    glColor3f(0.55,0.45,0);
    Cylin_draw(0.01,0.34,2.0,0.1,-1.0);
    glColor3f(0.39,0.195,0.312);
    glPushMatrix();
    glTranslatef(2.0,0.5,-1.0);
    glutWireSphere(0.1,10,10);
    glPopMatrix();
}

void swing()
{
    glTranslatef(-2.5,0.15,-1);
    glRotatef(20,0,0,1);
    drawCylinder(0.005,0.8,0,-0.4,0);
    glRotatef(-20,0,0,1);
    glTranslatef(2.5,-0.15,1);

    glTranslatef(-2.5,0.15,-0.5);
    glRotatef(20,0,0,1);
    drawCylinder(0.005,0.8,0,-0.4,0);
    glRotatef(-20,0,0,1);
    glTranslatef(2.5,-0.15,0.5);

    glTranslatef(-2.775,0.15,-0.5);
    glRotatef(-20,0,0,1);
    drawCylinder(0.005,0.8,0,-0.4,0);
    glRotatef(20,0,0,1);
    glTranslatef(2.775,-0.15,0.5);

    glTranslatef(-2.775,0.15,-1);
    glRotatef(-20,0,0,1);
    drawCylinder(0.005,0.8,0,-0.4,0);
    glRotatef(20,0,0,1);
    glTranslatef(2.775,-0.15,1);

    drawHorizontalCylinder(0.005,0.5,-2.6375,0.53,-1);

    drawCylinder(0.003,0.3,-2.6375,0.23,-0.88);
    drawCylinder(0.003,0.3,-2.6375,0.23,-0.78);
    cuboid(-2.675,0.23,-0.76,0.075,0.14,0.03);

    drawCylinder(0.003,0.3,-2.6375,0.23,-0.58);
    drawCylinder(0.003,0.3,-2.6375,0.23,-0.68);
    cuboid(-2.675,0.23,-0.56,0.075,0.14,0.03);
}

void handle()
{
    drawHorizontalCylinder(0.005,0.1,0,0.28,-0.05);
    drawCylinder(0.005,0.07,0,0.21,-0.05);
    drawCylinder(0.005,0.07,0,0.21,0.05);
}

void drawBigCylinder(float radius,float height,float X,float Y,float Z){
    float Cx=X,Cy=Y,Cz=Z;
    for(int i=1;i<100000;i++){
        float x=Cx+radius*(cos(2*PI*i/100000));
        float z=Cz+radius*(sin(2*PI*i/100000));
        glBegin(GL_QUADS);
        glVertex3f(Cx,Cy,Cz);
        glVertex3f(x,Cy,z);
        glVertex3f(x,Cy+height,z);
        glVertex3f(Cx,Cy+height,Cz);
        glEnd();
    }
}

void merryGoRound()
{
    drawBigCylinder(0.3,0.01,-1.9,0.2,-0.7);
    glColor3f(0,0,0);

    glTranslatef(-1.7,0,-0.7);
    handle();
    glTranslatef(1.7,0,0.7);

    glTranslatef(-2.1,0,-0.7);
    handle();
    glTranslatef(2.1,0,0.7);

    glTranslatef(-1.9,0,-0.9);
    glRotatef(90,0,1,0);
    handle();
    glRotatef(-90,0,1,0);
    glTranslatef(1.9,0,0.9);

    glTranslatef(-1.9,0,-0.5);
    glRotatef(90,0,1,0);
    handle();
    glRotatef(-90,0,1,0);
    glTranslatef(1.9,0,0.5);


}
