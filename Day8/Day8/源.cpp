#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
vector<int> Dctionary(vector<string> vStr, int size)
{
	vector<int> flag;

	for (int i = 0; i < size; ++i)
	{
		if (strcmp(vStr[i].c_str(), vStr[i + 1].c_str()) <= 0)
		{
			flag.push_back(i);
		}
		else
		{
			flag.push_back(i + 1);
		}
	}
	return flag;
}
vector<int> Length(vector<string> vStr, int size)
{
	vector<int> flag;

	for (int i = 0; i < size - 1; ++i)
	{
		if (vStr[i].size() <= vStr[i + 1].size())
		{
			flag.push_back(i);
		}
		else
		{
			flag.push_back(i + 1);
		}
	}
	return flag;
}
bool Solution()
{
	int N;
	vector<string> vStr;
	vector<int> vFlag;
	vector<int> flag1;
	vector<int> flag2;
	string inStr;
	cin >> N;
	if (N <= 1)
	{
		return false;
	}
	//if(N == 1)
	//{
  //      cout << "both";
  //      return true;
 //   }
	for (int i = 0; i < N; ++i)
	{
		cin >> inStr;
		vStr.push_back(inStr);
		vFlag.push_back(i);
	}
	vStr.push_back("0");	
	flag1 = Dctionary(vStr, N);
	flag2 = Length(vStr, N);

	int j = 0;
	int k = 0;
	for (int i = 0; i < N; ++i)
	{
		if (flag1[i] == vFlag[i])
		{
			++j;
		}
		if (flag2[i] == vFlag[i])
		{
			++k;
		}
	}
	if ((j == N - 1) && (k == N - 1))
	{
		cout << "both";
	}
	else if ((j != N - 1) && (k == N - 1))
	{
		cout << "lengths";
	}
	else if ((j == N - 1) && (k != N - 1))
	{
		cout << "lexicographically";
	}
	//else
	//{
	  //  return false;
   // }
	return true;
}

int main()
{
	Solution();
	return 0;
}