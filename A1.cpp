#include<iostream>
using namespace std;
class complex
{
float x;
float y;
public:
complex()   //default constructor
{
x=0;
y=0;
}
complex operator+(complex);    //for addition
complex operator*(complex);   //for multiplication
//func to accept value of real and img part
friend istream &operator>>(istream &input,complex &t)  //passing the address of istream and complex
{
cout<<"Enter the real part:";
input>>t.x;  
cout<<"Enter the imaginary part:";
input>>t.y;
}
//func to display complex nos.
friend ostream &operator<<(ostream &output,complex &t)
{
output<<t.x<<"+"<<t.y<<"i\n";
}
};
complex complex::operator+(complex c) //func to add 2 complex nos overloading
//return_type class_name::operator op(arg list) op=operator being overloaded
{
complex temp;
temp.x=x+c.x;         //c3 real =c1 real+c2 real
//the obj we will be returning that will be addition of obj passed + obj passed with '+' sign
temp.y=y+c.y;
return(temp);
}
complex complex::operator*(complex c)  //func to multiply 2 complex nos
{
complex temp2;
temp2.x=(x*c.x)-(y*c.y);
temp2.y=(x*c.y)+(y*c.x);
return (temp2);
}
int main()
{
complex c1,c2,c3,c4;
cout<<"Default constructor value=\n";
cout<<c1;
cout<<"Enter 1st no:\n";
cin>>c1;
cout<<"Enter 2nd no:\n";
cin>>c2;
c3=c1+c2;     //invokes operator+ func   c1=invokes the func & c2 an arg that is passed
//this statement is equal to c3=c1.operator+(c2) 
c4=c1*c2;
cout<<"\nThe first no is=";
cout<<c1;
cout<<"\nThe second no is=";
cout<<c2;
cout<<"\nSum is=";
cout<<c3;
cout<<"\nProduct is=";
cout<<c4;
return 0;
}
