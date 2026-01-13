class Solution {
public:
    int longestValidParentheses(string s) {
        // スタックを使用した解法
        stack<int> st; // スタックにはインデックスを格納する
        vector<bool> marks(s.length(), false); // 有効な括弧の位置をマークする配列

        // 文字列を1文字ずつ処理する
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                // '('の場合はインデックスをスタックにプッシュ
                st.push(i);
            } else {
                // ')'の場合
                if(st.size() != 0) {
                    // スタックが空でない場合、対応する'('がある
                    int j = st.top(); // '('のインデックスを取得
                    st.pop(); // スタックから取り除く
                    marks[i] = true; // 現在の')'を有効としてマーク
                    marks[j] = true; // 対応する'('を有効としてマーク
                }
                // スタックが空の場合は無効な')'なので何もしない
            }
        }    

        // マークされた有効な括弧の連続する最大長を計算する
        int maxLen = 0; // 最大長
        int curLen = 0; // 現在の連続長
        for(auto p : marks) {
            if(p == true) {
                // 有効な括弧の場合はカウントを増やす
                curLen = curLen + 1;
                maxLen = max(curLen, maxLen); // 最大長を更新
            } else {
                // 無効な部分が現れたらカウントをリセット
                curLen = 0;
            }
        } 
        return maxLen; // 最大長を返す
    }
};