#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
void Solution(string& str)
{
	unordered_map<char, int> m;
	for (int i = 0; i < str.size(); ++i)
	{
		++m[str[i]];
	}
	int flag = 1;
	for (auto& e : m)
	{
		if (e.second == 1)
		{
			cout << e.first << endl;
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		cout << -1 << endl;
	}
}
int main()
{
	string str;
	while (cin >> str)
	{
		Solution(str);
	}
	return 0;
}