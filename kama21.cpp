//gpt给出的代码

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 定义二叉树节点结构体
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// 后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);  // 先遍历左子树
    postorderTraversal(root->right); // 再遍历右子树
    cout << root->val;              // 最后访问根节点
}

// 构建二叉树
TreeNode* buildTree(string preorder, string inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;

    // 前序遍历的第一个字符是根节点
    char rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);

    // 在中序遍历中找到根节点的位置，划分左右子树
    int rootIndex = inorder.find(rootVal);

    // 递归构建左右子树
    string leftPreorder = preorder.substr(1, rootIndex); // 左子树的前序遍历
    string leftInorder = inorder.substr(0, rootIndex);   // 左子树的中序遍历
    string rightPreorder = preorder.substr(rootIndex + 1); // 右子树的前序遍历
    string rightInorder = inorder.substr(rootIndex + 1);   // 右子树的中序遍历

    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
}

int main() {
    string s;
    while (getline(cin, s)) { // 接受一整行字符串
        string preorder = "", inorder = "";
        
        // 拆分出两个字符串，前序遍历和中序遍历
        int i;
        for (i = 0; s[i] != ' '; i++) preorder += s[i]; // 前序遍历字符串
        i++;
        for (; i < s.size(); i++) inorder += s[i];   // 中序遍历字符串

        // 开始构造二叉树
        TreeNode* root = buildTree(preorder, inorder);
        
        // 输出后序遍历结果
        postorderTraversal(root);
        cout << endl;
    }
    return 0;
}


3. 初始化列表
初始化列表是在构造函数的头部初始化成员变量的一种方式，它能提高代码效率，尤其是在处理常量成员变量或引用成员时。
class MyClass {
public:
    int a;
    double b;

    // 使用初始化列表
    MyClass(int x, double y) : a(x), b(y) {}
};


//leetcode 105

//具体思路
//1 构造二叉树 需要用到递归
//2 将构造好的二叉树 按照 左右中的方式 后续遍历 也需要用到递归
#include<bits/stdc++.h>
using namespace std;
//定义二叉树 结构体
//学习一下 初始化列表的 写法
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x):val(x),left(nullptr),right(nullptr){}
};

//后续遍历写法
void postTreversal(TreeNode* root){
    if(root == nullptr){
        return ;
    }
    //左 右 中
    postTreversal(root->left);
    postTreversal(root->right);
    cout<<root->val;
}
//如何通过 前序和 中序 构造后序
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

int main(){
    string s;
    while(getline(cin,s)){
        //借助 kama14中学习的 istringstream的用法
        istringstream ss(s);
        string preorder;
        ss>>preorder; //cout<<preorder<<endl;
        string inorder;
        ss>>inorder; //cout<<inorder<<endl;
        //开始构造二叉树
        TreeNode* root = buildTree(preorder,inorder);
        //输出后序遍历的结果
        postTreversal(root);
        cout<<endl;
    }
    return 0;
}
