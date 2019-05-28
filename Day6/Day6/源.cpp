class Solution
{
public:
	//考虑溢出
	//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
	//但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
	//数值为0或者字符串不是一个合法的数值则返回0。
	int StrToInt(string str)
	{
		size_t size = str.size();
		if (size > 11)
		{
			return 0;//int最大是11位，包括符号
		}
		size_t i = 0;
		char flag = str[0];
		if (flag == '+' || flag == '-')//第一为应该是+或-
		{
			i = 1;
		}
		long res = 0;
		for (i; i < size; ++i)
		{
			res *= 10;
			if (str[i] < '0' || str[i] > '9')
			{
				return 0;
			}
			res = res + (str[i] - '0');
		}
		if (flag == '-')
		{
			res = 0 - res;
		}
		if (res < INT_MIN || res > INT_MAX)
		{
			return 0;
		}
		return (int)res;
	}
};


#include<iostream>
using namespace std;
//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。
//每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。
bool Solution()
{
	int W;
	int H;
	double R = 2;
	int count = 0;
	int cflag = 0;
	int rflag = 0;
	cin >> W >> H;
	if ((W < 1 || W > 1000) && (H < 1 || H > 1000))
	{
		return false;
	}
	if (W == 1 && H == 1)
	{
		cout << 1;
		return true;
	}
	for (int w = 0; w < W; ++w)
	{
		int h = 0;
		++rflag;
		if (rflag == 3 || rflag == 4)
		{
			h += 2;
			if (rflag == 4)
			{
				rflag = 0;
			}

		}
		for (h; h < H; ++h)
		{
			++cflag;
			++count;
			if (cflag == 2)
			{
				h += 2;
				cflag = 0;
			}
		}
	}
	cout << count;
	return true;
}
int main()
{
	Solution();
	system("pause");
	return 0;
}