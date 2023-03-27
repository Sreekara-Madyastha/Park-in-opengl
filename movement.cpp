#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>
#include<GL/gl.h>

GLfloat Tx=0,Ty=0,Tz=0,Rx=0,Ry=0,Rz=0,S=1;
GLfloat old_x=0,old_y=0;

void keyboard(unsigned char key, int x,int y) {
    glLoadIdentity();
    if(key=='d' || key=='D'){
        Tx+=0.1;
    }
    else if(key=='a' || key=='A'){
        Tx-=0.10;
    }
    else if(key=='w' || key=='W'){
        Tz+=0.10;
    }
    else if(key=='s'|| key=='S'){
        Tz-=0.10;
    }
    else if(key=='r' || key=='R'){
        Ty+=0.10;
    }
    else if(key=='f' || key=='F'){
        Ty-=0.10;
    }
    else if(key=='q' || key=='Q'){
        S*=1.2;
    }
    else if(key=='e' || key=='E'){
        S*=0.83;
    }
    else if(key=='c'){
        Tx=0;Ty=0;Tz=0;Rx=0;Ry=0;Rz=0;S=1;
    }
    glutPostRedisplay();
    return;
}
void mouse(int x, int y){
    glLoadIdentity();
        if(x>(old_x+1)){
            Ry+=1;
        }
        else if(x<(old_x-1)){
            Ry-=1;
        }
    old_x=x;old_y=y;
    glutPostRedisplay();
    return;
}