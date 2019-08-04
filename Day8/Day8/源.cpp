#include<string>
#include<vector>
#include<iostream>
using namespace std;
//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
//1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" < "doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
int main()
{
    int n;
    vector<string> v;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    bool notleng = false;
    bool notdic = false;
    for(size_t i = 1; i < v.size(); ++i)
    {
        if(v[i].size() < v[i - 1].size())
        {
            notleng = true;
        }
        if(v[i] < v[i - 1])
        {
            notdic = true;
            if(notleng)
                break;
        }
    }
    if(notleng && notdic)
        cout << "none";
    else if(!(notleng || notdic))
        cout << "both";
    else if (notleng)
        cout << "lexicographically";
    else
        cout << "lengths";
    return 0;
}




#include<iostream>
using namespace std;
//题目描述
//
//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
int main()
{
    int A,B;
    cin >> A >> B;
    int min, max;
    if(A > B)
    {
        min = B;
        max = A;
    }
    else
    {
        min = A;
        max = B;
    }
    for(int i = 1; i <= min; ++i)
    {
        int tmp = max * i;
        if(tmp % min == 0)
        {
            cout << tmp;
            return 0;
        }
    }
    return 0;
}
