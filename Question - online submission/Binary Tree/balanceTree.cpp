//
// Created by amir on 8/23/22.
//

//check balance tree

/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
pair<bool,int> isBalance(BinaryTreeNode<int>* root){


    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalance(root->left);
    pair<bool,int> right = isBalance(root->right);


    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }


    return ans;

}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return isBalance(root).first;




}