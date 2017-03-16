#include<iostream>
#include<vector>
#include<algorithm>
//#include <stdio.h>      
//#include <stdlib.h>

using namespace std;

int main()
{
	vector<int> v;
	int var;
	for(int i=0;i<1000000;i++)
	{
		var = rand()%1000000000;
		v.push_back(var);
	}
	sort(v.begin(),v.end());
	int x=0,y=1000000-1;
	int ans; cin>>ans;
	while(y-x>1)
	{
		if(ans>=v[(x+y)/2])x=(x+y)/2;
		else if(ans<v[(x+y)/2])y=(x+y)/2;
	}
	if(ans==v[x])cout<<"Found x"<<v[x]<<" "<<v[y]<<endl;
	else if(ans==v[y])cout<<"Found y"<<v[x]<<" "<<v[y]<<endl;
	else cout<<"found between"<<v[x]<<" "<<v[y]<<endl;
}
