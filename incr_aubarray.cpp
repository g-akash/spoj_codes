#include <bits/stdc++.h>


using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> vec;
	vec.resize(n+1);
	vec[0]=-100;
	for(int i=1;i<=n;i++)
	{
		cin>>vec[i];
	}
	int maxlen=0,currlen=0;
	for(int i=1;i<=n;i++)
	{
		if(vec[i]>vec[i-1])currlen++;
		else currlen=1;
		maxlen=max(maxlen,currlen);
	}
	cout<<maxlen<<endl;
}