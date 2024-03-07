#include<iostream>
#define MAXSIZE 100
using namespace std;

typedef struct{
    int *data;
    int length;
}sqlist;

void createsqlist(sqlist &s,int n){
    s.data=new int[MAXSIZE];
    s.length=0;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        s.data[i]=e;
        s.length++;
    }
}    
void printlist(sqlist &s){
    for(int i=0;i<s.length;i++){
        cout<<s.data[i]<<" ";
    }
}

bool Insert(sqlist &s,int i,int e){
    if(i<1||i>s.length+1)return false;
	for(int j=s.length;j>=i;j--){
		s.data[j]=s.data[j-1];
	}
	s.data[i-1]=e;
	s.length++;
}

void Delete(sqlist &s,int i){
    for(int j=i-1;j<s.length-1;j++){
		s.data[j]=s.data[j+1];
	}
	s.length--;
}

void DeleteNodes(sqlist &s,int x){//删除多个重复结点
    int k=0;
    for(int i=0;i<s.length;i++){
        if(s.data[i]!=x)s.data[k++]=s.data[i];
    }
    s.length=k;
}
void mergelist(sqlist s1,sqlist s2,sqlist &s3){//合并有序表
    s3.length=s1.length+s2.length;
    s3.data=new int[s3.length];
    int* p1=s1.data;
    int* p1_last=&s1.data[s1.length-1];
    int* p2=s2.data;
    int* p2_last=&s2.data[s2.length-1];
    int* p3=s3.data;
    while(p1<=p1_last&&p2<=p2_last){
        if(*p1<=*p2)*p3++=*p1++;
        else *p3++=*p2++;
    }
    while(p1<=p1_last)*p3++=*p1++;
    while(p2<=p2_last)*p3++=*p2++;
}


int main()
{
    sqlist s1,s2,s3;
    int n;
    cin>>n;
    createsqlist(s1,n);
    DeleteNodes(s1,3);
    printlist(s1);
    return 0;
}