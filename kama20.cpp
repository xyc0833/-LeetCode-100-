//kama19题没有 跳过 不用管它
//自己的尝试
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;

    while(cin>>n){
        if(n == 0) {
            cout<<"list is empty"<<endl;
            break;
        }
        
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin>>m;
            arr.push_back(m);
        }
        for(auto p:arr){
            cout<<p<<" ";
        }
        cout<<endl;
    }
    return 0;
}


#include <iostream>
using namespace std;

// 定义链表节点结构体
struct LinkedNode {
    int val;           // 节点的值
    LinkedNode* next;  // 指向下一个节点的指针

    // 构造函数
    LinkedNode(int x) : val(x), next(nullptr) {}
};

// 输出链表
void printLinkedList(LinkedNode* head) {
    LinkedNode* cur = head;
    if (!cur) {
        cout << "list is empty" << endl;
        return;
    }
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 删除链表中的重复元素（去重）
LinkedNode* deleteDuplicates(LinkedNode* head) {
    LinkedNode* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        if (cur->val == cur->next->val) {
            // 如果当前节点和下一个节点值相等，删除下一个节点
            LinkedNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        } else {
            // 否则，继续移动到下一个节点
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    int n, m;
    while (cin >> n) {
        if (n == 0) {
            cout << "list is empty" << endl;
            continue;
        }

        // 创建虚拟头结点
        LinkedNode* dummyHead = new LinkedNode(0);
        LinkedNode* cur = dummyHead;

        // 构建链表
        while (n--) {
            cin >> m;
            LinkedNode* newNode = new LinkedNode(m);
            cur->next = newNode;
            cur = cur->next;
        }

        // 打印删除前的链表
        printLinkedList(dummyHead->next);

        // 删除重复元素
        LinkedNode* uniqueList = deleteDuplicates(dummyHead->next);

        // 打印删除后的链表
        printLinkedList(uniqueList);
    }

    return 0;
}




#include <bits/stdc++.h>
using namespace std;
//定义链表的结构体
struct LinkNode{
    int val; //节点的值
    LinkNode* next;//指向下一个节点的指针
    //构造函数
    LinkNode(int x):val(x),next(nullptr){}
};
//输出链表
void printLinkedList(LinkNode* head){
    LinkNode* temp = head;
    if(temp == nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    while(temp !=nullptr){
        cout<<temp->val<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}
//删除链表中的重复元素(去重)
//思路 用双指针 去重
LinkNode* deleteDuplicates(LinkNode* head){
    LinkNode* cur = head;
    while(cur != nullptr && cur->next != nullptr){
        if(cur->val == cur->next->val){
            //如果当前节点 和 下一个节点值相等
            LinkNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }else{
            //否则 继续移动到下一个节点
            cur = cur ->next;
        }
    }
    return head;
}

int main() {
    int n,m;
    while(cin>>n){
        if(n == 0){
            cout<<"list is empty"<<endl;
            continue;
        }
        //创建虚拟头节点
        LinkNode* dummyHead = new LinkNode(0);
        LinkNode* cur = dummyHead;
        //构建链表
        while(n--){
            cin>>m;
            LinkNode* newNode = new LinkNode(m);
            cur->next = newNode;
            //cur指针往后移
            cur = cur->next;
        }
        //打印删除前的链表
        printLinkedList(dummyHead->next);
        //删除链表中的重复元素
        LinkNode* uniqueList = deleteDuplicates(dummyHead->next);
        //打印删除后的链表
        printLinkedList(uniqueList);
    }
    return 0;
}
