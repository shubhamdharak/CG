/*g++ cg3.c -lglut -lGL -lGLEW -lGLU -o cg3
./cg3 */
#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
//#include<iostream>

#define ROUND(x) ((int)(x+0.5))

int ax=-10,ay=-150,bx=-10,by=-100;
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
void matrixmultiplication(int temp[][],int ax,int ay,int bx,int by,int cx,int cy,int ex,int ey)
	{
		int result[50][50],temp[40][40],point[20][20];
		int i,j;
		point[0][0]=ax;
		point[0][1]=ay;
		point[0][2]=1;
		point[1][0]=bx;
		point[1][1]=by;
		point[1][2]=1
		point[2][0]=cx;
		point[2][1]=cy;
		point[2][2]=1;
		point[3][0]=ex;
		point[3][1]=ey;
		point[3][2]=1;
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					result[i][j]=result[i][j]+(point[i][k]+temp[k][j]);
				}
			printf("%d",result[i][j]);
			}			
		}
	}
void scalingmatrix()
	{
		int s[30][30];
		
		printf("enter sx and sy values:");
		scanf("%d %d",&sx,&sy);
		s[0][0]=sx;
		s[0][1]=0;
		s[0][2]=0;
		s[1][0]=0;
		s[1][1]=sy;
		s[1][2]=0;
		s[2][0]=0;
		s[2][1]=0;
		s[2][2]=1;
		
	matrixmultiplication(s[][]);
		
	}
void transformmatrix()
	{
		int t[30][30];
		printf("enter tx and ty values\n");
		scanf("%d%d",&tx,&ty);
		
		t[0][0]=1;
		t[0][1]=0;
		t[0][2]=0;
		t[1][0]=0;
		t[1][1]=1;
		t[1][2]=0;
		t[2][0]=tx;
		t[2][1]=ty;
		t[2][2]=1;
		matrixmultiplication(t[][]);
	
		
	}

void rotationmatrix()
	{
		printf("enter the angle");
		scanf("%d",&ang);
		r[0][0]=cos(ang);
		r[0][1]=sin(ang);
		r[0][2]=0;
		r[1][0]=sin(-ang);
		r[1][1]=cos(ang);
		r[1][2]=0;
		r[2][0]=0;
		r[2][1]=0;
		r[2][2]=1;
		
	matrixmultiplication(r[][]);
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

void transform(int ax,int ay,int bx,int by,int cx,int cy,int ex,int ey)
{
	int ch1,ans;
	printf("\n1.square\n2.triangle\n");
	printf("enter your choice:");
	scanf("%d",&ch1);
	switch(ch1)
	{
		case 1:
			
			ddaline(ax,ay,bx,by);
			ddaline(bx,by,cx,cy);
			ddaline(cx,cy,dx,dy);
			ddaline(ex,ey,ax,ay);
			break;
	
		case 2:
			break;
	}
				
				int ch;
				do
				{
		
					printf("transforms\n1.rotation\n2.translation\n.3.scaling\n");
					printf("enter your choice:\n");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1://rotation
							rotation();
						break;

						case 2: //translation operation
							transmatrix();
						break;

						case 3://scaling operation
							
							scalingmatrix();
						break;
					}
		printf("\ndo u want to continue\n");
		scanf("%d",&ans);
		}while(ans==1);
	}	
	
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	coordinate_system();//draw Cartesian coordinate system
	drawpat(ax,ay,bx,by);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Draw Pattern");
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
