#include<iostream>
#include<string>
using namespace std;

void Solution(string& str1, string& str2)
{
	size_t size2 = str2.size();
	size_t size1 = str1.size();
	size_t tmp = 0;
	size_t i = 0;
	for (i; i < size2, tmp < size1; ++i)
	{
		if (str1[tmp] == '?')
		{
			++tmp;
			continue;
		}
		else if (str1[tmp] == '*')
		{
			++tmp;
			while (i < size2)
			{
				if (str2[i] == str1[tmp])
				{
					break;
				}
				++i;
			}
		}
		else
		{
			if (str1[tmp] != str2[i])
			{
				cout << "false" << endl;
				break;
			}
		}
		++tmp;
	}
	if(i == size2)
	cout << "true" << endl;
}


int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		Solution(str1, str2);
	}
	return 0;
}
