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

char n1[100005], n2[100005];


int main()
{
	while(true)
	{
		scanf("%s",n1);
		scanf("%s",n2);
		if(n1[0]=='*')break;
		int x1,x2;
		foi(100005)if(n1[i]=='\0'){x1=i-1;break;}
		foi(100005)if(n2[i]=='\0'){x2=i-1;break;}
		char ans = '=';
		//cout<<x1<<" "<<x2<<endl;
		while(x1>=0&&x2>=0)
		{
			//cout<<ans<<endl;
			if(n1[x1]>n2[x2])ans='>';
			else if(n1[x1]<n2[x2])ans='<';
			x1--;
			x2--;
		}
		while(x1>=0)
		{
			if(n1[x1]!='0')ans='>';
			x1--;
		}
		while(x2>=0)
		{
			if(n2[x2]!='0')ans='<';
			x2--;
		}
		printf("%c\n",ans);
	}
}