//#include<iostream>
//using namespace std;
//
//void Solution()
//{
//	int year_;
//	int month_;
//	int day_;
//	int outDay_ = 0;
//	int vYearDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31 ,30 ,31 };//数组第一个数是0，为了匹配输入
//	cin >> year_ >> month_ >> day_;
//	if (year_ <= 0 || month_ <= 0 || month_ > 12 || day_ < 0 || day_ > 31)
//	{
//		cout << -1;//对输入进行合法性判定
//		return;
//	}
//	if ((year_ % 400 == 0) || (year_ % 4 == 0 && year_ % 100 != 0))
//	{
//		vYearDay[2] += 1;//如果是闰年就对，二月+1天
//	}
//
//	if (day_ > vYearDay[month_])
//	{
//		cout << -1;//如果输入的数据大于当月的天数，则输入非法
//		return;
//	}
//	for (int i = 1; i < month_; ++i)
//	{
//		outDay_ += vYearDay[i];//加上本月以前的天数
//	}
//	outDay_ += day_;//加上当月的天数
//	cout << outDay_ << endl;//输出
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
//将输入的数据放入vector
//存储积与和。如果满足条件则幸运袋子+1
//求数组的子数组，全排列

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
	int ji_ = 1;//积
	int sum_ = 0;//和
	int count = 0;//幸运袋的数量
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