class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 結果を保存する変数（最大利益）
        int result = 0;
        // これまでの最小値を保存する変数、初期値は最初の日の価格
        int minprice = prices[0];
        
        // 全ての日付の価格をループでチェック
        for(int i=0; i<prices.size(); i++){
            // 現在の価格とこれまでの最小値を比較し、最小値を更新
            minprice = min(prices[i], minprice);
            // 現在の価格から最小値を引いた利益と、これまでの最大利益を比較し、最大値を更新
            result = max(result, prices[i] - minprice);
        }
        
        // 計算した最大利益を返す
        return result;
    }
};