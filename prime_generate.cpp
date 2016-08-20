#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x-y!=2&&x-y!=0)cout<<"No Number"<<endl;
		else 
		{
			int z=x+y;
			z=z/4;
			z=z*4;
			if(x==y)
			{
				if(z==x+y)cout<<z<<endl;
				else cout<<z+1<<endl;
			}
			else
			{
				if(z==x+y)cout<<z-1<<endl;
				else cout<<z+2<<endl;
			}
		}
	}
}

		
