#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
void drawlines(int x1,int y1,int x2,int y2)
{
	float x,y,dx,dy,len,xi,yi;
	int i;
	dx=x2-x1;
	dy=y2-y1;
	if((abs(dx)>abs(dy))
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
	for(i=0;i<n;i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel(x,y,15);
	}
}
int main{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int i,j,k,n,ch;
	float sx,sy,tx,ty;
	cout<<"Enter no of vertices: ";
	cin>>n;
	float poly[n][3];
	for(i=0;i<n;i++)
	{
		poly[i][2]=1;
	}
	for(i=0;i<n;i++)
	{
		cout<<"Enter the"<<i+1<<"th co-ordinate:";
		cin>>poly[i][0]>>poly[i][1];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<poly[i][j]<<"\t";
			cout<<endl;
		}
		cout<<endl;
		for(i=0;i<n-1;i++)
		{
			drawlines(poly[i][0],poly[i][1],poly[i+1][0],poly[i+1][1]);
		}
		drawlines(poly[n-1][0],poly[n-1][1],poly[0][0],poly[0][1]);
	
	}
	do{
		cout<<"\nSELECT ONE OPERATION";
		cout<<"\n1) SCALING";
		cout<<"\n2) TRANSLATION";
		cout<<"\n3) ROTATION";
		cin>>ch;
		if(ch==1)
		{
			cout<<"\nENTER SCALING CO-ORDINATES";
			cout<<"\nsx=";
			cin>>sx;
			xout<<"\nsy=";
			cin>>sy;
			float s[3][3];
			for(i=0;i<;i++)
			{
				for(j=0;j<3;j++)
				{
					s[i][j]=0;
				}
			}
			s[0][0]=sx;
			s[1][1]=sy;
			s[2][2]=1;
			float result[n][3];
			for(i=0;i<n;i++)
			{
				for(j=0;j<3;j++)
				{
					result[i][j]=0;
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<3;j++)
				{
					for(k=0;k<3;k++)
					{
						result[i][j]+=poly[i][k]*s[k][j];
					}
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<3;j++)
				{
					cout<<result[i][j]<<"\t";
					cout<<endl;
				}
			}
			for(i=0;i<n;i++)
			{
				drawlines(result[i][0],result[i][1],result[i+1][0],result[i+1][1]);
			}
			drawlines(result[n-1][0],result[n-1][1],result[0][0],result[0][1]);
		}
		else if(ch==2)
		{
		}
	}
}
