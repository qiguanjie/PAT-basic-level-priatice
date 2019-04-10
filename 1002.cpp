1002 写出这个数 （20 分)
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10100。
输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
yi san wu
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int zimu(int x){
    switch (x) {
        case 0:
            printf("ling");
            return 0;
            break;
        case 1:
            printf("yi");
            return 0;
            break;
        case 2:
            printf("er");
            return 0;
            break;
        case 3:
            printf("san");
            return 0;
            break;
        case 4:
            printf("si");
            return 0;
            break;
        case 5:
            printf("wu");
            return 0;
            break;
        case 6:
            printf("liu");
            return 0;
            break;
        case 7:
            printf("qi");
            return 0;
            break;
        case 8:
            printf("ba");
            return 0;
            break;
        case 9:
            printf("jiu");
            return 0;
            break;
            
    }
    return 0;
}
int main(){
    string input;
    int b[105]={0};
    int geshu=0;
    int i=0;
    int ans=0;
    stack<int> s;
    cin>>input;
    int len=(int)input.size();
    for(i=0;i<len;i++){
        b[i]=input[i]-'0';
    }
    for(i=0;i<len;i++){
        ans+=b[i];
    }
    int m_ans=ans;
    while(m_ans){
        m_ans/=10;
        geshu++;
    }
    m_ans=ans;
    while(m_ans){
        s.push(m_ans%10);
        m_ans/=10;
    }
    zimu(s.top());
    s.pop();
    for(i=0;i<geshu-1;i++){
        printf(" ");
        zimu(s.top());
        s.pop();
    }
    return 0;
}
