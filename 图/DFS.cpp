//深度优先搜索(以邻接矩阵为示范)
#include<iostream>
#include<queue>
#define MaxInt 32767
#define MVnum 100
using namespace std;

typedef struct{
    char vexs[MVnum];
    int arcs[MVnum][MVnum];
    int vexnum,arcnum;
    //int *visited;
}AMGraph;

int locate(AMGraph g,char v){
    for(int i=0;i<g.vexnum;i++){
        if(g.vexs[i]==v)return i;
    }
    return -1;
}
void createAMGraph(AMGraph &g){
    cin>>g.arcnum>>g.vexnum;
    for(int i=0;i<g.vexnum;i++){
        cin>>g.vexs[i];
    }
    for(int i=0;i<g.vexnum;i++){
        for(int j=0;j<g.vexnum;j++){
            g.arcs[i][j]=0;
        }
    }
    for(int k=0;k<g.arcnum;k++){
        char v1,v2;
        cin>>v1>>v2;
        int i=locate(g,v1);
        int j=locate(g,v2);
        g.arcs[i][j]=g.arcs[j][i]=1;
    }
}
/*
void printAMGraph(AMGraph g){
    for(int i=0;i<g.vexnum;i++){
        for(int j=0;j<g.vexnum;j++){
            printf("%10d",g.arcs[i][j]);
        }
        cout<<endl;
    }
}*/

void DFS(AMGraph &g,int * &visited,int v){
    cout<<g.vexs[v]<<"  ";
    visited[v]=1;
    for(int w=0;w<g.vexnum;w++){
        if(g.arcs[v][w]==1&&visited[w]==0)
            DFS(g,visited,w);
    }
}

int main()
{
    AMGraph g;
    createAMGraph(g);
    int *visited;
    visited=new int[g.vexnum];
    for(int i=0;i<g.vexnum;i++){
        visited[i]=0;
    }
    DFS(g,visited,0);
    return 0;
}