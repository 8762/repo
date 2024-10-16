#include <iostream>
using namespace std;
int a(int m,int n)
{
	if(m==0)
		return n+1;
	else if (n==0)
		return a( m-1, 1);
	else
		return a( m-1, a( m, n-1));
}
int main()
{
	int b,c,d;
	cin>>b>>c;
	d=a(b,c);
	cout<<d;
}
