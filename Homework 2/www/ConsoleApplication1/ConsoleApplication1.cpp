#include <iostream>
using namespace std;
// 定義一個結構表示多項式的項
struct Term {
	Term* top;  // 指向下一個項的指標
	float exp;  // 指數
	int coef;   // 係數
};

// 定義多項式類別
class Polynomial
{
public:
	Polynomial() : top1(nullptr), top2(nullptr), top3(nullptr) {}// 定義多項式類別
	~Polynomial() {
	}
	friend ostream& operator<<(ostream& os, const Polynomial& p);
	friend istream& operator>>(istream& is, Polynomial& p);
	// 多項式加法
	void Add() {
		int coef = 0;      // 暫存當前的係數
		float exp = 0;     // 暫存當前的指數
		Term* tem2 = top2; // 指向第二個多項式的頭節點
		Term* tem1 = top1; // 指向第一個多項式的頭節點
		// 合併兩個多項式
		for (int i = 0; tem1 and tem2; i++)
		{

			if (tem1->coef == tem2->coef)
			{
				// 如果兩個項的指數相同，係數相加

				coef = tem2->coef;
				exp = tem1->exp + tem2->exp;
				tem2 = tem2->top;
				tem1 = tem1->top;

				in(exp, coef, 2);// 插入結果多項式
			}//3x^2+2x^1-5x^0
			else if (tem1->coef > tem2->coef)
			{
				// 第一個多項式的指數較大，加入結果
				coef = tem1->coef;
				exp = tem1->exp;
				tem1 = tem1->top;
				in(exp, coef, 2);
			}
			else
			{
				// 第二個多項式的指數較大，加入結果
				coef = tem2->coef;
				exp = tem2->exp;
				tem2 = tem2->top;
				in(exp, coef, 2);
			}
		}
		// 處理剩餘的多項式項
		while (tem1) {

			coef = tem1->coef;
			exp = tem1->exp;
			tem1 = tem1->top;
			in(exp, coef, 2);
		}
		while (tem2) {

			coef = tem2->coef;
			exp = tem2->exp;
			tem2 = tem2->top;
			in(exp, coef, 2);
		}



	}
	void Mult() {
		const int all = con1 * con2; // 最大可能的結果項數
		int conb = 0, cons = 0, f = 0, f2 = 0, con3 = 0;
		int* coef = new int[all], coeft = 0; // 最大可能的結果項數
		float* exp = new float[all], expt = 0; // 儲存指數
		Term* tem2;
		Term* tem1;
		// 確定兩個多項式中長度較長的作為基準
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
		// 逐項相乘
		for (int i = 0; conb > i; i++)
		{
			for (int i1 = 0; cons > i1; i1++)
			{
				coeft = tem2->coef + tem1->coef;// 新的係數
				expt = tem2->exp * tem1->exp; // 新的指數
				// 判斷是否有相同的指數項
				for (int i3 = 0; i3 < con3; i3++)
				{
					if (coef[i3] == coeft) {
						exp[i3] = exp[i3] + expt;
						f = 1;
					}
				}// 若無相同指數，新增一項
				if (f == 0)
				{
					coef[con3] = coeft;
					exp[con3] = expt;
					con3++;
				}
				tem2 = tem2->top;
				f = 0;
			}

			// 重置第二個多項式指標
			if (con1 > con2)
				tem2 = top2;
			else
				tem2 = top1;
			tem1 = tem1->top;
		}
		// 將結果插入結果多項式
		for (int i = 0; i < con3; i++)
		{
			in(exp[i], coef[i], 2);
		}
	}
	void in(float exp, int coef, int f) {
		// 根據標誌 f 插入到相應的多項式
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
		else if (f == 1)
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
	}    // 輸出結果多項式


private:
	Term* top1; // 第一個多項式
	Term* top2; // 第二個多項式
	Term* top3; // 結果多項式
	int con1 = 0, con2 = 0; // 第一個和第二個多項式的項數
};
int f2;
ostream& operator<<(ostream& os, const Polynomial& p)
{
	Term* head = p.top3;
	int i = 0;
	while (head) {
		if (head != nullptr and head != p.top3) {
			cout << "+";
		}
		cout << head->exp << "x^" << head->coef << " ";
		head = head->top;
	}
	std::cout << std::endl;
	return os;
}
istream& operator>>(istream& is, Polynomial& p) {
	// paste your input process here, and replace all "cin" with "is".
	// assign newterm(coef, exp) to "p".
	// for example
	string in;
	is >> in;
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
	f2 = 1;
	return is;
}
int main()
{
	Polynomial p;
	char a;
	cin >> p;
	cin >> a;
	cin >> p;

	if (a == '+')
		p.Add();
	else if (a == '*')
		p.Mult();
	cout << "p1"<<a<<"p2=";
	cout << p;
}

