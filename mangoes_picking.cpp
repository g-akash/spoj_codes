#include <bits/stdc++.h>

using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		printf("Case %d:\n",i+1);
		vector<int> mang,maxi;
		mang.resize(100000);
		maxi.resize(100000);
		int n,pos=0,temp;
		scanf("%d",&n);
		mang[0]=0;
		maxi[0]=0;
		char s[256];
		for(int j=0;j<n;j++)
		{
			scanf(" %s", &s);
			if(s[0]=='A')
			{
				scanf("%d",&temp);
				pos+=1;
				mang[pos]=temp;
				maxi[pos]=max(temp,maxi[pos-1]);
			}
			else if(s[0]=='Q')
			{
				if(pos>0)printf("%d\n",maxi[pos]);//<<endl;
				else printf("Empty\n");//cout<<"Empty"<<endl;
			}
			else
			{
				if(pos>0)--pos;
			}
		}
	}
}