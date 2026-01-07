class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (right + left )/2;
            // もし単調増加する区間なら、一番左の値を直接返す
            if(nums[left]<=nums[mid] && nums[mid] <=nums[right]){
                return nums[left];
            }else if(nums[left]<=nums[mid]){
                // 左半分が整列している場合、最小値は右半分にある
                left = mid + 1 ;
            }else if(nums[mid]<=nums[right]){
                // 右半分が整列している場合、最小値は左半分にある（mid自体が最小値の可能性もある）
                right = mid; // midは最小値の可能性があるため、-1せずにそのまま設定
            }
        }
        return -1; // ここには到達しないはず（入力配列は常に最小値を持つ）
    }
};