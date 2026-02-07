//最终参考学习的写法 自己容易理解的写法
#include<bits/stdc++.h>
using namespace std;

//学习写外置函数的写法
string leftShift(const string& t,long long p ){
//&取地址符保证直接操作原字符串提高效率
//const 保证是常量 保证字符串在函数内不被修改
    if(t.empty() || p<=0){
        return t;
    }
    long long len = t.size();
    //取模避免p超过长度
    long long shift = p % len;
    string front = t.substr(0,shift);
    string back = t.substr(shift);
    return back + front;
}

int main(){
    //加速输入输出的 方法 
    ios::sync_with_stdio(false);
    //解除 C++ 标准流（cin/cout）和 C 标准流（scanf/printf）的同步关系。
    cin.tie(nullptr);
    //解除 cin 和 cout 的绑定关系
    //tie() 函数的作用是将一个流绑定到另一个流
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        string t = "";
        //改用long long 避免数字溢出
        long long p = 0;
        for(auto c: s){
            //处理数字字符
            //isdigit(c)
            if(c>='0' && c<='9'){
                int x = c -'0';
                if(p == 0){
                    p = x;
                }else{
                    p = 10*p +x;
                }
            }
            //处理字符
            if((c>='A' && c<='Z') || (c>='a' && c<='z')){
                //第一步 执行左移操作
                t = leftShift(t,p);
                //第二步 重置p为0
                p = 0;
                //第三步 处理字符
                if(c == 'R'){
                    reverse(t.begin(),t.end());
                }else{
                    t = t+c;//追加字符
                    //t.push_back(c);
                }
            }
        }
        cout<<t<<endl;
    }


    return 0;
}

//豆包给的答案

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 字符串左移p位：前p个字符移到末尾
string leftShift(const string& t, long long p) {
    if (t.empty() || p <= 0) return t;
    long long len = t.size();
    long long shift = p % len; // 取模避免p超长
    return t.substr(shift) + t.substr(0, shift);
}

int main() {
    ios::sync_with_stdio(false); // 加速输入输出
  //关闭 iostream（也就是 cin/cout）和 stdio（也就是 scanf/printf）的同步
    cin.tie(nullptr);
 // nullptr 是 “空指针”，这行代码表示 “把 cin 的绑定对象设为空”，也就是解除 cin 和 cout 的绑定。
//大白话：不用每次读输入前都刷新输出缓冲区了，进一步节省时间。
    
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string t = "";
        long long p = 0; // 改用long long避免数字溢出
        
        for (char c : s) {
            if (isdigit(c)) { // 处理数字字符
                int x = c - '0';
                if (p == 0) {
                    p = x; // p=0时直接赋值
                } else {
                    p = 10 * p + x; // 拼接数字
                }
            } else { // 处理非数字字符
                // 第一步：执行左移操作
                t = leftShift(t, p);
                // 第二步：重置p为0
                p = 0;
                // 第三步：处理字符（严格匹配大写R）
                if (c == 'R') {
                    reverse(t.begin(), t.end());
                } else {
                    t.push_back(c); // 追加字符
                }
            }
        }
        cout << t << endl;
    }
    return 0;
}

//第二版
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        //cout<<s<<endl;
        string t;//解密字符串
        int p = 0;//记录位移的字符串
        for(int i=0;i<s.size();i++){
            //cout<<s[i]<<endl;
            //如果是数字
            if(s[i]>='0'&& s[i]<='9'){
                if (p == 0){
                    p = s[i]-'0';//变成数字的值 
                    //cout<<p<<endl;
                }
                if(p !=0 ){
                    p = p *10 + (s[i]-'0');
                    //cout<<p<<endl;
                }
            }
            //如果是字符
            if((s[i]>='A' &&s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
                //先这么写着
                if(p !=0){
                   if(t.size()!=0){
                    //前面的操作 p可能会远远大于t.size()所以 这里p需要取模
                    p = p % t.size(); //防止p>t.size();
                    //左移
                    string front = t.substr(0,p);
                    string back = t.substr(p);
                    t = back + front;
                   }
                    //然后将p置为0;
                    p = 0;
                }
                if(s[i] == 'R') {
                    reverse(t.begin(),t.end());
                    //cout<<t<<endl;
                }else{ //若字符不为R，则直接将这个字符添加到字符串t的结尾
                    t = t + s[i];
                }
            }
        }
        //在遍历字符串时，p 可能在数字字符后累积，但未在遇到字母时触发左移（例如字符串末尾是数字）
        if(p !=0 && t.size()!=0){
            p = p % t.size();
            string front = t.substr(0,p);
            string back = t.substr(p);
            t = back + front;
        }
        cout<<t<<endl;
        

    }
    return 0;
}

//自己写的有问题的代码 先备份一下
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        //cout<<s<<endl;
        string t;//解密字符串
        int p = 0;//记录位移的字符串
        for(int i=0;i<s.size();i++){
            //cout<<s[i]<<endl;
            //如果是数字
            if(s[i]>='0'&& s[i]<='9'){
                if (p == 0){
                    p = s[i]-'0';//变成数字的值 
                    //cout<<p<<endl;
                }
                if(p !=0 ){
                    p = p *10 + (s[i]-'0');
                    //cout<<p<<endl;
                }
            }
            //如果是字符
            if((s[i]>='A' &&s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
                //先这么写着
                if(t.size()>0 && t.size()>=p && p !=0){
                    //cout<<s[i]<<endl;
                    //先进行左移操作
                    //substr(i, len) 截取字符串 包左不包右 substr(i)从当前位置截取到最后
                    //应该是对字符串t左移吧
                    string front = t.substr(0,p);
                    string back = t.substr(p);
                    t = back + front;
                    //缺少考虑了一个问题
                    //在 t 为空字符串时尝试调用 t.substr(0, p)，而 p 可能大于 t.size()（即 0）
                    //cout<<t<<endl;

                    //然后将p置为0;
                    p = 0;
                    if(s[i] == 'R') {
                        reverse(t.begin(),t.end());
                        //cout<<t<<endl;
                    }
                }
                // if(s[i] == 'R') {
                //     reverse(t.begin(),t.end());
                //     //cout<<t<<endl;
                // }else{ //若字符不为R，则直接将这个字符添加到字符串t的结尾
                //     t = t + s[i];
                // }
                if(s[i] != 'R'){
                    t = t + s[i];
                }

            }
        }
        cout<<t<<endl;
        
        
        //字符串左移 
        //substr(i, len) 截取字符串 包左不包右 substr(i)从当前位置截取到最后
    }
    return 0;
}
