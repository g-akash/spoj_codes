#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define ull long long


class dat
{
public:
	 long long int h,ind;
};

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		stack<dat> s;
		dat d,p,nx;
		ull int lf,ht,rt;
		 long long int ans=0;
		for(ull int i=0;i<n;i++)
		{
			cin>>d.h;
			d.ind=i;
			if(s.empty())
			{
				s.push(d);
				continue;
			}
			p=s.top();
			if(p.h<=d.h)
			{
				s.push(d);
				continue;
			}
			while(!s.empty()&&p.h>d.h)
			{
				s.pop();
				if(s.empty())lf=0;
				else lf=s.top().ind+1;
				rt=d.ind;
				ht=p.h;
				if(ht*(rt-lf)>ans)ans=ht*(rt-lf);
				if(!s.empty())p=s.top();


			}
			s.push(d);

		}

		if(!s.empty())
		{
			rt=n;
			p=s.top();
			s.pop();
			while(!s.empty())
			{
				lf=s.top().ind+1;
				if((rt-lf)*p.h>ans)ans=(rt-lf)*p.h;
				p=s.top();
				s.pop();
			}
			if((n)*p.h>ans)ans=(n)*p.h;

		}




		cout<<ans<<endl;
		cin>>n;
	}
}