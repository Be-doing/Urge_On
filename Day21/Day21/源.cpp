#include<iostream>
#include<string>
using namespace std;
void Solution(int num, string command)
{
	int show = 1;
	if (num <= 4)//�����������С�ڵ���4
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
	while (cin >> num >> command)
	{
		Solution(num, command);
	}
	return 0;
}