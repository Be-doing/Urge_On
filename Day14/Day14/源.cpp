//#include<iostream>
//using namespace std;
//
//void Solution()
//{
//	int year_;
//	int month_;
//	int day_;
//	int outDay_ = 0;
//	int vYearDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31 ,30 ,31 };//�����һ������0��Ϊ��ƥ������
//	cin >> year_ >> month_ >> day_;
//	if (year_ <= 0 || month_ <= 0 || month_ > 12 || day_ < 0 || day_ > 31)
//	{
//		cout << -1;//��������кϷ����ж�
//		return;
//	}
//	if ((year_ % 400 == 0) || (year_ % 4 == 0 && year_ % 100 != 0))
//	{
//		vYearDay[2] += 1;//���������Ͷԣ�����+1��
//	}
//
//	if (day_ > vYearDay[month_])
//	{
//		cout << -1;//�����������ݴ��ڵ��µ�������������Ƿ�
//		return;
//	}
//	for (int i = 1; i < month_; ++i)
//	{
//		outDay_ += vYearDay[i];//���ϱ�����ǰ������
//	}
//	outDay_ += day_;//���ϵ��µ�����
//	cout << outDay_ << endl;//���
//}

//int main()
//{
//
//	Solution();
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//����������ݷ���vector
//�洢����͡�����������������˴���+1
//������������飬ȫ����

void buble(vector<int>& vx)
{
	for (int i = 1; i < vx.size(); ++i)
	{
		for (int j = 0; j < vx.size() - i; ++j)
		{
			if(vx[j] <vx[]]]]])
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int num;
	int ji_ = 1;//��
	int sum_ = 0;//��
	int count = 0;//���˴�������
	vector<int> vx_;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		vx_.push_back(num);
	}
	sort(vx_.begin(), vx_.end());
	while (n >= 2)
	{
		for (int i = 0; i < n; ++i)
		{
			ji_ *= vx_[i];
			sum_ += vx_[i];
		}
		if (sum_ > ji_)
		{
			++count;
		}
		--n;
	}
	cout << count;
	system("pause");
	return 0;
}