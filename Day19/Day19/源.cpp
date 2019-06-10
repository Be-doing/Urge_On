//abcdefghijklmnop
//abcsafjklmnopqrstuvw
#include<iostream>
#include<string>
using namespace std;

void Solution(string& str1, string& str2)
{
	string minstr;
	string maxstr;
	if (str1.size() > str2.size())
	{
		minstr = str2;
		maxstr = str1;
	}
	else
	{
		minstr = str1;
		maxstr = str2;
	}
	string res;
	for (int i = 0; i < minstr.size(); ++i)
	{
		for (int j = minstr.size(); j >= 0; --j)
		{
			string tmp = minstr.substr(i, j);
			if (maxstr.find(tmp) != string::npos)
			{
				if (tmp.size() > res.size())
				{
					res = tmp;
				}
			}
		}
	}
	cout << res << endl;
}
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		Solution(str1, str2);
	}
	return 0;
}
//#include<iostream>
//#include<vector>
//using namespace std;
//
//void Solution(vector<int>& v)
//{
//	size_t size = v.size();
//	for (size_t i = 0; i < size; ++i)
//	{
//		int n = v[i];
//		if (n < 3)
//		{
//			cout << 0 << endl;
//		}
//		else
//		{
//			int chu = n / 3;
//			int yu = n % 3;
//			int tmp = chu + yu;
//			int count = chu;
//			while (tmp > 2)
//			{
//				chu = tmp / 3;
//				yu = tmp % 3;
//				tmp = chu + yu;
//				count += chu;
//			}
//			if (tmp == 2)
//			{
//				count += 1;
//			}
//			cout << count << endl;	
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	int data;
//	vector<int> v;
//	while (1)
//	{
//		cin >> data;
//		if (data == 0)
//		{
//			break;
//		}
//		v.push_back(data);
//	}
//	Solution(v);
//	system("pause");
//	return 0;
//}
//
//
////int fun(int n)
////{
////	if (n < 2)
////		return 0;
////	if (n == 2)
////		return 1;
////	return (n / 3) + fun((n / 3) + (n % 3));
////}