#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
	int a,b,n;
	cin>>a>>b>>n;
	vector<int> v;
	vector<int> ans;
	v.resize(b-a+1);
	ans.resize(b-a+1);
	int srt=sqrt(b);
	for(int i=1;i<=srt;i++)
	{
		int l,r;
		l=(a/i)*i;
		while(l>=a)l-=i;
		while(l<a)l+=i;
		if(l<i*i)l=i*i;

		r=(b/i)*i;
		while(r<=b)r+=i;
		while(r>b)r-=i;
		for(int j=l;j<=r;j+=i)
		{
			if(i*i==j)ans[j-a]++;
			else ans[j-a]+=2;
		}
	}
	int count=0;
	for(int i=0;i<b-a+1;i++)if(ans[i]==n)count++;
		cout<<count<<endl;
}