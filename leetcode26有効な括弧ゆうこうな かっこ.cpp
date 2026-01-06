#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // スタックを用意して、左括弧を一時保存する
        for(auto& p : s) {  // 文字列sの各文字を順にチェック
            // 現在の文字が左括弧の場合、スタックにプッシュ
            if(p == '(' || p == '{' || p == '[') {
                st.push(p);
            } 
            // 現在の文字が右括弧の場合、スタックのトップとマッチするかチェック
            else if(st.size() != 0 && isMatch(st.top(), p) == true) {
                st.pop();  // マッチしたらスタックのトップをポップ
            } 
            else {
                return false;  // スタックが空の場合 or マッチしない場合はfalse
            }
        }
        // ループ終了後、スタックが空なら全ての括弧がマッチしている
        return st.size() == 0;
    }

    // 左括弧と右括弧が対応するか判定するヘルパー関数
    bool isMatch(char& left, char& right) {
        if(left == '(' && right == ')') return true;  // () が対応
        if(left == '[' && right == ']') return true;  // [] が対応
        if(left == '{' && right == '}') return true;  // {} が対応
        return false;  // それ以外は対応しない
    }
};