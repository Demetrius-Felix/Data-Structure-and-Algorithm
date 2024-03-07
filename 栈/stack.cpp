#include<iostream>
#include<string.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
using namespace std;

typedef struct{
    int *base;
    int *top;
    int stacksize;
}stack;

void Initstack(stack &s){
    s.top=s.base=new int[MAXSIZE];
    s.stacksize=MAXSIZE;
}

int push(stack &s,int e){
    if(s.top-s.base>=s.stacksize)return ERROR;
    *s.top++=e;
    return OK;
}

int pop(stack &s){
    if(s.top==s.base)return ERROR;
    cout<<*--s.top<<" ";
    return OK;
}

int main(){
    int m,n;
    stack s;
    Initstack(s);
    cin>>m;
    for(int i=0;i<m;i++){
        int e;
        cin>>e;
        push(s,e);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        pop(s);
    }
    cout<<*(s.top-1)<<endl;
    return 0;
}
