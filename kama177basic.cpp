#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int,vector<int> > map;
    int n,m,s,t;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>s>>t;
        map[s].push_back(t);
    }
    for(auto abc : map){
        int x = abc.first;
        cout<<x<<"-> ";

        vector<int> k = abc.second;
        for(auto x:k){
            cout<<x<<' ';
        }
        cout<<endl;
    }

    return 0;
}