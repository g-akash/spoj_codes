#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;


int main()
{
	int n,k,var;
	cin>>n>>k;

	unsigned long long int ans=0;
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		
		cin>>var;
		m[var]+=1;
	}
	unordered_map<int,int>::iterator it=m.begin();
	while(it!=m.end())
	{
		var=it->first;
		if(m.find(var+k)!=m.end())ans++;
		//cout<<it->second<<endl;
		//if(m.find(var-k)!=m.end())ans++;
		it++;
	}
	cout<<ans<<endl;

}