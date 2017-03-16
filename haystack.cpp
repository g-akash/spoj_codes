#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int n,k;
	cin>>n>>k;
	vector<long long int> v;
	v.resize(n+1);
	int a,b;
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		a--;
		v[a]++;
		v[b]-=1;
	}
	long long int var=0;
	for(int i=0;i<=n;i++)
	{
		var+=v[i];
		v[i]=var;
	}
	v.resize(n);
	sort(v.begin(),v.end());
	cout<<v[n/2]<<endl;
	//for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl;
}