#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //使用数组来记录映射关系 
    //这个初始化为0 非常关键
    vector<int> nums = vector<int>(30,0);
    int n,a,b;
    while(cin>>n){
        while(n--){
            cin>>a>>b;
            //记录映射关系
            nums[a] = b;
        }
        int len_ming = 0,len_yu = 0;
        //小明编号为1
        //类似 1 → 3 → 5 → 6 → 0 这样找祖先 
        //找到0的时候停止
        int ming = nums[1];
        while(ming != 0){
            ming = nums[ming];
            len_ming++;
        }
        //小宇的编号为2
        int yu = nums[2];
        while(yu !=0){
            yu = nums[yu];
            len_yu++;
        }
        if(len_ming>len_yu) cout<<"You are my elder"<<endl;
        else if(len_ming == len_yu) cout<<"You are my brother"<<endl;
        else cout << "You are my younger" << endl;
    }
    return 0;
}