// write your code here cpp
#include<vector>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
	vector<int> prime;
	for (int i = 2; i < 1000; ++i)
	{
		int j = 2;
		for (j; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
				break;
		}
		if (j > sqrt(i))
			prime.push_back(i);

	}
	//int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	int num;
	size_t size = prime.size();
	while (cin >> num)
	{
		cout << num << " = ";

		for (size_t i = 0; i < size; ++i)
		{
			if (num <= prime[i])
			{
				cout << num << endl;
				break;
			}
			while (num % prime[i] == 0 && num > prime[i])
			{
				num /= prime[i];
				cout << prime[i] << " * ";
			}
		}
		if (num > 997)
			cout << num << endl;
	}
	return 0;
}