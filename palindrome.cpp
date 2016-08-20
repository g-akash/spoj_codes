#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

vector<vector<int> > vec;
vector<int> chrs;

void update(int v, int index, int value)
{
	while(index<vec[v].size())
	{
		vec[v][index]+=value;
		index+=(index&(-1*index));
	}
	return;
}

int calculate(int v, int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=vec[v][index];
		index-=(index&(-1*index));
	}
	return sum;
}


int main()
{
	vec.resize(26);
	int n,q;
	cin>>n>>q;
	int var=1;
	while(var<=n)var*=2;
	for(int i=0;i<26;i++)
	{
		vec[i].resize(var);
	}
	chrs.resize(var);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		update(int(s[i])-97,i+1,1);
		chrs[i+1]=s[i]-97;
	}
	int typ,a,b;
	char ch;
	for(int i=0;i<q;i++)
	{
		cin>>typ;
		if(typ==1)
		{
			cin>>a>>ch;
			update(chrs[a],a,-1);
			update(int(ch)-97,a,1);
			chrs[a]=int(ch)-97;
		}
		else
		{
			cin>>a>>b;
			int o=0,e=0;
			for(int i=0;i<26;i++)
			{
				int ans=calculate(i,b);
				if(a>1)ans-=calculate(i,a-1);
				if(ans%2==0)e++;
				else o++;
			}
			if(o>1)cout<<"no"<<endl;
			else cout<<"yes"<<endl;
		}
	}
}