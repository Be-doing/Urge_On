//请编写一个函数，将两个数字相加。不得使用 + 或其他算数运算符。
//
//给定两个int A和B。请返回A＋B的值
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		int sum = 0;
		int carry = 0;
		while (B)
		{
			sum = A ^ B;//异或相当与相加
			carry = (A&B) << 1;//与相当于进位，因为只有1&1 == 1
			B = carry;
			A = sum;
		}
		return sum;
	}
};

#include<iostream>
using namespace std;
//请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
//沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

#include<iostream>
using namespace std;
int PathNum(int n, int m)
{
    if(n > 1 && m > 1)
        return PathNum(n - 1, m) + PathNum(n, m -1);
    else if(n == 1 || m == 1)
        return m + n;
    else
        return 0;
}
int main()
{
    int m, n;
    while(cin >> n >> m)
    cout << PathNum(n, m) << endl;
    return 0;
}
