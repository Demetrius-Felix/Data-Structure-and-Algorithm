#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*Linklist;

void createlist_r(Linklist &l,int n){
    LNode *r,*p;
    r=l=new LNode;
    cin>>r->data;
    for(int i=0;i<n-1;i++){
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}

LNode* mergelist(Linklist &a,Linklist &b){
    LNode *p,*curr;
    p=curr=new LNode;
    while(a&&b){
        if(a->data<b->data){
            curr->next=a;
            curr=a;
            a=a->next;
        }
        else{
            curr->next=b;
            curr=b;
            b=b->next;
        }
    }
    curr->next=a?a:b;
    return p;
}

int main()
{
    Linklist a,b;
    int m,n;
    cout<<"请输入链表a的长度并依次输入链表元素:"<<endl;
    cin>>m;
    createlist (a,m);
    cout<<"请输入链表b的长度并依次输入链表元素:"<<endl;
    cin>>n;
    createlist (b,n);
    cout<<"合并结果如下:"<<endl;
    LNode *curr=mergelist (a,b)->next;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
    return 0;
}
