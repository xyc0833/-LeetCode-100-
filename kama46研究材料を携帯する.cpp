#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, bagweight;
    cin >> n >> bagweight;
    vector<int> weight(n, 0); // 各アイテムの重量を格納
    vector<int> value(n, 0);  // 各アイテムの価値を格納

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    // dp[i][j] は、容量 j のバッグで、アイテム 0 から i までの任意の組み合わせで得られる最大価値を表す
    // i はアイテムの数、j はバッグの容量
    // バッグの容量は bagweight だが、0 から bagweight までのすべての容量（0 と bagweight を含む）を表現する必要がある
    // 例えば、bagweight = 5 の場合、可能なバッグ容量は 0, 1, 2, 3, 4, 5 の 6 個の値（つまり bagweight + 1）
    vector<vector<int>> dp(n, vector<int>(bagweight + 1, 0));

    // 初期化：dp[i-1] の値を利用するため
    // j < weight[0] の場合（バッグ容量が 0 の場合はすでに 0 に初期化されている）
    // j >= weight[0] の場合（バッグ容量がアイテム 0 の重量以上の場合は価値を更新）
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // 動的計画法開始：アイテムを先に遍歴し、バッグ容量を後に遍歴する（順序は逆でも可）
    // i = 0 の場合はすでに初期化されているので、1 から開始
    for (int i = 1; i < weight.size(); i++) { // アイテムを遍歴
        for (int j = 0; j <= bagweight; j++) { // 容量を遍歴
            // アイテムが入らない場合は、dp[i-1][j] を継承
            // アイテムが入る場合は、推論式を参照
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    // 最終的に、dp[n-1][bagweight] が最適解（最大価値）
    cout << dp[n - 1][bagweight] << endl;
    return 0;
}