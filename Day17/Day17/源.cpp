#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	int tmp = 1;
	vector<int> v1;
	vector<int> v2;
	cin >> n;

	int mid = 1;
	for (int i = 0; i < n; ++i)
	{
		tmp = tmp + 2;
	}
	//n行有mid个数，mid一定是奇数
	//再取其中间的数
	v1.resize(tmp);
	v2.resize(tmp);
	mid = tmp / 2 ;

	v1[mid] = 1;
	for (int i = 0; i < n; ++i)
	{
		//每次叠加两个数1	3   	5   	7	   9
		//tmp = tmp + 2;
		for (int j = 1; j < tmp - 1; ++j)
		{
			v2[j] = v1[j - 1] + v1[j] + v1[j + 1];

		}
		v1 = v2;
	}
	v2[0] = 1;
	v2[tmp-1] = 1;

	for (auto& e : v2)
	{
		if (e % 2 == 0)
		{
			cout << e << endl;
			break;
		}
	}
	system("pause");
	return 0;
}


#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Solution2(string& str1, string& str2)
{
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	size_t size1 = str1.size();
	size_t size2 = str2.size();
	size_t size3 = 0;
	int flag = 0;
	if (size1 >= size2)
	{
		size3 = size2 ;
	}
	else
	{
		size3 = size1;
	}
	string res;
	size_t i = 0;
	for ( i ; i < size3; ++i)
	{
		int s1 = str1[i] - '0';
		int s2 = str2[i] - '0';
		int sum = s1 + s2 + flag;
		res += (sum % 10) + '0';
		if (sum > 9)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	if (size1 > size2)
	{
		for (i; i < size1; ++i)
		{
			int s1 = str1[i] - '0';
			int sum = s1  + flag;
			res += (sum % 10) + '0';
			if (sum > 9)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
	}
	else
	{
		for (i; i < size2; ++i)
		{
			int s2 = str2[i] - '0';
			int sum = s2 + flag;
			res += (sum % 10) + '0';
			if (sum > 9)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
	}
	if (flag == 1)
	{
		res += '1';
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		Solution2(str1, str2);
	}
	return 0;
}
