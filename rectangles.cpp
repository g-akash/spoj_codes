#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	v.resize(10001);
	for(int i=1;i<10001;i++)
	{
		for(int j=i*i;j<10001;j+=i)
			v[j]++;
	}
	int ans=0,n;
	cin>>n;
	for(int i=0;i<=n;i++)ans+=v[i];
		cout<<ans<<endl;
}