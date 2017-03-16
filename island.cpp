#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
multiset<int> ms;
vector<int> vec,gsize;

int find_root(int a)
{
	if(vec[a]==-1)return a;
	int parent = find_root(vec[a]);
	vec[a]=parent;
	return parent;
}

void merge(int a, int b)
{
	
	int p1,p2;
	p1=find_root(a);
	p2=find_root(b);
	if(p1!=p2){
	int s1=gsize[p1],s2=gsize[p2];
	if(s1>=s2)
	{
		vec[p2]=p1;
		gsize[p1]+=s2;
	}
	else
	{
		vec[p1]=p2;
		gsize[p2]+=s1;
	}
	ms.erase(ms.find(s1));
	ms.erase(ms.find(s2));
	ms.insert(s1+s2);}
	multiset<int>::iterator it1,it2;
	it1=ms.begin();
	it2=ms.end();
	it2--;
	if(it2==it1)cout<<0<<endl;
	else cout<<*it2-*it1<<endl;
}

int main()
{
	int n,q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++)ms.insert(1);
	vec.resize(n+1);
	gsize.resize(n+1);
	for(int i=0;i<=n;i++){vec[i]=-1;gsize[i]=1;}
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}
}