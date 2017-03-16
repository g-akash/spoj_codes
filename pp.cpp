#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> prims;
vector<int> pp;
vector<int> myfp;

void prime()
{
	prims[2]=0;
	for(int i=2;i<1000000;i++)
	{
		for(int j=2*i;j<1000000;j+=i)prims[j]=1;
	}
	return;
}

void finprim()
{
	for(int i=2;i<1000000;i++)
	{
		if(prims[i])continue;
		myfp.push_back(i);
		string s1,s2;
		s1=to_string(i);
		s2=s1;
		reverse(&s1[0],&s1[s1.length()]);
		if(s1==s2)pp.push_back(i);
	}
}
		

int main()
{
	prims.resize(1000000);
	prime();
	//pp.resize(1000);
	finprim();
	//for(int i=0;i<pp.size();i++)
	//{
		//cout<<i<<" "<<pp[i]<<endl;
	//}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int var,ans=1,a1;
		cin>>var;

		var=pp[var-1];
		a1=var;
		while(var!=0)
		{
			if(var%10!=0)ans*=var%10;
			var/=10;
		}
		cout<<a1<<" "<<myfp[ans-1]<<endl;
	}
}
