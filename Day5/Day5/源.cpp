#include<iostream>
#include<string>
using namespace std;
//#define INT_MAX 2147483647
//#define INT_MIN -21474836478

class Day5
{
public:
//���Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
//�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
//�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ���������
//������Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���磺
//A = ��aba����B = ��b����������4�ְ�B����A�İ취��
//* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
//* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//* ����ĸ��b��֮�� : "abba" �ǻ���
//* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//�������������Ĵ�Ϊ2
	bool IsPalindrome(const string & s)
	{
		return equal(s.begin(), s.end(), s.rbegin());
	}
	void SolutionOne()
	{
		string oneStr;
		string twoStr;
		string curStr;
		getline(cin, oneStr);
		getline(cin, twoStr);
		int count = 0;
		//string& insert (size_t pos, const string& str);
		size_t size = oneStr.size();
		size_t move = 0;
		while (move <= size)
		{
			curStr = oneStr;
			curStr.insert(move, twoStr);
			if (IsPalindrome(curStr))
			{
				++count;
			}
			++move;
		}
		cout << count;
	}

	//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3
	//	��������:
	//����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn������
	//��ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���
	//	������� :
	//���������������к�����ֵ
	void SolutionTwo()
	{

	}
};

