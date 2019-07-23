// write your code here cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

void Solution(string& A, string& B)
{
	map<char, int> mA;
	map<char, int> mB;
	for (const auto& e : A)
	{
		++mA[e];
	}
	for (const auto& e : B)
	{
		++mB[e];
	}
	
	for (const auto& e : mB)
	{
		if (mA[e.first]>= e.second)
			continue;
		else
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		Solution(A, B);
	}
	return 0;
}