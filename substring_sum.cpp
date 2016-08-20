#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int k;
		string s;
		int ans=0;
		cin>>k>>s;
		int curr_sum=0;
		int a=0,b=0;
		while(b<s.length())
		{
			if(curr_sum>k){curr_sum-=(int(s[a])-96);a++;if(curr_sum==k)ans++;continue;}
			{curr_sum+=(int(s[b])-96);b++;if(curr_sum==k)ans++;continue;}
			
		}
		cout<<ans<<endl;
	}
}
