#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Solution(int num)
{
	vector<int> vYue;
	int num_ = sqrt(num);
	for (int i = 1; i <= num_ ; ++i)
	{
		if (num % i == 0)
		{
			vYue.push_back(i);
			if (num / i != num)
			{
				vYue.push_back(num / i);
			}
		}
	}
	int sum = 0;
	for (size_t i = 0; i < vYue.size(); ++i)
	{
		sum += vYue[i];
	}
	if (sum == num)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int count(int num)
{
	int count = 0;
	for (int i = 2; i < num; ++i)
	{
		if (Solution(i))
		{
			++count;
		}
	}
	return count;
}

int main()
{
	int num;
	while (cin >> num)
	{
		cout << count(num) << endl;
	}
	system("pause");
	return 0;
}
