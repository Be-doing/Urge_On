#include<iostream>
using namespace std;

//Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
//在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，
//你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，
//现在给你一个数N求最少需要多少步可以变为Fibonacci数



//输入一个数，找到离它最近的两个斐波那契数，比较距离之后输出
//创建一个返回实现斐波那契数的函数
//在第一个大于它的数停下来
#define MAX 1000000
int Fibo(int ra)
{
	if (ra == 0)
	{
		return 0;
	}
	if (ra == 1)
	{
		return 1;//3    2 11
	}
	return Fibo(ra - 1) + Fibo(ra - 2);
}

bool SolutionOne()
{
	int N;
	cin >> N;
	int i = 0;
	int max = 0;
	int min = 0;
	for (i; i < MAX; ++i)
	{
		if (N == Fibo(i))
		{
			cout << 0;
			return true;
		}
		max = Fibo(i + 1);
		min = Fibo(i);
		if (N < max)
		{
			break;
		}
	}
	int res = (N - min) > (max - N) ? max - N : N - min;
	cout << res;
	return true;
}

#include<stack>
//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
class Parenthesis {
public:

	bool chkParenthesis(string A, int n) {
		// write code here
		if (n == 0 || n == 1)
		{
			return false;
		}
		stack<char> chStack;
		chStack.push(A[0]);
			for (int i = 1; i < n; ++i)
			{
				if (A[i] == ')')
				{
					if (!chStack.empty() && chStack.top() == '(')
					{
						chStack.pop();
					}
					else
					{
						return false;
					}

				}
				else if (A[i] == '(')
				{
					chStack.push(A[i]);
				}
				else
				{
					return false;
				}
			}
			if (!chStack.empty())
			{
				return false;
			}
			else
			{
				return true;
			}
	}
};
int main()
{
	Parenthesis s;
	string str = "())";
	size_t size = str.size();
	cout << s.chkParenthesis(str, size) << endl;;
	system("pause");
	return 0;
}