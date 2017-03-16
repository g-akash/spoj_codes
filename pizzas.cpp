#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,of=0,hf=0,tf=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s=="1/4")of++;
		else if(s=="1/2")hf++;
		else if(s=="3/4")tf++;
	}
	int ans=0;
	if(hf%2==0)
	{
		ans+=hf/2;
		if(tf>=of)
		{
			ans+=tf;
		}
		else
		{
			ans+=tf;
			of-=tf;
			ans+=of/4;
			if(of%4!=0)ans++;
		}

	}
	else
	{
		ans+=hf/2;
		if(tf>=of)
		{
			ans+=tf;
			ans++;
		}
		else
		{
			ans+=tf;
			of-=tf;
			ans+=of/4;
			if(of%4==0||of%4==1||of%4==2)ans++;
			else ans+=2;
		}

	}
	cout<<ans+1<<endl;
}