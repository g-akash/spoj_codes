#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int j=1;
	while(j<n)
	{
		if(v[j]>=v[j-1])break;
		j++;
	}
	if(j==n){cout<<"Yes"<<endl;return 0;}
	else 
	{
		bool ans=true;
		j++;
		while(j<n)
		{
			if(v[j]<=v[j-1])ans=false;
			j++;
		}
		if(ans)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}