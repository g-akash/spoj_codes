#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;





int main()
{
	string s;
	cin>>s;
	int t=0;
	while(s[0]!='-')
	{
		stack<char> st;
		st.push(s[0]);
		for(int i=1;i<s.length();i++)
		{
			if(s[i]=='}'&&!st.empty()&&st.top()=='{')st.pop();
			else st.push(s[i]);
		}
		int o=0,c=0;
		while(!st.empty())
		{
			if(st.top()=='{')o++;
			else c++;
			st.pop();
		}
		int ans=0;
		if(o==0)ans=c/2;
		else if(c==0)ans=o/2;
		else
		{
			ans+=o/2;
			ans+=c/2;
			if(o%2==1)
			{
				
				ans+=2;
			}

		}
		cout<<t+1<<". "<<ans<<endl;
		t++;
		cin>>s;
	}
}