//// write your code here cpp
//#include<iostream>
//#include<iomanip>
//using namespace std;
//double cuopai(long n)
//{
//	if (n == 2)
//		return 1;
//	long c1 = 0;
//	long c2 = 1;
//	long x = n;
//	for (long i = 3; i <= x; ++i)
//	{
//		n = (i - 1) * (c1 + c2);
//		c1 = c2;
//		c2 = n;
//	}
//	return n;
//}
//double jie(long n)
//{
//	if (n == 1)
//		return 1;
//	return jie(n - 1)*n;
//}
//
//int main()
//{
//	long n;
//	while (cin >> n)
//	{
//		if (n == 0)
//			cout << "0.00%" << endl;
//		else if (n == 1)
//			cout << "100.00%" << endl;
//		else
//		{
//			double res = cuopai(n) / jie(n) * 100;
//			printf("%.2lf%%\n", res);
//			//cout << setprecision(4) << res << "%" << endl;
//		}
//	}
//	return 0;
//}

// write your code here cpp
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
void Solution(string& namev, string& name)
{
	unordered_set<string> v;
	for (size_t i = 0; i < namev.size(); ++i)
	{
		if (namev[i] == '\"')
		{
			++i;
			size_t pos = namev.find('\"', i);
			v.insert(namev.substr(i, pos - i));
			i = pos + 1;
		}
		else
		{
			size_t pos = namev.find(',', i);
			if (pos == string::npos)
				pos = namev.size();
			v.insert(namev.substr(i, pos - i));
			i = pos;
		}
	}
	if (v.find(name) != v.end())
		cout << "ignore" << endl;
	else
		cout << "important" << endl;
}
int main()
{
	string name;
	string namev;
	while (getline(cin, namev))
	{
		getline(cin, name);
		Solution(namev, name);
	}
	return 0;
}