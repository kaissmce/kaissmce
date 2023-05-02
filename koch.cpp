#include<iostream>
using namespace std;
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void kcurve(int x1,int y1,int x2,int y2,int n)
{
	int x3,y3,x4,y4,x,y;
	float a=60*3.14/180;
	x3=(2*x1+x2)/3;
	y3=(2*y1+y2)/3;
	x4=(x1+2*x2)/3;
	y4=(y1+2*y2)/3;
	x=x3+(x4-x3)*cos(a)+(y4-y3)*sin(a);
	y=y3-(x4-x3)*sin(a)+(y4-y3)*cos(a);
	if(n>1)
	{
		kcurve(x1,y1,x3,y3,n-1);
		kcurve(x3,y3,x,y,n-1);
		kcurve(x,y,x4,y4,n-1);
		kcurve(x4,y4,x2,y2,n-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
		delay(50);
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int x1,y1,x2,y2,n;
	cout<<"\nEnter 1st co-ordinate ";
	cin>>x1>>y1;
	cout<<"\nEnter 2nd co-ordinate ";
	cin>>x2>>y2;
	cout<<"\nEnter no of iteration ";
	cin>>n;
	kcurve(x1,y1,x2,y2,n);
	getch();
	closegraph();
}
