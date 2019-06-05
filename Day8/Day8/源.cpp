#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
//1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" < "doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
bool DecSort(vector<string>& Vstr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		if (strcmp(Vstr[i].c_str(), Vstr[i + 1].c_str()) > 0)
		{
			return false;
		}
	}
	return true;
}

bool SizeSort(vector<string>& Vstr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		if (Vstr[i].size() > Vstr[i + 1].size())
		{
			return false;
		}
	}
	return true;
}

void SolutionOne()
{
	int num;
	string str;
	vector<string> Vstr;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> str;
		Vstr.push_back(str);
	}
	size_t size = Vstr.size();
	bool decflag = DecSort(Vstr, size);
	bool sizeflag = SizeSort(Vstr, size);

	if (decflag && sizeflag)
	{
		cout << "both";
	}
	else if (decflag)
	{
		cout << "lexicographically";
	}
	else if (sizeflag)
	{
		cout << "lengths";
	}
	else
	{
		cout << "none";
	}
}

//题目描述
//
//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
void Swap(int& num1, int& num2)
{
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
bool SolutionTwo()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 == num2)
	{
		cout << num1;
		return true;
	}
	if (num2 > num1)
	{
		Swap(num1, num2);
	}
	if (num1 % num2 == 0)
	{
		cout << num1;
		return true;
	}
	for (int i = 1; i < num1 * num2; ++i)
	{
		int res = num1 + i;
		if ((res % num1 == 0) && (res % num2 == 0))
		{
			cout << res;
			return true;
		}
	}
	cout << num1 * num2;
	return true;
}

int main()
{
	SolutionOne();
	return 0;
}