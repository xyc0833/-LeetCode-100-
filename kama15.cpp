#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string a,b;
        string res;
        cin>>a>>b;
        //计算第一个数组的中间值
        int n = a.size()/2;
        //cout<<n;
        //先放a的前半
        for(int i=0;i<n;i++){
            res = res + a[i];
        }
        //然后放b
        res = res + b;
        //然后放a的后半
        for(int i = n;i<a.size();i++){
            res = res + a[i];
        }
        cout<<res <<endl;
    }

    return 0;
}