#include<iostream>
#include<string>
#include<vector>
using namespace std;
//#define INT_MAX 2147483647
//#define INT_MIN -21474836478

class Day5
{
public:
//回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
//花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。
//现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，
//帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
//例如：
//A = “aba”，B = “b”。这里有4种把B插入A的办法：
//* 在A的第一个字母之前: "baba" 不是回文
//* 在第一个字母‘a’之后 : "abba" 是回文
//* 在字母‘b’之后 : "abba" 是回文
//* 在第二个字母'a'之后 "abab" 不是回文
//所以满足条件的答案为2
	bool IsPalindrome(const string & s)
	{
		return equal(s.begin(), s.end(), s.rbegin());
	}
	void SolutionOne()
	{
		string oneStr;
		string twoStr;
		string curStr;
		getline(cin, oneStr);//读取一行
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
	//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1, 2, 1]，和最大的连续子数组为[2, 1]，其和为 3
	//	输入描述:
	//输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，
	//即每个元素, 每个整数都在32位int范围内。以空格分隔。
	//	输出描述 :
	//所有连续子数组中和最大的值
	void SolutionTwo()
	{
		//输入
		int N;
		int num;
		cin >> N;
		vector<int> arr;
		for (int i = 0; i < N; ++i)
		{
			cin >> num;
			arr.push_back(num);
		}

		//方案，用一个res来保存前面最大和，
		//如果res是个正数，那么res就会越来越大，如果res是负数，会暂定到最小的负数上
		//9    8    -8    3    ==    22
		//-1    -2    -3    -4    ==    -1
		//1    -2    3    4    ==    7
		int res = arr[0];
		int sum1 = 0;//保存
		int sum2 = 0;
		for (int i = 0; i < N; ++i)
		{
			sum2 = sum1 + arr[i];
			if (sum2 > res)
			{
				res = sum2;//来保存历史最大和
			}
			if (sum2 < 0)//如果第一个数就是负数，或者到后面最大和被负数加成了负数。
			{//如果是负数，就会拉低后面的最大和。所以重新开始
				sum2 = 0;
			}
			sum1 = sum2;//来保存当前的最大和
		}
		cout << res;
	}
};

