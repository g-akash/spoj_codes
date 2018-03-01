#include <iostream>
#include <string>
#include <math.h>
#include <vector>



using namespace std;


#define PI 3.14159265358


class complex
{
	public:
	double r,i;
	private:
	
	complex(double x, double y)
	{
		r=x;
		i=y;
	}
	
	public:
	
	complex()
	{
		r=0.0;
		i=0.0;
	}
	complex static frompolar(double mag, double angle)
	{
		complex res;
		res.r = mag*cos(angle);
		res.i = mag*sin(angle);
		return res;
	}
	
	complex static fromrealimag(double re, double imag)
	{
		complex res;
		res.r=re;
		res.i=imag;
		return res;
	}
	
	double magnitude()
	{
		return sqrt(r*r+i*i);
	}
	
	complex operator *(complex q)
	{
			complex res;
			res.r = r*q.r-i*q.i;
			res.i = i*q.r+r*q.i;
			return res;
	}
	
	complex operator +(complex q)
	{
		complex res;
		res.r = r+q.r;
		res.i = i+q.i;
		return res;
	}
	
	complex operator -(complex q)
	{
		complex res;
		res.r = r-q.r;
		res.i = i-q.i;
		return res;
	}
	
	void conj()
	{
		i = i*-1.0;
	}
};


double mul = 1.0;

vector<complex> fft(vector<complex> vec, complex c)
{
	int len = vec.size();
	if(len<=1)return vec;
	vector<complex> even,odd;
	for(int i=0;i<len;i++)
	{
		if(i%2==0)even.push_back(vec[i]);
		else odd.push_back(vec[i]);
	}
	complex mult = c*c;
	even = fft(even,mult);
	odd = fft(odd,mult);
	//c.conj();
	for(int i=0;i<len/2;i++)
	{	
		complex x = complex::frompolar(1.0,(mul*2.0*PI*double(i))/(double(len)));
		x=x*odd[i];
		vec[i]=even[i]+x;
		vec[i+len/2]=even[i]-x;
	}
	return vec;
}




int main()
{
	
	complex c1 = complex::fromrealimag(1.0,2.0);
	complex c2 = complex::fromrealimag(2.0,3.0);
	//cout<<(c1-c2).r<<(c1-c2).i<<endl;
	vector<complex> vec(8);
	for(int i=0;i<4;i++)vec[i]=complex::fromrealimag(1.0,0.0);
	for(int i=4;i<7;i++)vec[i]=complex::fromrealimag(0.0,0.0);
	complex mult = complex::frompolar(1.0,(2.0*PI)/(8.0));
	vec = fft(vec,mult);
	mult.conj();
	mul=-1.0;
	vec = fft(vec,mult);
	for(int i=0;i<8;i++)
	{
		cout<<vec[i].r/8.0<<" "<<vec[i].i/8.0<<endl;
	}
}
