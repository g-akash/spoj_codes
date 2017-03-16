#include<iostream>
#include<set>
#include<map>

using namespace std;

int main()
{
	int n;
	cin>>n;
	multiset<int> s;
	int a,b;
	for(int i=0;i<n;i++)
	{

		cin>>a;
		if(a==3){if(s.empty()){cout<<-1<<endl;continue;}cout<<*s.rbegin()<<endl;continue;}
		if(a==4){if(s.empty()){cout<<-1<<endl;continue;}cout<<*s.begin()<<endl;continue;}
		if(a==1){cin>>b;s.insert(b);continue;}
		if(a==2)
			{
				cin>>b;
				if(s.find(b)==s.end()){cout<<-1<<endl;continue;}
				else {s.erase(s.find(b));}
				continue;

			}
	}
}