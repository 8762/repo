#include <iostream>
using namespace std;
struct  Term
{

	Term* top;
	float exp;
	int coef;
};
class Polynomial
{
public:
	Polynomial() : top1(nullptr), top2(nullptr), top3(nullptr) {}
	~Polynomial() {
	}
	void Add() {
		int coef = 0;
		float exp = 0;
		Term* tem2 = top2;
		Term* tem1 = top1;
		for (int i = 0; tem1 and tem2; i++)
		{

			if (tem1->coef == tem2->coef)
			{


				coef = tem2->coef;
				exp = tem1->exp + tem2->exp;
				tem2 = tem2->top;
				tem1 = tem1->top;
				
				in(exp, coef, 2);
			}//3x^2+2x^1-5x^0
			else if (tem1->coef > tem2->coef)
			{

				coef = tem1->coef;
				exp = tem1->exp;
				tem1 = tem1->top;
				in(exp, coef, 2);
			}
			else
			{

				coef = tem2->coef;
				exp = tem2->exp;
				tem2 = tem2->top;
				in(exp, coef, 2);
			}
		}
			while (tem1) {

				coef = tem1->coef;
				exp = tem1->coef;
				tem1 = tem1->top;
				in(exp, coef, 2);
			}
			while (tem2) {

				coef = tem2->coef;
				exp = tem2->coef;
				tem2 = tem2->top;
				in(exp, coef, 2);
			}


		
	}
	void Mult() {
		const int all = con1 * con2;
		int conb=0,cons=0,f=0,f2=0,con3=0;
		int* coef = new int[all], coeft=0;
		float* exp = new float[all], expt=0;
		Term* tem2;
		Term* tem1;
		if (con1 > con2)
		{
			conb = con1;
			cons = con2;
			 tem2 = top2;
			 tem1 = top1;
		}
		else
		{
			conb = con2;
			cons = con1;
			tem1 = top2;
			tem2 = top1;
		}
		for (int i = 0;conb>i; i++)
		{
			for (int i1 = 0; cons>i1; i1++)
			{
				coeft=tem2->coef + tem1->coef;
				expt= tem2->exp * tem1->exp;
				for (int i3 = 0; i3<con3; i3++)
				{
					if (coef[i3] == coeft) {
						exp[i3] = exp[i3] + expt;
						f = 1;
					}
				}
				if (f == 0)
				{
					coef[con3] = coeft;
					exp[con3] = expt;
					con3++;
				}
				tem2= tem2->top;
				f = 0; 
			}
			
			
			if (con1 > con2)
				tem2 = top2;
			else
				tem2 = top1;
			tem1= tem1->top;
		}
		for (int i = 0; i < con3; i++)
		{
			in(exp[i], coef[i], 2);
		}
	}
	void in(float exp, int coef, int f) {
		Term* newNode = new Term();
		newNode->exp = exp;
		newNode->coef = coef;
		if (f == 0) {
			if (top1 == nullptr) {
				top1 = newNode;
			}
			else {
				Term* temp = top1;
				while (temp->top != nullptr) {
					temp = temp->top;
				}
				temp->top = newNode;
			}
			con1++;
		}
		else if(f==1)
		{
			if (top2 == nullptr) {
				top2 = newNode;
			}
			else {
				Term* temp = top2;
				while (temp->top != nullptr) {
					temp = temp->top;
				}
				temp->top = newNode;
			}
			con2++;
		}
		else
		{
			if (top3 == nullptr) {
				top3 = newNode;
			}
			else {
				Term* temp = top3;
				while (temp->top != nullptr) {
					temp = temp->top;
				}
				temp->top = newNode;
			}
		}
	}
	void print()  {
		Term* head = top3;
		int i = 0;
		while (head) {
			if ( head != nullptr and head != top3) {
				cout << "+";
			}
			cout << head->exp << "x^" << head->coef << " ";
			head = head->top;
		}
		std::cout << std::endl;
		
	}
private:
	Term* top1;
	Term* top2;
	Term* top3;
	int con1=0, con2=0;
};
int main()
{
	Polynomial p;
	string in;
	char a;
	int f2 = 0;
	cin >> in;
	float coefficient = 0; // 暫存係數
	int exponent = 0;    // 暫存指數
	int sign = 1;        // 當前符號（+1 或 -1）
	bool hasCoefficient = false; // 是否已讀取係數
	for (int i = 0; in[i] != '\0'; i++)
	{
		if (in[i] == '-' || in[i] == '+') {
			// 碰到符號時，如果有暫存的項，將其存入鏈結串列
			if (hasCoefficient) {
				p.in(coefficient * sign, exponent, f2);
				hasCoefficient = false;
			}
			// 更新符號
			sign = (in[i] == '-') ? -1 : 1;
		}
		else if (in[i] - '0' >= 0 && in[i] - '0' <= 9) {
			// 讀取數字，可能是係數或指數
			int num = 0;
			while (in[i] - '0' >= 0 && in[i] - '0' <= 9) {
				num = num * 10 + (in[i] - '0');
				i++;
			}
			i--; // 回退 1 位，因為 `for` 迴圈也會進行遞增
			if (!hasCoefficient) {
				coefficient = num;
				hasCoefficient = true;
			}
			else {
				exponent = num;
			}
		}
		else if (in[i] == 'x') {
			// 處理變數 x
			if (!hasCoefficient) {
				hasCoefficient = true;
			}
			if (in[i + 1] == '^') {
				// 如果後面是指數
				i += 2; // 跳過 '^'
				int num = 0;
				while (in[i] - '0' >= 0 && in[i] - '0' <= 9) {
					num = num * 10 + (in[i] - '0');
					i++;
				}
				i--; // 回退 1 位
				exponent = num;
			}
			else {
				// 沒有指數時，默認指數為 1
				exponent = 1;
			}
		}
	}
	if (hasCoefficient) {
		p.in(coefficient * sign, exponent, f2);
	}
	sign = 1;        
	hasCoefficient = false;
	cin >> a;
	cin >> in;
	f2 = 1;
	for (int i = 0; in[i] != '\0'; i++)
	{
		if (in[i] == '-' || in[i] == '+') {
			// 碰到符號時，如果有暫存的項，將其存入鏈結串列
			if (hasCoefficient) {
				p.in(coefficient * sign, exponent, f2);
				hasCoefficient = false;
			}
			// 更新符號
			sign = (in[i] == '-') ? -1 : 1;
		}
		else if (in[i] - '0' >= 0 && in[i] - '0' <= 9) {
			// 讀取數字，可能是係數或指數
			int num = 0;
			while (in[i] - '0' >= 0 && in[i] - '0' <= 9) {
				num = num * 10 + (in[i] - '0');
				i++;
			}
			i--; // 回退 1 位，因為 `for` 迴圈也會進行遞增
			if (!hasCoefficient) {
				coefficient = num;
				hasCoefficient = true;
			}
			else {
				exponent = num;
			}
		}
		else if (in[i] == 'x') {
			// 處理變數 x
			if (!hasCoefficient) {
				hasCoefficient = true;
			}
			if (in[i + 1] == '^') {
				// 如果後面是指數
				i += 2; // 跳過 '^'
				int num = 0;
				while (in[i] - '0' >= 0 && in[i] - '0' <= 9) {
					num = num * 10 + (in[i] - '0');
					i++;
				}
				i--; // 回退 1 位
				exponent = num;
			}
			else {
				// 沒有指數時，默認指數為 1
				exponent = 1;
			}
		}
	}
	if (hasCoefficient) {
		p.in(coefficient * sign, exponent, f2);
	}
	if (a == '+')
		p.Add();
	else if(a == '*')
		p.Mult();
	p.print();
}

