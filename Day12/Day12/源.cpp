#include<iostream>
#include<vector>
using namespace std;

//题目地址：https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?tpId
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		//1、先获取m的二进制位
		//2、获取n的二进制位
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

		//3、进行置换
		int k = 0;
		for (int i_ = j; i_ <= i; ++i_)
		{
			binN[i_] = binM[k];
			++k;
		}
		//4、转换出十进制
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

//题目地址：https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId
//1、输入一个偶数
//2、找出两个因子，从1和n-1开始。
//3、写一个判定是否是素数的函数
//3、判断是否是素数，是则求差，并保存差和这两个数。判断下面的数
//3、如果小于上一次的差，则更新两个数。

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
