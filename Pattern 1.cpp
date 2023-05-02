#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
using namespace std;
class assign
{
	private:
		int x,y;
	public:
		void circlebres(int xc,int yc,int r)
		{
			
			int x=0,y=r;
			int d=3-2*r;
			while(x<=y)
			{
				if(d>0)
				{
					x++;
					y--;
					d=d+4*x-4*y+10;
				}
				else
				{
					d=d+4*x+6;
					x++;
				}
			putpixel(xc+x,yc+y,WHITE);
			putpixel(xc-x,yc+y,WHITE);
			putpixel(xc+x,yc-y,WHITE);
			putpixel(xc-x,yc-y,WHITE);
			putpixel(xc+y,yc+x,WHITE);
			putpixel(xc-y,yc+x,WHITE);
			putpixel(xc+y,yc-x,WHITE);
			putpixel(xc-y,yc-x,WHITE);
			}
		}
};
void drawlines(int x1,int y1,int x2,int y2)
{
	float x,y,dx,dy,len,xi,yi;
	int i;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
	{
		len=abs(dx);
	}
	else
	{
		len=abs(dy);
	}
	xi=dx/len;
	yi=dy/len;
	putpixel(x1,y1,15);
	x=x1;
	y=y1;
	for(i=0;i<len;i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel(x,y,15);
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int r,r1,xc,yc;
	int x1,y1,x2,y2,x3,y3;
	cout<<"Enter the co-ordinates for circle"<<endl;
	cout<<"\nCenter co-ordinates are: ";
	cin>>xc>>yc;
	cout<<"\nOuter radius is: ";
	cin>>r;
	cout<<"\nInner radius is: ";
	cin>>r1;
	assign a,b;
	a.circlebres(xc,yc,r);
	b.circlebres(xc,yc,r1);
	cout<<"\nEnter co-ordinates for triangle";
	cout<<"\nx1=";
	cin>>x1;
	cout<<"\ny1=";
	cin>>y1;
	cout<<"\nx2=";
	cin>>x2;
	cout<<"\ny2=";
	cin>>y2;
	cout<<"\nx3=";
	cin>>x3;
	cout<<"\ny3=";
	cin>>y3;
	drawlines(x1,y1,x2,y2);
	drawlines(x2,y2,x3,y3);
	drawlines(x3,y3,x1,y1);
	getch();
	
}
