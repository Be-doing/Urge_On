//Í³¼Æconnect
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void Solution(vector<string>& v)
{
	int count = 0;
	int max = 0;
	for (size_t i = 1; i < v.size(); ++i)
	{
		if (v[i] == "connect")
		{
			count = 0;
			while (i < v.size() && v[i] == "connect")
			{
				++count;
				++i;
			}
		}
		if (count > max)
			max = count;
	}
	cout << max << endl;
}
int main()
{
	int n;
	string str;
	char c;
	vector<string> v;
	while (cin >> n)
	{
		while (n--)
		{
			cin >> c >> str;
			v.push_back(str);
		}
		Solution(v);
	}
	return 0;
}