#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
int main()
{
	int x,y,r=50;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	x=getmaxx()/2;
	y=getmaxy()/2;
	circle(x,y,r);
	int ch;
	while((ch=getch())!=13&&(ch=getch())!=27)
	{
		switch(ch)
		{
			case 75:
				if(x>=r+1)
				{
					cleardevice();
					circle(x-=10,y,r);
				}
				break;
			case 72:
				if(y>=r+1)
				{
					cleardevice();
					circle(x,y-=10,r);
				}
				break;
			case 77:
				if(x<getmaxx()-r-10)
				{
					cleardevice();
					circle(x+=10,y,r);
				}
				break;
			case 80:
				if(y<getmaxy()-r-10)
				{
					cleardevice();
					circle(x,y+=10,r);
				}
				break;
			default:
				cout<<"PRESS VALID KEYS";
		}
	}
	getch();
	closegraph();
}
