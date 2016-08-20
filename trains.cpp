#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans=0;
	vector<int> v;
	v.resize(n);
	cin>>v[0];
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
		if(v[i]<v[i-1])ans++;
	}
	cout<<ans<<endl;
}
3 1 2 5 4