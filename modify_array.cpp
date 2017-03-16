#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> a,b,c;
		int var;
		for(int j=0;j<n;j++)
		{
			cin>>var;
			
			if(var>0)a.push_back(var);
			else if(var==0)b.push_back(var);
			else c.push_back(var);
			
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		int posc=0;
		
		//cout<<int(c.size()-1)<<endl;
		while(posc<=int(c.size()-1)&&k>0)
		{//cout<<posc<<c.size()-1<<endl;
			a.push_back(-1*c[posc]);
			posc++;
			k--;
		}
		
		sort(a.begin(),a.end());
		if(k!=0)
		{
			if(b.size()==0&&a.size()>0)
			{
				if(k%2==1)a[0]=-1*a[0];
			}
		}
		//cout<<"okay"<<endl;
		int ans=0;
		for(int j=0;j<a.size();j++)ans+=a[j];
			for(int j=posc;j<=int(c.size()-1);j++)ans+=c[j];
		cout<<ans<<endl;
	}
}
