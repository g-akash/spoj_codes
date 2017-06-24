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
#include <stdio.h>
#include <set>

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




int main()
{
	int n,m,tmp,num;
	ll var;
	scanf("%d %d",&n,&m);
	vll vec(n);
	queue<ll> q1,q2;
	int ct1=n,ct2=0;
	foi(n)
	{
		scanf("%lld",&vec[i]);
		
	}
	sort(vec.begin(),vec.end());
	foi(n)
	{
		q1.push(vec[n-1-i]);
	}

	//vector<quer> vec(n);
	int que;
	int curr=0;
	foi(m)
	{
		scanf("%d",&que);
		while(curr<que-1)
		{
			ll val1 =-1, val2 =-1;
			if(ct1>0)val1=q1.front();
			if(ct2>0)val2=q2.front();

			if(val1>=val2)
			{
				q1.pop();
				ct1--;
				val1/=2;
				if(val1!=0){q2.push(val1);ct2++;}
			}	
			else
			{
				q2.pop();
				ct2--;
				val2/=2;
				if(val2!=0){q2.push(val2);ct2++;}
			}
			curr++;
			
		}
		ll val1 =-1, val2 =-1;
		if(ct1>0)val1=q1.front();
		if(ct2>0)val2=q2.front();

		if(val1>=val2)
		{
			q1.pop();
			ct1--;
			printf("%lld\n",val1);
			val1/=2;
			if(val1!=0){q2.push(val1);ct2++;}
		}	
		else
		{
			q2.pop();
			ct2--;
			printf("%lld\n",val2);
			val2/=2;
			if(val2!=0){q2.push(val2);ct2++;}
		}
		curr++;
		
		
	}
	

}