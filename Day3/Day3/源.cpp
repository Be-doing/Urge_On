#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Day3
{
//读入一个字符串str，输出字符串str中的连续最长的数字串
//abcd12345ed125ss123456789
//123456789
	bool SolutionOne()
	{
		string srcStr;
		string desStr;
		string curStr;
		cin >> srcStr;
		size_t size = srcStr.size();
		if (size > 254)
		{
			return false;
		}
		for (int i = 0; i < size; ++i)
		{
			while (srcStr[i] >= '0' && srcStr[i] <= '9')
			{
				curStr += srcStr[i];
				++i;
			}
			size_t desSize = desStr.size();
			size_t curSize = curStr.size();
			if (desSize < curSize)
			{
				desStr = curStr;
			}
			curStr.clear();
		}
		cout << desStr;
		return true;
	}
	//输入n个整数，输出出现次数大于等于数组长度一半的数。
	//3 9 3 2 5 6 7 3 2 3 3 3
	//3
	void SolutionTwo()
	{
		vector<int> arr;
		int num;
		while (cin >> num)
		{
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		int mid = (arr.size() / 2) - 1;
		cout << arr[mid];
	}
};


