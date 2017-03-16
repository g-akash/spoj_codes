#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n;
	cin>>n;
	int maxval=n*(n+1);
	int cur=n,p=1,end=maxval;;
	while(cur>0)
	{
		for(int i=0;i<n-cur;i++)cout<<"  ";
		for(int i=0;i<cur;i++)cout<<p+i<<"*";
			for(int i=end-cur+1;i<end;i++)cout<<i<<"*";cout<<end;cout<<endl;
				end-=cur;
			p+=cur;


		cur--;
	}
}