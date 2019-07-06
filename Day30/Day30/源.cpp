// write your code here cpp

//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string be;
//	string af;
//	while (getline(cin, be))
//	{
//		for (int i = 0; i < be.size(); ++i)
//		{
//			be[i] -= 5;
//			if (be[i] < 'A') be[i] += 26;
//		}
//		cout << be << endl;
//	}
//	system("pause");
//	return 0;
//}

// write your code here cpp
#include<cmath>
#include<iostream>
using namespace std;
bool isPrime(int n)
{
	for (int i = 2; i < sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int Count(int num)
{
	int count = 0;
	for (int i = 2; i < num; ++i)
	{
		if (num % i == 0)
		{
			if (isPrime(i)) ++count;
		}
	}
	return count;
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << Count(num) << endl;
	}
	return 0;
}