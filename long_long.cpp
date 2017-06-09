#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

int slen;





bool istrue(int len,string s,vi vec)
{
	umm(int,vi) um;
	
	int curr=vec[len-1];
	vi tmp;
	//um.clear();
	um[curr]=tmp;
	um[curr].pb(len);
	int var;
	for(int i=len;i<slen;i++)
	{
		//if(i-len-1<0)var=vec[i-1];
		//else var=vec[i-1]-vec[i-len-1];
		//curr-=var;
		curr+=((int(s[i]))-int(s[i-len]));
		//if(um.find(curr)==um.end())um[curr]=tmp;
		um[curr].pb(i+1);
	}
	umm(int,vi)::iterator it=um.begin();
	
	while(it!=um.end())
	{
		if((it->second).size()>1)
		{
			//tmp = it->second;
			var = it->second.size();
			for(int i=var-1;i>=0;i--)
			{
				for(int j=var-1;j>i;j--)
				{
					//if(issame(it->second[i],it->second[j],len))return true;
					//if(s.substr(it->second[i],len)==s.substr(it->second[j],len))return true;
					 int p1=it->second[i]-len,p2=it->second[j]-len;
					 bool same=true;
					 for(int k=len-1;k>=0;k--)
					 {
					 	if(s[p1+k]!=s[p2+k]){same=false;break;}
					 }
					 if(same)return true;
				}
			}
		}

		++it;
	}
	return false;

}

int main()
{
	string s;
	cin>>s;
	
	
	slen = s.length();
	vi vec;
	vec.resize(s.length());
	vec[0]=int(s[0]);
	foi1(s.length()-1)
	{
		vec[i]=vec[i-1]+int(s[i]);
	}
	
	if(249998<=slen)
	{
		if(istrue(249998,s,vec))
		{
			printf("249998\n");
			return 0;
		}

	}

	int x=1,y=slen;
	while(y-x>1)
	{
		int mid = (x+y)/2;
		if(istrue(mid,s,vec))x=mid;
		else y=mid;
	}
	printf("%d\n",x);
	
	
	
}