#include<iostream>
using namespace std;
#define size 10
int n;
template<class T>       //T helps us to take any data type //instead of class we can use the keyword typename
void selection(T a[size])
{
	int i,j,min;
	T temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	cout<<"\nSorted array is:";
	for(i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
int main()
{
	int i;
	int a[size];
	float b[size];     //T is replaced by int and float resp.
	cout<<"\nHow many integer values you want?";
	cin>>n;
	cout<<"\nEnter the values:";
	for(i=0;i<n;i++)               //accept values for int arry
	{
		cin>>a[i];
	}
	selection(a);
	cout<<"\nHow many float values you want?";
	cin>>n;
	cout<<"\nEnter the values:";
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	selection(b);
	return 0;
}
