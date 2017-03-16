#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double a,b,x,y;
		cin>>a>>b>>x>>y;
		if(max(a,b)>max(x,y)&&min(a,b)>min(x,y))
		{
			cout<<"Escape is possible."<<endl;
		}
		else if()
		{
			cout<<"Escape is possible."<<endl;
		}
		else
		{
			cout<<"Box cannot be dropped."<<endl;
		}
	}
}