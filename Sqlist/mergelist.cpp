#include<iostream>
#include<vector>
using namespace std;

class sqlist{
    private:    
        vector<int>data;
        //使用vector容器无需再引入length变量,可用data.size()标示
    public:
        void createlist(int n){
            //data.clear();
            for(int i=0;i<n;i++){
                int e;
                cin>>e;
                data.push_back(e);
            }
        }
        //引入迭代器vector<int>:: itererator对数组元素进行操作
        void mergelist(sqlist s1,sqlist s2,sqlist &s3){
            auto it1=s1.data.begin();
            auto it2=s2.data.begin();
            while(it1<s1.data.end()&&it2<s2.data.end()){
                if(*it1<=*it2)s3.data.push_back(*it1++);
                else s3.data.push_back(*it2++);
            }
            while(it1<s1.data.end())s3.data.push_back(*it1++);
            while(it2<s2.data.end())s3.data.push_back(*it2++);
        }

        void printlist(){
            for(auto it=data.begin();it<data.end();it++){
                cout<<*it<<" ";
            }
        }
};

int main()
{
    sqlist tmp;
    sqlist s1,s2,s3;
    int m;
    cin>>m;
    s1.createlist(m);
    int n;
    cin>>n;
    s2.createlist(n);
    tmp.mergelist(s1,s2,s3);
    s3.printlist();
    return 0;
}