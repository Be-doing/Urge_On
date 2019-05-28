#include<iostream>
#include<string>
#include<vector>
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
		//����
		int N;
		int num;
		cin >> N;
		vector<int> arr;
		for (int i = 0; i < N; ++i)
		{
			cin >> num;
			arr.push_back(num);
		}

		//��������һ��res������ǰ�����ͣ�
		//���res�Ǹ���������ôres�ͻ�Խ��Խ�����res�Ǹ��������ݶ�����С�ĸ�����
		//9    8    -8    3    ==    22
		//-1    -2    -3    -4    ==    -1
		//1    -2    3    4    ==    7
		int res = arr[0];
		int sum1 = 0;//����
		int sum2 = 0;
		for (int i = 0; i < N; ++i)
		{
			sum2 = sum1 + arr[i];
			if (sum2 > res)
			{
				res = sum2;//��������ʷ����
			}
			if (sum2 < 0)//�����һ�������Ǹ��������ߵ��������ͱ������ӳ��˸�����
			{//����Ǹ������ͻ����ͺ�������͡��������¿�ʼ
				sum2 = 0;
			}
			sum1 = sum2;//�����浱ǰ������
		}
		cout << res;
	}
};

