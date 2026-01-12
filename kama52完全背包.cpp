#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, bagweight; // n: 物品の個数, bagweight: バッグの容量
    cin >> n >> bagweight;

    vector<int> weight(n, 0); // 各物品の重量
    vector<int> value(n, 0);  // 各物品の価値
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i]; // 物品の重量と価値を入力
    }

    // DPテーブルの定義
    // dp[i][j]: i番目までの物品から選び、バッグ容量jのときの最大価値
    vector<vector<int>> dp(n, vector<int>(bagweight + 1, 0));

    // 初期化（最初の物品のみ考慮）
    // 完全背包問題なので、重量が許す限り同じ物品を複数回選べる
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = dp[0][j - weight[0]] + value[0]; // 最初の物品を繰り返し追加
    }

    // DPテーブルの更新
    for (int i = 1; i < n; i++) {          // 物品を1つずつ追加
        for (int j = 0; j <= bagweight; j++) { // バッグ容量を0から順に考慮
            if (j < weight[i]) {
                // 現在の物品iの重量がバッグ容量jを超える場合
                // 物品iを選べないので、前の状態（i-1番目までの結果）を引き継ぐ
                dp[i][j] = dp[i - 1][j];
            } else {
                // 物品iを選ぶ場合と選ばない場合の最大値を取る
                // dp[i-1][j]: 物品iを選ばない場合
                // dp[i][j - weight[i]] + value[i]: 物品iを選ぶ場合（完全背包なのでi番目の状態を参照）
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
            }
        }
    }

    // 最終的な結果は、n-1番目の物品まで考慮し、バッグ容量がbagweightのときの最大価値
    cout << dp[n - 1][bagweight] << endl;
    return 0;
}