#include <bits/stdc++.h>
#include <GL/glut.h>
#define PI 3.14159
using namespace std;

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
    // Left road  X Z Y
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-1.3, 0.151, -1.5);
    glVertex3f(-1.1, 0.151, -1.5);
    glVertex3f(-1.1, 0.151, 1.5);
    glVertex3f(-1.3, 0.151, 1.5);
    glEnd();
    glBegin(GL_QUADS); // Dividers
    glColor3f(1, 1, 1);
    glVertex3f(-1.21, 0.152, -1.5);
    glVertex3f(-1.19, 0.152, -1.5);
    glVertex3f(-1.19, 0.152, -1.17);
    glVertex3f(-1.21, 0.152, -1.17);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-1.21, 0.152, -0.84);
    glVertex3f(-1.19, 0.152, -0.84);
    glVertex3f(-1.19, 0.152, -0.51);
    glVertex3f(-1.21, 0.152, -0.51);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-1.21, 0.152, -0.18);
    glVertex3f(-1.19, 0.152, -0.18);
    glVertex3f(-1.19, 0.152, 0.15);
    glVertex3f(-1.21, 0.152, 0.15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-1.21, 0.152, 0.48);
    glVertex3f(-1.19, 0.152, 0.48);
    glVertex3f(-1.19, 0.152, 0.81);
    glVertex3f(-1.21, 0.152, 0.81);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-1.21, 0.152, 1.14);
    glVertex3f(-1.19, 0.152, 1.14);
    glVertex3f(-1.19, 0.152, 1.5);
    glVertex3f(-1.21, 0.152, 1.5);
    glEnd();
    // Middle road
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(0.5, 0.151, -1.5);
    glVertex3f(0.7, 0.151, -1.5);
    glVertex3f(0.7, 0.151, 1.5);
    glVertex3f(0.5, 0.151, 1.5);
    glEnd();
    glBegin(GL_QUADS); // Dividers
    glColor3f(1, 1, 1);
    glVertex3f(0.59, 0.152, -1.5);
    glVertex3f(0.61, 0.152, -1.5);
    glVertex3f(0.61, 0.152, -1.17);
    glVertex3f(0.59, 0.152, -1.17);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(0.59, 0.152, -0.84);
    glVertex3f(0.61, 0.152, -0.84);
    glVertex3f(0.61, 0.152, -0.51);
    glVertex3f(0.59, 0.152, -0.51);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(0.59, 0.152, -0.18);
    glVertex3f(0.61, 0.152, -0.18);
    glVertex3f(0.61, 0.152, 0.15);
    glVertex3f(0.59, 0.152, 0.15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(0.59, 0.152, 0.48);
    glVertex3f(0.61, 0.152, 0.48);
    glVertex3f(0.61, 0.152, 0.81);
    glVertex3f(0.59, 0.152, 0.81);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(0.59, 0.152, 1.14);
    glVertex3f(0.61, 0.152, 1.14);
    glVertex3f(0.61, 0.152, 1.5);
    glVertex3f(0.59, 0.152, 1.5);
    glEnd();
    // Right road
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(2.3, 0.151, -1.5);
    glVertex3f(2.5, 0.151, -1.5);
    glVertex3f(2.5, 0.151, 1.5);
    glVertex3f(2.3, 0.151, 1.5);
    glEnd();
    glBegin(GL_QUADS); // Dividers
    glColor3f(1, 1, 1);
    glVertex3f(2.39, 0.152, -1.5);
    glVertex3f(2.41, 0.152, -1.5);
    glVertex3f(2.41, 0.152, -1.17);
    glVertex3f(2.39, 0.152, -1.17);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(2.39, 0.152, -0.84);
    glVertex3f(2.41, 0.152, -0.84);
    glVertex3f(2.41, 0.152, -0.51);
    glVertex3f(2.39, 0.152, -0.51);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(2.39, 0.152, -0.18);
    glVertex3f(2.41, 0.152, -0.18);
    glVertex3f(2.41, 0.152, 0.15);
    glVertex3f(2.39, 0.152, 0.15);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(2.39, 0.152, 0.48);
    glVertex3f(2.41, 0.152, 0.48);
    glVertex3f(2.41, 0.152, 0.81);
    glVertex3f(2.39, 0.152, 0.81);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(2.39, 0.152, 1.14);
    glVertex3f(2.41, 0.152, 1.14);
    glVertex3f(2.41, 0.152, 1.5);
    glVertex3f(2.39, 0.152, 1.5);
    glEnd();
    // Left to Middle road
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-1.1, 0.151, -0.1);
    glVertex3f(-1.1, 0.151, -0.3);
    glVertex3f(0.5, 0.151, -0.3);
    glVertex3f(0.5, 0.151, -0.1);
    glEnd();
    glBegin(GL_QUADS); // Dividers
    glColor3f(1, 1, 1);
    glVertex3f(-1.0, 0.152, -0.19);
    glVertex3f(-1.0, 0.152, -0.21);
    glVertex3f(-0.7, 0.152, -0.21);
    glVertex3f(-0.7, 0.152, -0.19);
    glEnd();
    glBegin(GL_QUADS); // Dividers
    glColor3f(1, 1, 1);
    glVertex3f(-0.4, 0.152, -0.19);
    glVertex3f(-0.4, 0.152, -0.21);
    glVertex3f(-0.1, 0.152, -0.21);
    glVertex3f(-0.1, 0.152, -0.19);
    glEnd();
    glBegin(GL_QUADS); // Dividers
    glColor3f(1, 1, 1);
    glVertex3f(0.2, 0.152, -0.19);
    glVertex3f(0.2, 0.152, -0.21);
    glVertex3f(0.5, 0.152, -0.21);
    glVertex3f(0.5, 0.152, -0.19);
    glEnd();
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

void Lake(float x1, float y1, float r)
{
    float x2, y2;
    float angle;
    double radius = r;
    glColor3f(0.366, 0, 0.63);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1, 0.155, y1);
    // for(float j=0;j<r;j+=0.001){
    for (angle = 1.0f; angle < 361.0f; angle += 0.2)
    {
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex3f(x2, 0.155, y2);
    }
    // }
    glEnd();
}

void cuboid(double X,double Y,double Z,double L,double B,double H){
    double cuboid[8][3]={
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


void drawCylinder(double radius,double height,double X,double Y,double Z){
    double Cx=X,Cy=Y,Cz=Z;
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

void ferris_wheel(double X,double Z){
    glTranslatef(X,0.0,Z);
    double h=0.9;
    double r=0.7*h;
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



void person(double X,double Z){

    
    glTranslatef(X,0,Z);
    glRotatef(Direction,0,1,0);
    double h=0.2;
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



void trunk(int x,int y,int z)
{
    glTranslatef(0,0.15,0);
    glScalef(0.03,0.035,0.03);
    //trunk
    glColor3f(0.67,0.34, 0);
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(6,6,-6);
    make_cube();
    glPopMatrix(); 

    // middle part
    glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1,y+6,z+1);
    glScalef(8,7,-8);
    make_cube();
    glPopMatrix(); 
    

    //spheres 
    glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1,y+6,z+1);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7,y+6,z+1);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7,y+6,z-7);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1,y+6,z-7);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

    // 2nd line
    glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1,y+8,z+1);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7,y+8,z+1);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7,y+8,z-7);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1,y+8,z-7);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 



    //3rd line
    glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1,y+11,z+1);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7,y+11,z+1);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7,y+11,z-7);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1,y+11,z-7);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


    // middle line 1

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+3,y+6,z+1.5);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7.5,y+6,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+3,y+6,z-7.5);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1.5,y+6,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 



    // middle line  2

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+3,y+8.5,z+2);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+8,y+8.5,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+3,y+8.5,z-8);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-2,y+8.5,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

    

        // middle line  3

      glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+3,y+11.5,z+1.5);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+7.5,y+11.5,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+3,y+11.5,z-7.5);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x-1.5,y+11.5,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

     //top corner
       glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+4,y+13,z-4);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


      glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+2,y+12.5,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


      glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+5,y+12.5,z-3);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

      glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+2,y+12.5,z-4);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

      glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+5,y+12.5,z-4);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

    glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+2,y+12.5,z-2);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 

    glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+5,y+12.5,z-2);
    glScalef(2.5,2.5,-2.5);
    make_sphere();
    glPopMatrix(); 


     glColor3f(0,0.8,0);
    glPushMatrix();
    glTranslatef(x+2,y+12.5,z-1);
    glScalef(3,3,3);
    make_sphere();
    glPopMatrix(); 
    glScalef(1/0.03,1/0.035,1/0.03);
    glTranslatef(0,-0.15,0);
}

