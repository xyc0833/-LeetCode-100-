class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 現在の位置から到達可能な最遠位置を記録する変数
        int cover = 0;
        
        // ループの範囲は現在の到達可能範囲内（i <= cover）
        for(int i = 0; i <= cover; i++) {
            // 現在の位置iからジャンプした場合の最遠到達位置を更新
            cover = max(cover, i + nums[i]);
            
            // 最遠到達位置が配列の末尾を超えたら成功
            if(cover >= nums.size() - 1) return true;
        }
        
        // ループが終了しても末尾に到達できなかった場合は失敗
        return false;
    }
};