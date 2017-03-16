#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int winn=2,var;
	for(int i=0;i<n;i++)
	{
		cin>>var;
		if(var%2==0)
		{
			if(winn==2)winn=1;
			else winn=2;
			cout<<winn<<endl;
		}
		else if(var%2==1)
		{
			cout<<winn<<endl;
		}
	
	}
}