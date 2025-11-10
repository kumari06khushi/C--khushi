#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
int data;
Node*left;
Node*right;

Node(int val){
data=val;
left=right=NULL;
}
};

static int idx = -1;
Node*buildTree(vector<int>preorderd){
idx++;
if(preorderd[idx] == -1){
return NULL;
}
Node*root = new Node(preorderd[idx]);
root->left = buildTree(preorderd);
       root->right = buildTree(preorderd);
       return root;
}
//height of the tree
int height(Node*root){
    if(root==NULL){
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt , rightHt)+1;
}

int main(){
vector<int>preorderd = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node*root = buildTree(preorderd);
cout<< "height: "<<height(root)<<endl;
    return 0;
}
/*
Node 2 has no children (left=NULL and right=NULL).

So:
height(NULL) → 0
height(NULL) → 0
max(0,0) + 1 = 1
✅ So height(root->left) returns 1
*/