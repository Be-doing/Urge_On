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
//	int T;//����
//	int n;//2n����
//	int k;//ϴ���ٴ�
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
	else if (num <= 4)//�����������С�ڵ���4
	{
		for (int i = 0; i < command.size(); ++i)//���һ���ƶ�size��
		{
			if (show == 1 && command[i] == 'U')//�������ڵ�һ��λ�ã��������һ��λ��
			{
				show = num;
			}
			else if (show == 4 && command[i] == 'D')//�����������λ�ã����ڵ�һ��λ��
			{
				show = 1;
			}
			else if (command[i] == 'D')//��ͨģʽ��
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
		int upflag = 0;//��ҳ���
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
		if (upflag - dnflag >= 0)//����ڶ���
		{
			for (int i = 0; i < 4; ++i)
			{
				cout << show + i << " ";
			}
			cout << endl;
			cout << show << endl;
		}
		else if (upflag - dnflag <= -3)//����ڵײ�
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