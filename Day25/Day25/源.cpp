// write your code here cpp

//#include<iostream>
//#include<iomanip>
//#include<vector>
//using namespace std;
//
//void passwd(int n)
//{
//	vector<vector<int>> arr = { {1,1},{1,0} };
//	vector<vector<int>> tmp(arr);
//	vector<vector<int>> save(arr);
//	int sum = n - 1;
//	for (int i = 0; i < sum; ++i)
//	{
//		arr[0][0] = save[0][0] * tmp[1][0] + save[0][1] * tmp[1][0];
//		arr[0][1] = save[0][0] * tmp[0][1] + save[0][1] * tmp[1][1];
//		arr[1][0] = save[1][0] * tmp[0][0] + save[1][1] * tmp[0][1];
//		arr[1][1] = tmp[1][0] * tmp[0][1] + save[1][1] * tmp[1][1];
//		if (arr[0][0] > 9999)
//		{
//			arr[0][0] %= 10000;
//		}
//		save = arr;
//	}
//	cout << setfill('0') << setw(4) << arr[0][0];
//}
//
//int main()
//{
//	int n;
//	
//	while (cin >> n)
//	{
//		vector<int> arr;
//		int num;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> num;
//			arr.push_back(num);
//		}
//		for (auto e : arr)
//		{
//			passwd(e);
//		}
//		cout << endl;
//	}
//	return 0;
//}

// write your code here cpp

// write your code here cpp

// write your code here cpp

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int _fib(int n)
{
	int fb[10001];
	fb[0] = fb[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		fb[i] = fb[i - 1]%10000 + fb[i - 2]%10000;
	}
	return fb[n];
}
void passwd(int n)
{
	int res = _fib(n);
	cout << setfill('0') << setw(4) << res;
}

int main()
{
	int n;
	vector<int> fib(10001);
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 10001; i++)
		fib[i] = (fib[i - 1] % 10000 + fib[i - 2] % 10000) % 10000;
	while (cin >> n)
	{
		vector<int> arr;
		int num;
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			//printf("%4d", fib[num]);
			cout << setfill('0') << setw(4) << fib[num];
		}
		cout << endl;
	}
	return 0;
}