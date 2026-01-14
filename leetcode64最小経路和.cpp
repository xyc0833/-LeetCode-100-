class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] は (0, 0) から (i, j) までの最小パス和を表す
        // ここでは grid 配列を直接更新して DP テーブルとして使用する
        if(grid.size() == 0) return 0; // 空のグリッドの場合は 0 を返す
        int m = grid.size();    // 行数
        int n = grid[0].size(); // 列数

        // 第一行の初期化：左端のセルから右に向かって累積和を計算
        // (0, 0) から右に移動する場合、上方向は存在しないため、左のセルの値を加算するのみ
        for(int j = 1; j < n; j++){
            grid[0][j] = grid[0][j-1] + grid[0][j];
        }

        // 第一列の初期化：上端のセルから下に向かって累積和を計算
        // (0, 0) から下に移動する場合、左方向は存在しないため、上のセルの値を加算するのみ
        for(int i = 1; i < m; i++){
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }

        // 残りのセルを埋める：上と左のセルの最小値に現在のセルの値を加算
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                // 上から来るパス (i-1, j) と左から来るパス (i, j-1) の最小値を選択
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }

        // 右下のセル (m-1, n-1) が最小パス和を表す
        return grid[m-1][n-1];
    }
};