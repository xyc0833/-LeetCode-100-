class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //1 dp配列のインデックスと意味は？
        //2 dp配列の漸化式を確定する
        //3 初期化方法は？
        //4 ループの順序は？
        //5 dp配列を出力する
        //0-1ナップサック問題：アイテムを先に処理し、次にナップサックの容量を処理する
        //ナップサックの容量は逆順でループしなければならない。各アイテムを1回だけ入れるため。
        //もし順序通りにループすると、各アイテムを複数回入れることになってしまう。
        int sum = 0;
        // dp[i]のiはナップサック内の合計値を表す
        // 問題文によると：配列内の各要素は100を超えず、配列のサイズは200を超えない
        // したがって、合計値は20000を超えない。ナップサックの最大容量はその半分でよいため、10001で十分である
        vector<int> dp(10001, 0);
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        if(sum %2 ==1) return false; // 合計が奇数の場合は分割できない
        int target = sum/2;
        for(int i=0;i<nums.size();i++){
            //各要素は重複して入れることができないため、逆順でループする
            for(int j = target;j>=nums[i];j--){
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target] == target) return true;
        return false;
    }
};