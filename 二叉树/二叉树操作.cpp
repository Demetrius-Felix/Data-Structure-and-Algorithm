#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//根结点定义
typedef struct TreeNode{
    char val;
    TreeNode* left,*right;
}TreeNode;

//先序遍历
void preorderTraverse(TreeNode* root){
    if(!root)return;
    else{
        cout<<root->val;
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }
}

//中序遍历
void inorderTraverse(TreeNode* root){
    if(!root)return;
    else{
        inorderTraverse(root->left);
        cout<<root->val;
        inorderTraverse(root->right);
    }
}

//后序遍历
void postorderTraverse(TreeNode* root){
    if(!root)return;
    else{
        postorderTraverse(root->left);
        postorderTraverse(root->right);
        cout<<root->val;
    }
}

//层次遍历
void LevelorderTraverse(TreeNode* root){
    queue<TreeNode*>q;
    if(!root)return;
    else q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        cout<<curr->val;
        q.pop();
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    
}

//先序构建二叉树
void createBinaryTree_pre(TreeNode* &root){
    char ch;
    cin>>ch;
    if(ch=='#')root=nullptr;
    else{
        root=new TreeNode;
        root->val=ch;
        createBinaryTree_pre(root->left);
        createBinaryTree_pre(root->right);
    }
}


//翻转二叉树
TreeNode* invertTree(TreeNode* root){
    if(!root)return nullptr;
    swap(root->left,root->right);//交换根节点的左右结点
    invertTree(root->left);//递归交换左子树的左右结点
    invertTree(root->right);//递归交换右子树的左右结点
    return root;
}

//对称二叉树
bool isSymmetric(TreeNode* root) {
    if(!root)return true;
    return ismirror(root->left,root->right);//左右子树镜像对称
}
bool ismirror(TreeNode* p,TreeNode* q){//检查两棵树是否镜像对称
    if(!p&&!q)return true;//两树均为空
    else if(!p||!q)return false;//两树有一个为空
    else if(p->val!=q->val)return false;//两树值不相等
    else return ismirror(p->left,q->right)&&ismirror(p->right,q->left); 
}

//根据先序遍历和中序遍历序列构建二叉树
TreeNode* buildtree(char* preorder,char* inorder,int size){
    if(!preorder||!inorder||size==0)return NULL;
    int root_index=0;
    while(inorder[root_index]!=preorder[0]&&root_index<size){
        root_index++;
    }
    if(root_index>=size)return NULL;
    TreeNode* root=new TreeNode;
    root->val=preorder[0];
    root->left=root->right=NULL;
    if(root_index>0){
        root->left=buildtree(preorder+1,inorder,root_index);
    }
    if(size-root_index-1>0){
        root->right=buildtree(preorder+root_index+1,inorder+root_index+1,size-root_index-1);
    }
    return root;
}

int main()
{
    string preorder,inorder;
    cin>>preorder>>inorder;
    TreeNode* root=buildtree(&preorder[0],&inorder[0],preorder.size());
    postorderTraverse(root);
    return 0;
}
