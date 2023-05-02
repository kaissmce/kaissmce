/*write a c++ program that creates an output file, writes info to it,closes the file and open it again as input file and read information from the file*/
#include<iostream>
#include<fstream>         //includes classes that support file like ifsteram,ofstream
using namespace std;
int main()
{
	string text;
	ofstream fout;    //create output stream     // ofstream used to write on files   //syntax= class function    //fout acts as obj
	fout.open("B4.txt",ios::app);    //ios::app means we can insert the contents in file
	cout<<"Enter text you wish to be displayed:"<<endl;
	//cin>>text;      if we use this statement we cant get spaces in string
	getline(cin,text);     //gtline used to read statement line by line 
	fout<<text;
	fout.close(); 
	ifstream fin;    //ifstream used to read from files      //syntax= class function
	fin.open("B4.txt",ios::in);    //ios::in means open for input/reading only
	cout<<"\n";
	cout<<"Entered text is:"<<text;
	fin.close();   //it automatically closes the file but its a good practice to do this
	return 0;
}
