#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    // 大根堆（最大堆）→ 左半部分の最大値を保持
    // 左側の大きな値を管理する（降順にソートされる）
    priority_queue<int, vector<int>, less<int>> small; 

    // 小根堆（最小堆）→ 右半部分の最小値を保持
    // 右側の小さな値を管理する（昇順にソートされる）
    priority_queue<int, vector<int>, greater<int>> large;

public:
    // コンストラクタ（初期化は何もしない）
    MedianFinder() {
    }

    // 数値を追加するメソッド
    void addNum(int num) {
        // 最初は大根堆（small）に挿入する
        small.push(num);

        // 大根堆の最大値が小根堆の最小値より大きい場合、調整が必要
        // （大根堆の最大値は小根堆の最小値より小さくなければならない）
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            large.push(small.top()); // 大根堆の最大値を小根堆に移動
            small.pop();            // 大根堆から削除
        }

        // 両方の堆のサイズ差が1を超えないように調整する
        // もし大根堆のサイズが大きすぎる場合
        if (small.size() > large.size() + 1) {
            large.push(small.top()); // 大根堆の最大値を小根堆に移動
            small.pop();            // 大根堆から削除
        }
        // もし小根堆のサイズが大きすぎる場合
        if (large.size() > small.size() + 1) {
            small.push(large.top()); // 小根堆の最小値を大根堆に移動
            large.pop();            // 小根堆から削除
        }
    }

    // 現在のデータストリームの中央値を返すメソッド
    double findMedian() {
        // 小根堆（large）の方が要素数が多い場合 → 右側が多いので最小値（top）が中央値
        if (large.size() > small.size()) {
            return large.top();
        }
        // 大根堆（small）の方が要素数が多い場合 → 左側が多いので最大値（top）が中央値
        if (small.size() > large.size()) {
            return small.top();
        }
        // 両方の堆のサイズが等しい場合 → 中央値は両方のtopの平均
        return (large.top() + small.top()) / 2.0;
    }
};

/**
 * 使用方法：
 * MedianFinder* obj = new MedianFinder(); // オブジェクトを生成
 * obj->addNum(num);                       // 数値を追加
 * double param_2 = obj->findMedian();     // 中央値を取得
 */