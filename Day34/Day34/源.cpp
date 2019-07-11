//// write your code here cpp
//#include<string>
//#include<vector>
//#include<iostream>
//using namespace std;
//void Solutoion(vector<string> v)
//{
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		if (v[i].find(',') != string::npos || v[i].find(' ') != string::npos)
//		{
//			cout << "\"" << v[i] << "\"";
//		}
//		else
//			cout << v[i];
//		if (i != v.size() - 1)
//			cout << ", ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int n;
//	while (cin>>n)
//	{
//		cin.get();
//		vector<string> v;
//		string name;
//		while (getline(cin, name))
//		{
//			v.push_back(name);
//			--n;
//			if (n == 0)
//				break;
//		}
//		Solutoion(v);
//	}
//	return 0;
//}

// write your code here cpp

#include<iostream>
using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		if (n < 2)
			cout << 1 << endl;
		else
		{
			int sum = 0;
			int fib1 = 1;
			int fib2 = 1;
			for (int i = 1; i < n; ++i)
			{
				sum = fib1 + fib2;
				fib1 = fib2;
				fib2 = sum;
			}
			cout << sum << endl;
		}
	}
	return 0;
}
