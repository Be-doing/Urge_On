#include<iostream>
using namespace std;

//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
//��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N��
//���������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1��
//���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci��



//����һ�������ҵ��������������쳲����������ȽϾ���֮�����
//����һ������ʵ��쳲��������ĺ���
//�ڵ�һ������������ͣ����
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
//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
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