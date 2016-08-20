#include <bits/stdc++.h>

using namespace std;


int main()
{
	int var;
	while(cin>>var)
	{
		list<int> l;
		list<int>::iterator it,it1;
		it = l.begin();
		int s=0;
		while(var!=0)
		{
			if(var!=-1)
			{
				l.push_back(var);
				s++;
				if(s%2==1)it++;
				//cout<<*it<<endl;
			}
			else
			{
				if(s%2==0)
				{
					it1=it;
					it++;
					printf("%d\n",*it1);
					l.erase(it1);
					//it=it1;
				}
				else
				{
					it1=it;
					it--;
					//cout<<*it1<<endl;
					printf("%d\n",*it1);
					l.erase(it1);
					//it=it1;
				}
				s--;
			}
			//cout<<*it<<" hello"<<endl;
			scanf("%d",&var);
		}
		printf("\n");
		//cout<<endl;
	}
}