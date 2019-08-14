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


//https://www.nowcoder.com/questionTerminal/98dc82c094e043ccb7e0570e5342dd1b  计算公共字符串
