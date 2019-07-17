//// write your code here cpp
//#include<iostream>
//#include<string>
//using namespace std;
//void Solution(string& name)
//{
//	string res;
//	for (size_t i = 0; i < name.size(); ++i)
//	{
//		if (name[i] == '_')
//		{
//			res += name[++i] - 32;
//		}
//		else
//		{
//			res += name[i];
//		}
//	}
//	cout << res << endl;
//}
//int main()
//{
//	string name;
//	while (cin >> name)
//		Solution(name);
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void Solution(string& name)
{
	string tmp;
	string res;
	reverse(name.begin(), name.end());
	for (size_t i = 0; i < name.size(); ++i)
	{
		while (i < name.size() && ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')))
		{
			tmp += name[i];
			++i;
		}
		reverse(tmp.begin(), tmp.end());
		res += tmp;
		tmp.clear();
		res += "";
	}
	cout << res << endl;
}
int main()
{
	string name;
	while (getline(cin, name))
	{
		Solution(name);
	}
}