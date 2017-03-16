#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	
	int n;
	cin>>n;
	vector<int> v1,v2;
	while(n!=0)
	{
		
		v1.resize(n+1);
		v2.resize(n+1);
		int var;
		//bool ans=true;
		for(int i=1;i<=n;i++)
		{
			cin>>var;
			v1[i]=var;
			v2[var]=i;

		}
		bool ans=true;
		for(int i=1;i<=n;i++)if(v1[i]!=v2[i])ans=false;
		if(ans)cout<<"ambiguous"<<endl;
		else cout<<"not ambiguous"<<endl;
		cin>>n;
	}
}