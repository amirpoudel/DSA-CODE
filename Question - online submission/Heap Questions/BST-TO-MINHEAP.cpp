//
// Created by amirp on 11/19/2022.
//
//convert BST To Min Heap - code studio

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure:

	class BinaryTreeNode {

	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inorderTraversal(BinaryTreeNode*root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    if(root->left){
        inorderTraversal(root->left,arr);
    }
    arr.push_back(root->data);
    if(root->right){
        inorderTraversal(root->right,arr);
    }

}

void preorderTraversal(BinaryTreeNode*root,vector<int>&arr,int &index){
    if(root==NULL){
        return;
    }
    root->data = arr[index];
    index++;
    if(root->left){
        preorderTraversal(root->left,arr,index);
    }
    if(root->right){
        preorderTraversal(root->right,arr,index);
    }
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    // Write your code here.
    vector<int>arr;
    inorderTraversal(root,arr);
    int index = 0;
    preorderTraversal(root,arr,index);
    return root;
}