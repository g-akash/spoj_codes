#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class topic
{
public:
	unsigned long long int id;
	long long int z;
	unsigned long long int ze;
};

bool comp(topic p, topic q)
{
	if(p.z>q.z)return true;
	if(p.z==q.z&&p.id>q.id)return true;
	return false;
}

int main()
{
	int n;
	vector<topic> v;
	cin>>n;
	v.resize(n);
	long long int v1,v2,v3,v4,v5;
	for(int i=0;i<n;i++)
	{
		cin>>v[i].id;
		cin>>v1>>v2>>v3>>v4>>v5;
		v[i].z=(v2*50+v3*5+v4*10+v5*20)-v1;
		v[i].ze=(v2*50+v3*5+v4*10+v5*20);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<5;i++)cout<<v[i].id<<" "<<v[i].ze<<endl;

}