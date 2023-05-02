#include<iostream>
#include<algorithm>    //since we are using in built functions for searching and sorting therefore <algorithm>
#include<vector>
#include<string>
using namespace std;
class student
{
	public:
		int rollno;
		string name;
		char dob[15];
		//== operator is needed for search function
		bool operator==(const student &student1)  //we are overloading == operator cause it will be required by search
		//since we are comparing therefore bool data type
		{
			return(rollno==student1.rollno);  //we are comparing 2 roll nos,since we will be searching based on roll no.
		}
		bool operator<(const student &student1)
		{
			return(rollno<student1.rollno);
		}
		//overload << to display record
		friend ostream& operator<<(ostream &out,const student &); //for reading
		// ^ if i say cout<<s1 , it should display all variables from s1 which is obj of class student
		//overload >> to accept record
		friend istream& operator>>(istream &in,student &k); //for writing contents from user
};
ostream & operator << (ostream &out, const student &k) 
		{
			out<<"\n\t\t"<<k.rollno<<"\t\t"<<k.name<<"\t\t"<<k.dob;  //it will display
			//k is an object which is passed to overloaded op it will display content of it
			return out;
		}
istream & operator >> (istream &in , student &k)		
		{
			cout<<"\nEnter Roll No:";
			in>>k.rollno;
			cout<<"\nEnter Name:";
			in>>k.name;
			cout<<"\nEnter Mobile No.:";
			in>>k.dob;
			return in;
		}    //using this cin>>s1 will execute all these lines
vector<student> read()
{
	int n;
	student k;    // k is obj of type student
	vector<student> j;  //vector in which we will add the elements
	cout<<"\nEnter total no of students:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;   //since cin operator is overloaded it will accept all 3 i.e name roll no and mob
		j.push_back(k);   //add element to the end of vector ; k will be added to vector
	}
	return j;
} //case 1 completed
void printfunc(const student &k)
{
	cout<<k;
}
void print(const vector<student> &j)
{
	cout<<"\n\t\tRoll No\t\tName\t\tDate Of birth";
	for_each(j.begin(),j.end(),printfunc);
//for_each is a function which executes from first parameter of vector to last parameter the third parameter
//suppose i have 5 entries so for_each will execute printfunc from begin to end 5 times 
}//case 2 completed
void search(vector<student> &j)
{
	student k;
	cout<<"\nEnter student's roll no to be searched:";
	cin>>k.rollno;
	cout<<"\n\t\tRoll No\t\tName\t\tDate of birth";
	vector<student>::iterator p;  //iterator is used since we want to traverse through the vector
	p=find(j.begin(),j.end(),k);   //we have to find k that has the roll no to bes searched
	//we need to overload == operator since find is a buitl in function which does not compare 2 objs
	//so by overloading it we make find func to compare element of the obj 
	if(p!=j.end()) //if p has not reached end it means p is found 
		cout<<*p;   //p points to the record
	else
		cout<<"\nNot found";	
} //case 3 completed
bool sort_func(const student &x,const student &y)
{
	return(x.rollno<y.rollno);
}
void sort(vector<student> &j)
{
	sort(j.begin(),j.end(),sort_func);
}

int main()
{
	vector<student> s;   //created a vecotr s for class student
	int ch;
	do
	{
		cout<<"\n1) Create a record";
		cout<<"\n2) Display the record";
		cout<<"\n3) Search through the record";
		cout<<"\n4) Sort the record";
		cout<<"\n5) Quit menu";
		cout<<"\n\n Select One Option:";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				s=read();
				break;
			case 2:
				print(s);
				break;
			case 3:
				search(s);
				break;
			case 4:
				sort(s);
				print(s);
				break;
		}
	}while(ch!=5);
	cout<<"THANK YOU";
		}
