#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

#define ll long long 

int main()
{
	vector<ll int> v,w;
	v.resize(100001);
	w.resize(100001);
	for(ll int i=2;i<100001;i++)
	{
		for(ll int j=2*i;j<100001;j+=i)
			v[j]=1;
	}
	unordered_map<ll int, ll int> m;
	for(ll int i=0;i<100001;i++)
	{
		if(v[i]==0)
			{
				m[i*i+1]=1;
				m[i*i+2]=1;
			}

	}
//cout<<"oay"<<endl;
	unordered_map<ll int, ll int>::iterator it;
	w=v;
	for(ll int i=2;i<100001;i++)
	{
		if(v[i]==0)
		{
				it=m.begin();
				while(it!=m.end())
				{
					if(it->first%i==0&&it->first!=i){it->second=2;}
					it++;

				}
		}
	}
	//cout<<"ohyes"<<endl;
	ll int ans=0;
	for(ll int i=0;i<100001;i++)
	{

		
		if(w[i]==0)
			{
				//cout<<i<<endl;

				if(m[i*i+1]==1||m[i*i+2]==1){ans+=1;}
			}
		w[i]=ans;
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll int a,b;
		cin>>a>>b;
		if(a==0)cout<<w[b]<<endl;
		else cout<<w[b]-w[a-1]<<endl;
	}
}