/* g++ pat.c -lglut -lGL -lGLEW -lGLU -o pat
./pat
*/

#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
//#include<iostream>

#define ROUND(x) ((int)(x+0.5))
void secondSwitch();
 int x1,y1,x2,y2,x3,y3,x4,y4;

//int x1=10,x2=150,y1=10,y2=100;
//int x1,x2,y1,y2;

void coordinate_system(void)
{
	glBegin(GL_POINTS);
	glColor3f (1.0, 1.0, 1.0);
	 for(int i=-200 ; i<=200 ; i++)
	 {
		 glVertex2s(i,0);
 		 glVertex2s(0,i);
	 }
	 for(int i=-2; i<=2 ; i++)
	 {
		 glVertex2s(195+i,4+i);
		 glVertex2s(195-i,4+i);
	 } 
	 for(int i=0; i<=2 ; i++)
	 {
		 glVertex2s(4+i,195+i);
		 glVertex2s(4-i,195+i);
		 glVertex2s(4,195-i);
	 }

	glEnd();
	glFlush();
}

void putpixel(int x, int y)
{
	glColor3f (1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2s(ROUND(x),ROUND(y));
	glEnd();
}

void ddaline(int xa,int ya,int xb,int yb)
 {
	int dx=xb-xa,dy=yb-ya,steps,k;
	float xIncrement,yIncrement,x=xa,y=ya;

	 if(abs(dx)>abs(dy))
 		steps=abs(dx);
	 else 
		steps=abs(dy);
 
	 xIncrement=dx/(float)steps;
	 yIncrement=dy/(float)steps;

	for(k=0;k<steps;k++)
	 {
		putpixel(ROUND(x),ROUND(y)); 
		x+=xIncrement;
		 y+=yIncrement;
	 }
	 glFlush();
 }

 void init(void)
 {
	 glClearColor (0.0, 0.0, 0.0, 0.0);
 	glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
 }

void drawpatSquare(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	int m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y;
	ddaline(x1,y1,x2,y2);
	ddaline(x2,y2,x3,y3);
	ddaline(x3,y3,x1,y1);
		
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	coordinate_system();//draw Cartesian coordinate system
	drawpatSquare(x1,y1,x1,y2,x2,y2,x2,y1);//drawpat ,3
}
int main(int argc, char** argv)
{
	//printf("Enter the points\n");
	//scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	int A,B,C,D,choice;
	 int x1,y1,x2,y2,x3,y3,x4,y4;
	printf("\n*************");
	printf("\n1.Triangle");
	printf("\n2.Square");
	printf("\n***********");
	printf("\nEnter your choice ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter A[,]");
			scanf("%d%d",&x1,&y1);
			printf("Enter B[,]");
			scanf("%d%d",&x2,&y2);
			printf("Enter C[,]");
			scanf("%d%d",&x3,&y3);
			secondSwitch();
			break;
		case 2:
			printf("Enter A[,]");
			scanf("%d%d",&x1,&y1);
			printf("Enter B[,]");
			scanf("%d%d",&x2,&y2);		
			printf("Enter C[,]");
			scanf("%d%d",&x3,&y3);
			printf("Enter D[,]");
			scanf("%d%d",&x4,&y4);
			secondSwitch();
			break;
	glutInit(&argc, argv);//i
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Draw Pattern");
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	}
}


void secondSwitch()
{
	int choice;
	int Sx,Sy,Tx,Ty,o;
	printf("\n****Translation****");
	printf("\n1.Transformation");
	printf("\n2.Scaling");
	printf("\n3.Rotation");
	printf("\n***********");
	printf("\nEnter your choice ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n**Translation**");
			printf("\nEnter Value of Tx,Ty");
			scanf("%d%d",&Tx,&Ty);
			printf("\n*************");
			break;
      case 2:
			printf("\n**Scaling**");
			printf("\nEnter Value of Sx,Sy");
			scanf("%d%d",&Sx,&Sy);
			printf("\n*************");
			break;
		case 3:
			printf("\n**Rotation**");
			printf("\nEnter Value of O");
			scanf("%d",&o);
			printf("\n*************");
			break;
	}	
}
