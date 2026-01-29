#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x):val(x),left(nullptr),right(nullptr){}
};

// 前序
void preorder(TreeNode* root, string& res){
    if(!root) return;
    res += root->val;
    preorder(root->left, res);
    preorder(root->right, res);
}

// 中序
void inorder(TreeNode* root, string& res){
    if(!root) return;
    inorder(root->left, res);
    res += root->val;
    inorder(root->right, res);
}

// 后序
void postorder(TreeNode* root, string& res){
    if(!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res += root->val;
}

int main(){
    int N;
    cin >> N;

    vector<TreeNode*> nodes(N + 1);
    vector<int> L(N + 1), R(N + 1);

    // 1️⃣ 创建所有节点
    for(int i = 1; i <= N; i++){
        char c;
        cin >> c >> L[i] >> R[i];
        nodes[i] = new TreeNode(c);
    }

    // 2️⃣ 连左右孩子
    for(int i = 1; i <= N; i++){
        if(L[i] != 0) nodes[i]->left = nodes[L[i]];
        if(R[i] != 0) nodes[i]->right = nodes[R[i]];
    }

    TreeNode* root = nodes[1];

    string pre, in, post;
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);

    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;

    return 0;
}

// 思路 
// 树的定义方式按照上一题的做法
// 需要额外开 左右 两个数组来存下标
// 先创建所有的节点
// 然后再去连接 因为有可能没有被遍历到  
#include<bits/stdc++.h>
using namespace std;
//定义树的结构体
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    //初始化列表的写法
    TreeNode(char x):val(x),left(nullptr),right(nullptr){}
};
//三种遍历顺序 不敲了
// 前序
void preorder(TreeNode* root, string& res){
    if(!root) return;
    res += root->val;
    preorder(root->left, res);
    preorder(root->right, res);
}

// 中序
void inorder(TreeNode* root, string& res){
    if(!root) return;
    inorder(root->left, res);
    res += root->val;
    inorder(root->right, res);
}

// 后序
void postorder(TreeNode* root, string& res){
    if(!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res += root->val;
}
int main(){
    int n;
    cin>>n;
    //Step 1：先创建所有节点（只建点，不连边）
    vector<TreeNode*> nodes(n+1); //每个元素是一个指向 TreeNode 对象的指针。
    //因为后面的左右孩子可能指向还没读到的 结点
    //step 2 保存左右孩子编号（临时存）
    vector<int> L(n+1),R(n+1);
    
    for(int i=1;i<=n;i++){
        char c;
        cin>>c>>L[i]>>R[i];
        nodes[i] = new TreeNode(c);
    }
    //全部存完之后 开始连
    for(int i=1;i<=n;i++){
        if(L[i] != 0) nodes[i]->left = nodes[L[i]];
        if(R[i] != 0) nodes[i]->right = nodes[R[i]];
    }
    TreeNode* root = nodes[1];

    string pre, in, post;
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);

    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;

    return 0;
}