class Solution {
		//考虑溢出
	//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
	//但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
	//数值为0或者字符串不是一个合法的数值则返回0。
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        int sig = 1;
        size_t i = 0;
        if(str[0] == '-')
        {
            sig = -1;
            ++i;
        }
        else if(str[0] == '+')
        {
            sig = 1;
            ++i;
        }
        int res = 0;
        for(; i < str.size(); ++i)
        {
            res *= 10;
            if(str[i] < '0' || str[i] > '9')
                return 0;
            res = res + (str[i] - '0');
        }
	if (res < INT_MIN || res > INT_MAX)//这个其实带不带没区别，但是完善嘛
	{
		return 0;
	}
        return res * sig;
    }
};

#include<iostream>
using namespace std;
//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。
//每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。

//暴力求解法1：
bool Solution1()
{
	int w,h,res = 0; 
	cin >> w >> h; 
	vector<vector<int>> a; 
	a.resize(w); 
	for(auto& e : a) 
		e.resize(h, 1); 
		for(int i=0;i<w;i++) 
		{ 
			for(int j=0;j<h;j++) 
			{ 
			if(a[i][j]==1) 
			{ 
				res++; 
				if((i+2)<w) // 标记不能放蛋糕的位置 
					a[i+2][j] = 0; 
				if((j+2)<h) 
					a[i][j+2] = 0; 
			} 
		} 
	}
	cout << res;
}


//暴力求解2
bool Solution2()
{
	int W;
	int H;
	double R = 2;
	int count = 0;
	int cflag = 0;
	int rflag = 0;
	cin >> W >> H;
	if ((W < 1 || W > 1000) && (H < 1 || H > 1000))
	{
		return false;
	}
	if (W == 1 && H == 1)
	{
		cout << 1;
		return true;
	}
	for (int w = 0; w < W; ++w)
	{
		int h = 0;
		++rflag;
		if (rflag == 3 || rflag == 4)
		{
			h += 2;
			if (rflag == 4)
			{
				rflag = 0;
			}

		}
		for (h; h < H; ++h)
		{
			++cflag;
			++count;
			if (cflag == 2)
			{
				h += 2;
				cflag = 0;
			}
		}
	}
	cout << count;
	return true;
}
int main()
{
	Solution2();
	system("pause");
	return 0;
}
