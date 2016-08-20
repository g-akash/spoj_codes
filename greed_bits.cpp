#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		vector<int> vec;
		
		int n,k;
		cin>>n>>k;
		cin>>s;
		vec.resize(s.length());
		int rem = n-k;
		int she,die;
		if(rem%2==0){she=rem/2;die=rem/2;}
		else{she=rem/2+1;die=rem/2;}
		//cout<<rem<<she<<die<<endl;
		for(int j=0;j<s.length()&&she>0;j++)
		{
			if(s[j]=='1'&&vec[j]==0){vec[j]=1;she--;}
		}
		//cout<<"hello"<<endl;
		for(int j=0;j<s.length()&&she>0;j++)
		{
			if(s[j]=='0'&&vec[j]==0){vec[j]=1;she--;}
		}
		//cout<<"hello"<<endl;
		for(int j=0;j<s.length()&&die>0;j++)
		{
			if(s[j]=='0'&&vec[j]==0){vec[j]=1;die--;}
		}
		//cout<<"hello"<<endl;
		for(int j=0;j<s.length()&&die>0;j++)
		{
			if(s[j]=='1'&&vec[j]==0){vec[j]=1;die--;}
		}
		//cout<<"hello"<<endl;
		for(int j=0;j<s.length();j++)
		{
			if(vec[j]==0)cout<<s[j];
		}cout<<endl;

	}
}