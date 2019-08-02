#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define TEAMMAX 100000
#define LEVELMAX 1000000000
using namespace std;
class Day1
{
public:
//牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.现在要将这些选手进行组队, 一共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如 :
//一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2
//为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。
//如样例所示 :
//如果牛牛把6个队员划分到两个队伍
//如果方案为 :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//	而如果方案为 :
//	team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.
//	没有比总和为10更大的方案, 所以输出10.
		bool SolutionOne()
		{
			int teamNum;
			int level;
			cin >> teamNum;
			if (teamNum < 1 || teamNum > TEAMMAX)
			{
				return false;
			}
			vector<int> vLevel;
			while (cin >> level)
			{
				if (level < 1 || level > LEVELMAX)
				{
					return false;
				}
				vLevel.push_back(level);
			}
			sort(vLevel.begin(), vLevel.end());
			long long sum = 0;
			for (int i = teamNum * 3 - 2; i >= teamNum; i -= 2)
			{
				sum += vLevel[i];
			}
			cout << sum;
			return true;
		}

//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
		void SolutionTwo()
		{
			string srcStr;
			string delStr;
			getline(cin, srcStr);
			getline(cin, delStr);

			int hash[256] = { 0 };
			string res;
			size_t delSize = delStr.size();
			size_t srcSize = srcStr.size();
			for (size_t i = 0; i < delSize; ++i)
			{
				++hash[delStr[i]];
			}
			for (size_t i = 0; i < srcSize; ++i)
			{
				if (hash[srcStr[i]] == 0)
				{
					res += srcStr[i];
				}
			}
			cout << res;
		}
};
int main()
{
	Day1 d;
	d.SolutionOne();
	return 0;
}
