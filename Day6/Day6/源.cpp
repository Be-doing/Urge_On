class Solution
{
public:
	//�������
	//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�
	//����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
	//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
	int StrToInt(string str)
	{
		size_t size = str.size();
		if (size > 11)
		{
			return 0;//int�����11λ����������
		}
		size_t i = 0;
		char flag = str[0];
		if (flag == '+' || flag == '-')//��һΪӦ����+��-
		{
			i = 1;
		}
		long res = 0;
		for (i; i < size; ++i)
		{
			res *= 10;
			if (str[i] < '0' || str[i] > '9')
			{
				return 0;
			}
			res = res + (str[i] - '0');
		}
		if (flag == '-')
		{
			res = 0 - res;
		}
		if (res < INT_MIN || res > INT_MAX)
		{
			return 0;
		}
		return (int)res;
	}
};


#include<iostream>
using namespace std;
//����С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��
//ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������
bool Solution()
{
	int W;
	int H;
	double R = 2;
	int count = 0;
	int cflag = 0;
	int rflag = 0;
	cin >> W >> H;
	if ((W < 1 || W > 1000) && (H < 1 || H > 1000))
	{
		return false;
	}
	if (W == 1 && H == 1)
	{
		cout << 1;
		return true;
	}
	for (int w = 0; w < W; ++w)
	{
		int h = 0;
		++rflag;
		if (rflag == 3 || rflag == 4)
		{
			h += 2;
			if (rflag == 4)
			{
				rflag = 0;
			}

		}
		for (h; h < H; ++h)
		{
			++cflag;
			++count;
			if (cflag == 2)
			{
				h += 2;
				cflag = 0;
			}
		}
	}
	cout << count;
	return true;
}
int main()
{
	Solution();
	system("pause");
	return 0;
}