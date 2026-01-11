class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // C++での最小ヒープの定義方法を学ぶ
        // 優先度キュー(priority_queue)を使用して実装
        // priority_queueでgreater<int>を使用すると、
        // キューは昇順にソートされる（つまり最小の要素がヒープの頂点に来る）
        // ここでは最小ヒープを使用して、上位k個の要素を保持する
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // 配列の各要素を処理する
        for(auto p : nums) {
            // ヒープのサイズがk未満の場合、要素を追加
            if(minHeap.size() < k) {
                minHeap.push(p);
            } 
            // 現在の要素がヒープの最小要素（頂点）より大きい場合
            else if(p > minHeap.top()) {
                // 最小要素を削除
                minHeap.pop();
                // 現在の要素を追加
                minHeap.push(p);
            }
        }
        
        // ヒープの頂点要素（k番目に大きい要素）を返す
        return minHeap.top();
    }
};