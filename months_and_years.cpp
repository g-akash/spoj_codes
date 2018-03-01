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

vi vec;
vi days1(12),days2(12);

void make_months()
{
	foi(12)days1[i]=30;
	days1[0]=days1[2]=days1[4]=days1[6]=days1[7]=days1[9]=days1[11]=31;
	days1[1]=28;
	days2 = days1;
	days2[1] = 29;
}

int num(int x)
{
	int ans = 0;
	foi(vec.size())
	{
		if(vec[i]==x)
			ans+=1;
	}
	return ans;
}

bool possible(int st)
{
	for(int i=0;i<vec.size();i++)
	{
		if(days1[st]==vec[i]||days2[st]==vec[i]){st = (st+1)%12; continue;}
		else return false;
	}
	return true;
}



int main()
{
	make_months();
	int n;
	cin>>n;
	vec.resize(n);
	foi(n)
	{
		cin>>vec[i];
	}
	bool ans = false;
	foi(12)
	{
		if(possible(i)&&num(29)<2)
		{
			ans = true;
			break;
		}
	}
	if(ans)
	{
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}



}