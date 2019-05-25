#include<iostream>
#include<string>
using namespace std;
class Day4
{
public:
	//A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪�����µ���Ϣ��
	//A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
	//������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������
	void SolutionOne()
	{
		int a;
		int b;
		int c;
		int d;
		cin >> a >> b >> c >> d;

		int A = (a + c) / 2;
		int C = (d - b) / 2;
		int B1 = (c - a) / 2;
		int B2 = (b + d) / 2;
		if (B1 == B2)
		{
			cout << A << " " << B2 << " " << C;
		}
		else
		{
			cout << "No";
		}
	}
	//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
	//�������� :
	//����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
	//������� :
	//Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
	void SolutionTwo()
	{
		int M;
		int N;;
		string trans = "0123456789ABCDEF";
		string res;
		bool flag = false;//�Ƿ��Ǹ���
		cin >> M >> N;

		if (M < 0)
		{
			M = 0 - M;
			flag = true;
		}

		while (M != 0)
		{
			res += trans[M%N];
			M /= N;
		}
		if (flag)
		{
			res += '-';
		}
		reverse(res.begin(), res.end());

		cout << res;
	}
};



