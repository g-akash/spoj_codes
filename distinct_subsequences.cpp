#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll long long int
#define MOD %1000000007


int main()
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++)
	{
		string s;
		cin>>s;
		int len = s.length();
		vector<ll> sum,last;
		ll temp;
		sum.resize(s.length());
		last.resize(200);
		for(int i=0;i<200;i++)
		{
			last[i]=-1;
		}
		last[s[0]]=0;
		sum[0]=2;
		for(int i=1;i<len;i++)
		{
			if(last[s[i]]>=1)
			{
				temp = (sum[i-1]-sum[last[s[i]]-1]+1000000007)%1000000007;
			}
			else if(last[s[i]]==0)
			{
				temp = (sum[i-1]-1+1000000007)%1000000007;
			}
			else
			{
				temp = sum[i-1];
			}
			//cout<<temp<<endl;
			temp=temp%1000000007;
			sum[i]=sum[i-1]+temp;
			sum[i]=sum[i]%1000000007;
			last[s[i]]=i;
		}
		cout<<sum[len-1]<<endl;
	}
}