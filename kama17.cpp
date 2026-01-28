//gpt做法
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<int> out(N);
        for (int i = 0; i < N; i++) {
            cin >> out[i];
        }

        stack<int> st;
        int cur = 1;   // 下一个要入栈的数
        bool ok = true;

        for (int i = 0; i < N; i++) {
            int x = out[i];

            // 如果栈顶不是想要的，就一直入栈
            while ((st.empty() || st.top() != x) && cur <= N) {
                st.push(cur++);
            }

            // 如果栈顶是 x，出栈
            if (!st.empty() && st.top() == x) {
                st.pop();
            } else {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}

//大佬的做法

#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];
int main(){
    int n;
    while(cin>>n){
        if(n == 0) break;
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        stack<int> st;
        //正常的方式模拟栈
        for(int i=1,j=0;i<=n;i++){
            st.push(i); //所以i从1开始
            while(st.size()!=0 && st.top()== a[j]){
                st.pop();
                j++;
            }
        }
        if(st.size() == 0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

    }

    return 0;
}