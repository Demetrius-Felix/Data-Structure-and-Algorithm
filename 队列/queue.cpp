#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct{
    int *base;
    int front;
    int rear;
}queue;

void Init(queue &q){
    q.base=new int[MAXSIZE];
    q.front=q.rear=0;
}

int enqueue(queue &q,int e){
    if((q.rear+1)%MAXSIZE==q.front)return ERROR;
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXSIZE;
    return OK;
}

int Dequeue(queue &q){
    if(q.rear==q.front)return ERROR;
    cout<<q.base[q.front]<<" ";
    q.front=(q.front+1)%MAXSIZE;
    return OK;
}


int main()
{
    int n;
    queue q;
    Init(q);
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        enqueue(q,e);
    }
    int m;
    cin>>m;
    for(int j=0;j<m;j++){
        Dequeue(q);
    }
    cout<<endl<<q.base[q.front]<<endl;
    return 0;  
}
