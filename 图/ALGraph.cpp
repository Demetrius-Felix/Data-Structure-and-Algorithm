//邻接表
#include<iostream>
#define MVnum 100
using namespace std;

typedef struct ArcNode{
    int adjvex;//邻接顶点的下标
    struct ArcNode* next;
}ArcNode;//边结点

typedef struct VNode{
    char data;
    ArcNode *firstarc;//边表
}VNode,Adjlist[MVnum];//顶点表(顺序表，每个顶点连接一个边表)

typedef struct{
    Adjlist vertices;//邻接表
    int vexnum,arcnum;
    int *isvisited;
}ALGraph;

int locate(ALGraph g,char v1){
    for(int i=0;i<g.vexnum;i++){
        if(g.vertices[i].data==v1)return i;
    }
    return -1;
}

void CreateALGraph(ALGraph &g){
    /*g.isvisited=new int[g.vexnum];
    for(int i=0;i<g.vexnum;i++){
        g.isvisited[i]=0;
    }*/
    cin>>g.arcnum>>g.vexnum;
    for(int i=0;i<g.vexnum;i++){
        cin>>g.vertices[i].data;
        g.vertices[i].firstarc=NULL;
    }//初始化顶点表
    for (int k = 0; k< g.arcnum; k++)
    {
        char v1,v2;
        cin>>v1>>v2;
        int i=locate(g,v1);
        int j=locate(g,v2);
        ArcNode* p1=new ArcNode;
        p1->adjvex=j;
        p1->next=g.vertices[i].firstarc;
        g.vertices[i].firstarc=p1;
        ArcNode* p2=new ArcNode;
        p2->adjvex=i;
        p2->next=g.vertices[j].firstarc;
        g.vertices[j].firstarc=p2;
    }//添加边结点
}   

void printgraph(ALGraph g){
    for(int i=0;i<g.vexnum;i++){
        cout<<g.vertices[i].data<<" ";
        ArcNode* curr=g.vertices[i].firstarc;
        while(curr){
            cout<<curr->adjvex<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
}

int main()
{
    ALGraph g;
    CreateALGraph(g);
    printgraph(g);
    return 0;
}