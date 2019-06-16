#include<iostream>
#include<vector>
using namespace std;
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int bonus = board[0][0];
		int i = 0;
		int j = 0;
		while (i <= 6 && j <= 6)
		{
			if (board[i][j + 1] > board[i + 1][j])
			{
				bonus += board[i][j + 1];
				--i;
			}
			else
			{
				bonus += board[i + 1][j];
				--j;
			}
			if (i + 1 == 6 || j + 1 == 6)
			{
				break;
			}
			++i;
			++j;
		}
		return bonus;
	}
};

int main()
{
	Bonus b;
	vector<vector<int>> v = { {564 ,448,654 ,186 ,490, 699},
	{487 ,444 ,563,228, 365,261},
	{429 ,505, 612, 564 ,715 ,726},
	{464, 617, 234, 647, 702, 263},
	{245 ,249 ,231, 462 ,453, 646},
	{669, 510 ,492 ,512 ,622, 135 } };

	cout << b.getMost(v) << endl;;
	system("pause");
	return 0;
}