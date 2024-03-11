//二叉排序树
#include<iostream>
using namespace std;

typedef struct BSTNode{
    int key;
    struct BSTNode* lchild,*rchild;
}BSTNode,*BSTree;

void Insert(BSTree &t,int key){
    if(t==NULL){//根节点为空直接插入
        BSTNode* p=new BSTNode;
        p->key=key;
        p->lchild=p->rchild=nullptr;
        t=p;
    }
    else if(key<t->key)Insert(t->lchild,key);//key小于根节点，插入左子树
    else Insert(t->rchild,key);//key大于根节点，插入右子树
}

BSTNode* FindMin(BSTree t){
    BSTNode* curr=t;
    while(curr&&curr->lchild){
        curr=curr->lchild;
    }
    return curr;
}//非递归查找最小值

/*BSTNode* FindMin(BSTree t){
    BSTNode *curr=t;
    if(curr==NULL)return NULL;
    if(curr->lchild==NULL)return curr;
    else return FindMin(curr->lchild);
}//递归查找最小值*/

BSTNode* FindMax(BSTree t){
    BSTNode* curr=t;
    while(curr&&curr->rchild){
        curr=curr->rchild;
    }
    return curr;
}//非递归查找最大值

/*BSTNode* FindMax(BSTree t){
    BSTNode *curr=t;
    if(curr==NULL)return NULL;
    if(curr->rchild==NULL)return curr;
    return FindMax(curr->rchild);
}//递归查找最大值*/

BSTNode* Find(BSTree t,int key){
    if(t==NULL||key==t->key)return t;
    else if(key<t->key)return Find(t->lchild,key);
    else return Find(t->rchild,key);
}

void CreateBSTree(BSTree &t,int n){
    t=NULL;
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        Insert(t,key);
    }
}

/*void Delete(BSTree &t,int key){
    BSTNode* p=Find(t,key);
    if(p==NULL)return;
    if(p->lchild==NULL&&p->rchild==NULL){
        delete p;
    }
    else if(!p->lchild){
        p=p->rchild;
    }
    else if(!p->rchild){
        p=p->lchild;
    }
    else if(p->lchild&&p->rchild){
        BSTNode* tmp=FindMin(p->rchild);//左子树的最大结点为删除结点的前驱
        p->key=tmp->key;
        Delete(t->rchild,tmp->key);
    }
}*/

BSTNode* Delete(BSTree &t,int key){//在树中删除值为key的结点，返回删除后的二叉排序树
    if(!t)return NULL;
    //树不为空递归查找左右子树，直到key等于某一个根节点的值
    else if(key<t->key)t->lchild=Delete(t->lchild,key);//key小于根节点时，到左子树去删除key
    else if(key>t->key)t->rchild=Delete(t->rchild,key);//key大于根节点时，到右子树去删除key
    else{//key等于根节点
        if(t->lchild&&t->rchild){//左右子树都不为空，用右子树的最小替代根结点
            BSTNode* tmp=FindMin(t->rchild);
            t->key=tmp->key;
            t->rchild=Delete(t->rchild,tmp->key);//删除右子树最小结点
        }
        else{//左右子树有一个为空或两者都为空时
            BSTNode *tmp=t;
            if(!t->lchild){//左子树为空
                t=t->rchild;
            }
            else if(!t->rchild){//右子树为空
                t=t->lchild;
            }
            delete tmp;//均为空则释放结点(或左右子树有一个为空，用其非空子树替代后释放该结点)
        }
    }
}

void In_orderTraverse(BSTree t){
    if(t){
        In_orderTraverse(t->lchild);
        cout<<t->key<<" ";
        In_orderTraverse(t->rchild);
    }
}

int main()
{
    BSTree t;
    int n;
    cin>>n;
    CreateBSTree(t,n);
    int key;
    cin>>key;
    Delete(t,key);
    In_orderTraverse(t);
    return 0;
}
