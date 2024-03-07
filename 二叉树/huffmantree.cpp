#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;

typedef struct HTNode{
    int weight;
    int parent,lch,rch;
}HTNode,*huffmantree;

void select(huffmantree h,int n,int &s1,int &s2){
    int i;
	float min1 =100, min2 = 100;
	s1 = s2 = 1;
	for (i = 1; i <= n; i++){
		if (h[i].weight < min1 && h[i].parent == 0){
			min1 = h[i].weight;
			s1 = i;
		}
        else if(h[i].weight < min2 && h[i].parent == 0){
			min2 = h[i].weight;
			s2 = i;
		}
	}
}

void CreateHuffmantree(huffmantree &h,int n){
    h=new HTNode[2*n];
    for(int i=1;i<=n;i++){
        cin>>h[i].weight;
    }
    for(int i=1;i<2*n;i++){
        h[i].lch=h[i].rch=h[i].parent=0;
    }//初始化哈夫曼树   
    for(int i=n+1;i<=2*n-1;i++){
        int s1,s2;
        select(h,i-1,s1,s2);//找出权值最小的两个结点，返回其下标
        h[i].lch=s1;     h[i].rch=s2;
        h[s1].parent=h[s2].parent=i;  
        h[i].weight=h[s1].weight+h[s2].weight;   
    }
}

void print_huffmantree(huffmantree h,int n){
    cout<<"结点i"<<"   "<<"weight"<<"   "<<"parent"<<"   "<<"lch"<<"   "<<"rch"<<endl;
    for(int i=1;i<=2*n-1;i++){
        cout<<i<<"        "<<h[i].weight<<"        "<<h[i].parent<<"        "<<h[i].lch<<"      "<<h[i].rch<<"      "<<endl;
    }
}

int main()
{
    huffmantree h;
    int n;
    cin>>n;
    CreateHuffmantree(h,n);
    print_huffmantree(h,n);
    delete h;
    return 0;
}