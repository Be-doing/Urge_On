// write your code here cpp

#include<iostream>
#include<vector>
using namespace std;

class Date
{
public:
	Date(const int& year, const int& month, const int& day)
		:year_(year)
		,month_(month)
		,day_(day)
	{}
	Date operator-=(int days)
	{
		vector<int> monthday = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0)
			monthday[1] += 1;
		day_ -= days;

		while (day_ < 0)
		{
			--month_;
			if (month_ < 0)
			{
				month_ = 12;
				--year_;
			}
			day_ += monthday[month_];
		}
		return *this;
	}
	Date operator-( Date date)
	{
		int flag = 0;
		*this -= date.day_;
		int day =day_;
		int month = month_ - date.month_ ;
		if (month < 0)
		{
			flag = -1;
			month += 12;
			--year_;
		}
		int year = year_ - date.year_;

		return Date(year, month, day);
	}
	int Sum()
	{
		int day = day_;
		vector<int> monthday = {0, 62, 56, 62,30, 62, 30, 62, 31, 30, 31, 60, 31 };
		if (year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0)
			monthday[2] += 2;
		int sum = 2;
		for (int m = 1; m < month_; ++m)
		{
			sum += monthday[m];
		}
		if (month_ % 2 == 0 || month_ % 3 == 0)
			day *= 2;
		sum += day;
		for (int y = 0; 0 < year_; ++y)
		{
			for (const auto& e : monthday)
			{
				sum += e;
			}
		}
		return sum;
	}
public:
	int year_;
	int month_;
	int day_;
};
int main()
{
	int year1,year2, month1, month2, day1, day2;
	year1 = 2000;
	month1 = 1;
	day1 = 1;

	year2 = 2000;
	month2 = 1;
	day2 = 2;

	Date y1(year1, month1, day1);
	Date y2(year2, month2, day2);

	Date y3 = y2 - y1;

	cout << y3.Sum() << endl;
	//while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	//{
	//	Solution(year1, year2, month1, month2, day1, day2);
	//}
	system("pause");
	return 0;
}