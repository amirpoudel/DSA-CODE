//
// Created by amir on 9/2/22.
//
// is binary tree heap



/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
       public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode()
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int nodeCount(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    int count  = 1+nodeCount(root->left)+nodeCount(root->right);
    return count;
}


bool isCBT(BinaryTreeNode<int>* root,int i,int count){
    if(root==NULL){
        return true;
    }
    if(i>=count){
        return false;
    }else{
        bool left =  isCBT(root->left,2*i+1,count);
        bool right =  isCBT(root->right,2*i+2,count);

        return (left && right);
    }

}

bool isMaxOrder(BinaryTreeNode<int>*root){

    //leaf node
    if(root->left==NULL and root->right==NULL){
        return true;
    }

    if(root->right==NULL){
        if(root->data>=root->left->data){
            return true;
        }else return false;
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        if(left && right&& (root->data >= root->left->data && root->data >= root->right->data)){
            return true;
        }else{
            return false;
        }

    }

}



bool isBinaryHeapTree(BinaryTreeNode<int>* root)
{
    // Write your code here.
    int i=0;
    int count = nodeCount(root);
    if(isCBT(root,i,count) and isMaxOrder(root)){
        return true;
    }else{
        return false;
    }



}