#include <iostream>
using namespace std;
void p(char *a)
{
	int c[] = { 0,0,0 };//紀錄2進制
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
		//用2進制判斷要輸出甚麼
		for (int q = 0; q < 3; q++)
		{
			if (c[q]==1)
				cout << a[q];//輸出
		}
		cout << endl;
		for (int q = 0; q < 3; q++)
		{
			c[q] = 0;//歸0
		}
	}//0(n)=n+n+n
}
int main()
{
	char a[] = { 'a','b','c' };
	p(a);//因為輸出呈現2進制的排列方式故使用
}
