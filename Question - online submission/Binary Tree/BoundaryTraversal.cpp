//
// Created by amir on 8/24/22.
//
//Boundary Traversal



/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void leftPart(TreeNode<int>* root,vector<int>&result){

    if(root==NULL){
        return;
    }

    if(root->left==NULL and root->right==NULL){
        return;
    }

    result.push_back(root->data);
    if(root->left){
        leftPart(root->left,result);
    }else{
        leftPart(root->right,result);
    }

}


void leafNodePart(TreeNode<int>* root,vector<int>&result){
    if(root == NULL){

        return;
    }
    //leaf node
    if(root->left==NULL and root->right ==NULL){
        result.push_back(root->data);
    }

    leafNodePart(root->left,result);
    leafNodePart(root->right,result);

}


void rightPart(TreeNode<int>* root,vector<int>&result){

    if(root==NULL){
        return;
    }

    if(root->left==NULL and root->right==NULL){
        return;
    }

    if(root->right){
        rightPart(root->right,result);
    }else{
        rightPart(root->left,result);
    }

    result.push_back(root->data);



}


vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.

    vector<int> result ;
    if(root==NULL){
        return result;
    }

    //print left part

    result.push_back(root->data);
    leftPart(root->left,result);


    // traverse leaf;

    leafNodePart(root->left,result);
    leafNodePart(root->right,result);


    //print right part;
    rightPart(root->right,result);





}