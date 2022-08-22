//
// Created by amir on 8/21/22.
//
//Build Binary Tree;



#include "iostream"
#include "queue"
using namespace std;

//creating Node

class Node{
public:
    int data;
    Node* left;
    Node* right;
public:
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }


};



Node* buildTree(Node* root){
    cout<<"Enter Data";
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root = new Node(data);
    root->left  = buildTree(root);
    root->right = buildTree(root);
    return root;
}

Node* buildTreeFromLevelOrder(Node* root){
    queue<Node*>q;
    cout<<"Enter The Root Element";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter data for left part"<<temp->data;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data for Right part"<<temp->data;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }


    }

    return root;
}

void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left){
        postOrderTraversal(root->left);
    }
    if(root->right){
        postOrderTraversal(root->right);
    }
    cout<<root->data<<" ,";
}


void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<", ";
    if(root->left){
        preOrderTraversal(root->left);
    }
    if(root->right){
        preOrderTraversal(root->right);
    }
}


void inOrderTraversal(Node* root){
    if(root ==NULL){
        return;
    }

    if(root->left){
        inOrderTraversal(root->left);
    }
    cout<<root->data<<" ,";
    if(root->right){
        inOrderTraversal(root->right);
    }
}


void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();


        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" , ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }



    }
}


int main(){
    Node * root = NULL;
    root = buildTreeFromLevelOrder(root);
    //terminal input data - 11 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelOrderTraversal(root);
    inOrderTraversal(root);
    //preOrderTraversal(root);

    return 0;

}
