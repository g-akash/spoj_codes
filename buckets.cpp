#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<unsigned long long int> v;
	v.resize(1000000);
	v[1]=1;
	for(unsigned long long int i=2;i<1000000;i++)v[i]=(i*i)+v[i-1];
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		unsigned long long int s;
		cin>>s;
		int x=1,y=1000000;
		while(y-x>1)
		{
			if(v[(x+y)/2]<=s)x=(x+y)/2;
			else y=(x+y)/2;
		}
		if(v[y]>s)cout<<x<<endl;
		else cout<<y<<endl;
	}
}
