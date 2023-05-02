#include<iostream>
#include<string>
using namespace std;
class student;
class person
{
	private:
		string name,blood,adr,tele,lic,dob;
	public:
		friend class student;   //student is a friend class of person i.e it can access all private members of person
		
		person()    //default constructor
		{
			name="",blood="",adr="",tele="",lic="",dob="";   //it will remove the garbage value and give some default value to var
		}
		person(const person &p) //copy constructor
		{
			name=p.name;
			blood=p.blood;
			adr=p.adr;
			tele=p.tele;
			lic=p.lic;
			dob=p.dob;	
		}
	
		
};
class student
{
	private:
		int rollno;
		string cla;
		char *div;
		char d;    //to store division
	public:
		static int count;    //how many objs are created its value will be saved in count
		student()
		{
			div=new char;   //reserve single location for division
			person();   //calling the constructor so if we call student obj then automatically all things of person will be called
			rollno=0;
			cla="";
			div=NULL;
			count++;
		}
		inline void acceptstudent(person &p)  //to access private data so we pass the object of friend as parameter
		{
			cout<<"Enter your name:"<<endl;
			cin>>p.name;
			cout<<"Enter your blood group:"<<endl;
			cin>>p.blood;
			cout<<"Enter your address:"<<endl;
			cin>>p.adr;
			cout<<"Enter your telephone number:"<<endl;
			cin>>p.tele;
			cout<<"Enter your driving license no.:"<<endl;
			cin>>p.lic;
			cout<<"Enter your date of birth:"<<endl;
			cin>>p.dob;
			cout<<"Enter your roll no.:"<<endl;
			cin>>rollno;
			cout<<"Enter you class:"<<endl;
			cin>>cla;
			cout<<"Enter your division:"<<endl;
			cin>>d;
			div=&d;
		}
		void displaystudent(person &p)
		{
			cout<<"NAME: "<<p.name<<"|";
			cout<<"BLOOD GROUP: "<<p.blood<<"|";
			cout<<"ADDRESS: "<<p.adr<<"|";
			cout<<"TELEPHONE NUMBER: "<<p.tele<<"|";
			cout<<"DRIVING LICENSE NUMBER: "<<p.lic<<"|";
			cout<<"DATE OF BIRTH: "<<p.dob<<"|";
			cout<<"ROLL NO: "<<rollno<<"|";
			cout<<"CLASS: "<<cla<<"|";
			cout<<"DIVISION: "<<div<<"|";
			cout<<"------------------------------------------";
		}
		
		~student()
		{
			delete(div);    //dynamic memory deallocation
		}
		static int get()
		{
			return count;
		}
};
int student::count=0;  //all static member functions are called outside class
int main(){
	student *s[10];
	person *p[10];
	int f=0;
	int n;
	cout<<"Enter no of students: ";
	cin>>n;
	while(1)
	{
		int ch;
		cout<<"\n";
		cout<<"1) Enter a student info"<<"\n2) Display"<<"\n3) Exit"<<endl;
		cin>>ch;
		for(int j=0;j<n;j++)
		{
		
		if(ch==1)
		{
			s[f]=new student();
			p[f]=new person();
			s[f]->acceptstudent(*p[f]);  //* is used  for de-reference
			f++;
		}
		else if(ch==2)
		{
			for(int i=0;i<f;i++)
			{
				s[i]->displaystudent(*p[i]);  //passed the ith person object by de-referencing
			}
		}
		else if(ch==3)
		{
			cout<<"EXITED"<<endl;
			break;
		}
	}
	}
	
return 0;
}
