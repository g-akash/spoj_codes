#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main()
{
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		int j;
		vector<string> v;
		int ans=0;
		v.resize(2);
		cin>>v[0];
		cin>>v[1];
		string s;
		int x=v[0].find("#");
		int y=v[1].find("#");
		if(x>v[0].length()||x<0){cout<<"Yes"<<endl<<0<<endl;continue;}
		if(y>v[0].length()||y<0){cout<<"Yes"<<endl<<0<<endl;continue;}
		if(x<y){s=v[0];v[0]=v[1];v[1]=s;}
		int lane=0;
		if(v[lane][0]=='#'){cout<<"No"<<endl;continue;}
		for(j=0;j<v[0].length()-1;j++)
		{
			if(v[lane][j+1]=='.')continue;
			else if(v[(lane+1)%2][j+1]=='.'){ans++;lane=(lane+1)%2;}
			else{cout<<"No"<<endl;break;}
		}
		if(j>=v[0].length()-1)cout<<"Yes"<<endl<<ans<<endl;
	}
}
