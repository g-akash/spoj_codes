#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int q,var;
	vector<int> v;
	v.resize(20010);
	cin>>q;
	int ans=0;
	for(int i=0;i<q;i++)
	{
		cin>>var;
		if(var>0)
		{
			if(v[var-1]==0&&v[var+1]==0){v[var]=1;ans++;}
			else if(v[var-1]==0||v[var+1]==0){v[var]=1;}
			else {v[var]=1;ans--;}
		}
		else if(var==0)
		{
			if(v[1]==1)v[0]=1;
			else {v[0]=1;ans++;}
		}
		cout<<ans<<endl;
	}
	cout<<"Justice"<<endl;
}