#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string state;
	int popu;
	char ans='y';
	int ch;
	map<string,int> m;
	map<string,int>::iterator i;
	do
	{
		cout<<"SELECT ONE OPERATION";
		cout<<"\n1) INSERT ELEMENT";
		cout<<"\n2) DISPLAY";
		cout<<"\n3) SEARCH FOR A STATE"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the name of state:";
				cin>>state;
				cout<<"\nEnter population of state(in Cr):";
				cin>>popu;
				m.insert(pair<string,int>(state,popu));
				break;
			case 2:
				cout<<"\nSTATE AND POPULATIONS ARE:";
				for(i=m.begin();i!=m.end();i++)   //i is for iterator
					cout<<"["<<(*i).first<<","<<(*i).second<<"]";    //(*i).first==i->first
				break;
			case 3:
				cout<<"\nEnter the state to be searched:";
				cin>>state;
				if(m.count(state)!=0)
					cout<<"Population is:"<<m.find(state)->second<<"Cr";      
				else
					cout<<"State is not present"<<endl;
				break;
		}
		cout<<"\nDo you want to continue?(y/n)";
		cin>>ans;
	}while(ans=='y'|ans=='Y');
	cout<<"THANK YOU";
	return 0;
}
