#include<iostream>
#include<vector>
using namespace std;
//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b��
//�����һ���㷨�����a��b�������������ȵı�š�
//
//��������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
			{
				a /= 2;
			}
			else
			{
				b /= 2;
			}
		}
		return a;
	}
};

//����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//
//	���� : һ��byte�͵�����
//
//	��� : ��
//
//	���� : ��Ӧ�Ķ�����������1�����������
bool Solution()
{
	int num;
	vector<int> vBin;
	cin >> num;
	if (num > 127 || num < -128)
	{
		return false;
	}
	for (int i = 0; i < 8; ++i)
	{
		int b = ((num >> i) & 1);
		vBin.push_back(b);
	}

	int count = 0;
	int newcount = 0;
	for (int i = 0; i < 8; ++i)
	{
		while (i < 8 && vBin[i] == 1)
		{
			++i;
			++newcount;
		}
		if (newcount > count)
		{
			count = newcount;
		}
		newcount = 0;
	}
	if (num < 0)
	{
		cout << count + 1;
		return true;
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