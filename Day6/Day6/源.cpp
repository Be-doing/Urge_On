//class Solution
//{
//public:
//	//考虑溢出
//	//
//	int StrToInt(string str)
//	{
//		size_t size = str.size();
//		if (size > 11)
//		{
//			return 0;//int最大是11位，包括符号
//		}
//		size_t i = 0;
//		char flag = str[0];
//		if (flag == '+' || flag == '-')//第一为应该是+或-
//		{
//			i = 1;
//		}
//		long res = 0;
//		for (i; i < size; ++i)
//		{
//			res *= 10;
//			if (str[i] < '0' || str[i] > '9')
//			{
//				return 0;
//			}
//			res = res + (str[i] - '0');
//		}
//		if (flag == '-')
//		{
//			res = 0 - res;
//		}
//		if (res < INT_MIN || res > INT_MAX)
//		{
//			return 0;
//		}
//		return (int)res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	string str = "2147483647";
//	cout << s.StrToInt(str) << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>

using namespace std;

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