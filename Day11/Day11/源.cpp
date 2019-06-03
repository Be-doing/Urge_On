#include<iostream>
#include<vector>
using namespace std;

bool Solution()
{
	int num;
	vector<int> vBin;
	cin >> num;
	if (num > 127 || num < -128)
	{
		return false;
	}
	for (int i = 0; i < 8; ++i)
	{
		int b = ((num >> i) & 1);
		vBin.push_back(b);
	}

	int count = 0;
	int newcount = 0;
	for (int i = 0; i < 8; ++i)
	{
		while (i < 8 && vBin[i] == 1)
		{
			++i;
			++newcount;
		}
		if (newcount > count)
		{
			count = newcount;
		}
		newcount = 0;
	}
	if (num < 0)
	{
		cout << count + 1;
		return true;
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