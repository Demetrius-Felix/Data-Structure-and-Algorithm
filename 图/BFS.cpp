//广度优先搜索(以邻接表为示范)
#include<iostream>
#include<queue>
#include<stack>
#define MVnum 100
using namespace std;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode* next;
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode* firstarc;
}VNode,Adjlist[MVnum];

typedef struct{
    Adjlist vertices;
    int vexnum,arcnum;
    int *visited;
}ALGraph;

int locate(ALGraph g,char v1){
    for(int i=0;i<g.vexnum;i++){
        if(g.vertices[i].data==v1)return i;
    }
    return -1;
}
void CreateALGraph(ALGraph &g){
    cin>>g.arcnum>>g.vexnum;
    for(int i=0;i<g.vexnum;i++){
        cin>>g.vertices[i].data;
        g.vertices[i].firstarc=NULL;
    }//初始化顶点表
    g.visited=new int[g.vexnum];
    for(int i=0;i<g.vexnum;i++){
        g.visited[i]=0;
    }
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

void BFS(ALGraph &g,int v){
    queue<int>q;
    q.push(v);
    cout<<g.vertices[v].data<<"  ";
    g.visited[v]=1;
    while(!q.empty()){
        ArcNode *curr=g.vertices[q.front()].firstarc;
        q.pop();
        while(curr){
            if(g.visited[curr->adjvex]==0){
                cout<<g.vertices[curr->adjvex].data<<"  ";
                g.visited[curr->adjvex]=1;
                q.push(curr->adjvex);
            }
            curr=curr->next;
        }
    }
}

/*void printgraph(ALGraph g){
    for(int i=0;i<g.vexnum;i++){
        cout<<g.vertices[i].data<<" ";
        ArcNode* curr=g.vertices[i].firstarc;
        while(curr){
            cout<<curr->adjvex<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
}*/

int main()
{
    ALGraph g;
    CreateALGraph(g);
    BFS(g,0);
    return 0;
}