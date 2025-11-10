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
     Node*buildTree(vector<int>preordered){  //main fuction
        idx++;
        if(preordered[idx]==-1){
            return NULL;
        }
       Node* root=new Node(preordered[idx]);
      root->left = buildTree(preordered);
       root->right = buildTree(preordered);
       return root;
     }
    //preordered
    void Ordered(Node*root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        Ordered(root->left);
         Ordered(root->right);
    }

    int main(){
    vector<int>preordered = { 1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  Node*root = buildTree(preordered);
Ordered(root);
  cout<<endl;
    return 0;
}