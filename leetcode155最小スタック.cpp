#include <stack>
#include <utility> // for std::pair
#include <algorithm> // for std::min

using namespace std;

class MinStack {
private:
    // スタックの要素はペアで保持：
    // first: 実際の値
    // second: その時点での最小値
    stack<pair<int, int>> st;

public:
    MinStack() {
        // コンストラクタ（特に初期化処理は不要）
    }

    // 値をスタックにプッシュする
    void push(int val) {
        if (st.empty()) {
            // スタックが空の場合、最小値は自身の値
            st.push({val, val});
        } else {
            // スタックが空でない場合、最小値は現在の値と直前の最小値の小さい方
            st.push({val, min(val, st.top().second)});
        }
    }

    // スタックのトップ要素をポップする
    void pop() {
        st.pop();
    }

    // スタックのトップ要素を取得する
    int top() {
        return st.top().first;
    }

    // スタック内の最小値を取得する
    int getMin() {
        return st.top().second;
    }
};

/**
 * MinStack オブジェクトの使用例：
 * MinStack* obj = new MinStack();
 * obj->push(val);    // 値をプッシュ
 * obj->pop();        // トップ要素をポップ
 * int param_3 = obj->top();    // トップ要素を取得
 * int param_4 = obj->getMin(); // 最小値を取得
 */