//// write your code here cpp
//
//#include<string>
//#include<iostream>
//using namespace std;
//void Solution(string& s, string& t)
//{
//	int count = 0;
//	size_t flag = 0;
//	for (size_t pos = 0; pos < s.size(); ++pos)
//	{
//		flag = s.find(t, pos);
//		if (flag  == s.npos)
//		{
//			break;
//		}
//		else
//		{
//			++count;
//			flag += t.size() - 1;
//			pos = flag;
//		}
//	}
//	cout << count << endl;
//}
//int main()
//{
//	string s, t;
//	while (cin >> s >> t)
//	{
//		Solution(s, t);
//	}
//	return 0;
//}


// write your code here cpp

#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<int> breakfast(80, 1);
	int from, to;
	
	for (int i = 2; i < 80; ++i)
	{
		breakfast[i] = breakfast[i - 1] + breakfast[i - 2];
	}
	while (cin >> from >> to)
	{
		int sum = 0;
		for (int i = from - 1; i <= to - 1; ++i)
		{
			sum += breakfast[i];
		}
		cout << sum << endl;
	}
}