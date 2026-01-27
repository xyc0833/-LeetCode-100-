//自己写的代码 暂时 不太对

#include<bits/stdc++.h>
using namespace std;
int main(){
    char x;
    int n;
    while(cin>>x>>n){
        if(x == '@') break;
        //k代表底边长
        int k = 2 * n - 1;
        //首行和尾行 需要特殊处理
        //首行处理
        for(int i=0;i<k/2;i++) cout<<" ";
        cout<<x<<endl;
        //中间处理
        for(int i=2;i<=n-1;i++){
            //需要两层循环打印输出
            //先输出空格
            for(int j = 2;j<=(n-i);j++){
                cout<<" ";
            }
            cout<<x;
            //再输出空格
            for(int j=0;j<(k-2*(n-i)-2);j++){
                cout<<" ";
            }
            cout<<x<<endl;
        }
        //尾行处理
        for(int i=0;i<k;i++){
            cout<<x;
        }
        cout<<endl<<endl;
    }

    return 0;
}

//正确答案

前面少了 n==1 的情况
#include<bits/stdc++.h>
using namespace std;
int main(){
    char x;
    int n;
    while(cin>>x>>n){
        //前面少了 n==1的情况
        if (n == 1) {
            cout << x << endl << endl;
            continue;
        }
        if(x == '@') break;
        //k代表底边长
        int k = 2 * n - 1;
        //首行和尾行 需要特殊处理
        //首行处理
        for(int i=0;i<k/2;i++) cout<<" ";
        cout<<x<<endl;
        //中间处理
        for(int i=2;i<=n-1;i++){
            //需要两层循环打印输出
            //先输出空格
            for(int j = 0;j<n-i;j++){
                cout<<" ";
            }
            cout<<x;
            //再输出空格
            for(int j=0;j<(k-2*(n-i)-2);j++){
                cout<<" ";
            }
            cout<<x<<endl;
        }
        //尾行处理
        for(int i=0;i<k;i++){
            cout<<x;
        }
        cout<<endl<<endl;
    }

    return 0;
}