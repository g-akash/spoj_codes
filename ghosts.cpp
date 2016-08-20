#include<bits/stdc++.h>
#include<set>
#include<unordered_map>

using namespace std;

class ghost
{
public:
	int age,trophy;

	inline bool operator<(const ghost &g)const 
	{
		return trophy<g.trophy||(trophy==g.trophy&&age<g.age);
		//return q.trophy==g.trophy&&q.age<g.age;
	}
};


int main()
{
	int n,m,var,trop;
	cin>>n>>m;
	unordered_map<int,int> vec;
	set<ghost> ms;
	ghost gs;
	set<ghost>::iterator it;
	for(int i=0;i<n;i++)
	{
		//cout<<i<<endl;
		scanf("%d",&var);
		if(vec.find(var)==vec.end())trop=0;
		else trop=vec[var];
		gs.age=var;
		gs.trophy=trop;

		if(ms.find(gs)!=ms.end())ms.erase(ms.find(gs));
		gs.trophy++;
		ms.insert(gs);
		it = ms.end();
		if(vec.find(var)==vec.end())vec[var]=1;
		else vec[var]++;
		it--;
		printf("%d %d\n",it->age,it->trophy);//cout<<it->age<<" "<<it->trophy<<endl;
	}
	
}