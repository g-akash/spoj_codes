#include<iostream>
#include<vector>

using namespace std;

#define ull unsigned long long int

int main()
{
	int n;
	ull m,curr=0,mx=0,s=0,e=0;
	cin>>n>>m;
	vector<ull> v;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++)
	{
		curr+=v[i];
		e=i;
		while(curr>m)
		{
			curr-=v[s];
			s++;
		}
		mx=max(mx,curr);

	}
	cout<<mx<<endl;

}