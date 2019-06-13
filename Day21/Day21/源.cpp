#include<iostream>
#include<string>
using namespace std;
//#include<iostream>
//using namespace std;
//void Separate(int*& arr, int*& v1, int*& v2, int m)
//{
//	int j = 0;
//	for (int i = 0; i < m; ++i)
//	{
//		if (i < m / 2)
//			v1[i] = arr[i];
//		else
//		{
//			v2[j] = arr[i];
//			++j;
//		}
//	}
//}
//void Close(int*& v, int*& v1, int*& v2, int m)
//{
//	int n1 = m / 2 - 1;
//	int n2 = m / 2 - 1;
//	for (int t = m - 1; t >= 0; --t)
//	{
//		if (t%2 != 0)
//		{
//			v[t] = v2[n1];
//			--n1;
//		}
//		else
//		{
//			v[t] = v1[n2];
//			--n2;
//		}
//	}
//}
//void Solution(const int& n, const int& k)
//{
//	int N = 2 * n;
//	int num;
//	int j = 0;
//	int* v = new int[N];
//	int* v1 = new int[n];
//	int* v2 = new int[n];
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> num;
//		v[i] = num;
//	}
//	for (int i = 0; i < k; ++i)
//	{
//		Separate(v, v1, v2, N);
//		Close(v, v1, v2, N);
//	}
//	for (int t = 0; t < N; ++t)
//	{
//		cout << v[t] << " ";
//	}
//}
//int main()
//{
//	int T;//组数
//	int n;//2n张牌
//	int k;//洗多少次
//	cin >> T;
//	while (T--)
//	{
//		cin >> n >> k;
//		Solution(n, k);
//	}
//	return 0;
//}
//
#include<iostream>
#include<string>
using namespace std;
void Solution(int num, string command)
{
	int show = 1;
	if (num <= 0)
	{
		cout << endl;
		cout << 0 << endl;
	}
	else if (num <= 4)//如果歌曲总数小于等于4
	{
		for (int i = 0; i < command.size(); ++i)//光标一共移动size次
		{
			if (show == 1 && command[i] == 'U')//如果光标在第一个位置，放在最后一首位置
			{
				show = num;
			}
			else if (show == 4 && command[i] == 'D')//如果光标在最后位置，放在第一首位置
			{
				show = 1;
			}
			else if (command[i] == 'D')//普通模式下
			{
				++show;
			}
			else if (command[i] == 'U')
			{
				--show;
			}
		}
		for (int i = 1; i <= num; ++i)
		{
			cout << i << " ";
		}
		cout << endl;
		cout << show << endl;
	}
	else
	{
		int upflag = 0;//翻页标记
		int dnflag = 0;
		for (size_t i = 0; i < command.size(); ++i)
		{
			if (show == 1 && command[i] == 'U')
			{
				show = num;
			}
			else if (show == num && command[i] == 'D')
			{
				show = 1;
			}
			else if (command[i] == 'U')
			{
				++upflag;
				--show;
			}
			else if (command[i] == 'D')
			{
				++dnflag;
				++show;
			}
		}
		if (upflag - dnflag >= 0)//光标在顶部
		{
			for (int i = 0; i < 4; ++i)
			{
				cout << show + i << " ";
			}
			cout << endl;
			cout << show << endl;
		}
		else if (upflag - dnflag <= -3)//光标在底部
		{
			for (int i = 3; i >= 0; ++i)
			{
				cout << show - i << " ";
			}
			cout << endl;
			cout << show << endl;
		}
		else
		{
			int tmp = upflag > dnflag ? upflag - dnflag : dnflag - upflag;
			for (int i = 0; i < 4; ++i)
			{
				cout << show - tmp + i << " ";
			}
			cout << endl;
			cout << show << endl;
		}
	}
}
int main()
{
	int num;
	string command;
	while (cin >> num )
	{
		fflush(stdin);
		getline(cin, command);
		Solution(num, command);
	}
	return 0;
}