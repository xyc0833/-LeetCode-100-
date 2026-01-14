class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3種類の色分け問題（Dutch National Flag問題）
        // 0（赤）、1（白）、2（青）を左から順に並べる
        // 手法：3つのポインタ（left, i, right）を使ったスワップ

        int left = 0;               // 左ポインタ：次に0を配置する位置
        int right = nums.size() - 1; // 右ポインタ：次に2を配置する位置
        int i = 0;                  // 現在走査中の位置

        // 走査は右ポインタが追い越すまで続ける
        while (i <= right) {
            if (nums[i] == 0) {
                // 現在値が0の場合：左ポインタと交換
                swap(nums[i], nums[left]);
                ++i;    // 次の位置へ進む
                ++left; // 左ポインタを右に移動
            } 
            else if (nums[i] == 2) {
                // 現在値が2の場合：右ポインタと交換
                swap(nums[i], nums[right]);
                --right; // 右ポインタを左に移動
                // 注意：iはインクリメントしない！
                // （交換後のnums[i]は未確認のため、次ループで再チェック）
            } 
            else {
                // 現在値が1の場合：そのまま次へ進む
                ++i;
            }
        }
    }
};