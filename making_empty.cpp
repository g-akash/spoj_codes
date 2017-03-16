#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		stack<char> st;
		//if(s.length()>=2){st.push(s[0]);st.push(s[1]);}
		char c1,c2,c3;
		for(int j=0;j<s.length();j++)
		{
			if(st.size()<2){st.push(s[j]);continue;}
			c2=st.top();
			st.pop();
			c1=st.top();
			st.pop();
			c3=s[j];
			if(!(c1=='1'&&c2=='0'&&c3=='0')){st.push(c1);st.push(c2);st.push(c3);}
			//else cout<<"popped"<<endl;
		}
		if(st.empty())cout<<"Case "<<i+1<<": yes"<<endl;
		else cout<<"Case "<<i+1<<": no"<<endl;
	}
}
			
