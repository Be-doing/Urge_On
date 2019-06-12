#include<string>
#include <algorithm>
#include<iostream>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}