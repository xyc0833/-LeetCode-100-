class Solution {
public:
    string decodeString(string s) {
        stack<string> st; // 文字列と中間結果を格納するスタック
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ']') { // s[i]はchar型
                string tmp; // char型をstring型に変換する必要がある
                tmp = tmp + s[i];
                st.push(tmp);
            } else if(s[i] == ']') {
                string tmp;
                // '['が出てくるまでスタックのトップをポップして文字列を構築
                while(st.top() != "[") {
                    tmp = st.top() + tmp; // 順序を保つために前に追加
                    st.pop();
                }
                st.pop(); // 左括弧 '[' もポップする

                // 数字部分の処理
                string num;
                // スタックのトップが数字文字かどうかを判断（[0]で先頭文字を取得）
                while(st.size() != 0 && isdigit((st.top())[0])) {
                    num = st.top() + num; // 数字文字列を逆順で構築（後でstoiで正しく解析できるように）
                    st.pop();
                }
                string str;
                int cnt = stoi(num); // 文字列を整数に変換（string to integer）
                while(cnt != 0) {
                    str = str + tmp; // 文字列を繰り返し追加
                    cnt = cnt - 1; 
                }
                st.push(str); // 処理後の文字列をスタックにプッシュ
            }
        }
        string res;
        // スタックに残っている文字列を順番に結合（スタックは逆順に格納されているため）
        while(st.size() != 0) {
            res = st.top() + res; // スタックのトップを先頭に追加
            st.pop();
        }
        return res;
    }
};