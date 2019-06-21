
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Solution()
{
	string strIn;
	string strOut;
	vector<string> vStr;
	int count = 0;
	char c = 0;;
	getline(cin, strIn);

	int size = strIn.size();
	int i = 0;
	while (i < size)
	{
		c = strIn[i];
		while (i < size && c != ' ')
		{
			if (c == '"')
			{
				//strOut += c;
				++i;
				c = strIn[i];
				while (c != '"')
				{
					strOut += c;
					++i;
					c = strIn[i];
				}
				//c = strIn[i];
				//strOut += c;
				++i;
				break;
			}
			strOut += c;
			++i;
			c = strIn[i];
		}
		vStr.push_back(strOut);
		strOut.clear();
		++i;
	}
	cout << vStr.size() << endl;
	for (int i = 0; i < vStr.size(); ++i)
	{
		cout << vStr[i] << endl;
	}
}
int main()
{
	Solution();
	system("pause");
	return 0;
}