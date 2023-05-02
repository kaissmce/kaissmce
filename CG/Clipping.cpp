#include<iostream>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
using namespace std;
int LEFT=1,RIGHT=2,TOP=8,BOTTOM=4;
int xmin,xmax,ymin,ymax;
int getcode(int x,int y)
{
	int code=0;
	if(y>ymax) code|=TOP;
	if(y<ymin) code|=BOTTOM;
	if(x>xmax) code|=RIGHT;
	if(x<xmin) code|=LEFT;
	return code;
}
int main()
{
	int x1,y1,x2,y2;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	cout<<"\nEnter window co-ordinates";
	cout<<"\nxmin= ";
	cin>>xmin;
	cout<<"\nymin= ";
	cin>>ymin;
	cout<<"\nxmax= ";
	cin>>xmax;
	cout<<"\nymax= ";
	cin>>ymax;
	rectangle(xmin,ymin,xmax,ymax);
	cout<<"\nEnter line co-ordinates";
	cout<<"\nx1= ";
	cin>>x1;
	cout<<"\ny1= ";
	cin>>y1;
	cout<<"\nx2= ";
	cin>>x2;
	cout<<"\ny2= ";
	cin>>y2;
	line(x1,y1,x2,y2);
	int outcode1=getcode(x1,y1),outcode2=getcode(x2,y2);
	cout<<outcode1<<endl;
	cout<<outcode2<<endl;
	int x,y,temp;
	int accept=0;
	while(1)
	{
		float m=(float)(y2-y1)/(x2-x1);
		if((outcode1==0)&&(outcode2==0))
		{
			accept=1;
			break;
		}
		else if((outcode1 & outcode2)!=0)
		{
			break;
		}
		else
		{
			if(outcode1==0)
			temp=outcode2;
			else
			temp=outcode1;
			if(temp & TOP)
			{
				y=ymax;
				x=x1+(ymax-y1)/m;
			}
			else if(temp & BOTTOM)
			{
				y=ymin;
				x=x1+(ymin-y1)/m;
			}
			else if(temp & RIGHT)
			{
				x=xmax;
				y=y1+m*(xmax-x1);
			}
			else if(temp & LEFT)
			{
				x=xmin;
				y=y1+m*(xmin-x1);
			}
			if(temp==outcode1)
			{
				x1=x;
				y1=y;
				outcode1=getcode(x1,y1);
			}
			else
			{
				x2=x;
				y2=y;
				outcode2=getcode(x2,y2);
			}
		}
	}
if(accept)
	{
		cout<<"\nLine accepted";
		cleardevice();
		rectangle(xmin,ymin,xmax,ymax);
		setcolor(YELLOW);
		line(x1,y1,x2,y2);
	}
else
	{
		cout<<"\nLine rejected";
	}
	getch();
    closegraph();
}
