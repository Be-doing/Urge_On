#include<iostream>
using namespace std;

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