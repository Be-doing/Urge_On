#include<iostream>
#include<string>
using namespace std;
void Solution(int num, string command)
{
	int show = 1;
	if (num <= 4)//如果歌曲总数小于等于4
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
	while (cin >> num >> command)
	{
		Solution(num, command);
	}
	return 0;
}