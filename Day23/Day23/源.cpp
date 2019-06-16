//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<algorithm>
//using namespace std;
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		// write code here
//		//找数组中出现了一半的数
//		//2    2    2    3    3
//		//1    1    2    2    2
//		unordered_map<int, int> m;
//		for (int i = 0; i < n; ++i)
//		{
//			++m[gifts[i]];
//		}
//		for (const auto&e : m)
//		{
//			if (e.second > (gifts.size() / 2))
//			{
//				return e.first;
//			}
//		}
//		return 0;
//	}
//};
//
//int main()
//{
//	Gift g;
//	vector<int> v = {1,1,2};
//	cout << g.getValue(v, v.size()) << endl;
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;
void Solution(const string& str1, const string& str2)
{
	int count = 0;
	count = str1.size() > str2.size() ? str1.size() - str2.size() : str2.size() - str1.size();
	for (int i = 0; i < str2.size(); ++i)
	{
		if (i == str1.size())
		{
			break;
		}
		if (str1[i] != str2[i])
		{
			++count;
		}
	}
	cout << count << endl;
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