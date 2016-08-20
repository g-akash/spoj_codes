#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

#define ll long long int 

int main()
{
	int n;
	cin>>n;
	ll var,vex,ans=1;;
	stack<ll> st;
	for(int i=0;i<n;i++)
	{
		cin>>var;
		if(st.empty())st.push(var);
		else
		{
			while(!st.empty())
			{
				vex=st.top();
				if(vex<var){st.pop();ans=(ans*var)%1000000007;}
				else break;
			}
			st.push(var);
		}
	}
	cout<<ans<<endl;

}