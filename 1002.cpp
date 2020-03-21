#1002 写出这个数 (20 分)

读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10100。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789

输出样例：
yi san wu

作者: CHEN, Yue

单位: 浙江大学

时间限制: 400 ms

内存限制: 64 MB

代码长度限制: 16 KB
```cpp
#include<iostream>
using namespace std;

int main(){
    string input,zimu[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};;
    int b[105]={0},i=0,ans=0,ans_num[4];
    cin>>input;
    int len=(int)input.size();
    for(i=0;i<len;i++){
        b[i]=input[i]-'0';
    }
    for(i=0;i<len;i++){
        ans+=b[i];
    }
    for(i=0;ans;i++){
        int mid = ans%10;
        ans_num[i] = mid;
        ans /= 10;
    }
    for(int j = i-1;j>=0;j--){
        cout<<zimu[ans_num[j]];
        if (j!=0) {
            cout<<" ";
        }
    }
    return 0;
}
```
