//
// Created by amir on 8/18/22.
//
//Coding studio - Medium

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

class Stack
{
    //Write your code here
    Node* stackNode;
    Node* top;
    int sizeCount;

public:
    Stack()
    {
        //Write your code here
        this->top = NULL;
        this->sizeCount = 0;

    }

    int getSize()
    {
        //Write your code here
        return sizeCount;

    }

    bool isEmpty()
    {
        //Write your code here
        if(top==NULL){
            return true;
        }else{
            return false;
        }
    }

    void push(int data)
    {
        //Write your code here
        this->stackNode = new Node(data);
        stackNode->next = top;
        top = stackNode;
        sizeCount++;
    }

    void pop()
    {
        //Write your code here
        if(!isEmpty()){
            Node*temp = top;
            top = top->next;
            delete(temp);
            sizeCount--;
        }else{
            return;
        }

    }

    int getTop()
    {
        //Write your code here
        if(sizeCount>0){
            return top->data;
        }else{
            return -1;
        }
    }
};