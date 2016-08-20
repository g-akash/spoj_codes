#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		string s;
		int cnt0=0,cnt5=0;
		vector<int> digs;
		for(int i=0;i<s.length();i++)
		{
			if(int(s[i])-48==0){cnt0++;continue;}
			if(int(s[i])-48==5){cnt5++;continue;}
			digs.push_back(int(s[i])-48);
		}
		if(cnt5==0&&cnt0==0){cout<<"impossible"<<endl;continue;}
		if(cnt0!=0)
		{
			for(int i=0;i<cnt5;i++)digs.push_back(5);
			sort(digs.begin(),digs.end());
			int sum=0;
			for(int i=0;i<digs.size();i++)
			{
				sum+=digs[i];
			}
			if(digs.size()>=3)
			{
				if(sum%3==0){}
				else if((sum-digs[0])%3==0){}
				else if((sum-digs[1])%3==0){}
				else if((sum-digs[2])%3==0){}
				else if((sum-digs[0]-digs[1])%3==0){}
				else if((sum-digs[0]-digs[2])%3==0){}
				else if((sum-digs[1]-digs[2])%3==0){}
			}
			else if(digs.size()==2)
			{
				if(sum%3==0){}
				else if((sum-digs[0])%3==0){}
				else if((sum-digs[1])%3==0){}
				else if((sum-digs[2])%3==0){}
				else{}
			}
			else if(digs.size()==1)
			{
				if(sum%3==0){}
				else{}
			}
			else if(digs.size()==0){}

		}
		else
		{
			for(int i=0;i<cnt5-1;i++)digs.push_back(5);
			sort(digs.begin(),digs.end());
		}
	}
}