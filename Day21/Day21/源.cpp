#include<iostream>
using namespace std;

void Separate(int*& arr, int*& v1, int*& v2, int m)
{
	int j = 0;
	for (int i = 0; i < m; ++i)
	{
		if (i < m / 2)
			v1[i] = arr[i];
		else
		{
			v2[j] = arr[i];
			++j;
		}
	}
}
void Close(int*& v, int*& v1, int*& v2, int m)
{
	int n1 = m / 2 - 1;
	int n2 = m / 2 - 1;
	for (int t = m - 1; t >= 0; --t)
	{
		if (t%2 != 0)
		{
			v[t] = v2[n1];
			--n1;
		}
		else
		{
			v[t] = v1[n2];
			--n2;
		}
	}
}
void Solution(const int& n, const int& k)
{
	int N = 2 * n;
	int num;
	int j = 0;
	int* v = new int[N];
	int* v1 = new int[n];
	int* v2 = new int[n];
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		v[i] = num;
}
	for (int i = 0; i < k; ++i)
	{
		Separate(v, v1, v2, N);
		Close(v, v1, v2, N);
	}
	for (int t = 0; t < N; ++t)
	{
		cout << v[t] << " ";
	}
}
int main()
{
	int T;//组数
	int n;//2n张牌
	int k;//洗多少次
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		Solution(n, k);
	}
	return 0;
}
