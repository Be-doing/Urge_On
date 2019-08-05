//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。
//请设计一个算法，求出a和b点的最近公共祖先的编号。
//
//给定两个int a, b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        while(a != b)
        {
            a > b ? a /= 2 : b /= 2;
        }
        return a;
    }
};

//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//
//	输入 : 一个byte型的数字
//
//	输出 : 无
//
//	返回 : 对应的二进制数字中1的最大连续数
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
    int max = 0;
    while(n)
    {
        if(n & 1)
        {
            ++count;
            if(count > max)
                max = count;
        }
        else
            count = 0;
        n = n >> 1;
    }
    cout << max << endl;
    }
        return 0;
}
