#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int main()
{
	vector<int> v;
	v.resize(1000005);
	v[1]=1;
	v[0]=0;
	for(int i=2;i<1000005;i++)
	{
		for(int j=2*i;j<1000005;j+=i)
			v[j]=1;
	}
	for(int i=1;i<1000005;i++)
	{
		if(v[i]==0)v[i]=v[i-1]+1;
		else v[i]=v[i-1];
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<fixed<<setprecision(6)<<float(v[r]-v[l-1])/float(r+1-l)<<endl;


	}

}