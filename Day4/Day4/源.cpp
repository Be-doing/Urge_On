#include<iostream>
#include<string>
using namespace std;
class Day4
{
public:
	//A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下的信息：
	//A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
	//现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。
	void SolutionOne()
	{
		int x,y,z,w;
		cin >> x >> y >> z >> w;
		int A = (z + x)/2;
		int C = (w - y)/2;
		if((z - x) == (w + y))
			cout << A << " " << (z - x) / 2 << " " << C << endl;
		else
			cout << "No" << endl;
		return;
	}
	//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
	//输入描述 :
	//输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
	//输出描述 :
	//为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
	void SolutionTwo()
	{
		int M;
		int N;;
		string trans = "0123456789ABCDEF";
		string res;
		bool flag = false;//是否是负数
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



