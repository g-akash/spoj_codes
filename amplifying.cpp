#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int a, int b)
{

	if(a>b)return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<int> vec;
		int var,c1=0;
		for(int j=0;j<n;j++)
		{
			cin>>var;
			if(var==1)c1++;
			else vec.push_back(var);
		}
		sort(vec.begin(),vec.end(),comp);
		if(vec.size()==2&&vec[0]==3&&vec[1]==2){vec[0]=2;vec[1]=3;}
		for(int j=0;j<c1;j++)cout<<1<<" ";
		for(int j=0;j<vec.size();j++)cout<<vec[j]<<" ";cout<<endl;
	}
}