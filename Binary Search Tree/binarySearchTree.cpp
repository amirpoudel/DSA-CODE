//
// Created by amir on 8/28/22.
//
//Binary Search Tree

#include "iostream"

using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;

public:

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data>root->data){
        root->right = insertIntoBST(root->right,data);
    }else{
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

void takeInput(Node* &root){
    cout<<"Input data";
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

bool searchInBST(Node *root, int x) {
    // Write your code here.

    if(root==NULL){
        return false;
    }
    if(x == root->data){
        return true;
    }
    if(x>root->data){
        return searchInBST(root->right,x);
    }else{
        return searchInBST(root->left,x);
    }

}


int main(){

    Node* root = new Node(10);
    takeInput(root);


    return 0;
}