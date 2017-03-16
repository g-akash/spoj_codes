#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

#define ci 2.09
#define cw 4.19
#define em 335.0

int main()
{
	float mw,mi,tw,ti;
	cin>>mw>>mi>>tw>>ti;
	while(!(mw==0.0&&mi==0.0&&tw==0.0&&ti==0.0))
	{
		float h = ci*(ti+30.0)*mi+mw*cw*tw+em*mw+mw*ci*30.0;
		float mas=mi+mw;
		//cout<<mas<<endl;
		float answ,ansi,anst;
		if(mas*30.0*ci>=h)
		{
			answ=0.0;
			ansi=mas;
			anst=h/(mas*ci)-30.0;
		}
		else if(mas*30.0*ci+mas*em>=h)
		{
			h-=mas*30.0*ci;
			answ=h/em;
			ansi=mas-answ;
			anst=0.0;
		}
		else
		{
			//cout<<mas*30.0*ci<<" "<<em*mas<<endl;

			h-=mas*30.0*ci;
			h-=em*mas;
			//cout<<h<<endl;
			ansi=0;
			answ=mas;
			anst=h/(mas*cw);
		}
		cout<<fixed<<setprecision(1)<<ansi<<" g of ice and "<<answ<<" g of water at "<<anst<<" C"<<endl;
		cin>>mw>>mi>>tw>>ti;
	}
}