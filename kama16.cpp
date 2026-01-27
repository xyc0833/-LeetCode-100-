#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    
    cin>>n;
    //养成良好的编程习惯 
    //吸收一个回车
    getchar();
    while(n--){
        cin>>s;
        char tmp;

        for(int i=0,j=i+1;i<s.size()-1,j<s.size();i=i+2,j=j+2){
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
        cout<<s<<endl;
    }

    return 0;
}