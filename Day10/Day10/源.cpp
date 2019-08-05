#include<vector>
#include<iostream>
//题目地址：https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		for (int i = 0; i < 3; ++i)
		{
			if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] == 1))
			{
				return true;
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] == 1))
			{
				return true;
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 1)
		{
			return true;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 1)
		{
			return true;
		}
		return false;
	}
};
//题目地址：https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId
#include<iostream>
#include<string>
using namespace std;
int Passwd(string& passwd)
{
	int level = 0;
	size_t len = passwd.size();//密码长度
	if (len == 0)
	{
		cout << "VERY_WEAK";
	}
	if (len < 5)
	{
		level = 5;
	}
	else if (len > 4 && len < 8)
	{
		level = 10;
	}
	else
	{
		level = 25;
	}
	char c;
	int xch = 0;//小写字母标记
	int dch = 0;//大写字母标记
	int num = 0;//数字标记
	int fuh = 0;//符号标记
	for (size_t i = 0; i < len; ++i)
	{
		c = passwd[i];
		if (c >= 'a' && c <= 'z')
		{
			xch = 1;
		}
		if (c >= 'A' && c <= 'Z')
		{
			dch = 1;
		}
		if (c >= '0' && c <= '9')
		{
			num = num + 1;//是否只有一个数字
		}
		if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		{
			fuh = fuh + 1;//是否大于一个符号
		}
	}
	int flag = 0;//满足条件的标记
	if ((xch == 1 && dch == 0) || (dch == 1 && xch == 0))
	{//只有大写字符或者只有小写字母
		level += 10;
		flag = 1;
	}
	if (num == 1)//如果数字只有一个
	{
		level += 10;
		flag += 2;
	}
	if (num > 1)//数字大于一个
	{
		level += 20;
		flag += 2;
	}
	if (xch == 1 && dch == 1)//大小写都有
	{
		level += 20;
		flag += 50;//为了区分只有小写或者只有大写的标记
	}
	if (fuh == 1)//只有一个符号
	{
		level += 10;
		flag += 20;
	}
	if (fuh > 1)//大于一个符号
	{
		level += 25;
		flag += 20;
	}
	if (flag == 3 || flag == 52)//只有数字和字母
	{
		level += 2;
	}
	if (flag == 23)//有数字字母，和符号
	{
		level += 3;
	}
	if (flag == 72)
	{
		level += 5;
	}
	return level;
}
void Show()
{
	string passwd;
	cin >> passwd;
	int level = Passwd(passwd);
	if (level >= 90)
	{
		cout << "VERY_SECURE";
	}
	else if (level >= 80)
	{
		cout << "SECURE";
	}
	else if (level >= 70)
	{
		cout << "VERY_STRONG";
	}
	else if (level >= 60)
	{
		cout << "STRONG";
	}
	else if (level >= 50)
	{
		cout << "AVERAGE";
	}
	else if (level >= 25)
	{
		cout << "WEAK";
	}
	else if (level >= 0)
	{
		cout << "VERY_WEAK";
	}
}
int main()
{
	Show();
	system("pause");
	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//int numChar(string str, int k)
//{
//	//根据ASCII码判断字母大小写
//	int small = 0;
//	int big = 0;
//	for (int i = 0; i < k; i++)
//	{
//		if (str[i] >= 65 && str[i] <= 90)
//			big++;
//		else if (str[i] >= 97 && str[i] <= 122)
//			small++;
//	}
//	if ((small + big) == 0)
//		return 0;
//	else if (small == k || big == k)
//		return 10;
//	else if (small > 0 && big > 0)
//		return 20;
//	return 0;
//}
//int numNumber(string str, int k)
//{
//	//根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字
//	int num = 0;
//	for (int i = 0; i < k; i++)
//	{
//		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
//			num++;
//	}
//	if (num == 0)
//		return 0;
//	else if (num == 1)
//		return 10;
//	else
//		return 20;
//}
//int numSymbal(string str, int k)
//{
//	int num = 0;
//	for (int i = 0; i < k; i++)
//	{
//		//除去字母，数字，其它都为符号
//		if (!(str[i] >= 65 && str[i] <= 90)
//			&& !(str[i] >= 97 && str[i] <= 122)
//			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
//			num++;
//	}
//	if (num == 0)
//		return 0;
//	else if (num == 1)
//		return 10;
//	else
//		return 25;
//}
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
//		int k = str.size();
//		if (k <= 4)
//			sum1 = 5;
//		else if (k >= 8)
//			sum1 = 25;
//		else
//			sum1 = 10;
//		sum2 = numChar(str, k);
//		sum3 = numNumber(str, k);
//		sum4 = numSymbal(str, k);
//		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
//		{
//			if (sum2 == 10)
//				sum5 = 3;
//			else
//				sum5 = 5;
//		}
//		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
//			sum5 = 2;
//		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
//			cout << "VERY_SECURE" << endl;
//		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
//			cout << "SECURE" << endl;
//		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
//			cout << "VERY_STRONG" << endl;
//		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
//			cout << "STRONG" << endl;
//		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
//			cout << "AVERAGE" << endl;
//		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
//			cout << "WEAK" << endl;
//		else
//			cout << "VERY_WEAK" << endl;
//	}
//	system("pause");
//	return 0;
//}
