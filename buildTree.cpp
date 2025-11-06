#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
     Node*right;
     
     Node(int val){
        left=right=NULL;
        data=val;
     }
    };
     static int idx = -1;
     Node*buildTree(vector<int>preorderd){  //main fuction
        idx++;
        if(preorderd[idx]==-1){
            return NULL;
        }
       Node* root=new Node(preorderd[idx]);
      root->left = buildTree(preorderd);
       root->right = buildTree(preorderd);
       return root;
     }
     

int main(){
    vector<int>preorderd = { 1,2,-1,-1,3,4,-1,-1,5,-1,-1};
     Node* root=buildTree(preorderd);
     cout<<root->data<<endl;
        cout<<root->left->data<<endl;
             cout<<root->right->data<<endl;
    return 0;
}