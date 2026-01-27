#include <iostream>
using namespace std;

int main() {
  int n;
  while(cin>>n){
    //分上半部分 和 下半部分
    for(int i= 1;i<=n;i++){
        //然后针对每一行 进行输出
        //先是空格
        for(int s = 0;s<n-i;s++){
            cout<<" ";
        }
        //再是递增的数据
        for(int k = 1;k<=i;k++){
            cout<<k;
        }
        //再是递减的数据
        for(int k = i-1;k>0;k--){
            cout<<k;
        }
        cout<<endl;
    }
    //然后是下半部分
    for(int i=1;i<n;i++){
        //然后针对每一行输出

        //先是空格
        for(int s = 0;s<i;s++){
            cout<<" ";
        }
        //再是递增的数据
        for(int k=1;k<=n-i;k++){
            cout<<k;
        }
        //再是递减的数据
        for(int k = n-i-1;k>0;k--){
            cout<<k;
        }
        cout<<endl;
    }

  }
  return 0;
}
