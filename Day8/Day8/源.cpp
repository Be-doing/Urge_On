#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
//������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 
//1.�����ַ������ֵ����������磺
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.�����ַ����ĳ����������磺
//"car" < "cats" < "koala" < "doggies" < "carriage"
//������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
bool DecSort(vector<string>& Vstr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		if (strcmp(Vstr[i].c_str(), Vstr[i + 1].c_str()) > 0)
		{
			return false;
		}
	}
	return true;
}

bool SizeSort(vector<string>& Vstr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		if (Vstr[i].size() > Vstr[i + 1].size())
		{
			return false;
		}
	}
	return true;
}

void SolutionOne()
{
	int num;
	string str;
	vector<string> Vstr;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> str;
		Vstr.push_back(str);
	}
	size_t size = Vstr.size();
	bool decflag = DecSort(Vstr, size);
	bool sizeflag = SizeSort(Vstr, size);

	if (decflag && sizeflag)
	{
		cout << "both";
	}
	else if (decflag)
	{
		cout << "lexicographically";
	}
	else if (sizeflag)
	{
		cout << "lengths";
	}
	else
	{
		cout << "none";
	}
}

//��Ŀ����
//
//������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
void Swap(int& num1, int& num2)
{
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
bool SolutionTwo()
{
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 == num2)
	{
		cout << num1;
		return true;
	}
	if (num2 > num1)
	{
		Swap(num1, num2);
	}
	if (num1 % num2 == 0)
	{
		cout << num1;
		return true;
	}
	for (int i = 1; i < num1 * num2; ++i)
	{
		int res = num1 + i;
		if ((res % num1 == 0) && (res % num2 == 0))
		{
			cout << res;
			return true;
		}
	}
	cout << num1 * num2;
	return true;
}

int main()
{
	SolutionOne();
	return 0;
}