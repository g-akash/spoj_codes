#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> prims,primes;


void prms()
{
	for(int i=2;i<1000005;i++)
	{
		if(prims[i]==1)continue;
		for(int j=2*i;j<1000005;j+=i)prims[j]=1;
	}
	for(int i=2;i<1000005;i++)
	{
		if(prims[i]==0)primes.push_back(i);
	}
	return;
}



int main()
{
	prims.resize(1000005);
	prms();
	int t;
	cin>>t;
	int n;
	string ans;
	long long int var;
	for(int i=0;i<t;i++)
	{
		ans="-1 -1";
		var=1;
		bool done=false;
		cin>>n;
		for(int j=0;j<primes.size()&&primes[j]<n;j++)
		{
			if(prims[n-primes[j]]==0&&primes[j]!=(n-primes[j]))
				{
					if(primes[j]*(n-primes[j])>var)
						{
							var=(long long int)primes[j]*(long long int)(n-primes[j]);
							ans=to_string(min(primes[j],n-primes[j]))+" "+to_string(max(primes[j],n-primes[j]));
						}
					}
		}
	//	if(!done)cout<<-1<<endl;
		cout<<ans<<endl;

	}

}