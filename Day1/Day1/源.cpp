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
//ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
//���� :
//һ������������Ա��ˮƽֵ�ֱ���3, 3, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���3, 2, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���1, 5, 2.��ô�����ˮƽֵ��2
//Ϊ���ñ������п���, ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
//��������ʾ :
//���ţţ��6����Ա���ֵ���������
//�������Ϊ :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
//	���������Ϊ :
//	team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
//	û�б��ܺ�Ϊ10����ķ���, �������10.
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

//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
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
