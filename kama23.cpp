#include<bits/stdc++.h>
using namespace std;
//构建一个二叉树
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x): val(x),left(nullptr),right(nullptr){}
};
//构建一个二叉树
//1 确定递归的参数
TreeNode* buildTree(string preorder,string inorder){
    //2 确定递归的终止条件
    if(preorder.size() == 0 || inorder.size() == 0){
        return nullptr;
    }
    //先序遍历的第一个节点 肯定是根节点
    char rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);

    //然后在中序遍历中找到根节点 划分左右子树
    // inorder.find(rootVal) 返回的实际上是 size_t 类型，而你把它赋值给了 int 类型的 rootIndex。这在大多数情况下是可以工作的，因为 size_t 和 int 都是数值类型，并且 size_t 是无符号的，而 int 是有符号的。
    int rootIndex = inorder.find(rootVal);
    //递归构建左右子树
    string leftPreorder = preorder.substr(1,rootIndex);
    // substr(i, len) 截取字符串 包左不包右 substr(i)从当前位置截取到最后
    string rightPreorder = preorder.substr(rootIndex+1);
    string leftInorder = inorder.substr(0,rootIndex);
    string rightInorder = inorder.substr(rootIndex + 1);

    //递归
    root->left = buildTree(leftPreorder,leftInorder);
    root->right = buildTree(rightPreorder,rightInorder);
    return root;
}
//求一颗二叉树的最大深度
int getdepth(TreeNode* node) {
    if (node == NULL) return 0;
    int leftdepth = getdepth(node->left);       // 左
    int rightdepth = getdepth(node->right);     // 右
    int depth = 1 + max(leftdepth, rightdepth); // 中
    return depth;
}

int main(){
    int n;//表示二叉树的结点数
    while(cin>>n){
        string preorder,inorder;
        cin>>preorder;
        cin>>inorder;
        //cout<<preorder << ' '<< inorder;

        //先构建二叉树
        TreeNode* root = buildTree(preorder,inorder);
        
        //在求一个二叉树的最大深度
        cout<<getdepth(root)<<endl;
    }
    return 0;
}