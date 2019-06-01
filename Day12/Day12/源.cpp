#include<iostream>
#include<vector>
using namespace std;

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









//1、输入一个偶数
//2、找出两个因子，从1和n-1开始。
//3、写一个判定是否是素数的函数
//3、判断是否是素数，是则求差，并保存差和这两个数。判断下面的数
//3、如果小于上一次的差，则更新两个数。

#include<iostream>
using namespace std;
bool IsnotPrime(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if ((n % i) == 0)
		{
			return true;
		}
	}
	return false;
}
bool Solution()
{
	int num;//输入的数


	int ret1 = 0;//第一个因子
	int ret2 = 0;//第二个因子

	cin >> num;
	if (num % 2 != 0 || num <= 2)
	{
		return false;
	}
	int dif = num;//差

	int n = 1;
	int m = num - 1;
	int cur = 0;//当前的差
	while (n <= m)//例如10==5 + 5的时候，需要取等
	{
		if (IsnotPrime(n) || IsnotPrime(m))//不能是素数
		{
			++n;
			--m;
			continue;
		}
		cur = m - n;
		if (cur < dif)
		{
			dif = cur;
			ret1 = n;
			ret2 = m;
		}
		++n;
		--m;
	}
	cout << ret1 << ret2;
	//cout << ret2;
	return true;
}
int main()
{
	Solution();
	system("pause");
	return 0;
}