#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		//找数组中出现了一半的数
		//2    2    2    3    3
		//1    1    2    2    2
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i)
		{
			++m[gifts[i]];
		}
		for (const auto&e : m)
		{
			if (e.second > (gifts.size() / 2))
			{
				return e.first;
			}
		}
		return 0;
	}
};

int main()
{
	Gift g;
	vector<int> v = {1,1,2};
	cout << g.getValue(v, v.size()) << endl;
	system("pause");
	return 0;
}
