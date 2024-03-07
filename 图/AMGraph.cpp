//邻接矩阵
#include<iostream>
#define MaxInt 32767
#define MVnum 100
using namespace std;

typedef struct{
    char vexs[MVnum];
    int arcs[MVnum][MVnum];
    int vexnum,arcnum;
}AMGraph;

int locate(AMGraph g,char s1){
    for(int i=0;i<g.vexnum;i++){
        if(s1==g.vexs[i])return i;
    }
    return -1;
}
void CreateUDN(AMGraph &g){//无向图
    cin>>g.vexnum>>g.arcnum;
    for(int i=0;i<g.vexnum;i++){
        cin>>g.vexs[i];
    }
    for(int i=0;i<g.vexnum;i++){
        for(int j=0;j<g.vexnum;j++){
            g.arcs[i][j]=MaxInt;
        }
    }
    for(int k=0;k<g.arcnum;k++){
        char v1,v2;
        int w;
        cin>>v1>>v2>>w;
        int i=locate(g,v1);
        int j=locate(g,v2);
        g.arcs[i][j]=g.arcs[j][i]=w;
    }
}

void printAMGraph(AMGraph g){
    for(int i=0;i<g.vexnum;i++){
        for(int j=0;j<g.vexnum;j++){
            printf("%10d",g.arcs[i][j]);
        }
        cout<<endl;
    }
}
int main()
{
    
}