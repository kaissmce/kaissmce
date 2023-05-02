#include<iostream>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
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
			while(y>=x);
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
	float x,y,dx,dy,xi,yi,len;
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
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	int xc,yc,r;
	int x1,y1,x2,y2,x3,y3,x4,y4;
	int xa,ya,xb,yb,xe,ye,xd,yd;
	cout<<"Enter co-ordinates for circle"<<endl;
	cout<<"\nEnter center co-ordinates: ";
	cin>>xc>>yc;
	cout<<"\nEnter radius: ";
	cin>>r;
	assign a;
	a.circlebres(xc,yc,r);
	cout<<"\nEnter co-ordinates for outer box"<<endl;
	cout<<"x1= ";
	cin>>x1;
	cout<<"\ny1= ";
	cin>>y1;
	cout<<"x2= ";
	cin>>x2;
	cout<<"\ny2= ";
	cin>>y2;
	cout<<"x3= ";
	cin>>x3;
	cout<<"\ny3= ";
	cin>>y3;
	cout<<"\nx4= ";
	cin>>x4;
	cout<<"\ny4= ";
	cin>>y4;
	drawlines(x1,y1,x2,y2);
	drawlines(x2,y2,x3,y3);
	drawlines(x3,y3,x4,y4);
	drawlines(x4,y4,x1,y1);
	cout<<"\nEnter co-ordinates for inner box"<<endl;
	cout<<"xa= ";
	cin>>xa;
	cout<<"\nya= ";
	cin>>ya;
	cout<<"xb= ";
	cin>>xb;
	cout<<"\nyb= ";
	cin>>yb;
	cout<<"xe= ";
	cin>>xe;
	cout<<"\nye= ";
	cin>>ye;
	cout<<"\nxd= ";
	cin>>xd;
	cout<<"\nyd= ";
	cin>>yd;
	drawlines(xa,ya,xb,yb);
	drawlines(xb,yb,xe,ye);
	drawlines(xe,ye,xd,yd);
	drawlines(xd,yd,xa,ya);
	getch();
}
