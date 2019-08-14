#include<iostream> 
using namespace std; 
int ConventionNo(const int& a, const int& b) 
{ 
	for(int i = a; i > 0; --i) 
	{ 
		if(b % i == 0 && a % i == 0) 
		{ 
			return i; 
		} 
	}
	return 0; 
}
void Solution(const int& n, int& a) 
{ 
	int data;//怪物数据 
	int* arr = new int[n]; 
	for(int i = 0; i < n; ++i) 
	{ 
		cin >> data; 
		arr[i] = data; 
	}
	for(int i = 0; i < n; ++i)//开始打怪 
	{ 
		if(a >= arr[i]) 
		{ 
			a += arr[i]; 
		}
		else 
		{ 
			a += ConventionNo(a,arr[i]); 
		} 
	}
	cout << a << endl; 
}
int main() 
{ 
	int n;//怪物数量 
	int a;//初始值 
	while(cin >> n >> a) 
	{ 
		Solution(n,a); 
	}
	return 0; 
}





#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    string str;

    while(cin >> str)
    {
       int flag = 0;
        map<char, int> m;
        for(const auto& c : str)
            ++m[c];
        for(const auto& c : str)
        {
            if(m[c] == 1)
            {
                cout << c << endl;
                ++flag;
                break;
            }
        }
    if(flag == 0)
        cout << -1 << endl;
    }
    return 0;
}
