class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 排他論理和(XOR)演算を使用する
        // XOR演算の特性：
        // 1. 任意の数と0のXORはその数自身: a ^ 0 = a
        // 2. 任意の数とその数自身のXORは0: a ^ a = 0
        // 3. XOR演算は交換法則が成立: a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b
        // これらの特性を利用すると、配列中の数を全てXORすると、
        // 2回登場する数は0になり、最後に残るのは1回しか登場しない数となる
        
        int k = 0;  // 初期値は0（0はXORの単位元）
        
        // 配列内の全ての要素に対してXOR演算を適用する
        for(auto p : nums){
            k = k ^ p;  // 累積的にXORを取っていく
        }
        
        // 最終的にkには1回だけ登場する数が格納される
        return k;
    }
};