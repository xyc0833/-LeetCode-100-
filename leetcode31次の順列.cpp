class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // まず、インデックスを定義する
        int i;
        // 配列を逆順にトラバース
        for(i = nums.size()-1;i>=0;i-- ){
            // iを境界として、候補集合の範囲を区別する
            // 候補集合の範囲はiからnums.size()まで
            // 候補集合の要素は、常に降順を保証している
            // 現在のiより大きな要素が候補集合にあるかを確認する
            // そのため、逆順にトラバースを行う
            if(i+1<nums.size() && nums[i]<nums[i+1]){
                for(int j = nums.size()-1;j>i;j--){
                    if(nums[j]>nums[i]){ // i位置より大きい最初の要素を見つけた
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                break;
            }
        }
        // 候補集合の要素は左から右にかけて降順で並んでいるので、反転が必要
        int left = i+1;
        int right = nums.size()-1;
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
};
