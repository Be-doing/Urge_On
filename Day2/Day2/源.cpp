#include<iostream>
#include<vector>
#include<string>
using namespace std;
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�
//ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪��
//�����ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2
#define ARRMAX 100000
#define NUMMAX 1000000000
class Day2
{
public:
	bool SolutionOne()
	{
		int arrlen;
		int count = 0;
		vector<int> num;
		cin >> arrlen;
		if (arrlen < 1 || arrlen > ARRMAX)
		{
			return false;
		}
		int numIn;
		for (int i = 0; i < arrlen; ++i)
		{
			cin >> numIn;
			if (numIn < 1 || numIn > NUMMAX)
			{
				return false;
			}
			num.push_back(numIn);
		}
		num.push_back(0);
		int i = 0;
		while (i < arrlen)
		{
			if (num[i] < num[i + 1])
			{
				while (i < arrlen && num[i] <= num[i + 1])
				{
					++i;
				}
				++i;//1 2 1 2 1 2 1 0
				++count;
			}
			else if (num[i] == num[i + 1])
			{
				++i;
			}
			else
			{
				while (i < arrlen && num[i] >= num[i + 1])
				{
					++i;
				}
				++i;
				++count;
			}
		}
		cout << count;
		return true;
	}

	//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
	//ÿ�������������1������������ I like beijing.�����������Ȳ�����100
	//�����������֮����ַ���, �Կո�ָ�
	void SolutionTwo()
	{
		string oldStr;
		string newStr;
		cin >> oldStr;
		while (cin >> newStr)
		{
			newStr = newStr + " " + oldStr;
			oldStr = newStr;
		}
		cout << newStr;
	}
};
