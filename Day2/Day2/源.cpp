#include<iostream>
#include<vector>
#include<string>
using namespace std;
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。
//牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道
//他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2
#define ARRMAX 100000
#define NUMMAX 1000000000
class Day2
{
public:
	bool SolutionOne()
	{
		int arrlen;
		int count = 0;
		vector<int> num;
		cin >> arrlen;
		if (arrlen < 1 || arrlen > ARRMAX)
		{
			return false;
		}
		int numIn;
		for (int i = 0; i < arrlen; ++i)
		{
			cin >> numIn;
			if (numIn < 1 || numIn > NUMMAX)
			{
				return false;
			}
			num.push_back(numIn);
		}
		num.push_back(0);
		int i = 0;
		while (i < arrlen)
		{
			if (num[i] < num[i + 1])
			{
				while (i < arrlen && num[i] <= num[i + 1])
				{
					++i;
				}
				++i;//1 2 1 2 1 2 1 0
				++count;
			}
			else if (num[i] == num[i + 1])
			{
				++i;
			}
			else
			{
				while (i < arrlen && num[i] >= num[i + 1])
				{
					++i;
				}
				++i;
				++count;
			}
		}
		cout << count;
		return true;
	}

	//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
	//每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
	//依次输出倒置之后的字符串, 以空格分割
	void SolutionTwo()
	{
		string oldStr;
		string newStr;
		cin >> oldStr;
		while (cin >> newStr)
		{
			newStr = newStr + " " + oldStr;
			oldStr = newStr;
		}
		cout << newStr;
	}
};
