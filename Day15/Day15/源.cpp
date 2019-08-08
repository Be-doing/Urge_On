
#include<iostream>
using namespace std;
static int findNumverOf1(int num)
{
	int count = 0;
	int i = 0;
	while (i < 32)
	{
		int b = ((num >> i) & 1);
		if (b == 1)
		{
			++count;
		}
		++i;
	}
	cout << count;
	return 0;
}

int main()
{
	int num;
	cin >> num;
	findNumverOf1(num);
	system("pause");
	return 0;
}

