#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

#define ll long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{	
		int ans=0;
		string op="+",var;
		cin>>var;
		while(var!="=")
		{
			if(var=="+"||var=="-"||var=="*"||var=="/")op=var;
			else 
			{
				if(op=="+")ans+=stoll(var);
				else if(op=="-")ans-=stoll(var);
				else if(op=="*")ans*=stoll(var);
				else ans/=stoll(var);
			}
			cin>>var;
		}
		cout<<ans<<endl;
	}
}