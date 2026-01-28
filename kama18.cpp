#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,m,t,z;
    string s;
    cin>>n;
    while(n--){
        cin>>a;

    }

    return 0;
}



//gpt的答案

#include <bits/stdc++.h>
using namespace std;
//定义链表结点结构
struct Node{
    int data;
    Node* next;
    
    Node(int x) : data(x),next(nullptr){}
};
//链表类
class LinkedList{
public:
    Node* head;//头指针
    //构造函数
    LinkedList():head (nullptr){}

    //1 插入操作 ，插入位置前
    int addAtIndex(int pos,int value){
        //1 创建新节点
        Node* newNode = new Node(value);
        if(pos<0) return -1;//不合法的索引
        //2 插入头节点的情况
        if(pos == 0){
            newNode ->next = head;// 新节点指向原来的头节点
            head = newNode;  // 头指针指向新节点
            return 0;
        }
        //3 找到插入位置的前一个节点
        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            //如果temp指针为空  说明链表已经遍历完了 
            //相当于 pos的位置 大于链表实际的长度 返回 -1
            if(temp == nullptr) return -1;
            temp = temp ->next;
        }
        //4 如果遍历到最后仍然没有找到合适的插入位置
        // 说明超出了链表的范围
        if(temp == nullptr) return -1;

        //画图理解一下
        newNode->next = temp->next;
        temp->next = newNode;
        return 0;
    }
    //2 删除操作 删除指定位置的节点
    int deleteAtIndex(int pos){
        //先检查是否为空链表 或者不合法的索引
        if(head == nullptr || pos<0) return -1;
        // 如果是删除头节点的情况
        if(pos == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return 0;
        }
        //如果是删除 非头节点
        Node* temp = head;
        //也是要先找到删除位置的前一个节点
        for(int i=0;i<pos-1;i++){
            if(temp == nullptr || temp->next == nullptr) return -1;
            temp = temp ->next;
        }
        // 如果遍历到最后仍然没有找到合适的插入位置
        // 说明超出了链表的范围
        if(temp == nullptr || temp->next == nullptr) return -1;

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
        return 0;
    }

    //3. 获取指定位置的节点数据
    int get(int pos){
        Node* temp = head;
        for(int i=0;i<pos;i++){
            if(temp == nullptr)return -1;
            temp = temp->next;
        }
        if(temp == nullptr) return -1;
        return temp->data;
    }
    //4 显示链表内容
    void show(){
        if(head == nullptr){
            cout<<"Link list is empty"<<endl;
            return ;
        }
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data <<" ";
            temp = temp ->next;
        }
        cout<<endl;
    }

};


int main() {
    int n, a, m, t, z;
    string s;

    // 读入链表的初始化数据
    cin >> n;
    LinkedList list;

    // 初始化链表（倒序插入）
    while (n--) {
        cin >> a;
        //从头部插入
        list.addAtIndex(0,a);
    }
    cin>>m;//操作数
    while(m--){
        cin>>s;//操作类型
        if(s == "show"){
            list.show();
        }else if(s == "delete"){
            cin>>t;
            //为什么是 t-1
            //这是因为链表的索引是从 0 开始的，而题目中给出的操作（例如：delete 1）是从 1 开始的。
            //这就导致了 索引偏移
            if(list.deleteAtIndex(t-1) == -1){
                cout<<"delete fail"<<endl;
            }else {
                cout<<"delete OK"<<endl;
            }
        }else if(s == "insert"){
            cin>>t>>z;
            if(list.addAtIndex(t-1,z) == -1){
                cout<<"insert fail"<<endl;
            }else{
                cout<<"insert OK"<<endl;
            }
        }else if(s == "get"){
            cin>>t;
            int getValue = list.get(t-1);
            if(getValue == -1) cout<<"get fail"<<endl;
            else cout<<getValue<<endl;
        }
    }
    return 0;
}
