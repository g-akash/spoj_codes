#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int cas=1;
	while(s!="bye")
	{
		vector<int> v;
		v.resize(s.length());
		for(int i=0;i<s.length();i++)
		{
			v[i]=int(s[i])-48;
		}
		vector<vector<int> > ans;
		ans.resize(s.length());
		for(int i=0;i<s.length();i++)ans[i].resize(226);
		for(int i=0;i<v[0];i++)ans[0][i]=0;
		for(int i=v[0];i<=225;i++)ans[0][i]=1;
		for(int i=1;i<s.length();i++)
		{
			for(int j=0;j<=225;j++)
			{
				int sum=0;
				int pos=i;
				while(sum+v[pos]<=j)
				{
					sum+=v[pos];
					pos--;
					if(pos>=0)
					{
						ans[i][j]+=ans[pos][sum];
						
						}
					else{ans[i][j]+=1;}
					if(pos<0)break;
					}
		}
	}
	//for(int i=0;i<s.length();i++){
	//for(int j=0;j<20;j++)cout<<ans[i][j]<<" ";cout<<endl;}
		cout<<cas<<". "<<ans[s.length()-1][225]<<endl;
		
		cas++;
		cin>>s;
	}
}
