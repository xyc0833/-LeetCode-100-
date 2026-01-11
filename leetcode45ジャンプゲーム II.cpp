class Solution {
public:
    int jump(vector<int>& nums) {
        // 配列の長さが1の場合、ジャンプの必要なし（既に終点にいる）
        if(nums.size() == 1) return 0;
        
        // 現在のジャンプで到達可能な最遠位置
        int curDistance = 0;
        // ジャンプ回数をカウントする変数
        int ans = 0;
        // 次のジャンプで到達可能な最遠位置
        int nextDistance = 0;
        
        // 配列の全要素を走査（終点まで到達したらループを抜ける）
        for(int i = 0; i < nums.size(); i++) {
            // 次のジャンプで到達可能な最遠位置を更新
            nextDistance = max(nextDistance, nums[i] + i);
            
            // 現在の位置が現在のジャンプ範囲の終点に達した場合
            if(i == curDistance) {
                // ジャンプ回数を増やす
                ans++;
                // 現在のジャンプ範囲を次のジャンプ範囲で更新
                curDistance = nextDistance;
                
                // 次のジャンプ範囲が既に終点を超えている場合、ループを抜ける
                if(nextDistance >= nums.size() - 1) break;
            }
        }
        
        // 最少ジャンプ回数を返す
        return ans;
    }
};