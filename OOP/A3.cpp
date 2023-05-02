#include<iostream>
using namespace std;
class publication
{
	public:
		string title;
		float price;
		void put_data()
		{
			cout<<"\nEnter title for book/cassette:";
			cin.ignore();   //since we are using 2 cin function the compiler thinks that first cin has some data so it doesnt stop
			getline(cin,title);
			cout<<"\nEnter price:";
			cin>>price;
		}
		void show_data()
		{
			cout<<"\nTitle:"<<title<<endl;
			cout<<"\nPrice:"<<price<<endl;
		}
};
class book:public publication
{
	public:
		int page_count;
		void put_pagecount()
		{
		try{
			cout<<"Enter page count:";
			cin>>page_count;
			if(page_count<=0)
			throw page_count;
		}
		catch(...)
		{
			cout<<"\nENTER VALID DATA";
			page_count=0;
		}
		}
		void show_pagecount()
		{
			cout<<"Page count:"<<page_count<<endl;
		}
};
class tape:public publication
{
	public:
		float tape_count;
		void put_tapecount()
		{
			try{
				cout<<"Enter tape count:";
				cin>>tape_count;
				if(tape_count<=0.0)
				throw tape_count;
			}
			catch(...)
			{
				cout<<"\nENTER VALID DATA";
				tape_count=0;
			}
			
		}
		void show_tapecount()
		{
			cout<<"Tape count:"<<tape_count<<endl;
		}
};
int main()
{
	int n;
	char ans;
	do
	{
		cout<<"CHOICES\n"<<"1) BOOK\n"<<"2) CASSETTE\n";
		cout<<"Enter choice:";
		cin>>n;
		switch(n)
		{
			case 1:
				{
					book b;
					b.put_data();
					b.put_pagecount();
					b.show_data();
					b.show_pagecount();
					break;
				}
			case 2:
				{
					tape t;
					t.put_data();
					t.put_tapecount();
					t.show_data();
					t.show_tapecount();
					break;
				}
		}
	cout<<"\nDo you wish to continue?(y/n)";
			cin>>ans;
}
	while(ans=='y');
	cout<<"***THANK YOU***";
	return 0;
}
