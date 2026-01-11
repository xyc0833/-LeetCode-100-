class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 26個のアルファベットの最も遠い出現位置を記録する配列
        // インデックス0対応'a'、1対応'b'、...、25対応'z'
        int tmp[27] = {0};
        
        // 文字列sを走査し、各文字の最も遠い出現位置を記録
        for(int i = 0; i < s.size(); i++) {
            tmp[s[i] - 'a'] = i; // 文字のASCIIコードから'a'を引き、インデックスとして使用
        }
        
        int left = 0;  // 現在のパーティションの開始位置
        int right = 0; // 現在のパーティションの最遠位置
        vector<int> result; // 結果を格納する配列
        
        // 文字列sを再度走査し、パーティションを分割
        for(int i = 0; i < s.size(); i++) {
            // 現在の文字の最遠出現位置と現在のrightを比較し、大きい方をrightに設定
            right = max(right, tmp[s[i] - 'a']);
            
            // 現在の位置iがrightに達した場合、パーティションを分割
            if(i == right) {
                // パーティションの長さ（right - left + 1）を結果に追加
                result.push_back(right - left + 1);
                // 次のパーティションの開始位置を設定
                left = i + 1;
            }
        }
        
        return result; // 結果を返す
    }
};