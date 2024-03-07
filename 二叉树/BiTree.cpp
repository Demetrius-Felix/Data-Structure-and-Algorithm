#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;

class BinaryTree{
    private:
        char data;
        BinaryTree *lchild,*rchild;
    public:
        void Pre_orderTraverse(BinaryTree* t){
            if(t){
                cout<<t->data<<" ";
                Pre_orderTraverse(t->lchild);
                Pre_orderTraverse(t->rchild);
            }
        }

        void In_orderTraverse(BinaryTree* t){
            if(t){
                In_orderTraverse(t->lchild);
                cout<<t->data<<" ";
                In_orderTraverse(t->rchild);
            }
        }

        void CreateBinaryTree_pre(BinaryTree* &t){
            char ch;
            cin>>ch;
            if(ch=='#')t=NULL;
            else{
                t=new BinaryTree;
                t->data=ch;//判断不为空，则分配一个结点存放根结点的数据元素
                CreateBinaryTree_pre(t->lchild);
                CreateBinaryTree_pre(t->rchild);
            }
        }
        void LevelOrderTraverse(BinaryTree* t){
            queue<BinaryTree*>q;
            q.push(t);
            while(!q.empty()){
                BinaryTree* curr=q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->lchild)q.push(curr->lchild);
                if(curr->rchild)q.push(curr->rchild);
            }
        }
};


int main()
{
    BinaryTree* t;
    t->CreateBinaryTree_pre(t);
    t->LevelOrderTraverse(t);
    return 0;
}