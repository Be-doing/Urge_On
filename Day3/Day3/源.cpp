#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Day3
{
//����һ���ַ���str������ַ���str�е�����������ִ�
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
	//����n��������������ִ������ڵ������鳤��һ�������
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


