class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // 単調増加スタック（Monotonic Stack）
        stack<int> st; // st はインデックス（配列の添字）を格納する
        vector<int> result(t.size(), 0); // 結果配列を全て 0 で初期化
        st.push(0); // st に配列の最初のインデックス（0）を先に入れる
        for(int i = 1; i < t.size(); i++) { // スタックには既に 1 つの要素（インデックス）が入っている
            if(t[i] < t[st.top()]) { // ケース1：現在の温度 < スタックトップの温度
                st.push(i); // 現在のインデックスをスタックに追加
            } else if(t[i] == t[st.top()]) { // ケース2：現在の温度 == スタックトップの温度
                st.push(i); // 現在のインデックスをスタックに追加（同じ温度の場合も追加）
            } else {
                // ケース3：現在の温度 > スタックトップの温度
                while(st.size() != 0 && t[i] > t[st.top()]) {
                    result[st.top()] = i - st.top(); // スタックトップの要素に対して、待ち日数を計算
                    st.pop(); // スタックトップを取り出す（既に処理済み）
                }
                // 前で pop() した要素は、現在の温度より小さい
                // 単調増加スタックなので、現在のインデックスもスタックに追加する
                st.push(i);
            }
        }
        return result;
    }
};