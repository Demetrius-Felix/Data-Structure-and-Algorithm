#include<iostream>
#include<queue>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
using namespace std;

typedef struct BiNode{
    char data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void CreateBitree_pre(BiTree &t){
    char ch;
    cin>>ch;
    if(ch=='#')t=NULL;
    else{
        t=new BiNode;
        t->data=ch;
        CreateBitree_pre(t->lchild);
        CreateBitree_pre(t->rchild);
    }
}

void LevelOrderTraversal(BiTree t){
    queue<BiTree>q;
    q.push(t);
    while(!q.empty()){
        BiTree curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->lchild)q.push(curr->lchild);
        if(curr->rchild)q.push(curr->rchild);
    }
}

int main()
{
    BiTree t;
    CreateBitree_pre(t);
    LevelOrderTraversal(t);
    return 0;
}