#include<iostream>
using namespace std;

//Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
//在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，
//你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，
//现在给你一个数N求最少需要多少步可以变为Fibonacci数



//输入一个数，找到离它最近的两个斐波那契数，比较距离之后输出
//创建一个返回实现斐波那契数的函数
//在第一个大于它的数停下来
#include<iostream>
using namespace std;

int main()
{
    int res;//结果
    int min;//小的斐波那契数
    int max;//大的斐波那契数
    int num;//输入的数
    
    cin >> num;
    int f0 = 0;
    int f1 = 1;
    int fi;
    while(1)
    {
        fi = f0 + f1;
        f0 = f1;
        f1 = fi;
        if(num < fi)
        {
            min = num - f0;
            max = f1 - num;
            break;
        }
    }
    res = max > min ? min : max;
    cout << res << endl;
    return 0;
}

#include<stack>
//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        if(n == 0)
            return false;
        stack<char> s;
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] == '(')
                s.push(A[i]);
            else if(A[i] == ')')
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else
                    return false;
            else
                return false;
        }
            return true;
    }
};
