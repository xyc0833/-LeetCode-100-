class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 短い配列に対して二分探索を行うため、nums1 と nums2 を入れ替える（if needed）
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        
        // 二分探索の目標：nums1 で分割位置 i を見つけ、nums2 の分割位置 j を計算する
        // 条件：maxLeft1 <= minRight2 && maxLeft2 <= minRight1
        while(left <= right){
            int i = (left + right) / 2; // nums1 の分割位置（二分探索の mid 相当）
            int j = (m + n + 1) / 2 - i; // nums2 の分割位置（公式による計算）
            
            // nums1 の分割線左右の値を取得
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i-1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            // nums2 の分割線左右の値を取得
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j-1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // 分割線が条件を満たしているかチェック
            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1){
                // 合計長さが奇数の場合、左側の最大値が中央値
                if((m + n) % 2 == 1){
                    return max(maxLeft1, maxLeft2);
                } else { // 合計長さが偶数の場合、左側最大値と右側最小値の平均
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
            } else if(maxLeft1 > minRight2){ // 分割線を左に移動
                right = i - 1;
            } else { // 分割線を右に移動
                left = i + 1;
            }
        }
        return 0; // 念のため（実際には到達しない）
    }
};