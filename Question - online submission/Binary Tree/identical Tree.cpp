//
// Created by amir on 8/23/22.
//

//identical Tree

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.

    if(root1 == NULL and root2 == NULL){
        return true;
    }
    if(root1==NULL and root2!=NULL){
        return false;
    }
    if(root1!=NULL and root2==NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    bool left = identicalTrees(root1->left,root2->left);
    bool right = identicalTrees(root1->right,root2->right);
    bool val = root1->data==root2->data;
    if(left&&right&&val){
        return true;
    }else{
        return false;
    }


}