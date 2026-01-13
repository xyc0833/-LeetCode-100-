class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nums_len = nums.size();
        int max_res = INT_MIN;  // 最大結果を初期化（INT_MIN は最小整数値）
        long long cur_max = 1, cur_min = 1;  // 現在の最大積と最小積（1 で初期化）
        for (int i = 0; i < nums_len; i++) {
            // 前回の cur_max と cur_min を保存（cur_min 更新時に最新の cur_max を使わないように）
            long long temp_max = cur_max, temp_min = cur_min;
            // 状態遷移式（現在の最大積と最小積を更新）
            cur_max = max(max(temp_max * nums[i], temp_min * nums[i]), (long long)nums[i]);
            cur_min = min(min(temp_max * nums[i], temp_min * nums[i]), (long long)nums[i]);
            if (cur_min < INT_MIN) {
                cur_min = INT_MIN;  // 最小値の下限を INT_MIN に制限（冗長だが安全のため）
            }
            // 全局最大値を更新
            max_res = max(max_res, (int)cur_max);
        }
        return max_res;  // 最大積を返す
    }
};