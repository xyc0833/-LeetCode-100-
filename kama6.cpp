#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a;
    //输入多组数据
    while(cin>>n){
        //每组数据都有n行
        while(n--){
            cin>>m; //再输入每组头一个数
            int sum = 0;
            //每行有m个
            while(m--){
                cin>>a;
                sum = sum + a;
            }
            cout<<sum<<endl;
            //当n>0时 多输出一行
            //也就是说 最后一行时 n为0
            if(n>0) cout<<endl;
        }
    }
    return 0;
}