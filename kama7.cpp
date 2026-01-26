//先备份一下 代码有问题
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char,int> m;
    m['A'] = 4;
    m['B'] = 3;
    m['C'] = 2;
    m['D'] = 1;
    m['E'] = 0;
    string s;
    //怎么处理字符串的输入
    //这个是读取整行的用法  当然会包含空格
    while(getline(cin,s)){
        for(auto i=0;i<s.size();i = i + 2){
            int sum = 0;
            //直接读取的话 是有空格的 
            //空格也算在string里面 所以 i = i + 2
            //cout<<s[i]<<endl;
            if(m.find(s[i]) == true)//所以这个写法不对
                cout<<s[i]<<endl;
            
            auto search = data.find(str[i]);
            //等价于
            //map<char, int>::iterator search = data.find(str[i]);
            //search 是一个迭代器
            //如果要打印search的话 
            //cout << search->first << " : " << search->second << endl;

            //sum = sum + m[s[i]];
        }
    }

    // return 0;
}


//先记录一下 别人的代码

#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

map<char ,int> data = {
    {'A',4},
    {'B',3},
    {'C',2},
    {'D',1},
    {'F',0}
};


int main(){

  string str;
  while (getline(cin,str)){
    int count = 0;
    int num = 0;
    bool judge = false;
    for (int i = 0; i < str.size(); i = i + 2) {
      auto search = data.find(str[i]);
      if (search == data.end()){  //存在不规范字符
        judge = true;
        break;
      }
      count += data[str[i]];
      num++;
    }
    if (judge){
      cout<<"Unknown"<<endl;
      judge = false;
    }else{
      double result = (double)count / num;
      cout<<fixed<<setprecision(2)<<result<<endl;     //保留两位小数
    }
  }
  return 0;
}


//自己调试的代码 离目标越来越接近了

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,int> m;
    m['A'] = 4;
    m['B'] = 3;
    m['C'] = 2;
    m['D'] = 1;
    m['F'] = 0;
    string s;
   while(getline(cin,s)){
        int sum = 0;
        int k = 0;
        int avg = 0;
        for(int i=0;i<s.size();i = i + 2){
            
            //直接读取的话 是有空格的 
            //空格也算在string里面 所以 i = i + 2
            //cout<<s[i]<<endl;
            //if(m.find(s[i]) == true)//所以这个写法不对
                //cout<<s[i]<<endl;
            
            //auto search = data.find(str[i]);
            //等价于
            //map<char, int>::iterator search = data.find(str[i]);
            //search 是一个迭代器
            //如果要打印search的话 
            //cout << search->first << " : " << search->second << endl;

            //如果存在某个key找不到的话 直接输出unkown
            if(m.find(s[i]) == m.end()){
                //cout<<s[i]<<endl;
                cout<<"unkown"<<endl;
                //这个要不要加
                break;
            }
            sum = sum + m[s[i]];
            k = k + 1;
        }
        avg = sum/k;
        cout<<avg<<endl;
    }


  return 0;
}


1. setprecision 和 fixed 用法：

setprecision(n)：设置数字输出的总精度（即有效位数）。但如果和 fixed 一起使用时，它会设置输出的 小数点后位数。

fixed：强制以固定小数点的方式输出数字，而不是以科学计数法

#include <iostream>
#include <iomanip>  // 包含 setprecision 和 fixed
using namespace std;

int main() {
    double num = 3.14159;

    // 设置输出为固定小数点格式，并保留两位小数
    cout << fixed << setprecision(2) << num << endl;  // 输出: 3.14

    return 0;
}


//自己写的第一版代码 
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,int> m;
    m['A'] = 4;
    m['B'] = 3;
    m['C'] = 2;
    m['D'] = 1;
    m['F'] = 0;
    string s;
   while(getline(cin,s)){
        bool flag = true;
        double sum = 0;
        double k = 0;
        double avg = 0;
        for(int i=0;i<s.size();i = i + 2){
            //如果存在某个key找不到的话 直接输出unkown
            if(m.find(s[i]) == m.end()){
                //cout<<s[i]<<endl;
                cout<<"unkown"<<endl;
                flag = false;
                //这个要不要加
                //break;
            }
            sum = sum + m[s[i]];
            k = k + 1;
        }
        if(flag == true){
            avg = sum/k;
            cout<<fixed<<setprecision(2)<<avg<<endl;
        }else{
            //什么都不做
        }
    }
  return 0;
}

//还是有问题的

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,int> m;
    m['A'] = 4;
    m['B'] = 3;
    m['C'] = 2;
    m['D'] = 1;
    m['F'] = 0;
    string s;
   while(getline(cin,s)){
        bool flag = true;
        double sum = 0;
        double k = 0;
        double avg = 0;
        for(int i=0;i<s.size();i = i + 2){
            //如果存在某个key找不到的话 直接输出unkown
            if(m.find(s[i]) == m.end()){
                //cout<<s[i]<<endl;
                cout<<"Unknown"<<endl;
                flag = false;
                //这个要不要加
                //break;
            }
            sum = sum + m[s[i]];
            k = k + 1;
        }
        if(flag == true){
            avg = sum/k;
            cout<<fixed<<setprecision(2)<<avg<<endl;
        }else{
            //什么都不做
        }
    }
  return 0;
}


//正确答案

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,int> m;
    m['A'] = 4;
    m['B'] = 3;
    m['C'] = 2;
    m['D'] = 1;
    m['F'] = 0;
    string s;
   while(getline(cin,s)){
        bool flag = true;
        double sum = 0;
        double k = 0;
        double avg = 0;
        for(int i=0;i<s.size();i = i + 2){
            //如果存在某个key找不到的话 直接输出unkown
            if(m.find(s[i]) == m.end()){
                //cout<<s[i]<<endl;
                cout<<"Unknown"<<endl;
                flag = false;
                //这个要不要加
                break;
            }
            sum = sum + m[s[i]];
            k = k + 1;
        }
        if(flag == true){
            avg = sum/k;
            cout<<fixed<<setprecision(2)<<avg<<endl;
        }else{
            //什么都不做
        }
    }
  return 0;
}