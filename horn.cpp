#include<iostream>
#include<vector>

using namespace std;


int main()
{
	vector<int> vec;
	vec.resize(1000006);
	for(int i=1;i<=1000000;i++)
	{
		for(int j=i;j<=1000000;j+=i)
		{
			vec[j]+=i;
		}
	}
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(vec[temp]==2*temp)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}