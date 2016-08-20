#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<unsigned long long int> v; 

int main()
{
	v.resize(200005);
	v[0]=1;
	for(int i=1;i<v.size();i++)
	{
		v[i]=(v[i-1]*2)%1000000007;
	}
	vector<unsigned long long int> arr;
	unsigned long long int n;
	cin>>n;
	arr.resize(n+1);
	for(int i=1;i<=n;i++)cin>>arr[i];
		unsigned long long int ans=0;
	for(unsigned long long int i=1;i<=n;i++)
	{
		//cout<<arr[i]<<endl;
		if(i>=2)
		ans=ans+((v[n-i]*(((arr[i]*(i+1))*v[i-2])%1000000007)));
	else ans=ans+((v[n-i]*(((arr[i]*(i+1))/v[2-i])%1000000007)));
		//cout<<ans<<endl;
		ans=ans%1000000007;
	}
	cout<<ans<<endl;
}