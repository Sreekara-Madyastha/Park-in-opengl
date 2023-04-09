#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
#include<GL/gl.h>

GLfloat Tx=0,Ty=0,Tz=0,Rx=0,Ry=0,Rz=0,S=1;
GLfloat old_x=0,old_y=0;
bool wheel_on=true;
double T=0.0;

void keyboard(unsigned char key, int x,int y) {
    // glLoadIdentity();
    if(key=='d' || key=='D'){
        Tx+=0.1;
    }
    else if(key=='a' || key=='A'){
        Tx-=0.10;
    }
    else if(key=='w' || key=='W'){
        Tz-=0.10;
    }
    else if(key=='s'|| key=='S'){
        Tz+=0.10;
    }
    else if(key=='r' || key=='R'){
        Ty-=0.10;
    }
    else if(key=='f' || key=='F'){
        Ty+=0.10;
    }
    else if(key=='q' || key=='Q'){
        S*=1.2;
    }
    else if(key=='e' || key=='E'){
        S*=0.83;
    }
    else if(key=='c' || key=='C'){
        Tx=0;Ty=0;Tz=0;Rx=0;Ry=0;Rz=0;S=1;Direction=0;Angle=0;
    }
    else if(key=='T' || key=='t'){
        if(wheel_on){
            wheel_on=false;
        }
        else{
            wheel_on=true;
        }
    }
    else if(key=='0'){
        Direction=Direction+90;
        if(Direction>=360){
            Direction=0;
        }
    }
    glutPostRedisplay();
    return;
}
void mouse(int x, int y){
    // glLoadIdentity();
        if(x>(old_x+1)){
            Ry-=1;
        }
        else if(x<(old_x-1)){
            Ry+=1;
        }
    old_x=x;old_y=y;
    glutPostRedisplay();
    return;
}
void Person_movement(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            people[0][1]+=0.05;
            if(Angle>=0){
                Angle=-25;
            }
            else{
                Angle=25;
            }
            
        break;
        case GLUT_KEY_DOWN:
            people[0][1]-=0.05;
            if(Angle>=0){
                Angle=-25;
            }
            else{
                Angle=25;
            }
        break;
        case GLUT_KEY_LEFT:
            people[0][0]+=0.1;
            if(Angle>=0){
                Angle=-25;
            }
            else{
                Angle=25;
            }
        break;
        case GLUT_KEY_RIGHT:
            people[0][0]-=0.1;
            if(Angle>=0){
                Angle=-25;
            }
            else{
                Angle=25;
            }
        break;
    }

    glutPostRedisplay();
}