#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int m,n;
		cin>>m>>n;
		vector<int> f,s;
		f.resize(sqrt(n)+4);
		s.resize((n-m)+1);
		for(int j=2;j<f.size();j++)
		{
			if(f[j]==1)continue;

			for(int k=2*j;k<f.size();k+=j)f[k]=1;
				int l=(m/j)*j;
			while(l>=m)l-=j;
			while(l<m)l+=j;
			if(l==j)l+=j;
				for(int k=l-m;k<s.size();k+=j)s[k]=1;
				

		}
	int ans=0;
	for(int j=0;j<s.size();j++)if(s[j]==0&&j+m>1)cout<<j+m<<endl;
		cout<<endl;
		
	}
}