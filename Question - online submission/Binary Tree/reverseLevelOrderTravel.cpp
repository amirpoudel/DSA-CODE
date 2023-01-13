//
// Created by amirp on 11/15/2022.
//

//Reverse Level Order Traversal - code studio

//usign queue and stack

#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    vector<int>result;
    if(root==NULL){
        return result;
    }

    queue<TreeNode<int>*>level;
    stack<TreeNode<int>*>st;

    level.push(root);
    while(!level.empty()){
        TreeNode<int>* front = level.front();
        level.pop();
        st.push(front);
        if(front->left){
            level.push(front->left);
        }
        if(front->right){
            level.push(front->right);
        }

    }
    while(!st.empty()){
        result.push_back(st.top()->val);
        st.pop();
    }
    return result;
}