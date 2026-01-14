class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, votes = 0;  // x: 最終的な多数要素, votes: 現在の投票数
        for(auto p:nums){
            if(votes == 0) x = p;  // 投票数が0のとき、新しい候補者xを選ぶ
            votes = votes + (p == x ? 1 : -1);  // xと一致したら+1、違ったら-1
        }
        return x;  // 最終的に残った多数要素を返す
    }
};
