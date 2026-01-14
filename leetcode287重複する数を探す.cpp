class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        // フロイドの循環検出アルゴリズム（ウサギとカメ）
        // 最初に、slowとfastは同じ位置からスタートします。
        while(true){
            slow = nums[slow];  // カメは1歩進む（遅いポインタ）
            fast = nums[nums[fast]];  // ウサギは2歩進む（早いポインタ）
            if(slow == fast) break;  // サイクルが見つかったらループを終了
        }

        fast = 0;  // fastを最初の位置に戻す

        // サイクルの開始位置を見つける
        while(true){
            slow = nums[slow];  // カメは1歩進む
            fast = nums[fast];  // fastも1歩進む
            if(slow == fast) return slow;  // カメとウサギが交差する位置が重複した要素
        }
        
        return slow;  // 重複した値を返す
    }
};
