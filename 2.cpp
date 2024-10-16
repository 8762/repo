#include <iostream>
using namespace std;
void p(char *a)
{
	int c[] = { 0,0,0 };
	int b = 0;
	for (int i = 0; i < 8; i++)
	{
		b = i;
		if (b % 2 == 1)
			c[0] = 1;
		b = b / 2;
		if (b % 2 == 1)
			c[1] = 1;
		b = b / 2;
		if (b % 2 == 1)
			c[2] = 1;
		for (int q = 0; q < 3; q++)
		{
			if (c[q]==1)
				cout << a[q];
		}
		cout << endl;
		for (int q = 0; q < 3; q++)
		{
			c[q] = 0;
		}
	}
}
int main()
{
	char a[] = { 'a','b','c' };
	p(a);
}
