#include<iostream>
#include<vector>
using namespace std;
//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。
//请设计一个算法，求出a和b点的最近公共祖先的编号。
//
//给定两个int a, b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
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

//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//
//	输入 : 一个byte型的数字
//
//	输出 : 无
//
//	返回 : 对应的二进制数字中1的最大连续数
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