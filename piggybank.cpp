#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
unordered_map<int,int> m;
vector<int> w,v;
int n,e,f;
int minvalue(int weight, int j)
{

	//cout<<weight<<" hello "<<j<<endl;
	if(j>=n&&weight>0)return 1000000000;
	//if(j>=n&&weight<0)return 1000000000;
	if(weight==0)return 0;
	if(m.find(j*100000+weight)!=m.end())return m[j*100000+weight];
	if(weight-w[j]>=0)
	{
		int ans1,ans2;
		ans1=minvalue(weight,j+1);
		ans2=minvalue(weight-w[j],j)+v[j];
		if(ans2<=ans1){m[j*100000+weight]=ans2;return ans2;}
		else {m[j*100000+weight]=ans1;return ans1;}
	}
	else
	{
		int ans1= minvalue(weight,j+1);
		m[j*100000+weight]=ans1;
		return ans1;
	}

}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{

		

		cin>>e>>f>>n;
		
		w.resize(n);v.resize(n);
		for(int j=0;j<n;j++)cin>>v[j]>>w[j];
		m.clear();
		long long int ans=minvalue(f-e,0);
		if(ans>=1000000000)cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<endl;
	}
}