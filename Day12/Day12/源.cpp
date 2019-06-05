#include<iostream>
#include<vector>
using namespace std;

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		//1���Ȼ�ȡm�Ķ�����λ
		//2����ȡn�Ķ�����λ
		vector<int> binM;
		vector<int> binN;
		int tmp = 0;
		int res = 0;
		for (int i_ = 0; i_ < 32; ++i_)
		{
			tmp = ((n >> i_) & 1);
			binN.push_back(tmp);
			tmp = ((m >> i_) & 1);
			binM.push_back(tmp);
		}

		//3�������û�
		int k = 0;
		for (int i_ = j; i_ <= i; ++i_)
		{
			binN[i_] = binM[k];
			++k;
		}
		//4��ת����ʮ����
		for (int i_ = 31; i_ >= 0; --i_)
		{
			res = res << 1;
			res |= binN[i_];
		}
		return res;
	}
};

//int main()
//{
//	BinInsert b;
//	cout << b.binInsert(1024,19,2,6) << endl;
//	system("pause");
//	return 0;
//}









//1������һ��ż��
//2���ҳ��������ӣ���1��n-1��ʼ��
//3��дһ���ж��Ƿ��������ĺ���
//3���ж��Ƿ����������������������������������ж��������
//3�����С����һ�εĲ�������������

#include<iostream>
using namespace std;

bool IsPrime(int num)
{
	for (int i = 2; i < num / 2; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

void Solution(int num)
{
	int mid = num / 2;
	int i = mid;
	for (i; i >= 0; --i)
	{
		if (IsPrime(i) && IsPrime(num - i))
		{
			break;
		}
	}
	cout << i << endl << num - i << endl;
}

int main()
{
	int num;
	while (cin >> num)
	{
		Solution(num);
	}
	return 0;
}