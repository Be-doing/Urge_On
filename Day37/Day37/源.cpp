//#include<iostream>
//#include<string>
//#include<map>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//void Solution(vector<string>& v)
//{
//	map<char, char> m;
//	int flag = 0;
//	char s = '2';
//	for (char c = 'A'; c < 'P'; ++c)
//	{
//		m[c] = s;
//		++flag;
//		if (flag == 3)
//		{
//			++s;
//			flag = 0;
//		}
//	}
//	for (char c = 'P'; c < 'T'; ++c)
//		m[c] = '7';
//	for (char c = 'T'; c < 'W'; ++c)
//		m[c] = '8';
//	for (char c = 'W'; c <= 'Z'; ++c)
//		m[c] = '9';
//	vector<string> r;
//	string str;
//	for (auto& e : v)
//	{
//		flag = 0;
//		for (size_t i = 0; i < e.size(); ++i)
//		{
//			if (m[e[i]])
//				str += m[e[i]];
//			else
//				if(e[i] >= '0' && e[i] <= '9')
//				str += e[i];
//			++flag;
//			if (flag == 3)
//				str += '-';
//		}
//		r.push_back(str);
//		str.clear();
//	}
//	sort(r.begin(), r.end());
//	set<string> res;
//	for (const auto e : r)
//		res.insert(e);
//	for (const auto e : res)
//		cout << e << endl;
//}
//int main()
//{
//	int n;
//	//vector<string> v;
//	//string test("ABCD123");
//	//v.push_back(test);
//	//Solution(v);
//	while (cin >> n)
//	{
//		vector<string> v;
//		string str;
//		while (cin >> str)
//		{
//			v.push_back(str);
//			if (--n < 0)
//				break;
//		}
//		Solution(v);
//	}
//}
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void Solution(vector<string>& v)
{
	if (v.empty())
	{
		cout << "000-0000" << endl;
		return;
	}
	map<char, char> m;
	int flag = 0;
	char s = '2';
	for (char c = 'A'; c < 'P'; ++c)
	{
		m[c] = s;
		++flag;
		if (flag == 3)
		{
			++s;
			flag = 0;
		}
	}
	for (char c = 'P'; c < 'T'; ++c)
		m[c] = '7';
	for (char c = 'T'; c < 'W'; ++c)
		m[c] = '8';
	for (char c = 'W'; c <= 'Z'; ++c)
		m[c] = '9';
	vector<string> r;
	string str;
	for (auto& e : v)
	{
		if (e.empty())
		{
			string tmp("000-0000");
			r.push_back(tmp);
			continue;
		}
		flag = 0;
		for (size_t i = 0; i < e.size(); ++i)
		{
			if (m[e[i]])
				str += m[e[i]];
			else
				if (e[i] >= '0' && e[i] <= '9')
					str += e[i];
			++flag;
			if (flag == 3)
				str += '-';
		}
		r.push_back(str);
		str.clear();
	}
	sort(r.begin(), r.end());
	set<string> res;
	for (const auto e : r)
		res.insert(e);
	for (const auto e : res)
		cout << e << endl;
}
int main()
{
	int n;
	//vector<string> v;
	//string test("ABCD123");
	//v.push_back(test);
	//Solution(v);
	while (cin >> n)
	{
		vector<string> v;
		string str;
		while (cin >> str)
		{
			v.push_back(str);
			if (--n < 0)
				break;
		}
		Solution(v);
	}
}

#include<iostream>
#include<vector>
#include<map>
using namespace std;
void Solution(int n, int m)
{
	vector<int> v;
	map<int, int> res;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	int flag = 0;
	if (m > n)
	{
		for (const auto& e : v)
		{
			if ((e + v[v.size() - 1]) == m)
			{
				flag = e;
				break;
			}
		}
		int level = flag;
		for (int i = 0; i < v.size() - flag; ++i)
		{
			res[flag++] = v[v.size() - 1 - i];
			if ((level + v.size()) / 2 == flag)
			{
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i <= m/2; ++i)
		{
				res[i] = m  - i;
		}
	}

	for (const auto& e : res)
	{
		cout << e.first << " " << e.second << endl;
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		Solution(n, m);
	}
}