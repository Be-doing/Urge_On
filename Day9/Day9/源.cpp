//���дһ��������������������ӡ�����ʹ�� + �����������������
//
//��������int A��B���뷵��A��B��ֵ
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		int sum = 0;
		int carry = 0;
		while (B)
		{
			sum = A ^ B;//����൱�����
			carry = (A&B) << 1;//���൱�ڽ�λ����Ϊֻ��1&1 == 1
			B = carry;
			A = sum;
		}
		return sum;
	}
};

#include<iostream>
using namespace std;
//���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
//���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�
int LoadNum(int n, int m)
{
	if (n > 1 && m > 1)
	{
		return LoadNum(n - 1, m) + LoadNum(n, m - 1);
	}
	else if (((n == 1) && (m >= 1)) || ((n >= 1) && (m == 1)))
	{
		return n + m;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n;
	int m;
	cin >> n >> m;
	cout << LoadNum(n, m);
	system("pause");
	return 0;
}