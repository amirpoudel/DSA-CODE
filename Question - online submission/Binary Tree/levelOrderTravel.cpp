//
// Created by amirp on 11/15/2022.
//


//Level Order Traversal - code studio

#include <bits/stdc++.h>
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>result;
    if(root==NULL){
        return result;
    }
    queue<BinaryTreeNode<int>*> level;

    level.push(root);
    while(!level.empty()){
        BinaryTreeNode<int> * front = level.front();
        level.pop();
        result.push_back(front->val);
        if(front->left){
            level.push(front->left);
        }
        if(front->right){
            level.push(front->right);
        }
    }
    return result;
}