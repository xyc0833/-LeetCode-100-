//自己不太好的写法
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    // do{
    //     cin>>a>>b;
    //     cout<<a+b<<endl;
    // }while(a == 0 && b == 0);
        do{
        cin>>a>>b;
        if(a == 0 && b == 0 ){
            break;
        }
        cout<<a+b<<endl;
        
    }while(true);

    return 0;
}

//标准正确写法
#include<iostream>
using namespace std;
int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        cout << a + b << endl;
    }
}