//正统做法
class Solution {
public:
    //小顶堆
    class mycomparison{
        public:
            bool operator()(pair<int,int>& a,pair<int,int>& b){
                return a.second > b.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //为什么用小顶堆 （只对k个元素进行排序）
        //每次都会弹出最小的元素，遍历到后面就会留下较大的元素   
        unordered_map<int,int> map;
        for(auto p : nums)
            map[p]++;
        //用优先队列定义一个小顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> que;
        //用固定大小为k的小顶堆 扫描所有频率的数值
        for(auto p: map){
            que.push(p);
            if(que.size()>k) {
                que.pop();
            }
        }
        //如果要找出前k个高频元素 需要倒序输出
        vector<int> result(k);
        for(int i=k-1;i>=0;i--){
            result[i] = que.top().first;
            que.pop();
        }
        return result;

    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 頻度を統計する
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        // キーと値のペアを配列に格納する
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        // 頻度の降順でソートする
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        // 上位 k 個の数字を抽出する
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].first);
        }
        return result;
    }
};