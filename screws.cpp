#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n,k,s;
	cin>>n>>k>>s;
	vector<int> v;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	int cs=0,cb=0,st=n-1;
	while(!(cs>=s*k))
	{
		cs+=v[st];
		st--;
		cb++;
	}
	cout<<cb<<endl;
}
